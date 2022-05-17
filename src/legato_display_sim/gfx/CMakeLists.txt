file(GLOB_RECURSE SOURCES ./*.c)
add_library(legato STATIC ${SOURCES})
add_library(driver STATIC ${SOURCES})