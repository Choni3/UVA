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
    while(cin >> n && n != 0) {
        vii v;
        for(int i = 0, x, y; i < n; i++) {
            cin >> x >> y;
            v.pb(mp(x, y));
        }
        sort(all(v));
        int x = -1;
        vi v1;
        for(auto e : v){
            v1.pb(e.second);
        }
        vi LIS;
        for(int i = 0; i < n; i++) {
            int pos = upper_bound(all(LIS), v1[i]) - LIS.begin();
            if(pos == LIS.size()) LIS.pb(v1[i]);
            else LIS[pos] = v1[i];
        }
        cout << LIS.size() << "\n";
    }
    cout << "*\n";
    
    return 0;
}