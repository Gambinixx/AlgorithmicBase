def bs_leftmost(arr, target):
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2
        blue_point = arr[mid]

        if blue_point == target:
            safe = mid
            right = mid - 1

        if blue_point >= target:
            right = mid - 1
        else:
            left = mid + 1
    return safe


array = [1, 3, 5, 5, 6, 7, 7, 7, 9, 11]

print(bs_leftmost(array, 7))