def solution(number, k):
    i=0
    while i<len(number)-1 and k>0:
        if number[i]<number[i+1]:
            number = number[:i]+number[i+1:]
            if i!=0:
                i-=1
            k-=1
        else:
            i+=1
    if k>0:
        return number[:-k]
    return number