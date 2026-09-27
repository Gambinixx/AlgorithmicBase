def predicate(weights, capacity, d):
    days = 1

    total_load = 0
    for weight in weights:
        current_load = total_load + weight
        if current_load > capacity:
            days += 1

            # Делаем отрезок
            total_load = weight
        else:
            # Если укладываемся в объем, то докидываем ещё веса
            total_load += weight

    # Если укладываемся в дни:
    return days <= d

def bs_ship_capacity(weights, d_days):
    left, right = max(weights), sum(weights)
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2

        current_capacity = predicate(weights, mid, d_days)

        if current_capacity:
            safe = mid
            # если укладываемся в дни, уменьшаем объем
            right = mid - 1

        else:
            # не успели по дням, увеличиваем объем
            left = mid + 1

    return safe

weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
d_d = 5

print(bs_ship_capacity(weights, d_d))