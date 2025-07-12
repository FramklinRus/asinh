//#include <iostream>
//#include <thread>
//#include <chrono>
//#include <atomic>
//using namespace std;
//atomic<int> count_n{ 0 };
//const int max_client = 6;
//
//
//void client()
//{
//
//	while (true)
//	{
//		if (count_n.load(memory_order_relaxed) == max_client)
//		{
//			break;
//		}
//		this_thread::sleep_for(1s);
//		
//		count_n.fetch_add(1, memory_order_relaxed);
//		cout << "client: " << count_n << endl;
//		
//		
//
//
//}
//	
//
//	
//	
//
//
//
//
//}
//
//void oper()
//{
//
//	while (true)
//	{
//		this_thread::sleep_for(2s);
//		if (count_n.load(memory_order_relaxed) > 0)
//		{
//
//			count_n.fetch_sub(1, memory_order_relaxed);
//			cout << "oper: " << count_n << endl;
//
//		}
//		else if (count_n == 0)
//		{
//			break;
//		}
//
//	}
//
//}
//
//
//
//int main_2()
//{
//	thread f1{ client };
//	thread f2{ oper };
//
//
//	f1.join();
//	f2.join();
//
//	return 0;
//}
