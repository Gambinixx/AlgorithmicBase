def bucket_sort(arr):
    if len(arr) == 0:
        return arr

    n = len(arr)

    # создаем карманы (вёдра)
    buckets = [[] for _ in range(n)]

    # Распихиваем дроби по вёдрам
    for num in arr:
        indx = int(num * n)

        buckets[indx].append(num)

    #
    arr_indx = 0
    for bucket in buckets:

        sort_bucket = sorted(bucket)

        # Оставлю этот кусок, чтобы отметить как динамика алгоритма искажается в моей памяти. Забавно...
        #for i in range(len(sort_bucket)):
        #    arr[i] = sort_bucket[i]
        #
        for num in sort_bucket:
            arr[arr_indx] = num
            arr_indx += 1

array = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21]
bucket_sort(array)
print(array)  # Должно вернуть строго: [0.17, 0.21, 0.26, 0.39, 0.72, 0.78, 0.94]