#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;
atomic<int> count_n{0};
const int max_client = 6;


void client()
{
	
		for (count_n;count_n < max_client;)
		{
			this_thread::sleep_for(1s);
			count_n++;

			cout << "client: " << count_n << endl;
		}

	
	
	
	
}

void oper()
{
	
	while (true)
	{
		this_thread::sleep_for(2s);
		if (count_n > 0)
		{
			
			count_n--;
			cout << "oper: " << count_n << endl;
		
		}
		else if (count_n == 0 )
		{
			break;
		}
		
	}

}



int main_2()
{
	thread f1{client};
	thread f2{oper};
	

	f1.join();
	f2.join();

	return 0;
}
