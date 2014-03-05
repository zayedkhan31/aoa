#include<stdio.h>
#include<stdlib.h>

int my_random(){
    static long long a = 100011191;
    a = (a * 10003259 + 3223) % 2785 ;
    return (int) a * 3;
}

int play_match(int i, int j) {
    int win = my_random() % 10;
    if (win < 5) return i;
    else return j;
}

int simulate(int *players, int first, int last, int *prices) {
    int mid, i, j, k;
    if ((last - first) <= 0) {
        return first;
    }
    mid = first + (int) ((last - first) / 2);
    i = simulate(players, first, mid, prices);
    j = simulate(players, mid + 1, last, prices);
    k = play_match(i, j);
    if (i == k) {
        players[i]++;
        prices[i] += players[i] * 200;
        prices[j] += players[i] * 100;
    } else {
        players[j]++;
        prices[i] += players[i] * 100;
        prices[j] += players[i] * 200;
    }
    printf("Match between %d, %d\t winner %d\n", i, j, k);
    return k;
}

void simulate_tennis(int *players, int size, int *prices){
    int i;
    int winner = simulate(players, 0, size - 1, prices);
    printf("Winner is %d\n" , winner);
    printf("P\tM\t$\n");
    for(i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", i, players[i], prices[i]);
    }
}

void main() {
    int i = 0, j = 0;
    int players[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int price[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    simulate_tennis(players, 10, price);
}
