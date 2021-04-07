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

int n, m;
int a[12][105];
ll dp[12][105];
int INF = 1 << 30;
int ns[12][105];
ll dpp(int p1, int p2) {
    if(p2 == m) return 0;
    if(dp[p1][p2] != -1) return dp[p1][p2];
    ll ans = INF;
    ll uwu = ans;
    if(p1 == 0) {
        uwu = ans;
        ans = min(ans, dpp(p1, p2 + 1));
        if(uwu != ans) ns[p1][p2] = 0;
        uwu = ans;
        ans = min(ans, dpp(p1 + 1, p2 + 1));
        if(uwu != ans) ns[p1][p2] = 1;
        uwu = ans;
        ans = min(ans, dpp(n - 1, p2 + 1));
        if(uwu != ans) ns[p1][p2] = -1;
    }
    else if(p1 == n - 1) {
        uwu = ans;
        ans = min(ans, dpp(0, p2 + 1));
        if(uwu != ans) ns[p1][p2] = 1;
        uwu = ans;
        ans = min(ans, dpp(p1 - 1, p2 + 1));
        if(uwu != ans) ns[p1][p2] = -1;
        uwu = ans;
        ans = min(ans, dpp(p1, p2 + 1));
        if(uwu != ans) ns[p1][p2] = 0;
    }
    else {
        uwu = ans;
        ans = min(ans, dpp(p1 - 1, p2 + 1));
        if(uwu != ans) ns[p1][p2] = -1;
        uwu = ans;
        ans = min(ans, dpp(p1, p2 + 1));
        if(uwu != ans) ns[p1][p2] = 0;
        uwu = ans;
        ans = min(ans, dpp(p1 + 1, p2 + 1));
        if(uwu != ans) ns[p1][p2] = 1;
        uwu = ans;
    }
    
    
    return dp[p1][p2] = ans + a[p1][p2];
}
int main(){
    
    while(cin >> n >> m) {
        int sum = 0;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                sum += a[i][j];
            }
        }
        int maxi = INF;
        if(n == 1) {
            for(int i = 0; i < m; i++) cout << 1 << " \n"[i == m - 1];
            cout << sum << "\n";
            continue;
        }
        else {
            
            int p = 0;
            for(int i = 0; i < n; i++) {
                if(maxi > dpp(i, 0)) {
                    p = i;
                    maxi = dpp(i, 0);
                }
            }
            int x = p;
            for(int i = 0; i < m; i++) {
                cout << x + 1 << " \n"[i == m - 1];
                int av = ns[x][i];
                int nx;
                if(av == 1 && x == n - 1) nx = 0;
                else if(av == -1 && x == 0) nx = n - 1;
                else nx = x + av;
                x = nx;
            }
        }
        
        cout << maxi << "\n";
    }
    return 0;
}