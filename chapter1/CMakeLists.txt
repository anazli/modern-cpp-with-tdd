add_library(chapter1_lib
	Soundex.h
	Soundex.cpp
)

target_include_directories(chapter1_lib
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_executable(chapter1_test
	SoundexTest.cpp
)
target_link_libraries(chapter1_test
	PRIVATE
		chapter1_lib
		gtest_main
)

add_test(NAME Chapter1Tests COMMAND chapter1_test)

