# Спецификация: Сортируем массив и находим k-й по величине элемент (0-индексированный)

# Находим индекс нашего pivot
def partition(arr, low, high):
    pivot = arr[high]

    i = low - 1
    for j in range(low, high):
        # В общем, если находим число больше pivot то продвигаем его вперёд, а в конце цикла кидаем самый большой элемент в отсортированную часть (в конец массива).
        # В итоге получим массив где все элементы меньше pivot будут слева, а больше — справа. Идеальный индекс pivot будет в середине.
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]

    return i + 1

def quick_select(arr, low, high, k):
    # Наш базовый случай: если наши указатели встретились, то мы нашли искомый таргет
    if low == high:
        return arr[low]

    # получаем индекс pivot
    pivot_index = partition(arr, low, high)

    # Используем логику бинарного поиска
    # Первая ветвь, мы нашли наш кей
    if pivot_index == k:
        return arr[pivot_index]

    # Вторая: pivot больше кей
    elif pivot_index > k:
        # Отрезаем правое пространство: ищем от low до pivot — k именно там.
        return quick_select(arr, low, pivot_index - 1, k)

    else:
    # Третья ветвь: pivot меньше кей
        # Отрезаем левое пространство
        return quick_select(arr, pivot_index + 1, high, k)

array = [64, 34, 25, 12, 22, 11, 90]
target_k = 2

result = quick_select(array, 0, len(array) - 1, target_k)
print(result) # 22