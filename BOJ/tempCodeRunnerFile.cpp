
        printf ("%d -> %d -> %d\n", fibo2, fibo1, fibo2+fibo1);
        if (fibo1 < N && N <= fibo1 + fibo2){
            if(fibo1 == N) { 
                res = fibo2; break;} 
            else {
                res = (fibo2 + chi(N -fibo1)); break;} 
            } 
        }
    return res;
}

int main() {
    long long int n; 
    char str[100]; 
    scanf("%s", str);
    n = atoi(str);
    //printf ("input : %d\n", n);
    long long int res = chi(n);
    printf ("res : %d",res);
    return 0;
}