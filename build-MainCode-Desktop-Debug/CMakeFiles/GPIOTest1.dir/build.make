# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mads/semesterProjekt/GripperGit/GPIOTest1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/GPIOTest1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GPIOTest1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GPIOTest1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GPIOTest1.dir/flags.make

CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.o: CMakeFiles/GPIOTest1.dir/flags.make
CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.o: GPIOTest1_autogen/mocs_compilation.cpp
CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.o: CMakeFiles/GPIOTest1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.o -MF CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.o -c /home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug/GPIOTest1_autogen/mocs_compilation.cpp

CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug/GPIOTest1_autogen/mocs_compilation.cpp > CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.i

CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug/GPIOTest1_autogen/mocs_compilation.cpp -o CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.s

CMakeFiles/GPIOTest1.dir/main.cpp.o: CMakeFiles/GPIOTest1.dir/flags.make
CMakeFiles/GPIOTest1.dir/main.cpp.o: /home/mads/semesterProjekt/GripperGit/GPIOTest1/main.cpp
CMakeFiles/GPIOTest1.dir/main.cpp.o: CMakeFiles/GPIOTest1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GPIOTest1.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPIOTest1.dir/main.cpp.o -MF CMakeFiles/GPIOTest1.dir/main.cpp.o.d -o CMakeFiles/GPIOTest1.dir/main.cpp.o -c /home/mads/semesterProjekt/GripperGit/GPIOTest1/main.cpp

CMakeFiles/GPIOTest1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GPIOTest1.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mads/semesterProjekt/GripperGit/GPIOTest1/main.cpp > CMakeFiles/GPIOTest1.dir/main.cpp.i

CMakeFiles/GPIOTest1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GPIOTest1.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mads/semesterProjekt/GripperGit/GPIOTest1/main.cpp -o CMakeFiles/GPIOTest1.dir/main.cpp.s

CMakeFiles/GPIOTest1.dir/DCMotor.cpp.o: CMakeFiles/GPIOTest1.dir/flags.make
CMakeFiles/GPIOTest1.dir/DCMotor.cpp.o: /home/mads/semesterProjekt/GripperGit/GPIOTest1/DCMotor.cpp
CMakeFiles/GPIOTest1.dir/DCMotor.cpp.o: CMakeFiles/GPIOTest1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GPIOTest1.dir/DCMotor.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GPIOTest1.dir/DCMotor.cpp.o -MF CMakeFiles/GPIOTest1.dir/DCMotor.cpp.o.d -o CMakeFiles/GPIOTest1.dir/DCMotor.cpp.o -c /home/mads/semesterProjekt/GripperGit/GPIOTest1/DCMotor.cpp

CMakeFiles/GPIOTest1.dir/DCMotor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GPIOTest1.dir/DCMotor.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mads/semesterProjekt/GripperGit/GPIOTest1/DCMotor.cpp > CMakeFiles/GPIOTest1.dir/DCMotor.cpp.i

CMakeFiles/GPIOTest1.dir/DCMotor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GPIOTest1.dir/DCMotor.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mads/semesterProjekt/GripperGit/GPIOTest1/DCMotor.cpp -o CMakeFiles/GPIOTest1.dir/DCMotor.cpp.s

# Object files for target GPIOTest1
GPIOTest1_OBJECTS = \
"CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/GPIOTest1.dir/main.cpp.o" \
"CMakeFiles/GPIOTest1.dir/DCMotor.cpp.o"

# External object files for target GPIOTest1
GPIOTest1_EXTERNAL_OBJECTS =

GPIOTest1: CMakeFiles/GPIOTest1.dir/GPIOTest1_autogen/mocs_compilation.cpp.o
GPIOTest1: CMakeFiles/GPIOTest1.dir/main.cpp.o
GPIOTest1: CMakeFiles/GPIOTest1.dir/DCMotor.cpp.o
GPIOTest1: CMakeFiles/GPIOTest1.dir/build.make
GPIOTest1: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
GPIOTest1: CMakeFiles/GPIOTest1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable GPIOTest1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GPIOTest1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GPIOTest1.dir/build: GPIOTest1
.PHONY : CMakeFiles/GPIOTest1.dir/build

CMakeFiles/GPIOTest1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GPIOTest1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GPIOTest1.dir/clean

CMakeFiles/GPIOTest1.dir/depend:
	cd /home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mads/semesterProjekt/GripperGit/GPIOTest1 /home/mads/semesterProjekt/GripperGit/GPIOTest1 /home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug /home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug /home/mads/semesterProjekt/GripperGit/build-MainCode-Desktop-Debug/CMakeFiles/GPIOTest1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GPIOTest1.dir/depend

