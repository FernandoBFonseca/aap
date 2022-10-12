#include <stdio.h>
#include <math.h>


int getSumDividers(int num){

    int x = num/2;
    float sum = 0;

    for(int i = x; i>0; i--){
        if(num%i ==0) sum +=i;
    }
    return sum;
}

int isFriend(int n, int m){

    return (n == getSumDividers(m)) && (m == getSumDividers(n));
}


int main(void){
    printf("Printing all friends:\n");
    int n = 284;
    for(int i = n; i>0; i--){
        int sum = getSumDividers(i);
        if (isFriend(i, sum)){
            printf("%d - %d\n", i, sum);
        }
    }
    


    return 0;
}