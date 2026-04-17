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
const ll MAXN=16,INF=1e4+5;

struct pt{
	ll x,y;
	pt(ll x, ll y): x(x), y(y){};
	pt(){};
};
struct node{
	pt s,b; ll v;
	node(pt s, pt b, ll v):s(s),b(b),v(v){};
	node(){};
};
ll k;
ll cnt(pt s, pt b){
	return (b.x-s.x+b.y-s.y)*2+8*k;
}

int main(){FIN;
	ifstream cin; cin.open("placas.in", ios::in);
	ofstream cout; cout.open("placas.out", ios::out);
	ll n; cin>>k>>n;
	pt a[n];
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	vector<node>c;
	fore(i,0,n)c.pb(node(a[i],a[i],cnt(a[i],a[i])));
	while(SZ(c)>1){
		vector<node>ci;
		ll us=0;
		fore(mk,1,1ll<<SZ(c)){
			ll sum=0;
			pt s=pt(INF,INF),b=pt(-1,-1);
			fore(i,0,SZ(c)){
				if(!(mk&(1ll<<i)))continue;
				sum+=c[i].v;
				s.x=min(s.x,c[i].s.x),s.y=min(s.y,c[i].s.y);
				b.x=max(b.x,c[i].b.x),b.y=max(b.y,c[i].b.y);
			}
			if(cnt(s,b)<sum){
				us=mk;
				ci.pb(node(s,b,cnt(s,b)));
				break;
			}
		}
		if(!us)break;
		fore(i,0,SZ(c))if(!(us&(1ll<<i)))ci.pb(c[i]);
		//cout<<us<<" "<<SZ(c)<<"\n";
		c=ci;
	}
	ll res=0;
	for(auto i:c)res+=i.v;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

