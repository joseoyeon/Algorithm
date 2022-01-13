#include<iostream>
using namespace std;

void quick_sort(int *data, int start, int end) {
    if(start >= end) {
    //원소가 1개인 경우
    return;
    }
    
    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp = 0;
    
    while(i <= j){
        while(i<= end && data[i] <= data[pivot]){
            i++;
        }
        while(j > start && data[j] >= data[pivot]){
            j--;
        }
        
        if (i > j) {
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    quick_sort(data, start, j-1);
    quick_sort(data, j+1, end);
}

int main(void) {
 int T = 0;
 int N = 0;
 int cards_odd[10001];
 int cards_odd_len =0 ; //홀수 
 int cards_even[10001];
 int cards_even_len =0 ; // 짝수
 int answer =0;
 int tmp_input =0;

 cin >> T;
 for(int i=0; i<T; i++) {
    cin >> N;
    answer = 0; 
    cards_odd_len =0 ; //홀수 
    cards_even_len =0 ; // 짝수

    // 카드 입력 
    for(int x =0; x<N; x++) {
        cin >> tmp_input;
        if (tmp_input % 2 == 1) {//홀수 
            cards_odd[cards_odd_len] = tmp_input;
            cards_odd_len += 1;
        } else {// 짝수
            cards_even[cards_even_len] = tmp_input;
            cards_even_len += 1;
        }
    }
    
    quick_sort(cards_odd,0,cards_odd_len-1);
    quick_sort(cards_even,0,cards_even_len-1);

    for(int odd = ((cards_odd_len+1)/2); odd < cards_odd_len ; odd++) {
        answer += cards_odd[odd];
    }
    for(int even = ((cards_even_len+1)/2); even < cards_even_len ; even++) {
        answer += cards_even[even];
    }

    if (cards_odd_len % 2 == 1){ //카드의 개수는 짝수 이므로 하나가 짝수면 나머지 한쪽도 짝수다.  
        //무조건 마지막에 홀/짝 두개가 남는 경우에는 작은 쪽을 택해야 한다. 
        if (cards_odd[(cards_odd_len-1)/2] < cards_even[(cards_even_len-1)/2]) {
            answer += cards_odd[(cards_odd_len-1)/2];
        }else {
            answer += cards_even[(cards_even_len-1)/2];
            }
        }
    
    ///////////////////////////////////
    cout << "#" << i+1 << " " << answer << endl;
    // 그 다음에 answer에다가 더해주고 고른 수를 -1 취급한다
 }
return 0;
}