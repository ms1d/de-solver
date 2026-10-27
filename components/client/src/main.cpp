#include <QApplication>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QFont>
#include <QString>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    //QFont creates a font object to be sed by QObjects
    QFont font;
    font.setPointSize(20);

    //InputPanel contains all the QWidgets that require input
    QFrame InputPanel;
    InputPanel.setFrameShape(QFrame::Panel);
    InputPanel.setFont(font);

    //EquationL is a label that tells the user to input...
    QLabel EquationL("Insert Equation",&InputPanel);
    EquationL.setGeometry(0,0,400,75);

    QString EquationS(" y' + (1/x)y = (1)");

    //...the ODE in this QWidget
    QLineEdit EquationT(EquationS,&InputPanel);
    EquationT.setGeometry(0,75,400,75);

    QLabel BoundaryConditionsL("Boundary Conditions",&InputPanel);
    BoundaryConditionsL.setGeometry(0,150,400,75);

    QString BoundaryConditionS("{10<x<20},{-3<y<3}");

    QLineEdit BoundaryConditionsT(BoundaryConditionS,&InputPanel);
    BoundaryConditionsT.setGeometry(0,225,400,75);

    InputPanel.show();

    return app.exec();}
