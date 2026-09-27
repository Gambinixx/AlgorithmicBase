# Структура для чтение бесконечного массива
class ArrayReader:
    def __init__(self, arr):
        self._arr = arr # получается просто параметр для работы с массивом

    # теперь метод для возвращения индекса с потока
    def get(self, index):
        if index >= len(self._arr):
            # если индекс вышел за рамки потока возвращаем бесконечность
            return float('inf')
        # возвращаем текущий индекс
        return self._arr[index]

def bs_infinite(reader, target):
    # Первый Этап — Экспоненциальный разгон (удвоение шага)
    left, right = 0, 1 # right пока на шаг впереди

    while reader.get(right) < target: # пока правая сторона строго меньше таргета.
        point_value = reader.get(right)
        # на этом этапе мы ищем диапазон в бесконечном потоке где находится таргет
        # Отрезаем левое пространство до точки right
        left = right
        # Теперь используем экспоненциальный разгон и увеличиваем пространство right в два раза
        right = right * 2 # хотя можно было бы использовать и более лаконичное right *= 2
    pass # когда диапазон с таргетом будет найден, обновленные границы уже будут хранится в left и right. Этот цикл нам больше не нужен

    # Теперь дело за малым, используем классический бинарный поиск
    while left <= right:
        mid = left + (right - left) // 2

        mid_point = reader.get(mid)

        if mid_point == target:
            return mid

        elif mid_point > target:
            right = mid - 1
        else:
            left = mid + 1
    return -1

inf_array = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29]

stream = ArrayReader(inf_array)

print(f"размер потока: {len(inf_array)}")

print(bs_infinite(stream, 100))