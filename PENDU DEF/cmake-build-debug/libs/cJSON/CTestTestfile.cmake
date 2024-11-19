# CMake generated Testfile for 
# Source directory: C:/Users/BASTIEN/CLionProjects/PENDU/libs/cJSON
# Build directory: C:/Users/BASTIEN/CLionProjects/PENDU/cmake-build-debug/libs/cJSON
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cJSON_test "C:/Users/BASTIEN/CLionProjects/PENDU/cmake-build-debug/libs/cJSON/cJSON_test")
set_tests_properties(cJSON_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/BASTIEN/CLionProjects/PENDU/libs/cJSON/CMakeLists.txt;248;add_test;C:/Users/BASTIEN/CLionProjects/PENDU/libs/cJSON/CMakeLists.txt;0;")
subdirs("tests")
subdirs("fuzzing")
