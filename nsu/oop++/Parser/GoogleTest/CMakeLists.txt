project(GoogleTest)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
enable_testing()
# adding the Google_Tests_run target
add_executable(Google_Tests_run
        FileReader_test.cpp
        ../FileReader.h
        ../FileReader.cpp
        Parser_test.cpp
        ../Parser.h
        ../Parser.cpp
        Statistic_test.cpp
        ../Statistic.h
        ../Statistic.cpp
        FileWriter_test.cpp
        ../FileWriter.h
        ../FileWriter.cpp
)

# linking Google_Tests_run with DateConverter_lib which will be tested
# target_link_libraries(Google_Tests_run ${CMAKE_PROJECT_NAME}_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)