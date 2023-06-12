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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pair<ll,ll>> p(3);
		map<ll,ll>f;
		map<ll,ll>c;
		fore(i,0,3){
			cin>>p[i].fst>>p[i].snd;
			p[i].fst--,p[i].snd--;
			f[p[i].fst]++;
			c[p[i].snd]++;
		}
		pair<ll,ll> s,e;
		for(auto i:f)if(i.snd==2)s.fst=i.fst;
		for(auto i:c)if(i.snd==2)s.snd=i.fst;
		cin>>e.fst>>e.snd;
		e.fst--,e.snd--;
		set<pair<ll,ll>>esq={{0,0},{0,n-1},{n-1,0},{n-1,n-1}};
		if(esq.count(s)){
			ll flag=0;
			if(e.fst==s.fst||e.snd==s.snd)flag=1;
			if(flag)cout<<"YES\n";
			else cout<<"NO\n";
			continue;
		}
		if(s.fst%2!=e.fst%2&&s.snd%2!=e.snd%2)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
