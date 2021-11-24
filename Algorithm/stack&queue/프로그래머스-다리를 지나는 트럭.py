def solution(bridge_length, weight, truck_weights):
    timer = 0
    completed = []
    in_bridge = [0] * bridge_length
    size = len(truck_weights)
    while len(completed) < size:
        timer += 1
        top = in_bridge.pop(0)
        if top != 0:
            completed.append(top)
        if len(truck_weights) > 0: 
            if sum(in_bridge) + truck_weights[0] <= weight:
                in_bridge.append(truck_weights.pop(0))
            else:
                in_bridge.append(0)
    return timer
print(solution(100,	100,	[10,10,10,10,10,10,10,10,10,10]))