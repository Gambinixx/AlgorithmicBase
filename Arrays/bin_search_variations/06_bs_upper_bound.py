def upper_bound(arr, target):
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2
        blue_point = arr[mid]

        if blue_point > target:
            safe = mid

            right = mid - 1
        else:
            left = mid + 1

    return safe

array = [1, 3, 5, 7, 7, 7, 9, 11]
print(upper_bound(array, 7)) # Терминал должен вывести индекс 6 (девятку)

array = [1, 3, 5, 7, 7, 7]
# Мы ищем target = 7. 
# Числа, которое строго больше 7, в массиве НЕТ.
print(upper_bound(array, 7))

array = [10, 12, 15, 17, 19, 21]
# Мы ищем target = 7. 
# Все числа в массиве строго больше 7. Какое из них первое больше 7? 
# Физически это самое первое число в массиве (10). То есть индекс 0.
print(upper_bound(array, 7))
