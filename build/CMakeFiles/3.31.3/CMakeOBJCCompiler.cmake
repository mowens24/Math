set(CMAKE_OBJC_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_OBJC_COMPILER_ARG1 "")
set(CMAKE_OBJC_COMPILER_ID "Clang")
set(CMAKE_OBJC_COMPILER_VERSION "19.1.6")
set(CMAKE_OBJC_COMPILER_VERSION_INTERNAL "")
set(CMAKE_OBJC_COMPILER_WRAPPER "")
set(CMAKE_OBJC_STANDARD_COMPUTED_DEFAULT "11")
set(CMAKE_OBJC_EXTENSIONS_COMPUTED_DEFAULT "ON")
set(CMAKE_OBJC_STANDARD_LATEST "23")
set(CMAKE_OBJC_COMPILE_FEATURES "")
set(CMAKE_OBJC90_COMPILE_FEATURES "")
set(CMAKE_OBJC99_COMPILE_FEATURES "")
set(CMAKE_OBJC11_COMPILE_FEATURES "")
set(CMAKE_OBJC17_COMPILE_FEATURES "")
set(CMAKE_OBJC23_COMPILE_FEATURES "")

set(CMAKE_OBJC_PLATFORM_ID "Darwin")
set(CMAKE_OBJC_SIMULATE_ID "")
set(CMAKE_OBJC_COMPILER_FRONTEND_VARIANT "GNU")
set(CMAKE_OBJC_SIMULATE_VERSION "")


set(CMAKE_AR "/usr/bin/ar")
set(CMAKE_OBJC_COMPILER_AR "/opt/homebrew/Cellar/llvm/19.1.6/bin/llvm-ar")
set(CMAKE_RANLIB "/opt/homebrew/opt/llvm/bin/llvm-ranlib")
set(CMAKE_OBJC_COMPILER_RANLIB "/opt/homebrew/Cellar/llvm/19.1.6/bin/llvm-ranlib")
set(CMAKE_LINKER "/usr/bin/ld")
set(CMAKE_LINKER_LINK "")
set(CMAKE_LINKER_LLD "")
set(CMAKE_OBJC_COMPILER_LINKER "/usr/bin/ld")
set(CMAKE_OBJC_COMPILER_LINKER_ID "AppleClang")
set(CMAKE_OBJC_COMPILER_LINKER_VERSION 1053.12)
set(CMAKE_OBJC_COMPILER_LINKER_FRONTEND_VARIANT GNU)
set(CMAKE_MT "")
set(CMAKE_TAPI "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/tapi")
set(CMAKE_COMPILER_IS_GNUOBJC )
set(CMAKE_OBJC_COMPILER_LOADED 1)
set(CMAKE_OBJC_COMPILER_WORKS TRUE)
set(CMAKE_OBJC_ABI_COMPILED TRUE)

set(CMAKE_OBJC_COMPILER_ENV_VAR "OBJC")

set(CMAKE_OBJC_COMPILER_ID_RUN 1)
set(CMAKE_OBJC_SOURCE_FILE_EXTENSIONS m)
set(CMAKE_OBJC_IGNORE_EXTENSIONS h;H;o;O)
set(CMAKE_OBJC_LINKER_PREFERENCE 5)
set(CMAKE_OBJC_LINKER_DEPFILE_SUPPORTED )

foreach (lang C CXX OBJCXX)
  foreach(extension IN LISTS CMAKE_OBJC_SOURCE_FILE_EXTENSIONS)
    if (CMAKE_${lang}_COMPILER_ID_RUN)
      list(REMOVE_ITEM CMAKE_${lang}_SOURCE_FILE_EXTENSIONS ${extension})
    endif()
  endforeach()
endforeach()

# Save compiler ABI information.
set(CMAKE_OBJC_SIZEOF_DATA_PTR "8")
set(CMAKE_OBJC_COMPILER_ABI "")
set(CMAKE_OBJC_BYTE_ORDER "LITTLE_ENDIAN")
set(CMAKE_OBJC_LIBRARY_ARCHITECTURE "")

if(CMAKE_OBJC_SIZEOF_DATA_PTR)
  set(CMAKE_SIZEOF_VOID_P "${CMAKE_OBJC_SIZEOF_DATA_PTR}")
endif()

if(CMAKE_OBJC_COMPILER_ABI)
  set(CMAKE_INTERNAL_PLATFORM_ABI "${CMAKE_OBJC_COMPILER_ABI}")
endif()

if(CMAKE_OBJC_LIBRARY_ARCHITECTURE)
  set(CMAKE_LIBRARY_ARCHITECTURE "")
endif()





set(CMAKE_OBJC_IMPLICIT_INCLUDE_DIRECTORIES "/opt/homebrew/Cellar/llvm/19.1.6/lib/clang/19/include;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/usr/include")
set(CMAKE_OBJC_IMPLICIT_LINK_LIBRARIES "")
set(CMAKE_OBJC_IMPLICIT_LINK_DIRECTORIES "/opt/homebrew/opt/llvm/lib;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/usr/lib;/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/usr/lib/swift")
set(CMAKE_OBJC_IMPLICIT_LINK_FRAMEWORK_DIRECTORIES "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX14.5.sdk/System/Library/Frameworks")
