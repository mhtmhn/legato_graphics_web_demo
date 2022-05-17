cmake_minimum_required(VERSION 3.16.3)
project (legato_display_sim)

include_directories(${PROJECT_SOURCE_DIR})
add_subdirectory(gfx)

file(GLOB MY_SOURCES "./*.c")
set(SOURCES ${MY_SOURCES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -s USE_SDL=2")
add_executable(legato_display_sim ${SOURCES} ${INCLUDES})
set(CMAKE_EXECUTABLE_SUFFIX ".html")

target_link_libraries(legato_display_sim driver legato)
set_target_properties(legato_display_sim PROPERTIES LINK_FLAGS "--shell-file ${PROJECT_SOURCE_DIR}/wrapper.html -s SINGLE_FILE=1")
