# монотонный "чёрный ящик"
# rps — показатель нагрузки на сервер
def server_predicate(rps): # наш mid на виртуальной шкале
    critical_threshold = 42
    # Нагрузка в пределах нормы — True
    return rps <= critical_threshold

def bs_find_mono(low, high):
    #генерируем тестовый срез состояний чтобы убедиться что полученный график монотонный
    test_slice = list(range(35, 50))
    graph = [server_predicate(x) for x in test_slice]
    print(f"Тестовый срез графика: {graph}")

    left, right = low, high
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2

        answer = server_predicate(mid)

        if answer:
            safe = mid
            left = mid + 1
        else:
            # выпрыгнули за лимит, укорачиваем правую сторону виртуального отрезка
            right = mid - 1

    return safe # возвращаем максимально допустимое стабильное значение перед падением в False

# Тест-драйв: диапазон нагрузки от 0 до 1000 запросов в секунду
print(f"Максимальная стабильная нагрузка: {bs_find_mono(0, 1000)}")
# Должно вернуть 42