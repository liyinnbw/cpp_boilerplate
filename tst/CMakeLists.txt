# find packages here
find_package (Threads REQUIRED)

# specify source files
# auto select
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true *.h *.cpp)

# # alternatively, manual select:
# set(TEST_SOURCES
# file1.h
# file1.cpp
# ...
# )

# # include thirdparty headers not provided by find_package
# include_directories(
#  ${EIGEN3_INCLUDE_DIRS}
# ) 

# build executable
#  name executable and lib
set(EXE ${CMAKE_PROJECT_NAME}_tst)
#  add source files to executable
add_executable(${EXE} ${TEST_SOURCES})
#  add executable to test
add_test(NAME ${EXE} COMMAND ${EXE})
#  name src library (same as in src/CMakeLists.txt)
set(LIB ${CMAKE_PROJECT_NAME}_lib)
#  link src library, thirdparty libraries, and test library
target_link_libraries(${EXE} PUBLIC ${LIB} ${CMAKE_THREAD_LIBS_INIT} gtest)

# # incase you have test data that needs to be copied to build folder
# file(COPY testdata DESTINATION ${CMAKE_CURRENT_BINARY_DIR})