# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/build

# Include any dependencies generated for this target.
include CMakeFiles/RationalThinking.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RationalThinking.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RationalThinking.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RationalThinking.dir/flags.make

CMakeFiles/RationalThinking.dir/main.cpp.o: CMakeFiles/RationalThinking.dir/flags.make
CMakeFiles/RationalThinking.dir/main.cpp.o: /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/main.cpp
CMakeFiles/RationalThinking.dir/main.cpp.o: CMakeFiles/RationalThinking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RationalThinking.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RationalThinking.dir/main.cpp.o -MF CMakeFiles/RationalThinking.dir/main.cpp.o.d -o CMakeFiles/RationalThinking.dir/main.cpp.o -c /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/main.cpp

CMakeFiles/RationalThinking.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RationalThinking.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/main.cpp > CMakeFiles/RationalThinking.dir/main.cpp.i

CMakeFiles/RationalThinking.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RationalThinking.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/main.cpp -o CMakeFiles/RationalThinking.dir/main.cpp.s

CMakeFiles/RationalThinking.dir/Integer.cpp.o: CMakeFiles/RationalThinking.dir/flags.make
CMakeFiles/RationalThinking.dir/Integer.cpp.o: /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/Integer.cpp
CMakeFiles/RationalThinking.dir/Integer.cpp.o: CMakeFiles/RationalThinking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RationalThinking.dir/Integer.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RationalThinking.dir/Integer.cpp.o -MF CMakeFiles/RationalThinking.dir/Integer.cpp.o.d -o CMakeFiles/RationalThinking.dir/Integer.cpp.o -c /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/Integer.cpp

CMakeFiles/RationalThinking.dir/Integer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RationalThinking.dir/Integer.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/Integer.cpp > CMakeFiles/RationalThinking.dir/Integer.cpp.i

CMakeFiles/RationalThinking.dir/Integer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RationalThinking.dir/Integer.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/Integer.cpp -o CMakeFiles/RationalThinking.dir/Integer.cpp.s

CMakeFiles/RationalThinking.dir/Rational.cpp.o: CMakeFiles/RationalThinking.dir/flags.make
CMakeFiles/RationalThinking.dir/Rational.cpp.o: /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/Rational.cpp
CMakeFiles/RationalThinking.dir/Rational.cpp.o: CMakeFiles/RationalThinking.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RationalThinking.dir/Rational.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RationalThinking.dir/Rational.cpp.o -MF CMakeFiles/RationalThinking.dir/Rational.cpp.o.d -o CMakeFiles/RationalThinking.dir/Rational.cpp.o -c /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/Rational.cpp

CMakeFiles/RationalThinking.dir/Rational.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RationalThinking.dir/Rational.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/Rational.cpp > CMakeFiles/RationalThinking.dir/Rational.cpp.i

CMakeFiles/RationalThinking.dir/Rational.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RationalThinking.dir/Rational.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/Rational.cpp -o CMakeFiles/RationalThinking.dir/Rational.cpp.s

# Object files for target RationalThinking
RationalThinking_OBJECTS = \
"CMakeFiles/RationalThinking.dir/main.cpp.o" \
"CMakeFiles/RationalThinking.dir/Integer.cpp.o" \
"CMakeFiles/RationalThinking.dir/Rational.cpp.o"

# External object files for target RationalThinking
RationalThinking_EXTERNAL_OBJECTS =

RationalThinking: CMakeFiles/RationalThinking.dir/main.cpp.o
RationalThinking: CMakeFiles/RationalThinking.dir/Integer.cpp.o
RationalThinking: CMakeFiles/RationalThinking.dir/Rational.cpp.o
RationalThinking: CMakeFiles/RationalThinking.dir/build.make
RationalThinking: CMakeFiles/RationalThinking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable RationalThinking"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RationalThinking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RationalThinking.dir/build: RationalThinking
.PHONY : CMakeFiles/RationalThinking.dir/build

CMakeFiles/RationalThinking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RationalThinking.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RationalThinking.dir/clean

CMakeFiles/RationalThinking.dir/depend:
	cd /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/build /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/build /Users/jaylee/University/300-Level/COSC326/COSC326-Rational-Thinking/build/CMakeFiles/RationalThinking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RationalThinking.dir/depend

