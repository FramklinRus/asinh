#include <iostream>
#include <vector>
#include <future>
#include <algorithm>

// Асинхронный поиск индекса минимального элемента в диапазоне [start, end)
void find_min_index_async(const std::vector<int>& vec, size_t start, std::promise<size_t> prom) {
    size_t min_index = start;
    for (size_t i = start + 1; i < vec.size(); ++i) {
        if (vec[i] < vec[min_index]) {
            min_index = i;
        }
    }
    prom.set_value(min_index);  // Возвращаем индекс через promise
}

// Сортировка выбором с асинхронным поиском минимума
void selection_sort_async(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        // Создаём promise и получаем future
        std::promise<size_t> prom;
        std::future<size_t> fut = prom.get_future();

        // Запускаем асинхронную задачу поиска минимума
        std::thread th(find_min_index_async, std::cref(vec), i, std::move(prom));

        // Получаем результат из future
        size_t min_index = fut.get();
        th.join();

        // Обмен текущего элемента и минимального
        if (i != min_index) {
            std::swap(vec[i], vec[min_index]);
        }
    }
}


int main_2() {
    std::vector<int> data = { 64, 25, 12, 22, 11 };

    std::cout << "Before: ";
    for (int n : data) std::cout << n << " ";
    std::cout << "\n";

    selection_sort_async(data);

    std::cout << "After: ";
    for (int n : data) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}