def find_rotated_dupl(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        left_point = arr[left]
        mid_point = arr[mid]
        right_point = arr[right]

        if mid_point == target:
            return mid

        if left_point == mid_point == right_point:
            left += 1
            right -= 1
            continue # Сразу переходим на новый виток цикла

        if left_point <= mid_point:
            if left_point <= target <= mid_point:
                right = mid - 1
            else:
                left = mid + 1
        else:
            if mid_point <= target <= right_point:
                right = mid - 1
            else:
                left = mid + 1
    return -1

array = [2, 2, 2, 1, 2, 3, 2]
target = 3

# Тройка лежит под индексом 5.
print(find_rotated_dupl(array, target))

# второй тест с исправленным условием нахождения ротации
array = [2, 5, 6, 0, 0, 1, 2]
target = 0
# Ноль лежит под индексом 3.
print(find_rotated_dupl(array, target))

array = [2, 5, 6, 0, 1, 2, 3]
target = 3 # Ищем двойку на самом правом краю (индекс 6)
print(find_rotated_dupl(array, target))
