def heapify(arr, n, i):
    # Наибольший поумолчанию
    largest = i

    # определяем потомков через формулу
    left = 2 * i + 1
    right = 2 * i + 2

    # Находим наибольший элемент и незабываем проверить на index out of range
    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Предохранитель, проверяем изменился ли largest
    if largest != i:
        # меняем местами текущий i и largest (выдвигаем наибольший элемент в начало)
        arr[i], arr[largest] = arr[largest], arr[i]
        # запрыгиваем дальше, работая с измененным largest
        heapify(arr, n, largest)

def heap_sort(arr):
    # находим длину
    n = len(arr)

    # создаем кучу
    # берем отрезок посередине, начинаем с его конца, движемся до минус одного, с шагом в минус один
    for i in range(n // 2 - 1, -1, -1):
        # в конце цикла выдвигаем самый большой элемент на ноль
        heapify(arr, n, i)

    # с нулевого индекса забрасываем элементы в правую отсортированную часть, 
    # постепенно сужаем левую неотсортированную половину, вплоть до нуля
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        # всегда сортируем начиная с нулевого индекса, и не забываем сужать пространство через i
        heapify(arr, i, 0)

array = [64, 34, 25, 12, 22, 11, 90]
heap_sort(array)
print(array)