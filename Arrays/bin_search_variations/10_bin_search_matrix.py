def bs_matrix(matrix, target):

    # находим количества рядов и столбцов
    # со столбцами чуть сложнее. Мы берем первый массив по индексу 0, и смотрим его размер — это и будет колчество столбцов матрицы
    rows, cols = len(matrix), len(matrix[0]) 
    grid = rows * cols # получаем размер всей сетки
    left, right = 0, grid - 1

    while left <= right:
        mid = left + (right - left) // 2 # делим всю сетку на пополам

        # как получить номер ряда?
        row = mid // cols 

        # как получить номер столбца?
        col = mid % cols

        inter_point = matrix[row][col]

        if inter_point == target:
            return f"intersection: {row, col}" # а что возвращать то?.. row col??

        elif inter_point > target:
            # по классике отрезаем пространство справа от mid?
            right = mid - 1
        else:
            left = mid + 1

    return -1

matrix = [
    [2, 3, 10, 15], # intersection: 0, 1
    [23, 30, 34, 60],
    [67, 70, 75, 80],
    [84, 87, 90, 95]
]

print(bs_matrix(matrix, 95))