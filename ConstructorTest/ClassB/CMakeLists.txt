target_sources(ConstructorTest PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/ClassB.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ClassB.hpp)

target_include_directories(ConstructorTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})