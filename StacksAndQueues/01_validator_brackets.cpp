#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool is_valid_brackets(string str) {
    ArrayStack<char> stack; // создаем стек под char

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch); // Если натыкаемся на закрывающуюся скобку, то добавляем на вершину стека
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.is_empty()) return false; // Предохранитель от краша, при попытке взять элемент из пустого контейнера

            char top_bracket = stack.pop();
            
            // Сравниваем, соответствует ли символ вершине
            if (ch == ')' && top_bracket != '(') return false; // если вершина и текущая скобка одинаковы, то скобки не валидны
            if (ch == '}' && top_bracket != '{') return false;
            if (ch == ']' && top_bracket != '[') return false;

        }
    }
    return stack.is_empty(); // Если цикл закончился и стек пустой, то все скобки соответствовали друг другу
}

void validator(string str) {
    if (is_valid_brackets(str)) {
        cout << str << " brackets is valid."; cout << endl;
    } else {
        cout << str << " brackets is invalid."; cout << endl;
    }
}

int main() {

    string str1 = "{[()]}";
    string str2 = "{[(])}";

    validator(str1);
    validator(str2);

    return 0;
}
