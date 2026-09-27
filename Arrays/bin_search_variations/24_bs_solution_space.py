def predicate(positions, dist, k):
    # первый объект на первую позицию
    obj = 1
    # координата последнего поставленного объекта
    last_pos = positions[0]

    for i in range(1, len(positions)):
        current_pos = positions[i]

        if current_pos - last_pos >= dist:
            # cтавим объект
            obj += 1

            # обновляем последнюю точку
            last_pos = positions[i]

    # Если смогли раставить k или больше объектов
    return obj >= k

def bs_max_min_dist(pos, k_obj):
    left = 1
    right = max(pos) - min(pos)
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2

        current_dist = predicate(pos, mid, k_obj)

        if current_dist:
            safe = mid

            # ищем максимально возможное растояние
            left = mid + 1
        else:
            # если не получилось уместить объекты, значит укорачиваем дистанцию (нашу виртуальную шкалу с mid)    
            right = mid - 1

    return safe

# Массив координат (места)
positions = [1, 2, 4, 8, 9]
k_objects = 3 # максимально возможное значение (дистанция) для трёх объектов при девяти позициях: 3

print(bs_max_min_dist(positions, k_objects)) # Должно вернуть 3
