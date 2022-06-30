project(CLines)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -g -lstdc++fs")
set(CMAKE_CPP_COMLILER g++)

file(GLOB SRC "source/*.cpp")
file(GLOB HDR "source/headers/*.h")

find_package(SDL2)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC} ${HDR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

link_libraries(stdc++fs)
