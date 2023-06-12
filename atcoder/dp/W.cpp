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
const ll INF=1e15;
#define NEUT 0
ii CLEAR={0,-INF}; // cleared lazy node
ll oper(ll a, ll b){return a+b;}
void acum(ii &a, ii v){
	a.fst+=v.fst;
	a.snd=max(a.snd+v.fst,v.snd);
} // accumulate lazy node
ll calc(ll s, ll e, ll a, ii v){
	if(e-s>1)return NEUT;
	return max(v.snd,a+v.fst);
} // calculate STree range st[k], a=previous value

struct STree{
	vector<ll>st; vector<ii>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ii v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll p){
		if(e<=p||p<s)return NEUT;
		push(k,s,e);
		if(e-s==1&&s==p)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,p),query(2*k+1,m,e,p));
	}
	void upd(ll a, ll b, ii v){upd(1,0,n,a,b,v);}
	ll query(ll p){return query(1,0,n,p);}
};

int main(){FIN;
	ll n,m; cin>>n>>m;
	//ll a[m];
	vector<pair<ll,ll>> a[n];
	fore(i,0,m){
		ll l,r,w; cin>>l>>r>>w; l--,r--;
		a[r].pb({l,w});
	}
	//fore(i,0,n)sort(a[i]);
	/*fore(i,0,n){
		for(auto j:a[i])cout<<j.fst<<","<<j.snd<<" ";
		cout<<"\n";
	}
	cout<<"==========================\n\n";*/
	STree dp(n);
	for(ll i=n-1;i>=0;i--){
		ll x=dp.query(i);
		ll sum=0;
		for(auto j:a[i])dp.upd(j.fst,i+1,{j.snd,-INF}),sum+=j.snd;
		dp.upd(0,n,{0,x+sum});
		//cout<<i<<": "; fore(j,0,n)cout<<dp.query(j)<<" "; cout<<"\n";
	}
	ll res=0;
	fore(i,0,n)res=max(res,dp.query(i));
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
