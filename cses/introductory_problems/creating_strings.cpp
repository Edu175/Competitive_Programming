#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<"\n";
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	string s; cin>>s;
	sort(ALL(s));
	vector<string>res;
	do res.pb(s);
	while(next_permutation(ALL(s)));
	cout<<SZ(res)<<"\n";
	imp(res);
	return 0;
}
