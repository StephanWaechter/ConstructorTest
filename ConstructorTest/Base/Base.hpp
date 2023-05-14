#pragma once
#include <string>
#include <ostream>

namespace ConstructorTest
{
	class Base
	{
	public:
		explicit Base(std::string const& name);
		explicit Base(const Base& other);
		Base(Base&& other) noexcept;
		Base& operator= (const Base& other);
		Base& operator= (Base&& other) noexcept;
		virtual ~Base();

		void print(std::ostream& os) const;

	private:
		virtual std::string const & get_Type() const;
		std::string m_Name;
	};

	inline std::ostream& operator<<(std::ostream& os, const Base& a) {
		a.print(os);
		return os;
	};
}

