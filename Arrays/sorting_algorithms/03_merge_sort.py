# Мы переходим ко второму блоку: 2. Разделяй и властвуй (Рекурсивное деление),
# ветка 2.1 Merge Sort (Сортировка слиянием).

def merge_sort(arr):
    # базовый случай
    if len(arr) <= 1:
        return

    # фаза divide
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    # дробим дальше
    merge_sort(left_half)
    merge_sort(right_half)

    # фаза слияния (conquer)
    left_point = 0
    right_point = 0
    over_point = 0

    # пока на обоих отрезках есть элементы
    while left_point < len(left_half) and right_point < len(right_half):
        current_left = left_half[left_point]
        current_right = right_half[right_point]

        if current_left < current_right:
            arr[over_point] = current_left
            left_point += 1
        else:
            arr[over_point] = current_right
            right_point += 1
        
        over_point += 1

    # Сбрасываем хвосты
    while left_point < len(left_half):
        arr[over_point] = left_half[left_point]

        left_point += 1
        over_point += 1

    while right_point < len(right_half):
        arr[over_point] = right_half[right_point]

        right_point += 1
        over_point += 1


array = [64, 34, 25, 12, 22, 11, 90]
merge_sort(array)
print(array)  # Должно вернуть: [11, 12, 22, 25, 34, 64, 90]
