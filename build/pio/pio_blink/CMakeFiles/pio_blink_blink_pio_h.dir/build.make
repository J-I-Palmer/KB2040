# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/vboxuser/pico/pico-examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vboxuser/pico/pico-examples/build

# Utility rule file for pio_blink_blink_pio_h.

# Include any custom commands dependencies for this target.
include pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/compiler_depend.make

# Include the progress variables for this target.
include pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/progress.make

pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h: pio/pio_blink/blink.pio.h

pio/pio_blink/blink.pio.h: /home/vboxuser/pico/pico-examples/pio/pio_blink/blink.pio
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vboxuser/pico/pico-examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating blink.pio.h"
	cd /home/vboxuser/pico/pico-examples/build/pio/pio_blink && ../../pioasm/pioasm -o c-sdk /home/vboxuser/pico/pico-examples/pio/pio_blink/blink.pio /home/vboxuser/pico/pico-examples/build/pio/pio_blink/blink.pio.h

pio_blink_blink_pio_h: pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h
pio_blink_blink_pio_h: pio/pio_blink/blink.pio.h
pio_blink_blink_pio_h: pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/build.make
.PHONY : pio_blink_blink_pio_h

# Rule to build all files generated by this target.
pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/build: pio_blink_blink_pio_h
.PHONY : pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/build

pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/clean:
	cd /home/vboxuser/pico/pico-examples/build/pio/pio_blink && $(CMAKE_COMMAND) -P CMakeFiles/pio_blink_blink_pio_h.dir/cmake_clean.cmake
.PHONY : pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/clean

pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/depend:
	cd /home/vboxuser/pico/pico-examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vboxuser/pico/pico-examples /home/vboxuser/pico/pico-examples/pio/pio_blink /home/vboxuser/pico/pico-examples/build /home/vboxuser/pico/pico-examples/build/pio/pio_blink /home/vboxuser/pico/pico-examples/build/pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pio/pio_blink/CMakeFiles/pio_blink_blink_pio_h.dir/depend

