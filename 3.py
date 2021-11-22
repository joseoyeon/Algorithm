import math 

def solution(fees, records):
    car_data = []
    answer = []
    for data in records : 
        car_data.append(data.split()) # _time, number, IO
    
    car_number_ = set([x[1] for x in car_data])
    car_number = dict([(key,[]) for key in car_number_])

    for data in car_data : 
        car_number[data[1]].append([data[0], data[2] ])
    
    # 각 자동차 별로 요금 계산하기 
    for car in sorted(car_number.keys()) : 
        iorecord = car_number[car]
        car_fee =0
        _time =0 

        for i in range(len(iorecord)//2) :
            OUT_time = iorecord[i*2+1][0].split(':')
            IN_time = iorecord[i*2][0].split(':')
            _time += (int(OUT_time[0]) - int(IN_time[0]))*60 + (int(OUT_time[1]) - int(IN_time[1]))          

        if(len(iorecord)%2) : 
            IN_time = iorecord[-1][0].split(':')
            _time += (23 - int(IN_time[0]))*60 + (59 - int(IN_time[1]))
       
        if _time > fees[0] :
            car_fee = fees[1] + math.ceil((_time - fees[0])/fees[2]) * fees[3]
        else : 
            car_fee = fees[1]

        answer.append(car_fee)
    return answer