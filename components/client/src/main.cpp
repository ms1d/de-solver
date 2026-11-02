#include <QApplication>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QFont>
#include <QString>
#include <QPushButton>
#include <QObject>

QLineEdit *EquationT;
QLineEdit *BoundaryConditionsT;
std::string *Info;

/*This class is just going to be used as a bridge for connect
 * the button press and transferring strings from inputs.
 * Keyword 'public' is necessary for casting in connect.*/
class OutputClass:public QObject{
public:
/* This function is going to be used to take the text in the inputs.
 * Proper validation will be done over on the engine side.*/
void TypeOut(){
    //Text needs to be casted as its type is QString
    Info->append((EquationT->text()).toStdString());
    Info->append((BoundaryConditionsT->text()).toStdString());
}
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    //QFont creates a font object to be sed by QObjects
    QFont DefaultFont;
    DefaultFont.setPointSize(20);

    //InputPanel contains all the QWidgets that require input
    QFrame InputPanel;
    InputPanel.setFrameShape(QFrame::Panel);
    InputPanel.setFont(DefaultFont);

    //EquationL is a label that tells the user to input...
    QLabel EquationL("Insert Equation",&InputPanel);
    EquationL.setGeometry(0,0,400,75);

    QString EquationS(" y' + (1/x)y = (1)");

    //...the ODE in this QWidget
    EquationT = new QLineEdit(EquationS,&InputPanel);
    EquationT->setGeometry(0,75,400,75);

    QLabel BoundaryConditionsL("Boundary Conditions",&InputPanel);
    BoundaryConditionsL.setGeometry(0,150,400,75);

    QString BoundaryConditionS("{10<x<20},{-3<y<3}");

    BoundaryConditionsT = new QLineEdit(BoundaryConditionS,&InputPanel);
    BoundaryConditionsT->setGeometry(0,225,400,75);

    //Assign a null value so it can be appended on
    Info = new std::string();

    QString RunButtonS("Press to run the program");

    QPushButton RunButton(RunButtonS,&InputPanel);
    RunButton.setGeometry(0,300,400,75);
    //Object to allow for slot use
    OutputClass OutputObject;

    QObject::connect(&RunButton,SIGNAL(clicked()),&OutputObject,SLOT(TypeOut()));

    //Should connect button press to method that moves string to engine.

    InputPanel.show();

    return app.exec();
}
