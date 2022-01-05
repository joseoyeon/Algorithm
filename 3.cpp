#include<iostream>
using namespace std;

int main()
{
    int N = 0; //2 ~ 10000
    int T = 0;

    cin >> T;
    for (int x = 0; x < T; x++){
        int map[100001];
        int answer_map[100001];
        int answer = 0;
        int des = 0;
        int rest_pos = -1;       // 휴게소 위치
        int hotel_pos = -1;      // 숙박소 위치
        int car_distance = 0;    // 한번에 달린 거리
        int oneday_distance = 0; // 하루 동안 달린 거리

        cin >> N;
        // 입력
        for (int j = 0; j < N; j++)
        {
            cin >> map[j];
            if (map[j] == 3){
                des = j; // 가장 마지막에 있는 캠핑장은 목적지
            }
        }
        cout << des << endl; 
        answer = des;
        int pos=0;
        // 캠핑차 타고 이동하기
        while(pos < des){   
            pos ++; 
            answer_map[pos] = 1;  //
            car_distance += 1;    // 차로 안쉬고 달린 거리
            oneday_distance += 1; // 하루에 달린 거리

            if (map[pos] == 2){                   // 휴게소
                rest_pos = pos; // 지나친 휴게소로 저장
            }
            if (map[pos] == 3){
                hotel_pos = pos; // 지나친 숙박으로 가기
            }

            if (car_distance ==6){   
                if (hotel_pos == -1 && rest_pos == -1) { 
                    answer = -1 ;
                    break;
                }
                //차를 타고 한번에 이동하는 시간 <= 6
                if (rest_pos != -1 && (hotel_pos-rest_pos) != 1 ){ //
                    oneday_distance -= (pos-rest_pos);
                    pos = rest_pos;      
                    rest_pos = -1;        // 다시 동일한 휴게소를 가지 않는다.
                    answer_map[pos] =2 ; // 휴게소 가서 한시간 쉰거
                    car_distance = 0;     // 한번에 간 거리 초기화
                }else{
                    pos = hotel_pos;     // 휴게소가 없으면 쉰다.
                    hotel_pos = -1;      // 다시 동일한 호텔로 가지 않는다.
                    answer_map[pos] =3 ;
                    car_distance = 0;    // 한번에 간 거리 초기화
                    oneday_distance = 0; // 하루동안 간 거리 초기화
                    // 만약 3 이전에 car 거리 늘리려고 방문한 곳이 있다면 1로 초기화 해준다. 
                    bool set_bit = false; 
                    for (int q = pos-4; q<pos; q++) {
                        if (answer_map[q] != 1) {set_bit = true;}
                        if (set_bit) {
                            if (answer_map[q] != 1) {answer_map[q] = 1; }
                        }
                    }
                }
            }
            if (oneday_distance == 15)
            {                  
                if (hotel_pos == -1) {
                    answer = -1 ;
                    break;
            }      //
                pos = hotel_pos;     // 지나쳤던 최근 호텔에 간다.
                hotel_pos = -1;      // 다시 동일한 호텔로 가지 않는다.
                answer_map[pos] =3 ; // 휴게소 가서 한시간 쉰거
                car_distance = 0;    // 한번에 간 거리 초기화
                oneday_distance = 0; // 하루동안 간 거리 초기화
            }
        }

        if (answer != -1 ) { 
        /// answer map 의 거리를 모두 더한다.
            for (int k = 0; k < N; k++)
            {
                if (answer_map[k] == 2) {
                    answer += 1;
                }
                cout << answer_map[k] << " "; 
            }
        }else{
            for (int k = 0; k < N; k++)
            {
                cout << answer_map[k] << " "; 
            }

        }
        cout << endl; 
        cout << "#" << x + 1 << " " << answer << endl;
    }
return 0;
}