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
ll dp[205];
string s;
ll num = 2147483647;
ll pot[11];
int n;
ll dpp(int p1) {
    if(p1 == n) return 0;
    if(dp[p1] != -1) return dp[p1];
    ll ans = 0;
    ll cur = 0;
    for(int i = p1; i <= min(p1 + 9, n); i++) {
        int c = s[i] - '0';
        cur += pot[i - p1] * c;
        if(cur > num) break;
        ans = max(ans, cur + dpp(i + 1));
    }
    return dp[p1] = ans;
}
int main(){
    pot[0] = 1;
    for(int i = 1; i < 10; i++) pot[i] = pot[i - 1] * 10;
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        reverse(all(s));
        memset(dp, -1, sizeof(dp));
        n = s.size();
        cout << dpp(0) << "\n";
    }   
    return 0;
}