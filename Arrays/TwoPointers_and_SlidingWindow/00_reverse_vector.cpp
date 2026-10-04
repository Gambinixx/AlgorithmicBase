#include <iostream>
#include <algorithm>
#include <vector>

void reverse_vec(std::vector<int>& vec) {
    if (vec.size() <= 0) return;

    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        std::swap(vec[left], vec[right]);

        left++;
        right--;
    }
}

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80};

    // vector это промышленный контейнер, и он сам знает свою длину

    reverse_vec(vec);

    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

