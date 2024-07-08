#include <stdio.h>
#include <stdlib.h>

int findWinner(int n,int k){
    int winner=0;

    for (int i = 1; i <= n; i++) {
        winner = (winner + k) % i;
    }

    return winner + 1;
}

int main(void){
    int answer = findWinner(5,2);
    printf("%d",answer);

    int wait;
    scanf("%d",&wait);

    return 0;
}
