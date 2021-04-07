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
int main(){
    int n;
    int cas = 0;
    while(cin >> n) {
        if(n == -1) return 0;
        if(cas) cout << "\n";
        vi v;
        v.pb(n);
        while(cin >> n && n != -1) {
            v.pb(n);
        }
        vi LIS;
        reverse(all(v));
        for(int i = 0; i < v.size(); i++) {
            int pos = lower_bound(all(LIS), v[i]) - LIS.begin();
            if(pos == LIS.size()) LIS.pb(v[i]);
            else LIS[pos] = v[i];
        }
        cas++;
        int nn = LIS.size();    
        printf("Test #%d:\nmaximum possible interceptions: %d\n", cas, nn);
    
    }    
    return 0;
}