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
ll pot[10];
int main(){
    pot[0] = 1;
    for(int i = 1; i < 10; i++) {
        pot[i] = pot[i - 1] * 10;
    }
    string s;
    int t;
    cin >> t;
    while(t--) {
        int d;
        cin >> s >> d;
        
        sort(all(s));
        int cnt = 0;
        int n = s.size();
        do {
            ll num = 0;
            for(int i = 0; i < n; i++) {
                int x = s[n - i - 1] - '0';
                num += pot[i] * x;
            }
            if(num % d == 0) cnt++;
        }while(next_permutation(all(s)));
        cout << cnt << "\n";
    }
    return 0;
}