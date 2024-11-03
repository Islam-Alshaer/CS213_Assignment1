# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/FCAI-islam/Level2/Semester-1/OOP/Assignments/Assignment 1/volemachine/CS213_Assignment1/task 4 & 5/cmake-build-debug/_deps/googletest-src"
  "E:/FCAI-islam/Level2/Semester-1/OOP/Assignments/Assignment 1/volemachine/CS213_Assignment1/task 4 & 5/cmake-build-debug/_deps/googletest-build"
  "E:/FCAI-islam/Level2/Semester-1/OOP/Assignments/Assignment 1/volemachine/CS213_Assignment1/task 4 & 5/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "E:/FCAI-islam/Level2/Semester-1/OOP/Assignments/Assignment 1/volemachine/CS213_Assignment1/task 4 & 5/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "E:/FCAI-islam/Level2/Semester-1/OOP/Assignments/Assignment 1/volemachine/CS213_Assignment1/task 4 & 5/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "E:/FCAI-islam/Level2/Semester-1/OOP/Assignments/Assignment 1/volemachine/CS213_Assignment1/task 4 & 5/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "E:/FCAI-islam/Level2/Semester-1/OOP/Assignments/Assignment 1/volemachine/CS213_Assignment1/task 4 & 5/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/FCAI-islam/Level2/Semester-1/OOP/Assignments/Assignment 1/volemachine/CS213_Assignment1/task 4 & 5/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/FCAI-islam/Level2/Semester-1/OOP/Assignments/Assignment 1/volemachine/CS213_Assignment1/task 4 & 5/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
