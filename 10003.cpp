#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(A) int(A.size())
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(A) begin(A),end(A)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<int,int>> vii;
int dp[105][105];
int s, n;
vi v;
int dpp(int l, int r) {
    if(l == r) return 0;
    if(l + 1 == r) return v[r] - v[l];
    if(dp[l][r] != -1) return dp[l][r];
    int ans = 10000000;
    for(int i = l + 1; i < r; i++) {
        ans = min(dpp(l, i) + dpp(i, r), ans);
    }
    return dp[l][r] = ans + v[r] - v[l];
}
int main(){
    while(cin >> s && s != 0) {
        memset(dp, -1, sizeof(dp));
        v.clear();
        cin >> n;
        v.pb(0);
        for(int i = 0, x; i < n; i++) {
            cin >> x;
            v.pb(x);
        }
        n += 2;
        v.pb(s);
        //for(int i = 0; i < n; i++) cout << v[i] << " \n"[i == n - 1];
        printf("The minimum cutting is %d.\n", dpp(0, n - 1) - s);
    }   
    return 0;
}