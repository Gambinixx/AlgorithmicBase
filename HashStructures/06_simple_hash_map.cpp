#include <iostream>
#include <list>
#include <string>
#include <cstddef>
#include <utility>
#include <vector>

using s_t = std::size_t;

template <typename Key, typename Value>
class SimpleHashMap {
private:
    using Node = std::pair<Key, Value>; // Сразу создадим алиас/псевдоним для пары ключ:значение — это будут наши узлы в связном списке при коллизиях

    // Создаем массив бакетов с цепочками пар
    std::vector<std::list<Node>> buckets;

    s_t count; // счетчик элементов в хэш-мапе

    // далее функция для преобразования хэша и нахождения индекса бакета в импровизированной хэш-мапе
    s_t hash_func(const Key& k) const {
        // создаем временный хэшер объект по шаблонному типу, сразу вызываем и получаем хэш для нашего аргумента
        return std::hash<Key>{}(k) % buckets.size(); // Находим остаток от деления: хэша деленного на количество бакетов
    }

public:
    // Конструктор
    explicit SimpleHashMap(s_t buckets_count) : buckets(buckets_count), count(0) {}

    // Так как встроенный контейнеры vector и list уже содержат в себе деструкторы, то можно попробовать реализовать метод который просто очищает содержимое структуры
    void clear() {
        for (auto& bucket : buckets) {
            bucket.clear(); // очищаем все узлы
        }
        count = 0; // обнуляем счетчик элементов
    }

    // Функция вставки пар
    void insert_pair(const Key& k, const Value& v) {
        s_t indx = hash_func(k); // находим индекс бакета

        // проверяем есть ли в бакете такой ключ
        for (auto& pair : buckets[indx]) {
            if (pair.first == k) {
                // если есть то добавляем значение
                pair.second = v;
                return;
            }
        }

        // если нет, то добавляем пару 
        buckets[indx].push_front({k, v});
        ++count; // префиксная инкрементация
    }

    // Поиск по ключу
    Value* find(const Key& k) {
        s_t indx = hash_func(k);

        for (auto& pair : buckets[indx]) {
            if (pair.first == k) return &pair.second; // возвращаем указатель на элемент
        }
        
        return nullptr; // если не нашли
    }

    void print_map() {

        for (auto& bucket : buckets) {
            for (auto& pair : bucket) {
                std::cout << "key: " << pair.first << " -"
                            << " value: " << pair.second << "\n";
            }
        }
    }

};

int main() {
    SimpleHashMap<std::string, int> map(5);

    map.insert_pair("Zalupa", 20);
    map.insert_pair("Vasyan", 30);
    map.insert_pair("Igor", 50);
    map.insert_pair("Kazanova", 70);
    map.insert_pair("Imhotep", 100);
    map.insert_pair("Rage", 126);
    map.insert_pair("fear", 200);
    map.insert_pair("loath", 300);

    map.print_map();

    int* val = map.find("Zalupa");

    if (val != nullptr) {
        std::cout << "Zalupa value was find: " << *val << std::endl;
    } else {
        std::cout << "Not found" << "\n" << std::endl;
    }

    map.clear();

    map.print_map();

    return 0;
}