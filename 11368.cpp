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
bool cmp(pii a, pii b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main(){
    int t;
    cin >> t;
    while(t--) {
        int m;
        cin >> m;
        vii v;
        for(int i = 0, x, y; i < m; i++) {
            cin >> x >> y;
            v.pb(mp(x, y));
        }
        sort(all(v), cmp);
        reverse(all(v));
        vi LIS;
        for(int i = 0; i < m; i++) {
            int x = v[i].second;
            int pos = upper_bound(all(LIS), x) - LIS.begin();
            if(pos == LIS.size()) LIS.pb(x);
            else LIS[pos] = x;
        }
        cout << LIS.size() << "\n"; 
    }
    return 0;
}