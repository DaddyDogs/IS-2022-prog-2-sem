# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\labs sem2\6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\labs sem2\6\cmake-build-debug"

# Include any dependencies generated for this target.
include lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/depend.make
# Include the progress variables for this target.
include lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/flags.make

lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/flags.make
lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/includes_CXX.rsp
lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj: ../lib/googletest-main/googletest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\labs sem2\6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"
	cd /d C:\LABSSE~1\6\CMAKE-~1\lib\GOOGLE~1\GOOGLE~2 && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest_main.dir\src\gtest_main.cc.obj -c "C:\labs sem2\6\lib\googletest-main\googletest\src\gtest_main.cc"

lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /d C:\LABSSE~1\6\CMAKE-~1\lib\GOOGLE~1\GOOGLE~2 && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\labs sem2\6\lib\googletest-main\googletest\src\gtest_main.cc" > CMakeFiles\gtest_main.dir\src\gtest_main.cc.i

lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /d C:\LABSSE~1\6\CMAKE-~1\lib\GOOGLE~1\GOOGLE~2 && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\labs sem2\6\lib\googletest-main\googletest\src\gtest_main.cc" -o CMakeFiles\gtest_main.dir\src\gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

lib/libgtest_main.a: lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.obj
lib/libgtest_main.a: lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/build.make
lib/libgtest_main.a: lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\labs sem2\6\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\libgtest_main.a"
	cd /d C:\LABSSE~1\6\CMAKE-~1\lib\GOOGLE~1\GOOGLE~2 && $(CMAKE_COMMAND) -P CMakeFiles\gtest_main.dir\cmake_clean_target.cmake
	cd /d C:\LABSSE~1\6\CMAKE-~1\lib\GOOGLE~1\GOOGLE~2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/build: lib/libgtest_main.a
.PHONY : lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/build

lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/clean:
	cd /d C:\LABSSE~1\6\CMAKE-~1\lib\GOOGLE~1\GOOGLE~2 && $(CMAKE_COMMAND) -P CMakeFiles\gtest_main.dir\cmake_clean.cmake
.PHONY : lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/clean

lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\labs sem2\6" "C:\labs sem2\6\lib\googletest-main\googletest" "C:\labs sem2\6\cmake-build-debug" "C:\labs sem2\6\cmake-build-debug\lib\googletest-main\googletest" "C:\labs sem2\6\cmake-build-debug\lib\googletest-main\googletest\CMakeFiles\gtest_main.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/googletest-main/googletest/CMakeFiles/gtest_main.dir/depend

