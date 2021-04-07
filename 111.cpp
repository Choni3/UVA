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

vi v;
map<int, int>mop;
int n;
int main(){
    string s;
    while(getline(cin, s)) {
        int cnt = 0;
        istringstream iss (s);
        int aux;
        vi v_aux;
        while(iss >> aux) {
            cnt++;
            v_aux.pb(aux); 
        }
        if(cnt == 1) {
            n = v_aux[0];
            getline(cin, s);
            istringstream iss (s);
            int id = 0;
            mop.clear();
            cnt = 0;
            while(iss >> aux) {
                mop[id + 1] = aux;
                cnt++;
                id++;
            }
        }
        else {
            
            
            vi v_aux2 = v_aux;
            for(int i = 0; i < v_aux.size(); i++) {
                v_aux[v_aux2[i] - 1] = i + 1;
            }
            for(int i = 0; i < v_aux.size(); i++) v_aux[i] = mop[v_aux[i]];
            //GETLIS
            vi LIS;
            int nn = v_aux.size();
            //cout << nn << endl;
            for(int i = 0; i < nn; i++) {
                int pos = lower_bound(all(LIS), v_aux[i]) - LIS.begin();
                if(pos == LIS.size()) LIS.pb(v_aux[i]);
                else LIS[pos] = v_aux[i];
            }
            cout << LIS.size() << "\n";


        }
    }
    return 0;
}