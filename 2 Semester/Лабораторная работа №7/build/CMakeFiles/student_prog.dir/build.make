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
CMAKE_SOURCE_DIR = "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/build"

# Include any dependencies generated for this target.
include CMakeFiles/student_prog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/student_prog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/student_prog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/student_prog.dir/flags.make

CMakeFiles/student_prog.dir/main.c.o: CMakeFiles/student_prog.dir/flags.make
CMakeFiles/student_prog.dir/main.c.o: ../main.c
CMakeFiles/student_prog.dir/main.c.o: CMakeFiles/student_prog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/student_prog.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/student_prog.dir/main.c.o -MF CMakeFiles/student_prog.dir/main.c.o.d -o CMakeFiles/student_prog.dir/main.c.o -c "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/main.c"

CMakeFiles/student_prog.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/student_prog.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/main.c" > CMakeFiles/student_prog.dir/main.c.i

CMakeFiles/student_prog.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/student_prog.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/main.c" -o CMakeFiles/student_prog.dir/main.c.s

# Object files for target student_prog
student_prog_OBJECTS = \
"CMakeFiles/student_prog.dir/main.c.o"

# External object files for target student_prog
student_prog_EXTERNAL_OBJECTS =

student_prog: CMakeFiles/student_prog.dir/main.c.o
student_prog: CMakeFiles/student_prog.dir/build.make
student_prog: libmylog.so
student_prog: CMakeFiles/student_prog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable student_prog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/student_prog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/student_prog.dir/build: student_prog
.PHONY : CMakeFiles/student_prog.dir/build

CMakeFiles/student_prog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/student_prog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/student_prog.dir/clean

CMakeFiles/student_prog.dir/depend:
	cd "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7" "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7" "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/build" "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/build" "/mnt/c/Users/krivo/Программирование 1 курс/2 Семестр/Лабораторная работа №7/build/CMakeFiles/student_prog.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/student_prog.dir/depend

