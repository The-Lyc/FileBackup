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
CMAKE_SOURCE_DIR = /home/lyc/cpp_ws/file_backup/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lyc/cpp_ws/file_backup/test/build

# Include any dependencies generated for this target.
include CMakeFiles/cpt.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cpt.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cpt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpt.dir/flags.make

CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.o: CMakeFiles/cpt.dir/flags.make
CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.o: /home/lyc/cpp_ws/file_backup/src/copy.cpp
CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.o: CMakeFiles/cpt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyc/cpp_ws/file_backup/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.o -MF CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.o.d -o CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.o -c /home/lyc/cpp_ws/file_backup/src/copy.cpp

CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyc/cpp_ws/file_backup/src/copy.cpp > CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.i

CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyc/cpp_ws/file_backup/src/copy.cpp -o CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.s

CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.o: CMakeFiles/cpt.dir/flags.make
CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.o: /home/lyc/cpp_ws/file_backup/src/crypto.cpp
CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.o: CMakeFiles/cpt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyc/cpp_ws/file_backup/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.o -MF CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.o.d -o CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.o -c /home/lyc/cpp_ws/file_backup/src/crypto.cpp

CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyc/cpp_ws/file_backup/src/crypto.cpp > CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.i

CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyc/cpp_ws/file_backup/src/crypto.cpp -o CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.s

CMakeFiles/cpt.dir/crypto_test.cpp.o: CMakeFiles/cpt.dir/flags.make
CMakeFiles/cpt.dir/crypto_test.cpp.o: ../crypto_test.cpp
CMakeFiles/cpt.dir/crypto_test.cpp.o: CMakeFiles/cpt.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lyc/cpp_ws/file_backup/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cpt.dir/crypto_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpt.dir/crypto_test.cpp.o -MF CMakeFiles/cpt.dir/crypto_test.cpp.o.d -o CMakeFiles/cpt.dir/crypto_test.cpp.o -c /home/lyc/cpp_ws/file_backup/test/crypto_test.cpp

CMakeFiles/cpt.dir/crypto_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpt.dir/crypto_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lyc/cpp_ws/file_backup/test/crypto_test.cpp > CMakeFiles/cpt.dir/crypto_test.cpp.i

CMakeFiles/cpt.dir/crypto_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpt.dir/crypto_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lyc/cpp_ws/file_backup/test/crypto_test.cpp -o CMakeFiles/cpt.dir/crypto_test.cpp.s

# Object files for target cpt
cpt_OBJECTS = \
"CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.o" \
"CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.o" \
"CMakeFiles/cpt.dir/crypto_test.cpp.o"

# External object files for target cpt
cpt_EXTERNAL_OBJECTS =

cpt: CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/copy.cpp.o
cpt: CMakeFiles/cpt.dir/home/lyc/cpp_ws/file_backup/src/crypto.cpp.o
cpt: CMakeFiles/cpt.dir/crypto_test.cpp.o
cpt: CMakeFiles/cpt.dir/build.make
cpt: CMakeFiles/cpt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lyc/cpp_ws/file_backup/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cpt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpt.dir/build: cpt
.PHONY : CMakeFiles/cpt.dir/build

CMakeFiles/cpt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpt.dir/clean

CMakeFiles/cpt.dir/depend:
	cd /home/lyc/cpp_ws/file_backup/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lyc/cpp_ws/file_backup/test /home/lyc/cpp_ws/file_backup/test /home/lyc/cpp_ws/file_backup/test/build /home/lyc/cpp_ws/file_backup/test/build /home/lyc/cpp_ws/file_backup/test/build/CMakeFiles/cpt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpt.dir/depend

