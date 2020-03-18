#include <iostream>

using namespace std;

int main() {
    char A[1000];

    cin.getline(A,1000);

    for(int i=0 ; i<1000 && A[i] != 0; i++){
        if(A[i] <= 67) {A[i] = A[i] + 23;}
        else {A[i] -=3;}
        cout << A[i];
    }
    return 0;
}