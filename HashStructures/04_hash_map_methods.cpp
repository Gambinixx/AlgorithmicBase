#include <iostream>
#include <string>
#include <unordered_map>

using int_str_map = std::unordered_map<int, std::string>;

int main() {

    int_str_map notebook;

    // Операция вставки и перезаписи
    notebook[1] = "Zalupa";
    notebook[20] = "her";
    notebook[20] = "davalka";
    notebook[1000] = "drochila";

    // Операция поиска по ключу
    if (notebook.count(1)) std::cout << "1 value is: " << notebook[1] << std::endl;

    // Операция удаления по ключу
    notebook.erase(1000);
    notebook.erase(20);

    // Операция вывода
    for (const auto& pair : notebook) std::cout << " key: " << pair.first << ", value: " << pair.second << std::endl;

    return 0;
}