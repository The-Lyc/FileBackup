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
CMAKE_SOURCE_DIR = /home/lyc/cpp_ws/file_backup

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyc/cpp_ws/file_backup/build

# Include any dependencies generated for this target.
include CMakeFiles/bp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bp.dir/flags.make

CMakeFiles/bp.dir/src/main.cpp.o: CMakeFiles/bp.dir/flags.make
CMakeFiles/bp.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/bp.dir/src/main.cpp.o: CMakeFiles/bp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyc/cpp_ws/file_backup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bp.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bp.dir/src/main.cpp.o -MF CMakeFiles/bp.dir/src/main.cpp.o.d -o CMakeFiles/bp.dir/src/main.cpp.o -c /home/lyc/cpp_ws/file_backup/src/main.cpp

CMakeFiles/bp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bp.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyc/cpp_ws/file_backup/src/main.cpp > CMakeFiles/bp.dir/src/main.cpp.i

CMakeFiles/bp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bp.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyc/cpp_ws/file_backup/src/main.cpp -o CMakeFiles/bp.dir/src/main.cpp.s

CMakeFiles/bp.dir/src/search.cpp.o: CMakeFiles/bp.dir/flags.make
CMakeFiles/bp.dir/src/search.cpp.o: ../src/search.cpp
CMakeFiles/bp.dir/src/search.cpp.o: CMakeFiles/bp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyc/cpp_ws/file_backup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bp.dir/src/search.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bp.dir/src/search.cpp.o -MF CMakeFiles/bp.dir/src/search.cpp.o.d -o CMakeFiles/bp.dir/src/search.cpp.o -c /home/lyc/cpp_ws/file_backup/src/search.cpp

CMakeFiles/bp.dir/src/search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bp.dir/src/search.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyc/cpp_ws/file_backup/src/search.cpp > CMakeFiles/bp.dir/src/search.cpp.i

CMakeFiles/bp.dir/src/search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bp.dir/src/search.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyc/cpp_ws/file_backup/src/search.cpp -o CMakeFiles/bp.dir/src/search.cpp.s

# Object files for target bp
bp_OBJECTS = \
"CMakeFiles/bp.dir/src/main.cpp.o" \
"CMakeFiles/bp.dir/src/search.cpp.o"

# External object files for target bp
bp_EXTERNAL_OBJECTS =

../bp: CMakeFiles/bp.dir/src/main.cpp.o
../bp: CMakeFiles/bp.dir/src/search.cpp.o
../bp: CMakeFiles/bp.dir/build.make
../bp: CMakeFiles/bp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyc/cpp_ws/file_backup/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bp.dir/build: ../bp
.PHONY : CMakeFiles/bp.dir/build

CMakeFiles/bp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bp.dir/clean

CMakeFiles/bp.dir/depend:
	cd /home/lyc/cpp_ws/file_backup/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyc/cpp_ws/file_backup /home/lyc/cpp_ws/file_backup /home/lyc/cpp_ws/file_backup/build /home/lyc/cpp_ws/file_backup/build /home/lyc/cpp_ws/file_backup/build/CMakeFiles/bp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bp.dir/depend

