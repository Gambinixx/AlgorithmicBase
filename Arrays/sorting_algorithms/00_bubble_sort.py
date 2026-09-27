# Блок 1. Квадратичная база (Простые сортировки)
def bubble_sort(arr):

    # slice - текущий срез, количество элементов, которые уже отсортированы в конце массива
    for slice in range(0, len(arr) - 1):
        swapped = False

        for j in range(0, len(arr) - slice - 1):
            current = arr[j]
            next = arr[j + 1]

            if current > next:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

                swapped = True

        # если не было свапа, значит массив уже отсортирован
        if not swapped:
            break

array = [64, 34, 25, 12, 22, 11, 90]

bubble_sort(array)
# Массив изменяется прямо на месте (in-place). 
# Терминал должен вывести идеальный порядок: [11, 12, 22, 25, 34, 64, 90]
print(array)
