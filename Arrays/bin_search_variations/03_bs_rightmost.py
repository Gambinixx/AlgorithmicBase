def find_right_occurrence(arr, target):
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:

        mid = left + (right - left) // 2

        if arr[mid] == target:

            safe = mid

            left = mid + 1

        elif arr[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    if safe == -1:
        return "Искомого числа нет в массиве"
    else:
        return safe

array = [1, 3, 5, 7, 7, 7, 9, 11]
# Мы ищем target = 7. 
# Последняя семерка лежит на индексе 5.
print(find_right_occurrence(array, 7))

array = [1, 3, 5, 5, 6, 6, 8, 8, 9, 11]
# Ищем target = 7 (его тут нет)
print(find_right_occurrence(array, 7))

array = [7, 7, 7, 7, 7, 7, 7, 7] # индексы от 0 до 7
print(find_right_occurrence(array, 7))