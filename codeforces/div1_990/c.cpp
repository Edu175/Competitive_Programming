#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
ll tec(ll n){
	ll res=0;
	while(n>1)res++,n=(n+1)/2;
	return 1ll<<res;
}
struct STree{
	int n; vector<node>t;
	STree(int N):n(tec(N)),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
	ll find(ll k, ll x, ll fg){ // upperbound
		if(k>=n){
			ll res=k-n;
			if(!fg)res+=x>0;
			// else res-=x>0;
			// else res-=
			// cout<<"final "<<k<<" "<<x<<" "<<fg<<": "<<res<<"\n";
			// imp(t)
			return res;
		}
		if(fg){
			if(t[2*k+1]>=x)return find(2*k+1,x,fg);
			return find(2*k,x-t[2*k+1],fg);
		}
		if(t[2*k]>=x)return find(2*k,x,fg);
		return find(2*k+1,x-t[2*k],fg);
	}
	ll find(ll x, ll fg){
		// cout<<n<<"\n";
		// if(fg)x=t[1]-x;
		// cout<<"find "<<x<<" "<<fg<<"\n";
		ll ret=find(1,x,fg);
		// cout<<ret<<"\n\n";
		return ret;
	}
};
ll n,m; // m = snd coord
vector<ii>a;
pair<bool,ii> can(ll k){ // k!=0
	STree l(m),r(m);
	fore(i,0,n)r.upd(a[i].snd,1);
	ll flag=0;
	ii ans={-1,-1};
	// cout<<"can "<<k<<":\n";
	auto doit=[&](ll xc){
		ll s=max(l.find(k,0),r.find(k,0));
		ll e=min(l.find(k,1),r.find(k,1));
		// cout<<"doit "<<xc<<": "<<s<<","<<e<<"\n";
		// imp(l.t)
		// imp(r.t)
		if(s<=e)ans={xc,s},flag=1;
	};
	fore(i,0,n){
		if(i==0||a[i].fst!=a[i-1].fst)doit(a[i].fst);
		l.upd(a[i].snd,1);
		r.upd(a[i].snd,-1);
	}
	// doit(INF); ??
	// cout<<"= "<<flag<<": "<<ans.fst<<","<<ans.snd<<"\n";
	return {flag,ans};
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		a=vector<ii>(n);
		vv ys;
		fore(i,0,n)cin>>a[i].fst>>a[i].snd,ys.pb(a[i].snd);
		sort(ALL(a));
		sort(ALL(ys));
		auto _ys=ys; ys.clear();
		for(auto i:_ys)if(!SZ(ys)||i!=ys.back())ys.pb(i);
		m=SZ(ys);
		// imp(ys)
		fore(i,0,n)
			a[i].snd=lower_bound(ALL(ys),a[i].snd)-ys.begin();
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m).fst)l=m+1;
			else r=m-1;
		}
		ii ans={0,0};
		if(r!=0){
			ans=can(r).snd;
			ans.snd=ys[ans.snd];
		}
		cout<<r<<"\n";
		cout<<ans.fst<<" "<<ans.snd<<endl;
	}
	return 0;
}
