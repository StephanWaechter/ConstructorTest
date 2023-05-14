#include <iostream>
#include <vector>
#include <algorithm>
#include <ClassA.hpp>
#include <ClassB.hpp>
using namespace std;
using namespace ConstructorTest;

void print(Base const& c)
{
	cout << "main: " << c << endl;
}

int main()
{
	std::vector<std::unique_ptr<Base>> objects;

	objects.push_back(std::make_unique<Base>("1"));
	objects.push_back(std::make_unique<ClassA>("2"));
	objects.push_back(std::make_unique<ClassB>("3"));

	for (auto const& obj : objects) {
		print(*obj);
	}
	return 0;
}

