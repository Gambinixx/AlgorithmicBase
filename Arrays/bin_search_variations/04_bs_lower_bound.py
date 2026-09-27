def lower_bound(arr, target): # нахождение нижней грани
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2

        blue_point = arr[mid]

        if blue_point >= target:
            safe = mid

            right = mid - 1 # отрезаем правую часть от голубого рубежа (arr[mid]), потому что нам надо найти ближайшее к таргету справа

        else:
            # если голубой поинт находится ниже красного таргет, мы отрезаем левую часть
            left = mid + 1

    return safe # возвращаем ближайший индекс lower bound таргета

array = [1, 3, 5, 8, 9, 11, 15, 19]
# Мы ищем target = 7. Семерки в массиве НЕТ.
# Но ближайшее число СВЕРХУ (больше или равно 7) — это 8.
# Его индекс — 3.
print(lower_bound(array, 7))
