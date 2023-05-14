#pragma once
#include <string>
#include <ostream>
#include <Base.hpp>

namespace ConstructorTest
{
	class ClassA : public Base
	{
	public:
		explicit ClassA(std::string const& name);
		explicit ClassA(const ClassA& other);
		ClassA(ClassA&& other) noexcept;
		ClassA& operator= (const ClassA& other);
		ClassA& operator= (ClassA&& other) noexcept;
		~ClassA() override;

	private:
		std::string const& get_Type() const override;
	};
}