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
CMAKE_SOURCE_DIR = /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1

# Include any dependencies generated for this target.
include CMakeFiles/restorant.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/restorant.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/restorant.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/restorant.dir/flags.make

CMakeFiles/restorant.dir/main.cpp.o: CMakeFiles/restorant.dir/flags.make
CMakeFiles/restorant.dir/main.cpp.o: main.cpp
CMakeFiles/restorant.dir/main.cpp.o: CMakeFiles/restorant.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/restorant.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/restorant.dir/main.cpp.o -MF CMakeFiles/restorant.dir/main.cpp.o.d -o CMakeFiles/restorant.dir/main.cpp.o -c /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1/main.cpp

CMakeFiles/restorant.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/restorant.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1/main.cpp > CMakeFiles/restorant.dir/main.cpp.i

CMakeFiles/restorant.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/restorant.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1/main.cpp -o CMakeFiles/restorant.dir/main.cpp.s

# Object files for target restorant
restorant_OBJECTS = \
"CMakeFiles/restorant.dir/main.cpp.o"

# External object files for target restorant
restorant_EXTERNAL_OBJECTS =

restorant: CMakeFiles/restorant.dir/main.cpp.o
restorant: CMakeFiles/restorant.dir/build.make
restorant: CMakeFiles/restorant.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable restorant"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/restorant.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/restorant.dir/build: restorant
.PHONY : CMakeFiles/restorant.dir/build

CMakeFiles/restorant.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/restorant.dir/cmake_clean.cmake
.PHONY : CMakeFiles/restorant.dir/clean

CMakeFiles/restorant.dir/depend:
	cd /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1/build /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1/build /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1 /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1 /home/juho/Desktop/BrightsRepo/Studies/week_2/ex-2-2-1/CMakeFiles/restorant.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/restorant.dir/depend

