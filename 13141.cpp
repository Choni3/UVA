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

ll dp[90][2];
int n;
// 0 -> seguro
// 1 -> inseguro
ll dpp(int pos, int ram) {
    //cout << pos << " " << ram << "\n";
    if(pos == n) return 1;
    if(dp[pos][ram] != -1) return dp[pos][ram];
    if(ram) {
        return dp[pos][ram] = dpp(pos + 1, 1) + dpp(pos + 1, 0);
    }
    return dp[pos][ram] = dpp(pos + 1, 1);
}

int main() {
    
    while(cin >> n && n != 0) {
        memset(dp, -1, sizeof(dp));
        n--;
        cout << dpp(0, 0) << "\n";

    } 
}