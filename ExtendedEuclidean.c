#include<stdio.h>

int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 

    *x = y1 - (b/a) * x1; 
    *y = x1; 
    printf("here a = %d and b= %d \n", a,b);
    printf("Value of x1= %d and y1= %d \n",*x,*y);

    return gcd; 
} 
int main(){
    int x,y;
    printf("GCD of number 81 and 57 is: %d" , gcdExtended(81,57,&x,&y));
    return 0;
}