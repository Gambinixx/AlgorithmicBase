def predicate(weights, max_load, k):
    # на сколько кусков надо разрезать массив чтобы распределить нагрузку и не превысить лимит
    chunks = 1

    # Сумма текущего чанка
    current_sum = 0

    for weight in weights:
        if current_sum + weight > max_load:
            chunks += 1
            current_sum = weight
        else:
            # если лимит для чанка не превышен просто докидываем ещё вес
            current_sum += weight

    # если мы уложились в текущую нагрузку на заданное количество рабочих возвращаем true
    return chunks <= k

def bs_min_max_load(weights, workers):
    # на одного рабочего минимум один самый тяжелый вес
    left = max(weights)
    # максимум на одного рабочего сумма всех весов
    right = sum(weights)

    safe = -1

    while left <= right:
        mid = left + (right - left) // 2

        current_load = predicate(weights, mid, workers)

        if current_load:
            safe = mid
            # это значит, что мы ещё не достигли минимума, и нужно уменьшить нагрузку
            right = mid - 1
        else:
            # нагрузка слишком маленькая - увеличиваем
            left = mid + 1

    return safe

weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k_workers = 5

print(bs_min_max_load(weights, k_workers)) # Должно вернуть 15
