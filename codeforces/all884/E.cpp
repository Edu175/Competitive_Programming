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
const ll MAXN=1.7e7+5;

ll n,m,c;
vector<ll>g[MAXN];

ll cv(ii p){return m*p.fst+p.snd;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>n>>m>>k;
		c=n*m;
		fore(i,0,k){
			ii p0,p1; cin>>p0.fst>>p0.snd>>p1.fst>>p1.snd;
			p0.fst--,p0.snd--,p1.fst--,p1.snd--;
			ll x=cv(p0);
			if(p1.snd<p0.snd)g[]
			else 
		}
	}
	return 0;
}
