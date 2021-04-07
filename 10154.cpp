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
int dp[6005][10006];
vi fuerza, peso;
int n;
int dpp(int pos, int W) {
    if(pos == n) return 0;
    if(dp[pos][W] != -1) return dp[pos][W];
    if(fuerza[pos] >= W + peso[pos]) return dp[pos][W] = max(1 + dpp(pos + 1, W + peso[pos]), dpp(pos + 1, W));
    return dp[pos][W] = dpp(pos + 1, W);
}
int main(){
    int x, y;
    vii v;
    while(cin >> x >> y) {
        v.pb(mp(y, x));
    } 
    n = v.size();
    sort(all(v));
    for(int i = 0; i < n; i++) {
        fuerza.pb(v[i].first);
        peso.pb(v[i].second);
    }  
    memset(dp, -1, sizeof(dp));
    cout << dpp(0, 0) << "\n";
    return 0;
}