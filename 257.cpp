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
    string s;
    int pot[4];
    pot[0] = 1;
    pot[1] = 27;
    pot[2] = 27*27;
    pot[3] = 27*27*27;
    while(cin >> s) {
        int n = s.size();
        int cnt1 = 0;
        set<int>ss;
        int p1, p2;
        for(int i = 0; i + 2 < n; i++) {
            int num = 0;
            if(s[i] != s[i + 2])continue;
            for(int j = 0; j < 3; j++) {
                int c = s[i + j] - 'A';
                num += pot[j] * c;
            }
            if(ss.count(num) == 0) {
                cnt1++;
                p1 = i;
            }
            ss.insert(num);
        }
        ss.clear();
        int cnt2 = 0;
        for(int i = 0; i + 3 < n; i++) {
            int num = 0;
            if(s[i] != s[i + 3])continue;
            if(s[i + 1] != s[i + 2]) continue;
            if(s[i] == s[i + 1]) continue;
            for(int j = 0; j < 4; j++) {
                int c = s[i + j] - 'A';
                num += pot[j] * c;
            }
            if(ss.count(num) == 0) {
                cnt2++;
                p2 = i;
            }
            ss.insert(num); 
        }
        if(cnt1 + cnt2 > 1) cout << s << "\n";
    }
    return 0;
}