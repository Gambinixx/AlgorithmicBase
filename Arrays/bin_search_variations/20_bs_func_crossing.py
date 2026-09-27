# Root finding / Zero crossing
# наша монотонная функция предикат
def f(x):
    # Это формула кубического уравнения которая летит из глубокого минуса в плюс
    return x**3 - 2*x - 21

def bs_zero_crossing(low, high):
    left, right = low, high
    nf = "not found"

    while left <= right:
        mid = left + (right - left) // 2

        current_y = f(mid)

        if current_y == 0:
            return mid

        elif current_y > 0:
            right = mid - 1
        else:
            left = mid + 1
    return nf

# Точный целый корень этого уравнения — число 3.
# (Потому что 3³ - 2*3 - 21 = 27 - 6 - 21 = 0).
print(bs_zero_crossing(0, 100)) # Должно вернуть 3
