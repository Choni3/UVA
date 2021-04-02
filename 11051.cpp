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
int dp[1005][1005];
string s;
int n;
int dpp(int p1, int p2) {
    if(p1 > p2) return 0;
    if(dp[p1][p2] != -1) return dp[p1][p2];
    if(s[p1] == s[p2]) return dp[p1][p2] = dpp(p1 + 1, p2 - 1);
    return dp[p1][p2] = 1 + min(dpp(p1 + 1, p2), dpp(p1, p2 - 1));
}
int main(){
    int t;
    cin >> t;
    getline(cin, s);
    while(t--) {
        getline(cin, s);
        n = s.size();
        if(n == 0) {
            cout << n << "\n";
            continue;
        }
        memset(dp, -1, sizeof(dp));
        cout << n - dpp(0, n - 1) << "\n";
    }
    cout << "\n";
    return 0;
}