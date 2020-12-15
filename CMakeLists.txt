cmake_minimum_required(VERSION 3.5)

project(xml2html)

set(ROOT_DIR "${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
find_package(GTest REQUIRED)

set(SRC "${ROOT_DIR}/src")
set(INC "${ROOT_DIR}/inc")

set(SOURCES 
	${SRC}/main.cpp
	${SRC}/pugixml.cpp
	${SRC}/xml_parse.cpp
	${SRC}/html_table_generate.cpp
	${SRC}/key_value_data.cpp
	${SRC}/xml_to_html_test.cpp
	${SRC}/loguru.cpp
)

include_directories(${INC})
add_executable(xml2html ${SOURCES})
target_link_libraries(xml2html GTest::GTest GTest::Main "-lpthread -ldl")
