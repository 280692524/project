# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/onvif_su

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/onvif_su/build

# Include any dependencies generated for this target.
include CMakeFiles/onvif_su.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/onvif_su.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/onvif_su.dir/flags.make

CMakeFiles/onvif_su.dir/src/dom.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/dom.c.o: ../src/dom.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/onvif_su.dir/src/dom.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/dom.c.o   -c /mnt/onvif_su/src/dom.c

CMakeFiles/onvif_su.dir/src/dom.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/dom.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/dom.c > CMakeFiles/onvif_su.dir/src/dom.c.i

CMakeFiles/onvif_su.dir/src/dom.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/dom.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/dom.c -o CMakeFiles/onvif_su.dir/src/dom.c.s

CMakeFiles/onvif_su.dir/src/mecevp.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/mecevp.c.o: ../src/mecevp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/onvif_su.dir/src/mecevp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/mecevp.c.o   -c /mnt/onvif_su/src/mecevp.c

CMakeFiles/onvif_su.dir/src/mecevp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/mecevp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/mecevp.c > CMakeFiles/onvif_su.dir/src/mecevp.c.i

CMakeFiles/onvif_su.dir/src/mecevp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/mecevp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/mecevp.c -o CMakeFiles/onvif_su.dir/src/mecevp.c.s

CMakeFiles/onvif_su.dir/src/onvif_test.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/onvif_test.c.o: ../src/onvif_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/onvif_su.dir/src/onvif_test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/onvif_test.c.o   -c /mnt/onvif_su/src/onvif_test.c

CMakeFiles/onvif_su.dir/src/onvif_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/onvif_test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/onvif_test.c > CMakeFiles/onvif_su.dir/src/onvif_test.c.i

CMakeFiles/onvif_su.dir/src/onvif_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/onvif_test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/onvif_test.c -o CMakeFiles/onvif_su.dir/src/onvif_test.c.s

CMakeFiles/onvif_su.dir/src/smdevp.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/smdevp.c.o: ../src/smdevp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/onvif_su.dir/src/smdevp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/smdevp.c.o   -c /mnt/onvif_su/src/smdevp.c

CMakeFiles/onvif_su.dir/src/smdevp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/smdevp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/smdevp.c > CMakeFiles/onvif_su.dir/src/smdevp.c.i

CMakeFiles/onvif_su.dir/src/smdevp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/smdevp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/smdevp.c -o CMakeFiles/onvif_su.dir/src/smdevp.c.s

CMakeFiles/onvif_su.dir/src/soapC.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/soapC.c.o: ../src/soapC.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/onvif_su.dir/src/soapC.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/soapC.c.o   -c /mnt/onvif_su/src/soapC.c

CMakeFiles/onvif_su.dir/src/soapC.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/soapC.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/soapC.c > CMakeFiles/onvif_su.dir/src/soapC.c.i

CMakeFiles/onvif_su.dir/src/soapC.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/soapC.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/soapC.c -o CMakeFiles/onvif_su.dir/src/soapC.c.s

CMakeFiles/onvif_su.dir/src/soapClient.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/soapClient.c.o: ../src/soapClient.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/onvif_su.dir/src/soapClient.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/soapClient.c.o   -c /mnt/onvif_su/src/soapClient.c

CMakeFiles/onvif_su.dir/src/soapClient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/soapClient.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/soapClient.c > CMakeFiles/onvif_su.dir/src/soapClient.c.i

CMakeFiles/onvif_su.dir/src/soapClient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/soapClient.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/soapClient.c -o CMakeFiles/onvif_su.dir/src/soapClient.c.s

CMakeFiles/onvif_su.dir/src/stdsoap2.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/stdsoap2.c.o: ../src/stdsoap2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/onvif_su.dir/src/stdsoap2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/stdsoap2.c.o   -c /mnt/onvif_su/src/stdsoap2.c

CMakeFiles/onvif_su.dir/src/stdsoap2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/stdsoap2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/stdsoap2.c > CMakeFiles/onvif_su.dir/src/stdsoap2.c.i

CMakeFiles/onvif_su.dir/src/stdsoap2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/stdsoap2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/stdsoap2.c -o CMakeFiles/onvif_su.dir/src/stdsoap2.c.s

CMakeFiles/onvif_su.dir/src/threads.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/threads.c.o: ../src/threads.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/onvif_su.dir/src/threads.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/threads.c.o   -c /mnt/onvif_su/src/threads.c

CMakeFiles/onvif_su.dir/src/threads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/threads.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/threads.c > CMakeFiles/onvif_su.dir/src/threads.c.i

CMakeFiles/onvif_su.dir/src/threads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/threads.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/threads.c -o CMakeFiles/onvif_su.dir/src/threads.c.s

CMakeFiles/onvif_su.dir/src/wsaapi.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/wsaapi.c.o: ../src/wsaapi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/onvif_su.dir/src/wsaapi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/wsaapi.c.o   -c /mnt/onvif_su/src/wsaapi.c

CMakeFiles/onvif_su.dir/src/wsaapi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/wsaapi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/wsaapi.c > CMakeFiles/onvif_su.dir/src/wsaapi.c.i

CMakeFiles/onvif_su.dir/src/wsaapi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/wsaapi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/wsaapi.c -o CMakeFiles/onvif_su.dir/src/wsaapi.c.s

CMakeFiles/onvif_su.dir/src/wsseapi.c.o: CMakeFiles/onvif_su.dir/flags.make
CMakeFiles/onvif_su.dir/src/wsseapi.c.o: ../src/wsseapi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/onvif_su.dir/src/wsseapi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/onvif_su.dir/src/wsseapi.c.o   -c /mnt/onvif_su/src/wsseapi.c

CMakeFiles/onvif_su.dir/src/wsseapi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/onvif_su.dir/src/wsseapi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/onvif_su/src/wsseapi.c > CMakeFiles/onvif_su.dir/src/wsseapi.c.i

CMakeFiles/onvif_su.dir/src/wsseapi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/onvif_su.dir/src/wsseapi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/onvif_su/src/wsseapi.c -o CMakeFiles/onvif_su.dir/src/wsseapi.c.s

# Object files for target onvif_su
onvif_su_OBJECTS = \
"CMakeFiles/onvif_su.dir/src/dom.c.o" \
"CMakeFiles/onvif_su.dir/src/mecevp.c.o" \
"CMakeFiles/onvif_su.dir/src/onvif_test.c.o" \
"CMakeFiles/onvif_su.dir/src/smdevp.c.o" \
"CMakeFiles/onvif_su.dir/src/soapC.c.o" \
"CMakeFiles/onvif_su.dir/src/soapClient.c.o" \
"CMakeFiles/onvif_su.dir/src/stdsoap2.c.o" \
"CMakeFiles/onvif_su.dir/src/threads.c.o" \
"CMakeFiles/onvif_su.dir/src/wsaapi.c.o" \
"CMakeFiles/onvif_su.dir/src/wsseapi.c.o"

# External object files for target onvif_su
onvif_su_EXTERNAL_OBJECTS =

onvif_su: CMakeFiles/onvif_su.dir/src/dom.c.o
onvif_su: CMakeFiles/onvif_su.dir/src/mecevp.c.o
onvif_su: CMakeFiles/onvif_su.dir/src/onvif_test.c.o
onvif_su: CMakeFiles/onvif_su.dir/src/smdevp.c.o
onvif_su: CMakeFiles/onvif_su.dir/src/soapC.c.o
onvif_su: CMakeFiles/onvif_su.dir/src/soapClient.c.o
onvif_su: CMakeFiles/onvif_su.dir/src/stdsoap2.c.o
onvif_su: CMakeFiles/onvif_su.dir/src/threads.c.o
onvif_su: CMakeFiles/onvif_su.dir/src/wsaapi.c.o
onvif_su: CMakeFiles/onvif_su.dir/src/wsseapi.c.o
onvif_su: CMakeFiles/onvif_su.dir/build.make
onvif_su: CMakeFiles/onvif_su.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/onvif_su/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable onvif_su"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/onvif_su.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/onvif_su.dir/build: onvif_su

.PHONY : CMakeFiles/onvif_su.dir/build

CMakeFiles/onvif_su.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/onvif_su.dir/cmake_clean.cmake
.PHONY : CMakeFiles/onvif_su.dir/clean

CMakeFiles/onvif_su.dir/depend:
	cd /mnt/onvif_su/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/onvif_su /mnt/onvif_su /mnt/onvif_su/build /mnt/onvif_su/build /mnt/onvif_su/build/CMakeFiles/onvif_su.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/onvif_su.dir/depend

