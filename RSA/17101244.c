#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>


int main(void)
{
    unsigned long long plain=1;
    unsigned long long cipher = 132637;
    int p =547;
    int q =593;
    int e =17;
    unsigned long long n = p*q;
    int d;
    int dq =546*592;

    // d를 구해야 하는데 역원을 구해야 한다.
    // 역원은 n을 법으로하는 데서 17의 역원을 구해야 함
    for (int i =0 ; i<(dq); i++){
        if((17*i)%dq == 1) {d=i; break;}
    }
   
    printf("d: %ul\n",d);

    //d : 101 1110 1010 0010
    // d : cipher * cipher mod n, *
    printf("cipher : %u\n", cipher);
    for (int i=0 ; i<d; i++) {
        plain *= cipher;
        plain = plain % n;    
    }
    printf("plain : %u\n", plain);

   return 0;
}