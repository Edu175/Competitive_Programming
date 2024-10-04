#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<endl;}
#define impr(v) {cout<<"{ ";for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<"}";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ii NEUT={0,0};
ii oper(ii a, ii b){
	return {a.fst+b.fst,a.snd+b.snd};
}
ll tec(ll n){
	ll res=0;
	while(n>1)res++,n=(n+1)/2;
	return 1ll<<res;
}
struct STree{
	ll n; vector<ii>t; vector<ll>a,idx;
	STree(){}
	STree(vector<ll>A):n(tec(SZ(A))),t(2*n+5,NEUT),a(A){
		a.resize(n);
		vector<ii>b;
		fore(i,0,n)b.pb({a[i],i});
		sort(ALL(b));
		idx=vector<ll>(n);
		fore(i,0,n){
			idx[b[i].snd]=i;
		}
	}
	void upd(ll p, ll fg){ // 1 add, 0 remove
		// cout<<"upd "<<p<<"("<<n<<") "<<SZ(a)<<" --> ";
		ll i=p;
		p=idx[p];
		// cout<<p<<endl;
		p+=n;
		t[p]={fg,fg*a[i]};
		for(;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll p=0;
	void adjust(ll m){
		m++;
		while(p<m)upd(p++,1);
		while(p>m)upd(--p,0);
	}
	ll find(ll k, ll v){
		if(k>=n)return v>0?t[k].snd:0;
		if(t[2*k+1].fst<=v){
			return t[2*k+1].snd+find(2*k,v-t[2*k+1].fst);
		}
		return find(2*k+1,v);
	}
	ll query(ll v){
		return find(1,v);
	}
};
ll val[3*MAXN];
STree st;
ll fg;
void dnc(ll l, ll r, ll s, ll e){
	// cout<<"dnc "<<l<<","<<r<<" "<<s<<","<<e<<endl;
	ll m=(l+r)/2;
	ll opt=0, &res=val[m]; res=-1;
	fore(i,s,e){
		st.adjust(i);
		ll di=m-(1+fg)*i;
		ll resi=st.query(di);
		if(resi>res)opt=i,res=resi;
	}
	if(r-l>1){
		dnc(l,m,s,opt+1);
		dnc(m+1,r,opt,e);
	}
}
vector<ll> getds(vector<ll>a, ll d, ll _fg){
	// cout<<"getds: "<<fg<<", "; imp(a); 
	ll n=SZ(a);
	fg=_fg;
	st=STree(a);
	vector<ll>res(d);
	if(!SZ(a))return res;
	dnc(0,d,0,n);
	fore(i,0,d)res[i]=val[i];
	// cout<<" = "; imp(res); 
	return res;
}

long long findMaxAttraction(int N, int s, int d, int A[]) {
	ll n=N;
	vector<ll>a(n);
	fore(i,0,n)a[i]=A[i];
	vector<ll>l,r;
	fore(i,0,n){
		if(i<s)l.pb(a[i]);
		else r.pb(a[i]);
	}
	reverse(ALL(l));
	ll res=0;
	fore(fg,0,2){
		auto lhs=getds(l,d+2,fg);
		auto rhs=getds(r,d+2,fg^1);
		fore(i,0,fg+1)lhs.insert(lhs.begin(),0);
		fore(i,0,d+1)res=max(res,lhs[i]+rhs[d-i]);
	}
	return res;
}
