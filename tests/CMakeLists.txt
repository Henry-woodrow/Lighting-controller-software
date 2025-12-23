include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(lighting_desk_tests
    universe_tests.cpp
    light_engine_tests.cpp
)

target_link_libraries(lighting_desk_tests
    PRIVATE
    light_engine_lib
    Catch2::Catch2WithMain
)

add_test(NAME lighting_desk_tests COMMAND lighting_desk_tests)
