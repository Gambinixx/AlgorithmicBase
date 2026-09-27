# Peak finding / Ternary search
# Унимодальная структура (горка)
# Инструмент: Тернарный поиск (или бинарный поиск по производной/соседним точкам) по виртуальной оси х.
# наш предикат функция:
def f(x):
    # Уравнение холма
    return -x**2 + 12*x + 5

def bs_optimum(low, high):
    left, right = low, high
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2

        current_y = f(mid)
        next_y = f(mid + 1)

        if current_y < next_y:
            # значит мы ещё недостаточно высоко
            left = mid + 1
        else:
            safe = mid
            # иначе слишко перепрыгнули, надо назад
            right = mid - 1

    return safe 

# Математический пик этой горки находится в точке x = 6.
# f(6) = -36 + 72 + 5 = 41. 
# Любой шаг влево или вправо (например, x=5 или x=7) даст результат меньше (40).
print(bs_optimum(0, 100)) # Должно вернуть 6