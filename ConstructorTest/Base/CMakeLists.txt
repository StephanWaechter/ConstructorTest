target_sources(ConstructorTest PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/Base.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Base.hpp)

target_include_directories(ConstructorTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})