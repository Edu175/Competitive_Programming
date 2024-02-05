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

ll n;
const ll K=21;//K such that 2^k>n
#define oper2 min
ll st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper2(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	/*if(e<=s){
		return oper2(st_query(0,e),st_query(s,n));
	}*/
	int k=31-__builtin_clz(e-s);
	return oper2(st[k][s],st[k][e-(1<<k)]);
}

#define NEUT 0
#define CLEAR -1 // cleared lazy node
ll oper(ll a, ll b){
	return a+b;
}
void acum(ll &a, ll v){ // accumulate lazy node
	a=v;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	if(v==-1)return a;
	return (e-s)*v;
}

struct STree{
	vector<ll>st,lazy; ll n;
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
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
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
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){
		/*if(a>b){
			upd(0,b,v);
			upd(a,n,v);
			return;
		}*/
		upd(1,0,n,a,b,v);
	}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll>a(n),b(2*n);
		fore(i,0,n)cin>>a[i],b[i]=b[i+n]=a[i];
		st_init(b);
		STree seg(n);
		vector<ll>vis(n);
		ll mex=0;
		fore(i,0,n){
			vis[a[i]]=1;
			while(mex<n&&vis[mex])mex++;
			seg.upd(i,i+1,mex);
		}
		ll res=seg.query(0,n);
		fore(i,0,n){
			ll l=i,r=i+n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(st_query(m,i+n)<a[i])l=m+1;
				else r=m-1;
			}
			ll c=r%n;
			if(a[i]==0)c=(i+1)%n;
			if(c>=i){
				seg.upd(c,n,a[i]);
				seg.upd(0,i,a[i]);
			}
			else seg.upd(c,i,a[i]);
			seg.upd(i,i+1,n);
			res=max(res,seg.query(0,n));
			/*cout<<i<<" "<<c<<": ";
			fore(i,0,n)cout<<seg.query(i,i+1)<<" ";
			cout<<"= "<<seg.query(0,n)<<"\n";*/
		}
		cout<<res<<"\n";
	}
	return 0;
}
