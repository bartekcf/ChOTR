# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/GAME/ChoTR_1/cmake-build-debug/_deps/fmt-src"
  "E:/GAME/ChoTR_1/cmake-build-debug/_deps/fmt-build"
  "E:/GAME/ChoTR_1/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix"
  "E:/GAME/ChoTR_1/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/tmp"
  "E:/GAME/ChoTR_1/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
  "E:/GAME/ChoTR_1/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src"
  "E:/GAME/ChoTR_1/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/GAME/ChoTR_1/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/GAME/ChoTR_1/cmake-build-debug/_deps/fmt-subbuild/fmt-populate-prefix/src/fmt-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
