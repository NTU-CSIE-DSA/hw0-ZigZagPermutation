#include <bits/stdc++.h>

using namespace std;

int a[20];
int ans[200000][20];
int cur[20];
int num = 0;
bool used[20] = {};

void solve(int idx, int n) {
  if(idx == n) {
    for(int i = 0; i < n; i++) {
      ans[num][i] = cur[i];
    }
    num++;
    return;
  }
  int pre = -1;
  for(int i = 0; i < n; i++) {
    if(!used[i]) {
      if(pre != -1 && a[pre] == a[i]) continue;
      pre = i;
      if(idx < 2 || ((a[i] - cur[idx - 1]) * (cur[idx - 1] - cur[idx - 2]) < 0)) {
        cur[idx] = a[i];
        used[i] = true;
        solve(idx + 1, n);
        used[i] = false;
      }
    }
  }
}

signed main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 1; j < n; j++) {
      if(a[j - 1] > a[j]) {
        int tmp = a[j - 1];
        a[j - 1] = a[j];
        a[j] = tmp;
      }
    }
  }

  solve(0, n);
  cout << num << '\n';
  for(int i = 0; i < num; i++) {
    for(int j = 0; j < n; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
