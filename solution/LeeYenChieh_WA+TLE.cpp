#include <stdio.h>
#include <stdlib.h>


// subtask 1: WA => unable to delete repeat completely 
// subtask 2: TLE

#define int long long

int n, number[32];

void init(){
    scanf("%lld", &n);
    for(int i = 0;i < n;i++)
        scanf("%lld", &number[i]);
    for(int i = n - 1;i > 0;i--)
        for(int j = 0;j < i;j++)
            if(number[j] > number[j + 1]){
                int temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
}

int zigzag[200000][32], zigzag_cnt = 0, curarray[32] = {}, used[32] = {};
void find_all_zigzag(int level){
    if(level == n){
        int repeat = 1;
        for(int i = 0;i < n;i++){
            zigzag[zigzag_cnt][i] = curarray[i];
            if(zigzag_cnt == 0 || zigzag[zigzag_cnt][i] != zigzag[zigzag_cnt - 1][i])
                repeat = 0;
        }
        if(repeat == 0)
            zigzag_cnt += 1;
    }
    for(int i = 0;i < n;i++){
        if(used[i] == 1)
            continue;
        if(level < 2 || (curarray[level - 1] - curarray[level - 2]) * (number[i] - curarray[level - 1]) < 0){
            used[i] = 1;
            curarray[level] = number[i];
            find_all_zigzag(level + 1);
            used[i] = 0;
        }
    }
}

signed main(void){
    init();
    find_all_zigzag(0);
    if(zigzag_cnt == 0)
        zigzag_cnt = -1;
    printf("%lld\n", zigzag_cnt);
    for(int i = 0;i < zigzag_cnt;i++){
        for(int j = 0;j < n;j++)
            printf("%lld ", zigzag[i][j]);
        printf("\n");
    }
}