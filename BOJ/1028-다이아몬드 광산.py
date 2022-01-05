R,C = map(int, input().split())

DIA = []
for _ in range(R) :
    DIA.append(list(map(str, input())))

# 가장 큰 다이아 몬드가 될 수 있는 것 
dia_max = min(R,C)/2  + min(R,C)%2
tmp_max = 0
X, Y = 0,0

for j in range(dia_max) : # 깊이는 절반만 
    for i in range(R) : 
        if DIA[j][i] == "1" : 
            tmp_max = 1 
            # 이 때부터 깊이를 잰다. 
            while j <= C and i <= R :
                if DIA[]
    # 절반이 넘어가면 무조건 줄어드는 걸로 한다. 