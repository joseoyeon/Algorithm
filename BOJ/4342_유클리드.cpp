#include <stdio.h>

int gcd (int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void swap (int &a, int &b) {
    int tmp =a;
    a = b;
    b = tmp;
}

int main() {
    int A[1000000000];
    int B[1000000000];
    int A1, A2;
    char end = 0; 

    int i=0;
   while(true){
        scanf("%d %d", &A[i], &B[i]);
        if(A[i] == 0 && B[i] == 0) {break;}
        i++;
    }
    //printf ("input : %d\n", i);

    for (int j=0; j<i; j++){
        A1 = A[j]; A2 = B[j];
        while(true) {
            if(A1 < A2) swap(A1,A2);

            A1 = A1 % A2;
            //printf("%d %d\n",A1, A2);
            if(A1 == 0) {end = 1; break;}

            if(A1 < A2) swap(A1,A2);
            A1 = A1 % A2;
            //printf("%d %d\n",A1, A2);
            if(A1 == 0) {end = 2; break;}
        }

        if(end == 1) {printf("A wins\n");}
        if(end == 2) {printf("B wins\n");}
    }
    return 0;
}