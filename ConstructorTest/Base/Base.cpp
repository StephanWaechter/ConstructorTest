#include "Base.hpp"
#include <iostream>
#include <memory>

using namespace std;

ConstructorTest::Base::Base(std::string const& name)
	: m_Name{ name }
{
	cout << "New Base " << *this << endl;
}

ConstructorTest::Base::Base(const Base& other)
	: m_Name{other.m_Name}
{
	cout << "Copy Base " << *this << endl;
}

ConstructorTest::Base::Base(Base&& other) noexcept 
	: m_Name{ std::exchange(other.m_Name,"invalid") }
{
	cout << "Move Base " << *this << endl;
}

ConstructorTest::Base& ConstructorTest::Base::operator=(const Base& other)
{
	m_Name = other.m_Name;
	cout << "=Copy Base " << *this << endl;
	return *this;
}

ConstructorTest::Base& ConstructorTest::Base::operator=(Base&& other) noexcept
{
	m_Name = std::exchange(other.m_Name,"invalid");
	cout << "=Move Base " << *this << endl;
	return *this;
}

ConstructorTest::Base::~Base()
{
 	cout << "Delete Base " << *this << endl;
}

void ConstructorTest::Base::print(std::ostream& os) const
{
	os << get_Type() << "(" << m_Name << ")";
}

std::string const& ConstructorTest::Base::get_Type() const
{
	static const std::string Type{ "Base" };
	return Type;
}