#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,acts=b;i<acts;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdf:v)cout<<sdf<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e5+5;
typedef ll node;
ll oper(ll a, ll b, ll ty){
	if(ty==2)return max(a,b);
	if(ty)return min(a,b);
	return a+b;
}
ll NEUT[2]={0,MAXN,0};
void unit(ll &a, ll v, ll ty){
	if(ty)a=v;
	else a+=v;
}
struct STree{
	int n,ty; vector<node>t;
	STree(int n, int ty):n(n),ty(ty),t(2*n+5,NEUT[ty]){}
	void upd(int p, node v){
		for(p+=n,unit(t[p],v,ty);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1],ty);
	}
	node query(int l, int r){
		node res=NEUT[ty];
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++],ty);
			if(r&1)res=oper(res,t[--r],ty);
		}
		return res;
	}
};

ll exl[MAXN];
ll a[MAXN],h[MAXN],L[MAXN],R[MAXN],ini,fin;
void pop(ll x){
	L[R[x]]=L[x];
	R[L[x]]=R[x];
	//L[x]=R[x]=-1;
}
ll n,nq;
ll can(ll x){
	return a[x]+h[x]<=a[R[x]]?1:(a[L[x]]<=a[x]-h[x]?2:0);
}
int main(){FIN;
	cin>>n>>nq;
	fore(i,0,n)cin>>a[i]>>h[i];
	vector<ll>pl(n),exr(n);
	fore(i,0,n){
		pl[i]=upper_bound(a,a+n,a[i]-h[i])-a;
	}
	STree stmax(n);
	for(ll i=n-1;i>=0;i--){
		auto p=lower_bound(a,a+n,a[i]+h[i])-a-1;
		ll res=max(i,stmax.query(i,p+1));
		stmax.upd(i,res);
		exr[i]=res;
	}
	vector<ii> qs[n+1];
	vector<ll>ans(nq);
	fore(i,0,nq){
		ll l,r; cin>>l>>r; l--;
		qs[r].pb({l,i});
	}
	STree st(n,0),stmin(n,1);
	ini=n+1,fin=n+2;
	a[ini]=a[0]; a[fin]=a[n-1];
	fore(i,0,n){
		L[i]=i-1;
		R[i]=i+1;
	}
	R[ini]=0,L[0]=ini;
	R[n-1]=fin,L[fin]=n-1;
	fore(r,0,n+1){
		cout<<"r "<<r<<"\n";
		for(auto [l,i]:qs[r]){
			ans[i]=st.query(l,n);
			cout<<"query "<<l<<"\n";
		}
		if(r==n)break;
		for(auto x=r;x!=ini&&can(x);pop(x),x=L[x]){
			ll p=can(x)==1?x:min(x,stmin.query(pl[x],x));
			st.upd(p,1); stmin.upd(x,p);
			cout<<"upd "<<x<<","<<p<<"\n";
		}
	}
	fore(i,0,nq)cout<<ans[i]<<"\n";
	return 0;
}
