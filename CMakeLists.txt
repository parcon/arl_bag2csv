cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()


rosbuild_add_boost_directories()
rosbuild_add_executable(rosbag_to_csv src/make_csv.cpp)
rosbuild_link_boost(rosbag_to_csv system)
 
#rosbuild_add_executable(roa_to_csv src/make_csv_roa.cpp)
#rosbuild_link_boost(roa_to_csv system)
 
rosbuild_add_executable(make_bag src/make_bag.cpp)
rosbuild_link_boost(make_bag system)

#rosbuild_add_executable(roa_make_bag src/make_bag_roa.cpp)
#rosbuild_link_boost(roa_make_bag system)

rosbuild_add_executable(csv_listener src/csv_listener.cpp)


#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})
