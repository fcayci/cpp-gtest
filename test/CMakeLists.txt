find_package(GTest REQUIRED)
include(GoogleTest)

set(TEST_TARGET test_${TARGET})

set(TEST_SOURCES
    dummy_tests.cc
    fly_tests.cc
    duck_tests.cc
)

add_executable(${TEST_TARGET} ${TEST_SOURCES})
target_include_directories(${TEST_TARGET} PUBLIC ../include)
target_link_Libraries(${TEST_TARGET} PRIVATE
    ${LIBRARY_TARGET}
    GTest::GTest
    GTest::Main
)

gtest_discover_tests(${TEST_TARGET})