# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/steelbar_cut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/steelbar_cut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/steelbar_cut.dir/flags.make

CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.o: CMakeFiles/steelbar_cut.dir/flags.make
CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.o: ../exercise/steelbar_cut.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.o -c /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/exercise/steelbar_cut.cpp

CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/exercise/steelbar_cut.cpp > CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.i

CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/exercise/steelbar_cut.cpp -o CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.s

# Object files for target steelbar_cut
steelbar_cut_OBJECTS = \
"CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.o"

# External object files for target steelbar_cut
steelbar_cut_EXTERNAL_OBJECTS =

../bin/steelbar_cut: CMakeFiles/steelbar_cut.dir/exercise/steelbar_cut.cpp.o
../bin/steelbar_cut: CMakeFiles/steelbar_cut.dir/build.make
../bin/steelbar_cut: CMakeFiles/steelbar_cut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/steelbar_cut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/steelbar_cut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/steelbar_cut.dir/build: ../bin/steelbar_cut

.PHONY : CMakeFiles/steelbar_cut.dir/build

CMakeFiles/steelbar_cut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/steelbar_cut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/steelbar_cut.dir/clean

CMakeFiles/steelbar_cut.dir/depend:
	cd /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/build /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/build /home/kk/SynologyDrive/bigProject/algorithmStudy_cpp/build/CMakeFiles/steelbar_cut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/steelbar_cut.dir/depend
