#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>
using namespace std;
void sum_vec(vector<int>& vec1, vector<int>& vec2, size_t  start, size_t  end)
{
	for (size_t i = start; i < end; i++)
	{
		vec1[i] = vec1[i] + vec2[i];

	}

}

void run_parallel_sum(size_t num_threads, vector<int>& a,  vector<int>& b)
{
	size_t size= a.size();
	vector<thread> trhead;
	size_t threads = size / num_threads;
	auto start = std::chrono::steady_clock::now();
	
	
	for (size_t i = 0; i < num_threads; i++)
	{
		
		size_t start = i * threads;
		size_t end = (i == num_threads - 1) ? size : start + threads;
		
			trhead.emplace_back(sum_vec, ref(a), ref(b), start, end);
			
		
	
		
	}
	for (auto& t : trhead) {
		t.join();  
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time for "<< num_threads<<": " << elapsed_seconds.count() << "s\n";
}


int main()
{
	vector<int> v1(1'000,1);
	vector<int> v2(10'000,2);
	vector<int> v3(100'000,3);
	vector<int> v4(100'000'000,4);
	int cores = std::thread::hardware_concurrency();
	std::cout << "Cores: " << cores << std::endl;
	cout << endl;
	cout << 1000 << endl;
	
	run_parallel_sum(1, v1, v1);
	run_parallel_sum(2, v1, v1);
	run_parallel_sum(4, v1, v1);
	run_parallel_sum(8, v1, v1);
	run_parallel_sum(16, v1, v1);

	cout << 10'000 << endl;

	run_parallel_sum(1, v2, v2);
	run_parallel_sum(2, v2, v2);
	run_parallel_sum(4, v2, v2);
	run_parallel_sum(8, v2, v2);
	run_parallel_sum(16, v2, v2);
	cout << 100'000 << endl;

	run_parallel_sum(1, v3, v3);
	run_parallel_sum(2, v3, v3);
	run_parallel_sum(4, v3, v3);
	run_parallel_sum(8, v3, v3);
	run_parallel_sum(16, v3, v3);
	cout << 100'000'000 << endl;

	run_parallel_sum(1, v4, v4);
	run_parallel_sum(2, v4, v4);
	run_parallel_sum(4, v4, v4);
	run_parallel_sum(8, v4, v4);
	run_parallel_sum(16, v4, v4);

}

