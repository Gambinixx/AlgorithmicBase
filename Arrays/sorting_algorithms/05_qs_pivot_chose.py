def get_median_of_three(arr, left, right):
    mid = left + (right - left) // 2

    if (arr[left] <= arr[mid] <= arr[right] or arr[right] <= arr[mid] <= arr[left]):
        return mid
    if (arr[mid] <= arr[left] <= arr[right] or arr[right] <= arr[left] <= arr[mid]):
        return left
    return right

def quick_sort(arr, left, right):
    # не забываем про базовый случай
    if left >= right:
        return
    # находим самое среднее из трех
    p_indx = get_median_of_three(arr, left, right)
    arr[p_indx], arr[right] = arr[right], arr[p_indx]
    # получаем значение pivot
    pivot = arr[right]
    # всегда начинаем с левого края - 1
    i = left - 1 # наша сейв зона для элементов ниже pivot

    for j in range(left, right):
        current_min = arr[j]

        if current_min <= pivot:
            i += 1 # продавливаем сейв зону вперед

            # если i и j не сходятся то мы поменяем местами их элеменеты, а если сходятся, то просто перезапишем
            arr[i], arr[j] = arr[j], arr[i]
    # в конце цикла перебрасываем последний элемент в сейв зону
    arr[i + 1], arr[right] = arr[right], arr[i + 1]
    # опора для уровней ниже
    current_p_indx = i + 1

    # сортируем левую сторону
    quick_sort(arr, left, current_p_indx - 1)

    # сортируем правую сторону
    quick_sort(arr, current_p_indx + 1, right)

array = [10, 20, 30, 40, 50, 60, 70]
quick_sort(array, 0, len(array) - 1)
print(array) # Должно вернуть: [10, 20, 30, 40, 50, 60, 70]


