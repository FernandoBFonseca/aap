#include <stdio.h>
#include <math.h>

int main(void){
    
    const int n=5;
    printf("Finding for narcissistic numbers from 1 to %d\n", (int)pow(10, n) -1);

    for(int i=1; i<=n; i++){
        float min = pow(10, i-1);
        float max = pow(10, i) - 1;

        for(int num = min; num<=max; num++){
            float sum = 0;
            int x = num;
            
            while(x != 0){
                sum += pow(x%10, i);
                x /= 10;
            }
            if(sum == num){
                printf("%d\n", num);
            }
        }
    }
    
    return 0;
}