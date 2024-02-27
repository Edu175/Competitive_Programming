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
const ll MAXN=35;
vector<ll> comp[MAXN]; ll id[MAXN];
void uf_init(ll n){
	fore(i,0,n){
		comp[i]={i};
		id[i]=i;
	}
}
int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	uf_init(30);
	ll q; cin>>q;
	while(q--){
		char c,d; cin>>c>>d;
		ll i=c-'a',j=d-'a';
		if(i==j)continue;
		for(auto k:comp[i])comp[j].pb(k),id[k]=j;
		comp[i].clear();
	}
	for(auto &i:s)i='a'+id[i-'a'];
	cout<<s<<"\n";
	return 0;
}
