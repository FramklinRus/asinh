#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

class DATA
{
	int data;
	mutex dx;
public:
	
	DATA(int date)
	{
		data = date;

	}
	mutex& get_mutex()
	{
		return dx;
	}
	int& get_data() { return data; }
};
void change_lock(DATA& d1, DATA& d2)
{
	lock(d1.get_mutex(), d2.get_mutex());
	swap(d1.get_data(), d2.get_data());
	
	lock_guard<mutex> lock_1(d1.get_mutex(), adopt_lock);
	lock_guard<mutex> lock_2(d2.get_mutex(), adopt_lock);
	cout << d1.get_data();
}

void change_uniq(DATA& d1, DATA& d2)
{
	unique_lock<mutex> lock_1(d1.get_mutex(), defer_lock);
	unique_lock<mutex> lock_2(d2.get_mutex(), defer_lock);
	lock(lock_1, lock_2);
	swap(d1.get_data(), d2.get_data());
	
	cout << d1.get_data();
}

void change_scoped(DATA& d1, DATA& d2)
{
	scoped_lock lock{ d1.get_mutex(),d2.get_mutex()};
	swap(d1.get_data(), d2.get_data());

	cout << d1.get_data();
}
int main()
{
	DATA d1(5), d2(8);
	thread t1(change_scoped,ref(d1), ref(d2));
	thread t2(change_scoped, ref(d2), ref(d1));
	t1.join();
	t2.join();
	return 0;

}