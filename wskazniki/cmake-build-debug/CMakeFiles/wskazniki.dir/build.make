# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Programy na C++\wskazniki"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Programy na C++\wskazniki\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/wskazniki.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wskazniki.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wskazniki.dir/flags.make

CMakeFiles/wskazniki.dir/main.cpp.obj: CMakeFiles/wskazniki.dir/flags.make
CMakeFiles/wskazniki.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Programy na C++\wskazniki\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wskazniki.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\wskazniki.dir\main.cpp.obj -c "D:\Programy na C++\wskazniki\main.cpp"

CMakeFiles/wskazniki.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wskazniki.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Programy na C++\wskazniki\main.cpp" > CMakeFiles\wskazniki.dir\main.cpp.i

CMakeFiles/wskazniki.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wskazniki.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Programy na C++\wskazniki\main.cpp" -o CMakeFiles\wskazniki.dir\main.cpp.s

# Object files for target wskazniki
wskazniki_OBJECTS = \
"CMakeFiles/wskazniki.dir/main.cpp.obj"

# External object files for target wskazniki
wskazniki_EXTERNAL_OBJECTS =

wskazniki.exe: CMakeFiles/wskazniki.dir/main.cpp.obj
wskazniki.exe: CMakeFiles/wskazniki.dir/build.make
wskazniki.exe: CMakeFiles/wskazniki.dir/linklibs.rsp
wskazniki.exe: CMakeFiles/wskazniki.dir/objects1.rsp
wskazniki.exe: CMakeFiles/wskazniki.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Programy na C++\wskazniki\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wskazniki.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\wskazniki.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wskazniki.dir/build: wskazniki.exe

.PHONY : CMakeFiles/wskazniki.dir/build

CMakeFiles/wskazniki.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\wskazniki.dir\cmake_clean.cmake
.PHONY : CMakeFiles/wskazniki.dir/clean

CMakeFiles/wskazniki.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Programy na C++\wskazniki" "D:\Programy na C++\wskazniki" "D:\Programy na C++\wskazniki\cmake-build-debug" "D:\Programy na C++\wskazniki\cmake-build-debug" "D:\Programy na C++\wskazniki\cmake-build-debug\CMakeFiles\wskazniki.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/wskazniki.dir/depend

