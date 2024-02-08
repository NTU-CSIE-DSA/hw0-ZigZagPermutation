#include "testlib.h"
#include <cassert>

int a[20];

int main(int argc, char* argv[]) {
  assert(argc > 4);
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int l = atoi(argv[2]);
  int r = atoi(argv[3]);
  assert(l <= r);
  int x, y;
  if(rnd.next(0, 1) == 0) {
    x = l;
    y = r;
  }
  else {
    x = rnd.next(l, r);
    y = rnd.next(l, r);
  }
  printf("%d\n", n);
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    int type = rnd.next(0, 2);
    if(type == 0) {
      a[i] = rnd.next(l, r);
      cnt++;
      if(cnt > 4) {
        type = rnd.next(0, 1) + 1;
      }
    }
    if(type == 1) {
      a[i] = x;
    }
    if(type == 2) {
      a[i] = y;
    }
    printf("%d", a[i]);
    if(i == n - 1) printf("\n");
    else printf(" ");
  }
}
