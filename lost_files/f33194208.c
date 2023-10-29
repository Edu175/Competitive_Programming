#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    FIN;
    string s;
    cin >> s;
    int n = s.size();
    int max_len = 1, curr_len = 1;
    char curr_char = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == curr_char) {
            curr_len++;
        } else {
            max_len = max(max_len, curr_len);
            curr_len = 1;
            curr_char = s[i];
        }
    }
    max_len = max(max_len, curr_len);
    cout << max_len << endl;
    return 0;
}

