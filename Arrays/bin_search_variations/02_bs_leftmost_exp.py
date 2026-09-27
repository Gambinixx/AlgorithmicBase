def find_left_ocurrennce(arr, target):
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2

        if target == arr[mid]: # когда первым ставишь таргет, визуализация ломается. Первым всегда должен стоять "найденный элемент", потому что он динамичный в воображении, а таргет всегда статичен

            safe = mid

            right = mid - 1

        elif target > arr[mid]: # тоже самое — сбивает визуализацию и путает манипуляцию с пространством
            right = mid - 1
        else:
            left = mid + 1

    return safe

array = [1, 3, 5, 5, 6, 6, 8, 8, 9, 11] # как отработает логика алгоритма если таргет вообще не будет найден?
print(find_left_ocurrennce(array, 7))

array = [7, 7, 7, 7, 7, 7, 7, 7]
print(find_left_ocurrennce(array, 7)) # как отработает логика с массивом из сплошных дубликатов таргет?
