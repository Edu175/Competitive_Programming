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
const ll MOD=1e9+7;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
#define NEUT 0
#define CLEAR 1 // cleared lazy node
ll oper(ll a, ll b){
	return (a+b)%MOD;
}
void acum(ll &a, ll v){ // accumulate lazy node
	a=a*v%MOD;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	a=a*v%MOD;
	return a;
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
	void upd(ll k, ll s, ll e, ll p, ll v){
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			st[k]=v;
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};
typedef ii node;
node operit(node a, node b){return {a.fst+b.fst,a.snd+b.snd};}
#define NEUTit {0,0}
struct STreeit{
	int n; vector<node>t;
	STreeit(int n):n(n),t(2*n+5,NEUTit){}
	void upd(int p, ll v){
		for(p+=n,t[p]={v,1};p>1;p>>=1)t[p>>1]=operit(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUTit;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=operit(res,t[l++]);
			if(r&1)res=operit(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		vector<ii>b;
		fore(i,0,n)cin>>a[i],b.pb({a[i],i});
		sort(ALL(b)); reverse(ALL(b));
		vector<ll>p(n);
		fore(i,0,n)p[b[i].snd]=i;
		STreeit st(n);
		STree laz(n);
		ll res=0,sum=0;
		for(ll i=n-1;i>=0;i--){
			ll resi=fpow(2,n-i-1)*a[i]%MOD+fpow(2,n-i-2)*sum%MOD;
			resi=(resi-(a[i]*st.query(0,p[i]).snd%MOD)
			+st.query(0,p[i]).fst+MOD)%MOD;
			ll sub=laz.query(0,n);
			res=(res+resi-sub+MOD)%MOD;
			cout<<i<<" "<<a[i]<<":\n"<<fpow(2,n-i-1)*a[i]<<"+"<<fpow(2,n-i-2)*sum<<" -"<<a[i]*st.query(0,p[i]).snd<<"+"<<st.query(0,p[i]).fst<<": "<<resi<<"\n"<<sub<<"\n"<<resi-sub<<"\n\n";
			laz.upd(p[i],n,2);
			laz.upd(p[i],fpow(2,st.query(0,p[i]).snd)*a[i]%MOD);
			st.upd(p[i],a[i]);
			sum+=a[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}
