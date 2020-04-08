# include<stdio.h>
# include<stdlib.h>
int main() {
    int a[4097];
    int b[4097];
    int num ;
    int tmp;
    char Res[4098];
    char res [4098];
    int carry = 0 ;
    char s;

    scanf("%d",&num);
    for (int i=0; i<num; i++) {scanf("%1d",&a[i]); }//printf("input a : %d, %d\n", i, a[i]);}
    for (int i=0; i<num; i++) {scanf("%1d",&b[i]); }//printf("input b : %d, %d\n", i, b[i]);}

    for (int i=num-1; i>=0; i--) {
        tmp = (a[i] + b[i] + carry);
        Res[i+1] = tmp%10;
        if (tmp >= 10){carry = 1;}
        else  {carry =0;}
       //printf("%d\n",i);
    }
    
    if(carry == 1) {Res[0] = 1; s = 0;}
    else {Res[0] =0; s=1;}
    for (int i = 0 +s; i <=num; i++) {
    printf("%d", Res[i]);
        //res[i] = Res[i] + 48;
    }
    // if (res[num] == 48) res[num] =0;
    //     printf("%s", res);
    return 0;
}