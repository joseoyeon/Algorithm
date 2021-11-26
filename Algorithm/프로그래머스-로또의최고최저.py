def solution(lottos, win_nums):
    zero, same = 0,0
    for i in lottos : 
        if i == 0 : 
            zero += 1
        if i in win_nums : 
            same += 1 
    if zero == 6 : 
        same = 1
        zero = 5
    if same == 0 and zero == 0 : 
        same = 1
    return [7-(same+zero),7-same]