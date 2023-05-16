#include <iostream>
#include <vector>
#include <algorithm>
#include <ClassA.hpp>
#include <ClassB.hpp>
#include <thread>

using namespace std;
using namespace ConstructorTest;
using namespace std::chrono_literals;

void print(std::string const& where, Base const& c)
{
	cout << where << ": " << c << endl;
}

std::thread print_delete(std::unique_ptr<Base> base, std::chrono::duration<double> time)
{
	print("main", *base);
	std::thread task(
		[b = std::move(base), time]() mutable
		{
			print("thread", *b);
			std::this_thread::sleep_for(1s + time);
		}
		);
	return task;

}

int main()
{
	std::vector<
		std::pair<
			std::unique_ptr<Base>,
			std::chrono::duration<double>
		>
	> objects;

	objects.push_back({ std::make_unique<Base>("1"), 300ms });
	objects.push_back({ std::make_unique<ClassA>("2"), 200ms });
	objects.push_back({ std::make_unique<ClassB>("3"), 100ms });

	std::vector<std::thread> tasks;
	while (objects.size())
	{
		auto [obj, time] = std::move(objects.back());
		objects.pop_back();
		tasks.push_back(
			print_delete(std::move(obj), time)
		);
	}

	std::for_each(tasks.begin(), tasks.end(),
		[](auto& task)
		{
			task.join();
		}
	);
	return 0;
}

