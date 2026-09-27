def closest_left(arr, target):
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

def closest_right(arr, target):
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

# Это проверка работоспособности
#array = [1, 3, 5, 7, 7, 7, 9, 11]
#print(closest_left(array, 7)) # должен быть 5. Всё правильно, так как 7 встречается несколько раз, и ближайший слева индекс для 7 - это 5-й индекс.
#print(closest_right(array, 7)) # тоже 3й


#array_missing = [1, 3, 5, 8, 9, 11, 15, 19]
#print(closest_left(array_missing, 7)) # 2й
#print(closest_right(array_missing, 7)) # 3й

def absolute_closest(arr, target):
    # сразу получаем индексы ближайших слева и справа
    left_closest = closest_left(arr, target)
    right_closest = closest_right(arr, target)

    # проверяем не вернуло ли -1
    if left_closest == -1: # все числа больше таргета
        left_closest = right_closest # значит он справой стороны, меняем их местами.
        # не знаю правильно ли я делаю, но я не хочу делать return потому что программа завершится. А так я просто сдвигаю индекс left на место right. 
    if right_closest == -1:
        right_closest = left_closest 

    dist_left = abs(arr[left_closest] - target) # вычисляем дистанцию до таргет
    dist_right = abs(arr[right_closest] - target) # тоже самое только для правой стороны

    if dist_left == dist_right:
        return f"индекс: {left_closest}, значение: {arr[left_closest]}"

    elif dist_left <= dist_right:
        return f"индекс: {left_closest}, значение: {arr[left_closest]}"
    else:
        return f"индекс: {right_closest}, значение: {arr[right_closest]}"

array = [1, 2, 5, 11, 15, 20]
target = 8

# Восьмерка зажата между 5 (индекс 2) и 11 (индекс 3).
# До пятерки расстояние: 8 - 5 = 3.
# До одинадцати расстояние: 11 - 8 = 3. 
# Расстояния равны. В случае равенства возвращай меньшее число (левый индекс 2).
print(absolute_closest(array, target)) # Должно вернуть 2

target2 = 10
# Десятка ближе к 11 (индекс 3), так как 11 - 10 = 1, а 10 - 5 = 5.
print(absolute_closest(array, target2)) # Должно вернуть 3
