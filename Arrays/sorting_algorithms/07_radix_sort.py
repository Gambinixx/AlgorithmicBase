def counting_sort_for_radix(arr, exp):
    n = len(arr)

    output = [0] * n
    counts = [0] * 10

    for num in arr:
        digit = (num // exp) % 10

        counts[digit] += 1

    # Прием из prefix sum
    for i in range(1, 10):
        # текущи элемент плюс предыдущий
        counts[i] += counts[i - 1]

    # Добавляем в output
    # С конца, до минус одного, с шагом минус один на каждой итерации
    for i in range(n - 1, -1, -1):
        # num это текущий элемент в массиве
        num = arr[i]

        digit = (num // exp) % 10

        insert_point = counts[digit]

        output[insert_point - 1] = num

        # убираем единицу из счётчика
        counts[digit] -= 1

    # Переписываем массив: элементы по возрастанию разрядов (сначала единицы, при следующем вызове десятки, при третьем вызове — сотни)
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    # Сразу проверяем размер массива
    if len(arr) <= 0:
        return

    # находим максимальное значение
    max_value = max(arr)

    # наши разряды
    exp = 1
    while max_value // exp > 0:
        counting_sort_for_radix(arr, exp)
        # меняем разряд
        exp *= 10

array = [170, 45, 75, 90, 802, 24, 2, 66]
radix_sort(array)
print(array)  # Должно вернуть: [2, 24, 45, 66, 75, 90, 170, 802]
