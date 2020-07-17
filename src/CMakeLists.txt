# find packages here
find_package (Threads REQUIRED)

# specify source files
# auto select
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

# # alternatively, manual select:
# set(SOURCES
# file1.h
# file1.cpp
# ...
# )

# # include thirdparty headers not provided by find_package
# include_directories(
#  ${EIGEN3_INCLUDE_DIRS}
# ) 

# build executable
#  name executable
set(EXE ${CMAKE_PROJECT_NAME})
#  add source files to executable
add_executable(${EXE} ${SOURCES})
#  link thirdparty libraries
target_link_libraries(${EXE} ${CMAKE_THREAD_LIBS_INIT})

# optional: build static library used by test
#  name library
set(LIB ${CMAKE_PROJECT_NAME}_lib)
#  add source files to library statically
add_library(${LIB} STATIC ${SOURCES})
#  link thirdparty libraries
target_link_libraries(${LIB} ${CMAKE_THREAD_LIBS_INIT})