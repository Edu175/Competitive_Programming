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
const ll MAXN=3e5+5;

ll n,h;
ll t[MAXN],d[MAXN];
ll ev(ll i,ll j,ll x){
	return d[i]*min(x-j,t[i]);
}
bool can(ll x){ // hasta turno x)
	ll b=0;
	fore(i,0,n)if(ev(i,0,x)>ev(b,0,x)||(ev(i,0,x)==ev(b,0,x)&&t[i]<t[b]))b=i;
	ll rs=t[b],rb=b,t[b]=min(t[b],x);
	vector<pair<ll,ll>>p;
	fore(i,0,n)p.pb({t[i]*d[i],i});
	sort(ALL(p)); reverse(ALL(p));
	ll j=0;
	ll res=0;
	fore(i,0,n){
		ll k=i.snd;
		if(d[k]<=d[b]||t[k]>=t[b])continue;
		ll ij=x-p[i].fst/d[b]+1;
		// turnos [j,ij) con b
		res+=(ij-j)
		b=k;
		j=ij;
	}
	// turnos [j,x) con b
	res+=
	t[rb]=rs;
}
int main(){FIN;
	cin>>n>>h;
	fore(i,0,n)cin>>t[i]>>d[i];
	ll l=1,r=1e18+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
