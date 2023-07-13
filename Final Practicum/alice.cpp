#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdio>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k; cin >> n >> k;
  ll a[n];
  vector<unordered_map<int, int>> mod(11);

  ll pow10[11];
  pow10[0] = 1;
  for(int i=1; i<11; i++) pow10[i] = pow10[i-1] * 10 % k;

  for(int i=0; i<11; i++){
    mod[i].reserve(2e5+1);
  }

  for(int i=0; i<n; i++) {
    cin >> a[i];
    for(int j=0; j<11; j++){
      mod[j][a[i] * pow10[j] % k]++;
    }
  }
  
  ll ans = 0;
  for(int i=0; i<n; i++){
    int digit = to_string(a[i]).length();
    ans += mod[digit][(k - a[i] % k) %  k];

    if(a[i] * (pow10[digit] + 1) % k == 0)
      ans--;
  }
  
  cout << ans << endl;

  return 0;
}