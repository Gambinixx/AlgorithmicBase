def find_closest_right(arr, target):
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2
        mid_point = arr[mid]

        if mid_point >= target:
            safe = mid
            right = mid - 1

        else:
            left = mid + 1

    return safe

array = [1, 3, 5, 7, 7, 7, 9, 11]
# Семерка есть. Ближайший справа (больше или равен 7) — это САМАЯ ПЕРВАЯ семерка. Индекс 3.
print(find_closest_right(array, 7)) 

array_missing = [1, 3, 5, 8, 9, 11, 15, 19]
# Семерки нет. Ближайший справа (больше или равен 7) — это восьмерка. Индекс 3.
print(find_closest_right(array_missing, 7))
