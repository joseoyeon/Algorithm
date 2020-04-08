# include<stdio.h>

int fibo (int n) {
    int i, f1 =1, f2 =1, f3;
    if(n<=2) {return 1;}
    for (i =3; i<=n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int main() {
    int a[100];
    int num;

    scanf("%d",&num);

    for (int i=0; i<num; i++) {
        scanf("%d", &a[i]);
        a[i] = fibo(a[i]);
    }

    for (int i = 0; i<num; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}