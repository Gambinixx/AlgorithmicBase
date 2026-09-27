def bs_rotated(arr, target):
    left, right = 0, len(arr) - 1
    safe = -1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid

        if arr[left] <= arr[mid]:
            if arr[left] <= target <= arr[mid]:
                right = mid - 1
             
            else:
                left = mid + 1
                
        else: 
            if arr[mid] <= target <= arr[right]: 
                left = mid + 1 
             
            else: 
                right = mid - 1

    return safe



      

        

array = [7, 8, 9, 1, 2, 3, 4, 5, 6]
# left (7), mid (2), right (6)

print(bs_rotated(array, 8)) # Почему-то возвращает правильный индекс: 1

print(bs_rotated(array, 3)) # Возвращает 5й индекс

print(bs_rotated(array, 6)) 