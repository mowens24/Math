# Install script for directory: /Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser/libmuparser.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmuparser.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmuparser.a")
    execute_process(COMMAND "/opt/homebrew/opt/llvm/bin/llvm-ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmuparser.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParser.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserBase.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserBytecode.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserCallback.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserDLL.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserDef.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserError.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserFixes.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserInt.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserTemplateMagic.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserTest.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserToken.h"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/third_party/muparser/include/muParserTokenReader.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/muparser/muparser-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/muparser/muparser-targets.cmake"
         "/Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser/CMakeFiles/Export/f4bad9bb078ad8062c3d1d8d4dc8f96d/muparser-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/muparser/muparser-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/muparser/muparser-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/muparser" TYPE FILE FILES "/Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser/CMakeFiles/Export/f4bad9bb078ad8062c3d1d8d4dc8f96d/muparser-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/muparser" TYPE FILE FILES "/Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser/CMakeFiles/Export/f4bad9bb078ad8062c3d1d8d4dc8f96d/muparser-targets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/muparser" TYPE FILE FILES
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser/muparserConfig.cmake"
    "/Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser/muparserConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/Users/mwo/Documents/GitHub/C++/Practice/Math/build/muparser.pc")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/mwo/Documents/GitHub/C++/Practice/Math/build/third_party/muparser/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
