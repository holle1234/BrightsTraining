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
CMAKE_SOURCE_DIR = /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/build

# Include any dependencies generated for this target.
include CMakeFiles/lorem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lorem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lorem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lorem.dir/flags.make

CMakeFiles/lorem.dir/main.cpp.o: CMakeFiles/lorem.dir/flags.make
CMakeFiles/lorem.dir/main.cpp.o: ../main.cpp
CMakeFiles/lorem.dir/main.cpp.o: CMakeFiles/lorem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lorem.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lorem.dir/main.cpp.o -MF CMakeFiles/lorem.dir/main.cpp.o.d -o CMakeFiles/lorem.dir/main.cpp.o -c /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/main.cpp

CMakeFiles/lorem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lorem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/main.cpp > CMakeFiles/lorem.dir/main.cpp.i

CMakeFiles/lorem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lorem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/main.cpp -o CMakeFiles/lorem.dir/main.cpp.s

# Object files for target lorem
lorem_OBJECTS = \
"CMakeFiles/lorem.dir/main.cpp.o"

# External object files for target lorem
lorem_EXTERNAL_OBJECTS =

lorem: CMakeFiles/lorem.dir/main.cpp.o
lorem: CMakeFiles/lorem.dir/build.make
lorem: CMakeFiles/lorem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lorem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lorem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lorem.dir/build: lorem
.PHONY : CMakeFiles/lorem.dir/build

CMakeFiles/lorem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lorem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lorem.dir/clean

CMakeFiles/lorem.dir/depend:
	cd /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1 /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1 /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/build /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/build /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-4-1/build/CMakeFiles/lorem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lorem.dir/depend

