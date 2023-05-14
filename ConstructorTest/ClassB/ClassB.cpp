#include "ClassB.hpp"
#include <iostream>
#include <memory>

using namespace std;

ConstructorTest::ClassB::ClassB(std::string const& name) : Base(name)
{
	cout << "New B " << *this << endl;
}

ConstructorTest::ClassB::ClassB(const ClassB& other) : Base(other)
{
	cout << "Copy B " << *this << endl;
}

ConstructorTest::ClassB::ClassB(ClassB&& other) noexcept : Base(std::move(other))
{
	cout << "Move B " << *this << endl;
}

ConstructorTest::ClassB& ConstructorTest::ClassB::operator=(const ClassB& other)
{
	Base::operator=(other);
	cout << "=Copy B " << *this << endl;
	return *this;
}

ConstructorTest::ClassB& ConstructorTest::ClassB::operator=(ClassB&& other) noexcept
{
	Base::operator=(std::move(other));
	cout << "=Move B " << *this << endl;
	return *this;
}

ConstructorTest::ClassB::~ClassB()
{
	cout << "Delete B " << *this << endl;
}

std::string const& ConstructorTest::ClassB::get_Type() const
{
	static const std::string Type{ "ClassB" };
	return Type;
}
