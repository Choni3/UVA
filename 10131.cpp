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

struct ele{
    int x, y, id;
    ele(){}
    ele(int _x, int _y, int _id) {
        x = _x, y = _y, id = _id;
    }
};
bool cmp(ele a, ele b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
vi solu;
vi adj[100005];
vi parent[100005];
vi iden[100005];
vi v;
vi ids;
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
        iden[pos].pb(ids[i]);
        if(pos == 0) parent[pos].pb(-1);
        else parent[pos].pb(int(adj[pos - 1].size()) - 1);
    }
    int nn = LIS.size() - 1;
    x = 0;
    vi resu;
    while(x != -1) {
        resu.pb(iden[nn][x]);
        x = parent[nn][x];
        nn--;
    }
    cout << LIS.size() << "\n";
    for(auto e : resu) {
        cout << e << "\n";
    }
}
int main(){
    int x, y;
    vector<ele> v1;
    int idd = 0;
    while(cin >> x >> y) {
        idd++;
        v1.pb(ele(x, y, idd));
    }
    sort(all(v1), cmp);
    reverse(all(v1));
    for(auto e : v1) v.pb(e.y);
    for(auto e : v1) ids.pb(e.id);
    recon();

    return 0;
}