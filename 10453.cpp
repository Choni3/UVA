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
int dp[1005][1005];
int tipo[1005][1005];
//0 - inicio
//1 - final
//2 - ninguno
char letra[1005][1005];
vi agregar;
void adda(char c, int posi) {
    string awa = "";
    awa += c;
    
    int p = upper_bound(all(agregar), posi) - agregar.begin();
    //cout << c << " " << posi + p << "\n";
    s.insert(posi + p, awa);
}
void recon(int p1, int p2) {
    if(p1 > p2) return;
    //cout << p1 << " " << p2 << " " << tipo[p1][p2] << "\n";
    if(tipo[p1][p2] == 0) {
        
        adda(letra[p1][p2], p1);
        agregar.pb(p1);
        recon(p1, p2 - 1);
    }
    else if(tipo[p1][p2] == 1) {
        adda(letra[p1][p2], p2 - 1);
        agregar.pb(p2 - 1);
        recon(p1 + 1, p2);
    }
    else {
        recon(p1 + 1, p2 - 1);
    }
}
int dpp(int p1, int p2) {
    if(p1 > p2) return 0;
    if(dp[p1][p2] != -1) return dp[p1][p2];
    if(s[p1] == s[p2]) {
        tipo[p1][p2] = 2;  
        return dp[p1][p2] = dpp(p1 + 1, p2 - 1);
    }
    if(dpp(p1 + 1, p2) < dpp(p1, p2 - 1)) {
        tipo[p1][p2] = 1;
        letra[p1][p2] = s[p1];
        
        return dp[p1][p2] = 1 + dpp(p1 + 1, p2);
    }
    else {
        tipo[p1][p2] = 0;
        letra[p1][p2] = s[p2];
        return dp[p1][p2] = 1 + dpp(p1, p2 - 1);
    }
}
int main(){
    while(cin >> s) {
        agregar.clear();
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        dpp(0, n - 1);
        recon(0, n - 1);
        cout << dpp(0, n - 1) << " " << s << "\n";
    }
    return 0;
}