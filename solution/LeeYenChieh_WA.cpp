#include <stdio.h>
#include <stdlib.h>


typedef struct nnn{
    int cnt;
    int val;
}Number;


int n, array[32] = {}, num_size = 0;
Number number[32];

void init(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",&array[i]);
    for(int i = n - 1;i > 0;i--)
        for(int j = 0;j < i;j++)
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
    int prev = array[0], cnt = 0;
    for(int i = 0;i < n;i++){
        if(prev == array[i])
            cnt += 1;
        else{
            number[num_size].cnt = cnt;
            number[num_size].val = prev;
            num_size += 1;
            prev = array[i];
            cnt = 1;
        }
    }
    number[num_size].cnt = cnt;
    number[num_size].val = prev;
    num_size += 1;
    return;
}

int zigzag[200000][32], zigzag_cnt = 0, curarray[32] = {};
void find_all_zigzag(int level){
    if(level == n){
        for(int i = 0;i < n;i++)
            zigzag[zigzag_cnt][i] = curarray[i];
        zigzag_cnt += 1;
        return;
    }
    for(int i = 0;i < num_size;i++){
        if(number[i].cnt == 0)
            continue;
        if(level < 2 || (curarray[level - 1] - curarray[level - 2]) * (number[i].val - curarray[level - 1]) < 0){
            curarray[level] = number[i].val;
            number[i].cnt --;
            find_all_zigzag(level + 1);
            number[i].cnt ++;
        }
    }
    return;
}


signed main(void){
    init();
    find_all_zigzag(0);
    if(zigzag_cnt == 0)
        zigzag_cnt = -1;
    printf("%d\n", zigzag_cnt);
    for(int i = 0;i < zigzag_cnt;i++){
        for(int j = 0;j < n;j++)
            printf("%d ", zigzag[i][j]);
        printf("\n");
    }
}