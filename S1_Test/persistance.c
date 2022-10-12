#include <stdio.h>
#include <math.h>


int getPersistance(int num){

    int couter = 0;
    float old_num;
    while(num){
        
        float prod = 1;
        int x = num;
        while(x){
            prod *= x%10;
            x /= 10;
        }
        old_num = num;
        num = prod;
        if (num == old_num) return couter;
        couter++;
    }

    return couter;
}

int getLowestPersistance(int n){
    int i = 10;
    while(1){

        if(getPersistance(i)==n)return i;
        else i++; 
        
    }
}


int main(void){
    
    const int num = 67;

    printf("The persistence of %d is %d\n\n", num, getPersistance(num));

    const int n = 5;
    
    for(int i=1; i<=n;i++){
        printf("for n = %d, the lowest we have %d\n", i, getLowestPersistance(i));
    }
    return 0;
}