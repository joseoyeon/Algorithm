#include<stdio.h>
#include<math.h>
#define DOT_NUM 16

double min(double a, double b) {return a<=b? a : b;}

double distance(int dot[][DOT_NUM],int left, int right){
return sqrt((dot[0][right]-dot[0][left])*(dot[0][right]-dot[0][left])+
                    (dot[1][right]-dot[1][left])*(dot[1][right]-dot[1][left]));
}

double ClosestPair(int dot[][DOT_NUM],int left, int right,int size){
    double CP[2]={};
    if(size ==2) {return distance(dot, left, right);}
    if(size==3) {return min(distance(dot, left, right),min(distance(dot, left, left+1), distance(dot,right-1,right)));} // if dot number is 2 or 3, return min distance

// if size is not 2 or 3
    CP[0]= ClosestPair(dot,left,left+size/2,size/2);
    CP[1]= ClosestPair(dot,left+size/2,right, right-left-size/2);
//how merge???
}
    
int main() {
    int dot[2][DOT_NUM] = {
    {1,5,6,7,8,8,9,10,10,15,16, 17, 20, 20, 22, 30},
    {1,1,1,12,15,8,7,10,15,9,11,13,14,3,4,9}
    };
     printf("%0.f\n",ClosestPair(dot, 0, 2,3));
    return 0;
}