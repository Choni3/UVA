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
int n, c, t1, t2;
vi v;
int dp[1005];
int dpp(int pos) {
    if(pos == v.size()) {
        return 0;
    }
    if(dp[pos] != -1) return dp[pos];
    int p1 = upper_bound(all(v), v[pos] + t1) - v.begin();
    int p2 = upper_bound(all(v), v[pos] + t2) - v.begin();
    return dp[pos] = min(t1 + dpp(p1), t2 + dpp(p2));
}
int main(){
    while(cin >> n >> c >> t1 >> t2) {
        memset(dp, -1, sizeof(dp));
        v.clear();
        if(t1 > t2) swap(t1, t2);
        for(int i = 0, x; i < n; i++) {
            cin >> x;
            v.pb(x);
        }
        sort(all(v));
        int ans = dpp(0);
        //cout << ans << "\n";
        
        for(int i = n - 1; i >= 0; i--) {
            memset(dp, -1, sizeof(dp));
            if(v[i] + t2 < c) {
                break;
            }
            v.pop_back();
            if(v[i] + t1 >= c) {
                int p1 = upper_bound(all(v), v[i] + t1 - c) - v.begin();
                ans = min(ans, dpp(p1) + t1);
            }
            if(v[i] + t2 >= c) {
                int p2 = upper_bound(all(v), v[i] + t2 - c) - v.begin();
                ans = min(ans,  t2 + dpp(p2));
            }
        }
        cout << ans << "\n";
    }   
    return 0;
}