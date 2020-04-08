
    printf("%s\n", a);
    for (int i=0; i<num; i++) {
        scanf("%d", &b[i]);
    }
    
    for (int i=num-1; i>=0; i--) {
        Res[i] = (a[i] + b[i] + carry) %10;
        if ((a[i] + b[i] + carry) > 10){
            carry = 1;
        }
    }
    
    for (int i = 0; i<num; i++) {
        printf("%d", Res[i]);
    }
    return 0;
}