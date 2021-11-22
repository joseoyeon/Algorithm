def solution(n, lost, reserve):
    tmp_lost = list(set(lost) - set(reserve))
    tmp_reverse = list(set(reserve) - set(lost))
    answer = n
    
    for loster in tmp_lost :
        if loster-1 in tmp_reverse : 
            tmp_reverse.remove(loster-1)
        elif loster+1 in tmp_reverse :
            tmp_reverse.remove(loster+1)
        else :
            answer -= 1 
            
    return answer