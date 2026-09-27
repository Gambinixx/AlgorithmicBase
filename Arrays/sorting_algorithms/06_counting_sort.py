def counting_sort(arr):
    max_val = max(arr)
    # создаем массив из нулей
    counts = [0] * (max_val + 1)

    for num in arr:
        counts[num] += 1

    indx = 0
    for i in range(len(counts)):

        while counts[i] > 0:
            arr[indx] = i
            indx += 1
            counts[i] -= 1

array = [4, 2, 2, 8, 3, 3, 1]
counting_sort(array)
print(array)  # Должно вернуть: [1, 2, 2, 3, 3, 4, 8]
