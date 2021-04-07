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
int n, k;
vi v;
int dp[10005][105];
int dpp(int pos, int mod) {
    if(pos == n)return (mod == 0);
    if(dp[pos][mod] != -1) return dp[pos][mod];
    int p1 = (mod + v[pos]) % k;
    int p2 = (((mod - v[pos]) % k) + k) % k;
    return dp[pos][mod] = max(dpp(pos + 1, p1), dpp(pos + 1, p2));
}
int main(){
    int t;
    cin >> t;
    while(t--) {
        v.clear();
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        for(int i = 0, x; i < n; i++) {
            cin >> x;
            v.pb(x);
        }
        if(dpp(0, 0)) cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
    return 0;
}