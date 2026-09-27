def quick_sort(arr, left, right):
    # Базовый случай
    if left >= right:
        return

    # Разделение (partition)
    # Опорный элемент самый правый
    pivot = arr[right]
    i = left - 1 # граница сейв зоны элементов меньше pivot

    for j in range(left, right):
        current_min = arr[j]
        if current_min <= pivot:
            # Увеличиваем сейв зону
            i += 1
            # закидываем меньшее число в безопасную зону
            # делаем рокировку
            arr[i], arr[j] = arr[j], arr[i]

    # С каждой итерацией, мы продавливаем сейв-зону вперёд (вправо), и если текущий right окажется самым маленьким...
    # мы, просто ставим его в отсортированную половину
    arr[i + 1], arr[right] = arr[right], arr[i + 1]

    pivot_index = i + 1

    # Рекурсивный поиск для левого куска: от текущего низа, до границы pivot - 1
    quick_sort(arr, left, pivot_index - 1)

    # Тоже самое только для правой стороны от pivot
    quick_sort(arr, pivot_index + 1, right)


array = [64, 34, 25, 12, 22, 11, 90]

# Так как мы сортируем внутри одного массива по индексам, 
# на старте передаем границы: low = 0, high = последний индекс
quick_sort(array, 0, len(array) - 1)
print(array)  # Должно вернуть: [11, 12, 22, 25, 34, 64, 90]
