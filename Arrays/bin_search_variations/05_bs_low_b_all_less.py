def lower_bound(arr, target):
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2
        blue_point = arr[mid]

        if blue_point >= target:
            safe = mid

            right = mid - 1

        else:
            left = mid + 1

    return safe

array = [1, 2, 3, 4, 5]
# Мы ищем target = 10. 
# Все числа меньше 10. Ближайшего сверху нет.
print(lower_bound(array, 10))

array = [15, 17, 19, 21, 23]
# Мы ищем target = 10. 
# Все числа больше 10. Какое из них первое больше или равно 10? 
# Физически это самое первое число в массиве (15). То есть индекс 0.
print(lower_bound(array, 10))

array = [1, 3, 5, 7, 7, 7]
# Мы ищем target = 7. 
# Числа, которое строго больше 7, в массиве НЕТ.
print(lower_bound(array, 7))