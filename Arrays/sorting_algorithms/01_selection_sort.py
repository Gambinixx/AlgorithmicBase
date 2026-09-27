def selection_sort(arr):
    for slice in range(0, len(arr) - 1):
        min_index = slice

        # Получается тоже срез только слева направо. Интересно. Ты был прав. В пузырьковой сортировке ровно наооборот.
        for j in range(slice + 1, len(arr)):
            current_value = arr[j]
            min_value = arr[min_index]

            if current_value < min_value:
                min_index = j
        # у Selection Sort есть одно гигантское преимущество перед Bubble Sort: минимальное количество перезаписей в память (Writes).
        # Этим условием мы сэкономили не объём памяти (количество ячеек), 
        # а количество операций записи (CPU Cycles / Write Operations) в эту самую память.
        if min_index != slice:
            arr[slice], arr[min_index] = arr[min_index], arr[slice]

array = [64, 34, 25, 12, 22, 11, 90]

selection_sort(array)
print(array) # [11, 12, 22, 25, 34, 64, 90]

# Почему selection sort экономнее bubble sort?
# В компьютерном железе операция чтения (Read) из ячейки памяти выполняется очень быстро и не изнашивает структуру. 
# А вот операция записи (Write) — это физическое изменение состояния ячейки (подача напряжения на транзистор, 
# изменение заряда конденсатора или ячейки флеш-накопителя). 
# Запись всегда «дороже» по времени и по энергозатратам, чем чтение.
