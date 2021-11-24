from itertools import product

def solution(numbers, target):
    X = [1,-1]
    results =0 
    for x in product(X, repeat=len(numbers)) :
        result =0 
        for i in range(len(numbers)) : 
            result += x[i]*numbers[i]
        if result == target : 
            results += 1 
    
    return results

print(solution([1, 1, 1, 1, 1],	3))


#from itertools import product
#def solution(numbers, target):
#    l = [(x, -x) for x in numbers]
#    s = list(map(sum, product(*l)))
#    return s.count(target)