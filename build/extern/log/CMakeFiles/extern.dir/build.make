# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/jay/Projects/Byte_Geist

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jay/Projects/Byte_Geist/build

# Include any dependencies generated for this target.
include extern/log/CMakeFiles/extern.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include extern/log/CMakeFiles/extern.dir/compiler_depend.make

# Include the progress variables for this target.
include extern/log/CMakeFiles/extern.dir/progress.make

# Include the compile flags for this target's objects.
include extern/log/CMakeFiles/extern.dir/flags.make

extern/log/CMakeFiles/extern.dir/log.c.o: extern/log/CMakeFiles/extern.dir/flags.make
extern/log/CMakeFiles/extern.dir/log.c.o: /home/jay/Projects/Byte_Geist/extern/log/log.c
extern/log/CMakeFiles/extern.dir/log.c.o: extern/log/CMakeFiles/extern.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jay/Projects/Byte_Geist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object extern/log/CMakeFiles/extern.dir/log.c.o"
	cd /home/jay/Projects/Byte_Geist/build/extern/log && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT extern/log/CMakeFiles/extern.dir/log.c.o -MF CMakeFiles/extern.dir/log.c.o.d -o CMakeFiles/extern.dir/log.c.o -c /home/jay/Projects/Byte_Geist/extern/log/log.c

extern/log/CMakeFiles/extern.dir/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/extern.dir/log.c.i"
	cd /home/jay/Projects/Byte_Geist/build/extern/log && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jay/Projects/Byte_Geist/extern/log/log.c > CMakeFiles/extern.dir/log.c.i

extern/log/CMakeFiles/extern.dir/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/extern.dir/log.c.s"
	cd /home/jay/Projects/Byte_Geist/build/extern/log && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jay/Projects/Byte_Geist/extern/log/log.c -o CMakeFiles/extern.dir/log.c.s

# Object files for target extern
extern_OBJECTS = \
"CMakeFiles/extern.dir/log.c.o"

# External object files for target extern
extern_EXTERNAL_OBJECTS =

extern/log/libextern.a: extern/log/CMakeFiles/extern.dir/log.c.o
extern/log/libextern.a: extern/log/CMakeFiles/extern.dir/build.make
extern/log/libextern.a: extern/log/CMakeFiles/extern.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jay/Projects/Byte_Geist/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libextern.a"
	cd /home/jay/Projects/Byte_Geist/build/extern/log && $(CMAKE_COMMAND) -P CMakeFiles/extern.dir/cmake_clean_target.cmake
	cd /home/jay/Projects/Byte_Geist/build/extern/log && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/extern.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/log/CMakeFiles/extern.dir/build: extern/log/libextern.a
.PHONY : extern/log/CMakeFiles/extern.dir/build

extern/log/CMakeFiles/extern.dir/clean:
	cd /home/jay/Projects/Byte_Geist/build/extern/log && $(CMAKE_COMMAND) -P CMakeFiles/extern.dir/cmake_clean.cmake
.PHONY : extern/log/CMakeFiles/extern.dir/clean

extern/log/CMakeFiles/extern.dir/depend:
	cd /home/jay/Projects/Byte_Geist/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jay/Projects/Byte_Geist /home/jay/Projects/Byte_Geist/extern/log /home/jay/Projects/Byte_Geist/build /home/jay/Projects/Byte_Geist/build/extern/log /home/jay/Projects/Byte_Geist/build/extern/log/CMakeFiles/extern.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : extern/log/CMakeFiles/extern.dir/depend

