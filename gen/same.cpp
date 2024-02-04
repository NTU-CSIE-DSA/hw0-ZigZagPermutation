#include "testlib.h"
#include <cassert>

int main(int argc, char* argv[]) {
    assert(argc > 3);
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int R = atoi(argv[3]);
    printf("%d %d\n", N, M);
    for(int i = 0; i < N; i++) {
        printf("%d", R);
        if(i == N-1) printf("\n");
        else printf(" ");
    }
}
