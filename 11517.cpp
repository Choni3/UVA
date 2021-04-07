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

int dp[105][20005];
int n;
int W[105];
int dpp(int pos, int cnt) {
    //cout << pos << " " << cnt << "\n";
    if(pos == n) {
        if(cnt == 0) return 0;
        return 1000000;
    }
    
    if(dp[pos][cnt] != -1) return dp[pos][cnt];
    int ans = 1000000;
    if(W[pos] <= cnt) ans = 1 + dpp(pos + 1, cnt - W[pos]); 
    
    ans = min(dpp(pos + 1, cnt), ans);
    return dp[pos][cnt] = ans;
}
int main(){
    int S;
    
    int t;
    cin >> t;
    while(t--) {
        cin >> S;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++) cin >> W[i];
        //cout << dpp(0, 8642) << "\n";
        for(int i = S; i <= 20000; i++) {
            if(dpp(0, i) != 1000000 && dpp(0, i) != -1) {
                cout << i << " " << dpp(0, i) << "\n";
                break;
            }
        }
    }
    return 0;
}