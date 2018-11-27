message(STATUS "Tests module")

file(GLOB_RECURSE source_files "*.cpp")

project(Test_Target)

###############################################################
## GTest
###############################################################
include(ExternalProject)
ExternalProject_Add(gtest
    GIT_REPOSITORY https://github.com/abseil/googletest
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)
ExternalProject_Get_Property(gtest install_dir)
include_directories(${install_dir}/include)
###############################################################

include_directories(include)
add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries(${PROJECT_NAME} data_structures_library)
target_link_libraries(${PROJECT_NAME} generator_library)
target_link_libraries(${PROJECT_NAME} algorithms_library)
target_link_libraries(${PROJECT_NAME} common_library)

add_dependencies(${PROJECT_NAME} gtest)
target_link_libraries(${PROJECT_NAME} ${install_dir}/lib/libgmock.a)
target_link_libraries(${PROJECT_NAME} ${install_dir}/lib/libgmock_main.a)
target_link_libraries(${PROJECT_NAME} ${install_dir}/lib/libgtest.a)
target_link_libraries(${PROJECT_NAME} ${install_dir}/lib/libgtest_main.a)
