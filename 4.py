def solution(n, info):
    answer_point = 0 
    answer_list = [0]*11

    add_point = [i+1 for i in info]
    ap = sum([(10-i) for i in range(11) if info[i] >0])
    
    for i in range(11) : 
        tmp,n_,ap_ =0,n,ap
        tmp_list = [0]*11
        while(n_ >0 and i <11)  :
            if (n_ >= add_point[i]) : 
                tmp_list[i] = add_point[i]
                n_ -= add_point[i]
                tmp += (10-i)
                if add_point[i] >1 : 
                    ap_ -= (10-i)
            i += 1
            if tmp > answer_point and tmp > ap_ :
                if n_ != 0 : 
                    answer_list[-1] = n_
                answer_list = tmp_list
                answer_point = tmp

    if answer_point ==0 : 
        return [-1]
    return answer_list

print(solution(	9, [0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1]))