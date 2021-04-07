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
vi solu;
vi adj[100005];
vi parent[100005];
vi v;
void recon() {
    int non = solu.size();
    int x;
    solu.clear();
    for(int i = 0; i < non; i++) {
        adj[i].clear();
        parent[i].clear();
    }    
    vi LIS;
    int n = v.size();
    for(int i = 0; i < n; i++) {
        int pos = lower_bound(all(LIS), v[i]) - LIS.begin();
        if(pos == LIS.size()) LIS.pb(v[i]);
        else LIS[pos] = v[i];
        adj[pos].pb(v[i]);
        if(pos == 0) parent[pos].pb(-1);
        else parent[pos].pb(int(adj[pos - 1].size()) - 1);
    }
    int nn = LIS.size() - 1;
    x = 0;
    vi resu;
    while(x != -1) {
        resu.pb(adj[nn][x]);
        x = parent[nn][x];
        nn--;
    }
    reverse(all(resu));
    cout <<"Max hits: " << LIS.size() << "\n";
    for(auto e : resu) {
        cout << e << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        v.clear();
        for(int i = 0, x; i < n; i++) {
            cin >> x;
            v.pb(x);
        }
        recon();
    }
    return 0;
}