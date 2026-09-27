def bs_rotated(arr, target):
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2

        # Маркеры для удобного отображения значений на индексах в дебаггере
        left_point = arr[left]
        mid_point = arr[mid]
        right_point = arr[right]

        if mid_point == target:
            return mid

        # проверяем правильная ли последовательность
        if left_point <= mid_point:
            # ищем есть ли таргет внутри диапазона. Не забываем, что сравниваем значения массива, а не индексы
            if left_point <= target <= mid_point:
                # если таргет внутри левой ротации, то пространство справа от мид нам больше не нужно
                right = mid - 1
            else: # если в левой ротации таргета нет, то мы отрезаем её
                left = mid + 1
        else: # если ротация слева по центр была непоследовательной, то ищем в диапазоне справа от мида
            if mid_point <= target <= right_point:
                # если таргет в этой ротации, то мы отрезаем левое пространство от мид
                left = mid + 1
            else:
                # если таргета небыло в этой ротации, то мы её отрезаем
                right = mid - 1

    return safe # вообще, сейф в этом алгоритме не нужен, я его уже по приколу создаю, чтобы находить крайние вхождения левой и правой сторон

# Циклический сдвиг массива, который мы будем использовать для теста
array = [7, 8, 9, 1, 2, 3, 4, 5, 6]
# на первой итерации: left (7), mid (2), right (6)

print(bs_rotated(array, 8))

# print(bs_rotated(array, 3))

# print(bs_rotated(array, 6)) 