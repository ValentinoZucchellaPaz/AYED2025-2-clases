cmake_minimum_required(VERSION 3.30)
project(ayed)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
FetchContent_MakeAvailable(googletest)

# Get all direct children of the current directory
file(GLOB CHILDREN RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)

foreach(child ${CHILDREN})
    # Check if the child is a directory
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        # Check if the directory has a CMakeLists.txt and add it
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${child}/CMakeLists.txt")
            message(STATUS "Adding subdirectory: ${child}")
            add_subdirectory(${child})
        endif()
        
        # Now, check for sub-subdirectories (second level)
        file(GLOB GRANDCHILDREN RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/${child} ${CMAKE_CURRENT_SOURCE_DIR}/${child}/*)
        
        foreach(grandchild ${GRANDCHILDREN})
            # Check if the grandchild is a directory
            if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child}/${grandchild})
                # Check if it has a CMakeLists.txt and add it
                if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${child}/${grandchild}/CMakeLists.txt")
                    message(STATUS "Adding subdirectory: ${child}/${grandchild}")
                    add_subdirectory(${child}/${grandchild})
                endif()
            endif()
        endforeach()
    endif()
endforeach()
