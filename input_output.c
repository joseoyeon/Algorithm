#include <Stdio.h>

int main () {
  char a[10];
  char b[10];
	scanf("%s %s", &a, &b);
    int a1 = atoi(a);
  	int b1 = atoi(b);
    printf("%d", a1+b1);
return 0;
}