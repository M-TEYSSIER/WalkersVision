# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/riesjack/Documents/stage/WalkersVision/test/camera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/riesjack/Documents/stage/WalkersVision/test/camera

# Include any dependencies generated for this target.
include CMakeFiles/test2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test2.dir/flags.make

CMakeFiles/test2.dir/test2.cpp.o: CMakeFiles/test2.dir/flags.make
CMakeFiles/test2.dir/test2.cpp.o: test2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/riesjack/Documents/stage/WalkersVision/test/camera/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test2.dir/test2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/test2.cpp.o -c /home/riesjack/Documents/stage/WalkersVision/test/camera/test2.cpp

CMakeFiles/test2.dir/test2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/test2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/riesjack/Documents/stage/WalkersVision/test/camera/test2.cpp > CMakeFiles/test2.dir/test2.cpp.i

CMakeFiles/test2.dir/test2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/test2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/riesjack/Documents/stage/WalkersVision/test/camera/test2.cpp -o CMakeFiles/test2.dir/test2.cpp.s

CMakeFiles/test2.dir/test2.cpp.o.requires:

.PHONY : CMakeFiles/test2.dir/test2.cpp.o.requires

CMakeFiles/test2.dir/test2.cpp.o.provides: CMakeFiles/test2.dir/test2.cpp.o.requires
	$(MAKE) -f CMakeFiles/test2.dir/build.make CMakeFiles/test2.dir/test2.cpp.o.provides.build
.PHONY : CMakeFiles/test2.dir/test2.cpp.o.provides

CMakeFiles/test2.dir/test2.cpp.o.provides.build: CMakeFiles/test2.dir/test2.cpp.o


# Object files for target test2
test2_OBJECTS = \
"CMakeFiles/test2.dir/test2.cpp.o"

# External object files for target test2
test2_EXTERNAL_OBJECTS =

test2: CMakeFiles/test2.dir/test2.cpp.o
test2: CMakeFiles/test2.dir/build.make
test2: /usr/local/lib/libopencv_dnn.so.4.1.0
test2: /usr/local/lib/libopencv_gapi.so.4.1.0
test2: /usr/local/lib/libopencv_highgui.so.4.1.0
test2: /usr/local/lib/libopencv_ml.so.4.1.0
test2: /usr/local/lib/libopencv_objdetect.so.4.1.0
test2: /usr/local/lib/libopencv_photo.so.4.1.0
test2: /usr/local/lib/libopencv_stitching.so.4.1.0
test2: /usr/local/lib/libopencv_video.so.4.1.0
test2: /usr/local/lib/libopencv_videoio.so.4.1.0
test2: /usr/local/lib/libopencv_imgcodecs.so.4.1.0
test2: /usr/local/lib/libopencv_calib3d.so.4.1.0
test2: /usr/local/lib/libopencv_features2d.so.4.1.0
test2: /usr/local/lib/libopencv_flann.so.4.1.0
test2: /usr/local/lib/libopencv_imgproc.so.4.1.0
test2: /usr/local/lib/libopencv_core.so.4.1.0
test2: CMakeFiles/test2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/riesjack/Documents/stage/WalkersVision/test/camera/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test2.dir/build: test2

.PHONY : CMakeFiles/test2.dir/build

CMakeFiles/test2.dir/requires: CMakeFiles/test2.dir/test2.cpp.o.requires

.PHONY : CMakeFiles/test2.dir/requires

CMakeFiles/test2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test2.dir/clean

CMakeFiles/test2.dir/depend:
	cd /home/riesjack/Documents/stage/WalkersVision/test/camera && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/riesjack/Documents/stage/WalkersVision/test/camera /home/riesjack/Documents/stage/WalkersVision/test/camera /home/riesjack/Documents/stage/WalkersVision/test/camera /home/riesjack/Documents/stage/WalkersVision/test/camera /home/riesjack/Documents/stage/WalkersVision/test/camera/CMakeFiles/test2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test2.dir/depend

