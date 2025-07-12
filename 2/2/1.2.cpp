//#include <iostream>
//#include <vector>
//#include <thread>
//#include <mutex>
//#include <chrono>
//#include <iomanip>  
//
//std::mutex cout_mutex;
//using namespace std;
//void sum_vec(std::vector<int>& vec1, std::vector<int>& vec2, size_t start, size_t end, size_t thread_id) {
//    auto all = std::chrono::steady_clock::now();
//    size_t total = end - start;
//    const int bar_width = 50;
//
//    std::thread::id id = std::this_thread::get_id();
//    const int progress_line = thread_id + 2;
//
//    for (size_t i = start; i < end; i++) {
//        vec1[i] = vec1[i] + vec2[i];
//
//        if ((i - start) % (total / 100 + 1) == 0 || i == end - 1) {
//            float progress = static_cast<float>(i - start + 1) / total;
//            int pos = static_cast<int>(bar_width * progress);
//
//            std::lock_guard<std::mutex> lock(cout_mutex);
//
//           
//            std::cout << "\033[" << progress_line << ";0H";
//
//         
//            std::cout << "Thread number: " << thread_id << " Thread id: "<< id<< ": [";
//            for (int j = 0; j < bar_width; j++) {
//                if (j < pos) std::cout << "=";
//                else if (j == pos) std::cout << ">";
//                else std::cout << " ";
//            }
//            std::cout << "] " << std::setw(3) << int(progress * 100.0) << "%";
//
//          
//            auto now = std::chrono::steady_clock::now();
//            std::chrono::duration<double> elapsed = now - all;
//            std::cout << "  [Time: " << std::fixed << std::setprecision(2) << elapsed.count() << "s]";
//
//         
//            std::cout.flush();
//        }
//    }
//
//   
//    std::lock_guard<std::mutex> lock(cout_mutex);
//    auto end_time = std::chrono::steady_clock::now();
//    std::chrono::duration<double> total_elapsed = end_time - all;
//
//   
//}
//
//void run_parallel_sum(size_t num_threads, vector<int>& a, vector<int>& b)
//{
//   
//	size_t size = a.size();
//	vector<thread> trhead;
//	size_t threads = size / num_threads;
//	auto start = std::chrono::steady_clock::now();
//
//
//	for (size_t i = 0; i < num_threads; i++)
//	{
//
//		size_t start = i * threads;
//		size_t end = (i == num_threads - 1) ? size : start + threads;
//
//		trhead.emplace_back(sum_vec, ref(a), ref(b), start, end, i);
//	}
//	for (auto& t : trhead) {
//		t.join();
//	}
//	auto end = std::chrono::steady_clock::now();
//
//	
//}
//
//
//int main_2()
//{
//	vector<int> v1(1'000, 1);
//	vector<int> v2(10'000, 2);
//	vector<int> v3(100'000, 3);
//	vector<int> v4(100'000'000, 4);
//	
//run_parallel_sum(4, v4, v4);
//	
//return 0;
//}
//
