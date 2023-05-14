target_sources(ConstructorTest PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/ClassA.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ClassA.hpp)

target_include_directories(ConstructorTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})