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
CMAKE_SOURCE_DIR = /home/nyykki/Scrivania/histos_root

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nyykki/Scrivania/histos_root/build

# Include any dependencies generated for this target.
include CMakeFiles/merge_mll.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/merge_mll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/merge_mll.dir/flags.make

CMakeFiles/merge_mll.dir/src/merge_mll.cpp.o: CMakeFiles/merge_mll.dir/flags.make
CMakeFiles/merge_mll.dir/src/merge_mll.cpp.o: ../src/merge_mll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/merge_mll.dir/src/merge_mll.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/merge_mll.dir/src/merge_mll.cpp.o -c /home/nyykki/Scrivania/histos_root/src/merge_mll.cpp

CMakeFiles/merge_mll.dir/src/merge_mll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/merge_mll.dir/src/merge_mll.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nyykki/Scrivania/histos_root/src/merge_mll.cpp > CMakeFiles/merge_mll.dir/src/merge_mll.cpp.i

CMakeFiles/merge_mll.dir/src/merge_mll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/merge_mll.dir/src/merge_mll.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nyykki/Scrivania/histos_root/src/merge_mll.cpp -o CMakeFiles/merge_mll.dir/src/merge_mll.cpp.s

# Object files for target merge_mll
merge_mll_OBJECTS = \
"CMakeFiles/merge_mll.dir/src/merge_mll.cpp.o"

# External object files for target merge_mll
merge_mll_EXTERNAL_OBJECTS =

merge_mll: CMakeFiles/merge_mll.dir/src/merge_mll.cpp.o
merge_mll: CMakeFiles/merge_mll.dir/build.make
merge_mll: /home/nyykki/root/lib/libCore.so
merge_mll: /home/nyykki/root/lib/libImt.so
merge_mll: /home/nyykki/root/lib/libRIO.so
merge_mll: /home/nyykki/root/lib/libNet.so
merge_mll: /home/nyykki/root/lib/libHist.so
merge_mll: /home/nyykki/root/lib/libGraf.so
merge_mll: /home/nyykki/root/lib/libGraf3d.so
merge_mll: /home/nyykki/root/lib/libGpad.so
merge_mll: /home/nyykki/root/lib/libROOTDataFrame.so
merge_mll: /home/nyykki/root/lib/libTree.so
merge_mll: /home/nyykki/root/lib/libTreePlayer.so
merge_mll: /home/nyykki/root/lib/libRint.so
merge_mll: /home/nyykki/root/lib/libPostscript.so
merge_mll: /home/nyykki/root/lib/libMatrix.so
merge_mll: /home/nyykki/root/lib/libPhysics.so
merge_mll: /home/nyykki/root/lib/libMathCore.so
merge_mll: /home/nyykki/root/lib/libThread.so
merge_mll: /home/nyykki/root/lib/libMultiProc.so
merge_mll: ../libExRootAnalysis.so
merge_mll: CMakeFiles/merge_mll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nyykki/Scrivania/histos_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable merge_mll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/merge_mll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/merge_mll.dir/build: merge_mll

.PHONY : CMakeFiles/merge_mll.dir/build

CMakeFiles/merge_mll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/merge_mll.dir/cmake_clean.cmake
.PHONY : CMakeFiles/merge_mll.dir/clean

CMakeFiles/merge_mll.dir/depend:
	cd /home/nyykki/Scrivania/histos_root/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build /home/nyykki/Scrivania/histos_root/build/CMakeFiles/merge_mll.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/merge_mll.dir/depend
