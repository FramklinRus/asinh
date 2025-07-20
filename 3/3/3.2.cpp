#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>
#include <iterator>

template<typename Iterator, typename Func>
void parallel_for_each(Iterator begin, Iterator end, Func f, std::size_t min_per_thread = 1000) {
    const std::size_t length = std::distance(begin, end);

    if (length == 0) return;

    if (length <= min_per_thread) {
        // База рекурсии: слишком маленький диапазон — запускаем последовательно
        std::for_each(begin, end, f);
    }
    else {
        // Делим пополам
        Iterator mid = begin;
        std::advance(mid, length / 2);

        // Запускаем левую половину асинхронно
        auto future = std::async(std::launch::async,
            parallel_for_each<Iterator, Func>, begin, mid, f, min_per_thread);

        // Правая половина выполняется текущим потоком
        parallel_for_each(mid, end, f, min_per_thread);

        // Дожидаемся завершения левой части
        future.get();
    }
}

int main() {
    std::vector<int> data(10000, 1);

    parallel_for_each(data.begin(), data.end(), [](int& x) {
        x *= 2;
        });

    std::cout << "data[0] = " << data[0] << ", data[9999] = " << data[9999] << "\n";
    return 0;
}