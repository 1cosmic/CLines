project(CLines)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall") 
set(CMAKE_CPP_COMLILER g++)


set(SRC main.cpp source/graphic/draw.cpp source/logic/field.cpp)

add_executable(${PROJECT_NAME} ${SRC})
