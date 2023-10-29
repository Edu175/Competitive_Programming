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
const ll MOD=998244353;

string cv(ll x, ll sz){
	string s;
	fore(i,0,sz){
		if(x&(1ll<<i))s.pb('b');
		else s.pb('a');
	}
	return s;
}
set<string>st;
bool valid(string s){//O(sz²)
	ll flag=1;
	fore(l,0,SZ(s))fore(r,l+1,SZ(s)+1){
		string p;
		fore(i,l,r)p.pb(s[i]);
		//cout<<l<<","<<r<<": "<<p<<": "<<st.count(p)<<"\n";
		if(st.count(p))flag=0;
	}
	//cout<<flag<<"\n\n";
	return flag;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		string s; cin>>s; st.insert(s);
	}
	ll res=0;
	fore(i,0,1ll<<n){
		res=(res+valid(cv(i,n)))%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
