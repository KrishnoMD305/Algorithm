def isSorted(v:list) ->bool:
    for i in range(1,len(v)):
        if v[i]<v[i-1]:
            return False
    return True
