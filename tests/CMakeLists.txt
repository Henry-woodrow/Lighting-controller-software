include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE

)

FetchContent_MakeAvailable(googletest)

add_executable(lighting_desk_tests
    universe_tests.cpp
    light_engine_intensity_test.cpp
    dmx_universe_test.cpp
    # add other test files here
)

target_link_libraries(lighting_desk_tests
    PRIVATE
    light_engine_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(lighting_desk_tests)

set_target_properties(lighting_desk_tests PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_compile_options(lighting_desk_tests PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
)
target_include_directories(lighting_desk_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

add_custom_target(run_tests
    COMMAND lighting_desk_tests
    DEPENDS lighting_desk_tests
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

enable_testing()

add_test(NAME lighting_desk_tests COMMAND lighting_desk_tests)

set_tests_properties(lighting_desk_tests PROPERTIES
    TIMEOUT 30
)

