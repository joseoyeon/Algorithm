# include<stdio.h>

int main() {
    int a[4097];
    int b[4097];
    int num ;
    int tmp;
    char Res[4098];
    char res [4098];
    int carry = 0 ;

    scanf("%d",&num);
    for (int i=0; i<num; i++) {scanf("%1d",&a[i]);}
    for (int i=0; i<num; i++) {scanf("%1d",&b[i]);}

    for (int i=num-1; i>=0; i--) {
        tmp = (a[i] + b[i] + carry);
        Res[i+1] = tmp%10;
        if (tmp >= 10){carry = 1;}
        else  {carry =0;}
    }
    
    if(carry == 1) {Res[0] = 1;}
    //for (int i = 0; i <=num; i++) {printf(res, "%d", Res);}
    printf("%s", *Res);
    return 0;
}