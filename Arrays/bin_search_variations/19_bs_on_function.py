# математическая функция это по сути тот же черный ящик или предикат
# функция кубического уравнения
def f(x):
    # кубический рост
    return x**3 + 3*x

def bs_monotonic_func(y):
    left, right = 1, 100
    not_find = -1

    # хм, можно даже проверить на монотонность, так как ты говорил, что числа должны строго возрастать
    test_slice = list(range(1, 50))
    test_graphic = [f(mono) for mono in test_slice]
    print(f"Тест монотонности: {test_graphic}")

    while left <= right:
        mid = left + (right - left) // 2

        current_y = f(mid)
        # y — наше известное число
        # если результат формулы равен известному y,
        if current_y == y:
            # значит мы нашли наш x
            return mid

        # если текущий результат формулы больше, известного y
        elif current_y > y:
            # Значит X не подходит, и мы отрезаем правое пространство
            right = mid - 1
        else:
            # иначе отрезаем левое пространство, потому что x — слишком мал
            left = mid + 1

    return not_find

# Искомый результат Y = 140
target_y = 140

print(bs_monotonic_func(target_y))
