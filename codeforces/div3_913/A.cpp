#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ii cv(string s){
	return {s[0]-'a',s[1]-'1'};
}
string acv(ii p){
	char a='a'+p.fst,b='1'+p.snd;
	string s;
	s.pb(a),s.pb(b);
	return s;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ii p=cv(s);
		vector<string> a;
		fore(i,0,8)if(i!=p.fst)a.pb(acv({i,p.snd}));
		fore(j,0,8)if(j!=p.snd)a.pb(acv({p.fst,j}));
		for(auto i:a)cout<<i<<"\n"; 
	}
	return 0;
}
