# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xianyu/docker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xianyu/docker/build

# Include any dependencies generated for this target.
include CMakeFiles/docker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/docker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/docker.dir/flags.make

CMakeFiles/docker.dir/src/get_command.c.o: CMakeFiles/docker.dir/flags.make
CMakeFiles/docker.dir/src/get_command.c.o: ../src/get_command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xianyu/docker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/docker.dir/src/get_command.c.o"
	/opt/rh/devtoolset-7/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/docker.dir/src/get_command.c.o   -c /home/xianyu/docker/src/get_command.c

CMakeFiles/docker.dir/src/get_command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/docker.dir/src/get_command.c.i"
	/opt/rh/devtoolset-7/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xianyu/docker/src/get_command.c > CMakeFiles/docker.dir/src/get_command.c.i

CMakeFiles/docker.dir/src/get_command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/docker.dir/src/get_command.c.s"
	/opt/rh/devtoolset-7/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xianyu/docker/src/get_command.c -o CMakeFiles/docker.dir/src/get_command.c.s

CMakeFiles/docker.dir/src/main.c.o: CMakeFiles/docker.dir/flags.make
CMakeFiles/docker.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xianyu/docker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/docker.dir/src/main.c.o"
	/opt/rh/devtoolset-7/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/docker.dir/src/main.c.o   -c /home/xianyu/docker/src/main.c

CMakeFiles/docker.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/docker.dir/src/main.c.i"
	/opt/rh/devtoolset-7/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xianyu/docker/src/main.c > CMakeFiles/docker.dir/src/main.c.i

CMakeFiles/docker.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/docker.dir/src/main.c.s"
	/opt/rh/devtoolset-7/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xianyu/docker/src/main.c -o CMakeFiles/docker.dir/src/main.c.s

# Object files for target docker
docker_OBJECTS = \
"CMakeFiles/docker.dir/src/get_command.c.o" \
"CMakeFiles/docker.dir/src/main.c.o"

# External object files for target docker
docker_EXTERNAL_OBJECTS =

docker: CMakeFiles/docker.dir/src/get_command.c.o
docker: CMakeFiles/docker.dir/src/main.c.o
docker: CMakeFiles/docker.dir/build.make
docker: CMakeFiles/docker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xianyu/docker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable docker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/docker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/docker.dir/build: docker

.PHONY : CMakeFiles/docker.dir/build

CMakeFiles/docker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/docker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/docker.dir/clean

CMakeFiles/docker.dir/depend:
	cd /home/xianyu/docker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xianyu/docker /home/xianyu/docker /home/xianyu/docker/build /home/xianyu/docker/build /home/xianyu/docker/build/CMakeFiles/docker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/docker.dir/depend

