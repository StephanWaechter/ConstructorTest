#include "ClassA.hpp"
#include <iostream>
#include <memory>

using namespace std;

ConstructorTest::ClassA::ClassA(std::string const& name) : Base(name)
{
	cout << "New A " << *this << endl;
}

ConstructorTest::ClassA::ClassA(const ClassA& other) : Base(other)
{
	cout << "Copy A " << *this << endl;
}

ConstructorTest::ClassA::ClassA(ClassA&& other) noexcept : Base(std::move(other))
{
	cout << "Move A " << *this << endl;
}

ConstructorTest::ClassA& ConstructorTest::ClassA::operator=(const ClassA& other)
{
	Base::operator=(other);
	cout << "=Copy A " << *this << endl;
	return *this;
}

ConstructorTest::ClassA& ConstructorTest::ClassA::operator=(ClassA&& other) noexcept
{
	Base::operator=(std::move(other));
	cout << "=Move A " << *this << endl;
	return *this;
}

ConstructorTest::ClassA::~ClassA()
{
	cout << "Delete A " << *this << endl;
}

std::string const& ConstructorTest::ClassA::get_Type() const
{
	static const std::string Type{ "ClassA" };
	return Type;
}
