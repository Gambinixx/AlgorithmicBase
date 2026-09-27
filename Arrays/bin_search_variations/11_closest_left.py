def find_closest_left(arr, target):
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:
      mid = left + (right - left) // 2
      mid_point = arr[mid]

      if mid_point <= target:
        safe = mid
        left = mid + 1
      else:
        right = mid - 1

    return safe

array = [1, 3, 5, 7, 7, 7, 9, 11] # вернул двойку
# Ближайший слева (меньше или равен 7) — это последняя семерка. Индекс 5.
print(find_closest_left(array, 7)) 

array_missing = [1, 3, 5, 8, 9, 11, 15, 19] # вернул -1
# Семерки нет. Ближайший слева — это пятерка. Индекс 2.
print(find_closest_left(array_missing, 7))
