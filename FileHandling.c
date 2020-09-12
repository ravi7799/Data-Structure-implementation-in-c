#include<stdio.h>
const long long int M=1000000007;

int main(){
    FILE* fout=fopen("InputToTime.txt","w");
    printf("Maximum value of long is :%d",__LONG_MAX__);
    fprintf(fout,"Number of Input \t Time taken in nano Seconds \n");
    for(long i=0;i<1000000;i++){
        if(i*i >= __LONG_MAX__){
            fprintf(fout,"%10d %20d\n",i,(i*i)%M);
        }else{
            fprintf(fout,"%10d %20d\n",i,i*i);
        } 
    }
    fclose(fout);
    return 0;
}