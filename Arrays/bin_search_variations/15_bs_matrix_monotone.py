def find_mono_matrix(matrix, target):
    row, col = 0, len(matrix[0]) - 1

    while row < len(matrix) and col >= 0:

        point = matrix[row][col]

        if point == target:
            return (row, col)

        elif point > target:
            # если наш поинт больше таргет, то колонна справа нам больше не нужна (все числа в ней точно больше таргета)
            col -= 1 # отрезаем правую колонну
        else:
            # соответственно если поинт меньше...
            row += 1 # отрезаем верхний ряд
    return -1


mono_matrix = [
    [1, 4, 7, 11], 
    [2, 5, 8, 12], 
    [3, 6, 9, 16], 
    [10, 13, 14, 17]
]

targ = 5

print(find_mono_matrix(mono_matrix, 20))