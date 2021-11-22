def solution(people, limit):
    people.sort() 
    a, b = 0, len(people)-1
    while(b > a) :
        if limit >= people[a] + people[b] :
            a += 1
        b -= 1
    return len(people) - a