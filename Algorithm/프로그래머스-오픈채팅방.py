def solution(record):
    answer = []
    nicname = []
    dic_name = {}
    for file in record : 
        i = (file.split()) 
        if i[0] == "Enter" : 
            nicname.append([i[1]," 들어왔습니다."])
            dic_name[i[1]] = i[2]
        if i[0] == "Leave" :
            nicname.append([i[1]," 나갔습니다."])
        if i[0] == "Change" :
            dic_name[i[1]] = i[2]
    for key, value in  nicname: 
        answer.append(dic_name[key] + "님이" + value)
    return answer