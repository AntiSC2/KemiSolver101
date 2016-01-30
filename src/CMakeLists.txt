project(KemiSolver101)

include_directories("${CMAKE_SOURCE_DIR}/src")

set(SOURCES
	main.cpp
	kemi.cpp
	element.cpp
	error.cpp
	)
set(HEADERS
	kemi.hpp
	element.hpp
	error.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})
