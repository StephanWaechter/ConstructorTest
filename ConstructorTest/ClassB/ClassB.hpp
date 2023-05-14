#pragma once
#include <string>
#include <ostream>
#include <Base.hpp>

namespace ConstructorTest
{
	class ClassB : public Base
	{
	public:
		explicit ClassB(std::string const& name);
		explicit ClassB(const ClassB& other);
		ClassB(ClassB&& other) noexcept;
		ClassB& operator= (const ClassB& other);
		ClassB& operator= (ClassB&& other) noexcept;
		~ClassB() override;

	private:
		std::string const & get_Type() const override;
	};
}