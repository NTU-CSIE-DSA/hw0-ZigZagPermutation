#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int a[20];

int main(int argc, char* argv[]) {
  assert(argc > 4);
  registerGen(argc, argv, 1);
  int n = atoi(argv[1]);
  int l = atoi(argv[2]);
  int r = atoi(argv[3]);
  cout << n << '\n';
  for(int i = 0; i < n; i++) {
    a[i] = rnd.next(l, r);
    cout << a[i];
    cout << ((i < n - 1)? ' ':'\n');
  }
}
