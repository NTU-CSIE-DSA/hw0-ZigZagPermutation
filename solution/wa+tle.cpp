#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[20];
int ans[200000][20];
int cur[20];
int num = 0;
bool used[20] = {};

void solve(int idx, int n) {
  if(idx == n) {
    bool valid = false;
    for(int i = 0; i < n; i++) {
      if(i >= 2 && ((cur[i] - cur[i - 1]) * (cur[i - 1] - cur[i - 2]) >= 0)) {
        return;
      }
      if(num == 0 || ans[num - 1][i] != cur[i]) {
        valid = true;
      }
      ans[num][i] = cur[i];
    }
    if(valid) num++;
    return;
  }
  for(int i = 0; i < n; i++) {
    if(!used[i]) {
      cur[idx] = a[i];
      used[i] = true;
      solve(idx + 1, n);
      used[i] = false;
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
  if(num == 0) cout << "-1\n";
  else {
    cout << num << '\n';
    for(int i = 0; i < num; i++) {
      for(int j = 0; j < n; j++) {
        cout << ans[i][j] << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}
