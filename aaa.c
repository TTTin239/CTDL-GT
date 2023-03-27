#include<conio.h>
#include<stdio.h>

void main(){
    int i=0,s=1;
    do
    {
        if(i %4 != 0){
           s+=i+5;
        }
        i+=2;      
    } while (i<8);
    printf("%d ", s);
    getch();
}