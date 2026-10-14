#include <iostream>
#include <unordered_set>
#include <vector>

using int_set = std::unordered_set<int>;

int main() {

    int_set my_set;

    for (int i = 1; i <= 5; i++) my_set.insert(i * 10);
    
    // тестируем уникальность
    for (int i = 1; i <= 5; i++) my_set.insert(i * 10);

    if (my_set.count(20)) {
        std::cout << "Element exists in Hash Set!" << std::endl;
    }

    my_set.erase(20);

    if (my_set.count(20) == 0) {
        std::cout << "Element 20 was successfully erased." << std::endl;
    }

    std::vector<int> debug_set(my_set.begin(), my_set.end());

    std::cout << "Current items: ";
    for (int num : my_set) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}