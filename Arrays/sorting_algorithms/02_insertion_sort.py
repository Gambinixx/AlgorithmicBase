def insertion_sort(arr):
    # одиночный нулевой индекс сам по себе уже считается отсортированным
    for i in range(1, len(arr)):
        current_key = arr[i]

        #стартуем строго слева от текущего i
        j = i - 1
        while j >= 0:
            current_element = arr[j]
            if current_element > current_key:
                # сдвигаем элемент вправо
                arr[j + 1] = arr[j]
            else: # current_element < current_key (например 12 и 22)
                break
                # Мы обрываем цикл на текущем j, и на выходе из цикла сразу же записываем наш key (22) на пустое место впереди 12 = j + 1
            j -= 1
        arr[j + 1] = current_key
        

array = [64, 34, 25, 12, 22, 11, 90]

insertion_sort(array)
print(array) # Должно вернуть: [11, 12, 22, 25, 34, 64, 90]
