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
			std::this_thread::sleep_for(0.5s - time);
			print("thread", *b);
			std::this_thread::sleep_for(1.0s + time);
		}
		);
	return task;
}

int main()
{
	std::chrono::duration<double> time = 0ms;
	std::vector<std::thread> tasks;
	{
		std::vector<std::unique_ptr<Base>> objects;
		objects.push_back(std::make_unique<Base>("1"));
		objects.push_back(std::make_unique<ClassA>("2"));
		objects.push_back(std::make_unique<ClassB>("3"));


		for (auto& obj : objects)
		{
			tasks.push_back(
				print_delete(std::move(obj), time)
			);
			time += 100ms;
		}
	}

	for (auto& task : tasks)
	{
		task.join();
	}
	return 0;
}

