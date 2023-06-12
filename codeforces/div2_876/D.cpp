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

//SEGMENT TREE
#define oper max
#define NEUT 0
struct STree{
	vector<ll>st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);	

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		ll res[n+1]={};
		vector<STree> st(n+1,STree(n)); //k = 0
		fore(i,0,n){
			if(i&&a[i]<a[i-1])break;
			st[0].upd(a[i],i+1);
		}
		fore(k,1,n+1){
			ll l=0;
			cout<<k<<":\n";
			fore(i,0,n)cout<<st[k-1].query(i,i+1)<<" ";
			cout<<"\n";
			fore(i,0,n){
				ll x=st[k-1].query(0,a[i])+1;
				cout<<i<<" "<<a[i]<<": "<<x-1;
				if(i&&a[i]>a[i-1])x=max(x,l),cout<<" "<<l-1;
				else cout<<" -";
				st[k].upd(a[i],x);
				l=x+1;
				res[k]=max(res[k],x);
				if(k==n&&i==n-1)res[n-1]=max(res[n-1],x);
				cout<<": "<<x<<"\n";
			}
			cout<<"\n";
		}
		fore(i,0,n)cout<<n-res[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
