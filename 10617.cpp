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
string s;
ll dp[65][65];

ll dpp(int p1, int p2) {
    if(p1 > p2) return 1;
    if(dp[p1][p2] != -1) return dp[p1][p2];
    ll ans = 0;
    if(s[p1] == s[p2]) return dp[p1][p2] = dpp(p1 + 1, p2) + dpp(p1, p2 - 1);
    else return dp[p1][p2] = dpp(p1 + 1, p2) + dpp(p1, p2 - 1) - dpp(p1 + 1, p2 - 1);
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        cin >> s;
        int n = s.size();
        cout << dpp(0, n - 1) - 1 << "\n";
    }
    return 0;
}