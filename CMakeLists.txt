project(CLines)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -g -lstdc++fs")
set(CMAKE_CPP_COMLILER g++)


set(SRC main.cpp source/graphic/gui.cpp source/logic/field.cpp)
find_package(SDL2)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories("headers/")

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
