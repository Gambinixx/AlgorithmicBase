def three_way_partition(arr, low, high):
    # базовый случай
    if low >= high:
        return

    # Определяем указатели
    pivot = arr[low]
    left_p = low
    right_p = high

    i = low
    while i <= right_p:
        # нам надо постепенно сужать пространства с левой и правой сторон и закидывать дубликаты в центральный блок
        current_item = arr[i]
        if current_item < pivot:
            # закидываем в центр
            arr[left_p], arr[i] = arr[i], arr[left_p]
            # Сужаем левое пространство
            left_p += 1
            # двигаем каретку
            i += 1

        elif current_item > pivot:
            arr[right_p], arr[i] = arr[i], arr[right_p]
            # сужаем справа
            right_p -= 1

        # текущий элемент равен pivot. Двигаемся дальше
        else:
            i += 1

    # исследуем рекурсией пространства за пределами центрального блока дубликатов
    three_way_partition(arr, low, left_p - 1)
    three_way_partition(arr, right_p + 1, high)

array = [2, 0, 1, 2, 1, 0, 2, 1, 1, 0]
three_way_partition(array, 0, len(array) - 1)
print(array) # Должно вернуть строго: [0, 0, 0, 1, 1, 1, 1, 2, 2, 2]