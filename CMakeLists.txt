cmake_minimum_required( VERSION 2.8 )

if(CMAKE_VERSION VERSION_LESS "3.1")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    endif()
else()
    set(CMAKE_CXX_STANDARD 11)
endif()

if ( UNIX )
    set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror")
endif( UNIX )

if ( MSVC )
    set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} /WX")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /WX")
endif( MSVC )

find_package( OpenMP REQUIRED )
if ( OPENMP_FOUND )
    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}" )
    set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_C_FLAGS}" )
    set ( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}" )
endif( OPENMP_FOUND )

add_subdirectory(modules)

include_directories(3rdparty/gtest)
add_subdirectory(3rdparty/gtest)
add_subdirectory(tests)
