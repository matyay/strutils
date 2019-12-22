# =============================================================================
# Build tests

file(GLOB SRCS *.cc)

add_executable(tests ${SRCS})
target_link_libraries(tests PUBLIC strutils gtest pthread)

# =============================================================================
# Run the tests

add_custom_target(run_tests ALL
    ./tests
    DEPENDS tests
    VERBATIM)
