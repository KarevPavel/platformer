# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/yacopsae/CLionProjects/platformer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yacopsae/CLionProjects/platformer/build

# Include any dependencies generated for this target.
include src/core/models/CMakeFiles/models.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/core/models/CMakeFiles/models.dir/compiler_depend.make

# Include the progress variables for this target.
include src/core/models/CMakeFiles/models.dir/progress.make

# Include the compile flags for this target's objects.
include src/core/models/CMakeFiles/models.dir/flags.make

src/core/models/CMakeFiles/models.dir/general.cpp.o: src/core/models/CMakeFiles/models.dir/flags.make
src/core/models/CMakeFiles/models.dir/general.cpp.o: ../src/core/models/general.cpp
src/core/models/CMakeFiles/models.dir/general.cpp.o: src/core/models/CMakeFiles/models.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yacopsae/CLionProjects/platformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/core/models/CMakeFiles/models.dir/general.cpp.o"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/core/models/CMakeFiles/models.dir/general.cpp.o -MF CMakeFiles/models.dir/general.cpp.o.d -o CMakeFiles/models.dir/general.cpp.o -c /home/yacopsae/CLionProjects/platformer/src/core/models/general.cpp

src/core/models/CMakeFiles/models.dir/general.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/models.dir/general.cpp.i"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yacopsae/CLionProjects/platformer/src/core/models/general.cpp > CMakeFiles/models.dir/general.cpp.i

src/core/models/CMakeFiles/models.dir/general.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/models.dir/general.cpp.s"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yacopsae/CLionProjects/platformer/src/core/models/general.cpp -o CMakeFiles/models.dir/general.cpp.s

src/core/models/CMakeFiles/models.dir/player_model.cpp.o: src/core/models/CMakeFiles/models.dir/flags.make
src/core/models/CMakeFiles/models.dir/player_model.cpp.o: ../src/core/models/player_model.cpp
src/core/models/CMakeFiles/models.dir/player_model.cpp.o: src/core/models/CMakeFiles/models.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yacopsae/CLionProjects/platformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/core/models/CMakeFiles/models.dir/player_model.cpp.o"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/core/models/CMakeFiles/models.dir/player_model.cpp.o -MF CMakeFiles/models.dir/player_model.cpp.o.d -o CMakeFiles/models.dir/player_model.cpp.o -c /home/yacopsae/CLionProjects/platformer/src/core/models/player_model.cpp

src/core/models/CMakeFiles/models.dir/player_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/models.dir/player_model.cpp.i"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yacopsae/CLionProjects/platformer/src/core/models/player_model.cpp > CMakeFiles/models.dir/player_model.cpp.i

src/core/models/CMakeFiles/models.dir/player_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/models.dir/player_model.cpp.s"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yacopsae/CLionProjects/platformer/src/core/models/player_model.cpp -o CMakeFiles/models.dir/player_model.cpp.s

src/core/models/CMakeFiles/models.dir/player.cpp.o: src/core/models/CMakeFiles/models.dir/flags.make
src/core/models/CMakeFiles/models.dir/player.cpp.o: ../src/core/models/player.cpp
src/core/models/CMakeFiles/models.dir/player.cpp.o: src/core/models/CMakeFiles/models.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yacopsae/CLionProjects/platformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/core/models/CMakeFiles/models.dir/player.cpp.o"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/core/models/CMakeFiles/models.dir/player.cpp.o -MF CMakeFiles/models.dir/player.cpp.o.d -o CMakeFiles/models.dir/player.cpp.o -c /home/yacopsae/CLionProjects/platformer/src/core/models/player.cpp

src/core/models/CMakeFiles/models.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/models.dir/player.cpp.i"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yacopsae/CLionProjects/platformer/src/core/models/player.cpp > CMakeFiles/models.dir/player.cpp.i

src/core/models/CMakeFiles/models.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/models.dir/player.cpp.s"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yacopsae/CLionProjects/platformer/src/core/models/player.cpp -o CMakeFiles/models.dir/player.cpp.s

src/core/models/CMakeFiles/models.dir/ball.cpp.o: src/core/models/CMakeFiles/models.dir/flags.make
src/core/models/CMakeFiles/models.dir/ball.cpp.o: ../src/core/models/ball.cpp
src/core/models/CMakeFiles/models.dir/ball.cpp.o: src/core/models/CMakeFiles/models.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yacopsae/CLionProjects/platformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/core/models/CMakeFiles/models.dir/ball.cpp.o"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/core/models/CMakeFiles/models.dir/ball.cpp.o -MF CMakeFiles/models.dir/ball.cpp.o.d -o CMakeFiles/models.dir/ball.cpp.o -c /home/yacopsae/CLionProjects/platformer/src/core/models/ball.cpp

src/core/models/CMakeFiles/models.dir/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/models.dir/ball.cpp.i"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yacopsae/CLionProjects/platformer/src/core/models/ball.cpp > CMakeFiles/models.dir/ball.cpp.i

src/core/models/CMakeFiles/models.dir/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/models.dir/ball.cpp.s"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yacopsae/CLionProjects/platformer/src/core/models/ball.cpp -o CMakeFiles/models.dir/ball.cpp.s

src/core/models/CMakeFiles/models.dir/point_of_view.cpp.o: src/core/models/CMakeFiles/models.dir/flags.make
src/core/models/CMakeFiles/models.dir/point_of_view.cpp.o: ../src/core/models/point_of_view.cpp
src/core/models/CMakeFiles/models.dir/point_of_view.cpp.o: src/core/models/CMakeFiles/models.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yacopsae/CLionProjects/platformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/core/models/CMakeFiles/models.dir/point_of_view.cpp.o"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/core/models/CMakeFiles/models.dir/point_of_view.cpp.o -MF CMakeFiles/models.dir/point_of_view.cpp.o.d -o CMakeFiles/models.dir/point_of_view.cpp.o -c /home/yacopsae/CLionProjects/platformer/src/core/models/point_of_view.cpp

src/core/models/CMakeFiles/models.dir/point_of_view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/models.dir/point_of_view.cpp.i"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yacopsae/CLionProjects/platformer/src/core/models/point_of_view.cpp > CMakeFiles/models.dir/point_of_view.cpp.i

src/core/models/CMakeFiles/models.dir/point_of_view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/models.dir/point_of_view.cpp.s"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yacopsae/CLionProjects/platformer/src/core/models/point_of_view.cpp -o CMakeFiles/models.dir/point_of_view.cpp.s

src/core/models/CMakeFiles/models.dir/vector.cpp.o: src/core/models/CMakeFiles/models.dir/flags.make
src/core/models/CMakeFiles/models.dir/vector.cpp.o: ../src/core/models/vector.cpp
src/core/models/CMakeFiles/models.dir/vector.cpp.o: src/core/models/CMakeFiles/models.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yacopsae/CLionProjects/platformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/core/models/CMakeFiles/models.dir/vector.cpp.o"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/core/models/CMakeFiles/models.dir/vector.cpp.o -MF CMakeFiles/models.dir/vector.cpp.o.d -o CMakeFiles/models.dir/vector.cpp.o -c /home/yacopsae/CLionProjects/platformer/src/core/models/vector.cpp

src/core/models/CMakeFiles/models.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/models.dir/vector.cpp.i"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yacopsae/CLionProjects/platformer/src/core/models/vector.cpp > CMakeFiles/models.dir/vector.cpp.i

src/core/models/CMakeFiles/models.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/models.dir/vector.cpp.s"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yacopsae/CLionProjects/platformer/src/core/models/vector.cpp -o CMakeFiles/models.dir/vector.cpp.s

# Object files for target models
models_OBJECTS = \
"CMakeFiles/models.dir/general.cpp.o" \
"CMakeFiles/models.dir/player_model.cpp.o" \
"CMakeFiles/models.dir/player.cpp.o" \
"CMakeFiles/models.dir/ball.cpp.o" \
"CMakeFiles/models.dir/point_of_view.cpp.o" \
"CMakeFiles/models.dir/vector.cpp.o"

# External object files for target models
models_EXTERNAL_OBJECTS =

src/core/models/models: src/core/models/CMakeFiles/models.dir/general.cpp.o
src/core/models/models: src/core/models/CMakeFiles/models.dir/player_model.cpp.o
src/core/models/models: src/core/models/CMakeFiles/models.dir/player.cpp.o
src/core/models/models: src/core/models/CMakeFiles/models.dir/ball.cpp.o
src/core/models/models: src/core/models/CMakeFiles/models.dir/point_of_view.cpp.o
src/core/models/models: src/core/models/CMakeFiles/models.dir/vector.cpp.o
src/core/models/models: src/core/models/CMakeFiles/models.dir/build.make
src/core/models/models: src/core/models/CMakeFiles/models.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yacopsae/CLionProjects/platformer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable models"
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/models.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/core/models/CMakeFiles/models.dir/build: src/core/models/models
.PHONY : src/core/models/CMakeFiles/models.dir/build

src/core/models/CMakeFiles/models.dir/clean:
	cd /home/yacopsae/CLionProjects/platformer/build/src/core/models && $(CMAKE_COMMAND) -P CMakeFiles/models.dir/cmake_clean.cmake
.PHONY : src/core/models/CMakeFiles/models.dir/clean

src/core/models/CMakeFiles/models.dir/depend:
	cd /home/yacopsae/CLionProjects/platformer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yacopsae/CLionProjects/platformer /home/yacopsae/CLionProjects/platformer/src/core/models /home/yacopsae/CLionProjects/platformer/build /home/yacopsae/CLionProjects/platformer/build/src/core/models /home/yacopsae/CLionProjects/platformer/build/src/core/models/CMakeFiles/models.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/core/models/CMakeFiles/models.dir/depend

