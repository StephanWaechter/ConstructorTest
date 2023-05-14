# CMakeList.txt : CMake project for ConstructorTest, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ConstructorTest "ConstructorTestMain.cpp" "ClassB/ClassB.cpp" "Base/Base.cpp")
add_subdirectory("Base")
add_subdirectory("ClassA")
add_subdirectory("ClassB")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConstructorTest PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
