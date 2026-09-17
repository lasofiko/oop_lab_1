# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-src")
  file(MAKE_DIRECTORY "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-src")
endif()
file(MAKE_DIRECTORY
  "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-build"
  "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/OOP/laba_1/oop_lab_1/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
