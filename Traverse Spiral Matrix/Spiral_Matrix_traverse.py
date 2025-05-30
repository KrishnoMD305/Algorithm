from typing import List

def spiralOrder(matrix: List[List[int]]) -> List[int]:
    result = []
    top,bot = 0,len(matrix)-1
    l,r = 0,len(matrix[0])-1

    while top<=bot and l<=r:
        for i in range(l,r+1):
            result.append(matrix[top][i])
        top += 1

        for i in range(top,bot+1):
            result.append(matrix[i][r])
        r -= 1

        if top<=bot:
            for i in range(r,l-1,-1):
                result.append(matrix[bot][i])
            bot -= 1

        if l<=r:
            for i in range(bot,top-1,-1):
                result.append(matrix[i][l])
            l += 1

    return result
