#include <iostream>
#include <vector>
#include <stack>

using vec = std::vector<int>;

vec next_greater(vec& arr) {
    int n = arr.size();
    vec result(n, -1); // Куда будем складывать большую пару
    std::stack<int> mono;

    for (int i = 0; i < n; i++) {
        // Грубо говоря, если текущий элемент больше того, что лежит на вершине стека.
        while (!mono.empty() && arr[i] > arr[mono.top()]) {
            
            int target_indx = mono.top(); // сохраняем индекс меньшего элемента

            mono.pop(); // Удаляем из нашей локальной оперативки индекс, потому как нашли элементу большую пару в массиве
            
            result[target_indx] = arr[i]; // Сохраняем большую пару
        }

        mono.push(i);
    }

    return result;
}

// Мы используем стек (встроенный контейнер, а не кастомный) как локальную оперативную память алгоритма.
// Таким образом стек выступает прослойкой между оригинальным массивом и результативным (куда мы складываем большие пары), что существенно экономит память.
int main() {
    vec arr = {5, 4, 3, 2, 1, 25}; // 25 просто вытолкнет все числа: [25, 25, 25, 25, 25, -1]. Потому что 25 самая большая пара для каждого следующего элемента. 

    vec res = next_greater(arr);

    std::cout << "Next greater element: ";

    for (auto num : res) std::cout << num << " ";

    std::cout << std::endl;

    return 0;
}