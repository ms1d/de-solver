cmake_minimum_required(VERSION 3.26)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

file(GLOB CL_SRC src/*.cpp)
qt_add_executable(client
	${CL_SRC}
)

target_link_libraries(client PRIVATE
    Qt6::Widgets
	engine
)
