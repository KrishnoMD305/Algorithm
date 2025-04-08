def isSorted(v:list,n:int) ->bool:
    if n==0 or n==1:
        return True
    return v[n-1]>=v[n-2] and isSorted(v,n-1)
