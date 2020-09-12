#include<stdio.h>

int Findmax(int a,int b,int c){
    if(a>b){
        if(a>c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b>c){
            return b;
        }else{
            return c;
        }
    }
}


int maxArea(int hist[],int n,int high,int low){
    if(high<low){
        return 0;
    }
    if(high==low){
        return hist[high];
    }else{
        int min=low;
        for(int j=low+1;j<=high;j++){
            if(hist[min]>hist[j]){
                min=j;
            }
        }
        return Findmax(hist[min]*(high-low+1),maxArea(hist,n,min-1,low),maxArea(hist,n,high,min+1));
    }
}

int main(){
    int n,i,j;
    int hist[10]={6,2,5,4,5,1,6};
    n=10;
    printf("Maximum area is= %d",maxArea(hist,n,n-1,0));
    return 0;
}