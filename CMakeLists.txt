cmake_minimum_required (VERSION 2.6)
project(EPT_RayTrace)

# check for in-source build, forbid it!
if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR AND NOT MSVC_IDE)
  message(FATAL_ERROR "\nIn-source build attempt detected!\n"
    "Please create a new directory (e.g. build) and run `cmake ..`.\n"
    "Also don't forget to delete the created CMakeCache.txt and CMakeFiles dir"
    )
endif()
    
include(cmake/settings.cmake)
include(cmake/doxygen.cmake)

message(STATUS "*** Build Type:      " ${CMAKE_BUILD_TYPE})
message(STATUS "*** Compiler Flags:  " ${DEFAULT_COMPILE_FLAGS})
message(STATUS "*** Install libs to: " ${LIBRARY_OUTPUT_PATH})
message(STATUS "*** Install bin to:  " ${EXECUTABLE_OUTPUT_PATH})

# require a fairly recent ROOT version
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(ROOT "5.30" REQUIRED)

# since all subprojects need ROOT, set that up here
include_directories(${ROOT_INCLUDES})
link_directories(${ROOT_LIBRARY_DIR})

include_directories(inc)
set(ROOT_LIBRARIES "${ROOT_LIBRARIES} -lEG")
message(${ROOT_LIBRARIES})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")


add_executable(EPT_RayTrace
    inc/RTFieldMap.h
    src/RTFieldMap.cc
    src/EPT_RayTrace_main.cc
    )
target_link_libraries(EPT_RayTrace ${ROOT_LIBRARIES})

