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
ll oper(ll a, ll b){return a+b;}
#define NEUT 0

struct STree{
	ll n; vector<ll>st;
	STree(ll n):n(n),st(4*n+5,NEUT){};
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s){return NEUT;}
		if(a<=s&&e<=b){return st[k];}
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	ifstream cin; cin.open("sumo.in", ios::in);
	ofstream cout; cout.open("sumo.out", ios::out);
	ll n; cin>>n;
	vector<pair<ii,ll>>a,b;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		a.pb({{x,y},i});
		b.pb({{y,x},i});
	}
	sort(ALL(a));
	sort(ALL(b));
	ll id[n];
	fore(i,0,n)id[b[i].snd]=i;
	STree st(n);
	vector<ll>res(n);
	for(auto i:a){
		res[i.snd]=st.query(0,id[i.snd]);
		st.upd(id[i.snd],1);
	}
	for(auto i:res)cout<<i<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
