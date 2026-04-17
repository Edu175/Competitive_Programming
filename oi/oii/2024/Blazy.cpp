#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

struct STree{ //lazy
	vector<ll>t; ll n;
	STree(ll n):t(2*n+8,0),n(n+2){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=(t[p]+t[p^1]);
	}
	void upd(ll l, ll r, ll v){
		upd(l,v),upd(r,-v);
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=(t[l++]);
			if(r&1)res+=(t[--r]);
		}
		return res;
	}
	ll query(ll p){
		return query(0,p+1);
	}
};
const ll K=17;
ll ST[K][MAXN];
#define oper min
void st_init(vector<ll>&a){
	ll n=SZ(a);
	fore(i,0,n)ST[0][i]=a[i];
	fore(k,1,K)fore(i,0,n)if(i+(1ll<<k)<=n)
		ST[k][i]=oper(ST[k-1][i],ST[k-1][i+(1ll<<(k-1))]);
}
ll st_query(ll s, ll e){
	ll k=(63-__builtin_clzll(e-s));
	ll ret=oper(ST[k][s],ST[k][e-(1ll<<k)]);
	// cout<<"st_query "<<s<<","<<e<<": "<<ret<<"\n";
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll>fb(n,-1);
	// for(ll i=n-1;i>=0;i--)
	// 	for(fs[i]=i+1;fs[i]<n&&a[i]<=a[fs[i]];fs[i]=fs[fs[i]]);
	fore(i,0,n){
		for(fb[i]=i-1;fb[i]>=0&&a[i]>=a[fb[i]];fb[i]=fb[fb[i]]);
	}
	vector<ll> fr(n);
	for(ll i=n-1;i>=0;i--){
		for(fr[i]=i+1;fr[i]<n&&a[i]>a[fr[i]];fr[i]=fr[fr[i]]);
	}
	vector<ll>fs(n);
	st_init(a);
	fore(i,0,n){
		ll l=fr[i],r=n-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(st_query(fr[i],m+1)<a[i])r=m-1;
			else l=m+1;
		}
		fs[i]=l;
	}
	
	// imp(fb) imp(fr) imp(fs)
	// fore(i,0,n)
	// cout<<i<<": ["<<fb[i]+1<<","<<i+1<<") ["<<fr[i]<<","<<fs[i]<<")\n";
	ll q; cin>>q;
	vector<ii>qu(q);
	vector<ll>ans(q);
	vector<vector<ii>>querys(n+1);
	vector<vector<ll>>upds(n+1);
	vector<ll>h;
	fore(i,0,q){
		ll l,r; cin>>l>>r; l--;
		qu[i]={l,r};
		querys[l].pb({r-1,i});
	}
	vector<ll>is(n);
	fore(i,0,n){
		upds[fb[i]+1].pb(i);
		upds[i+1].pb(i);
	}
	STree st(n+5);
	fore(i,0,n+1){
		for(auto p:upds[i]){
			st.upd(fr[p],fs[p],is[p]?-1:1);
			is[p]^=1;
		}
		for(auto [r,id]:querys[i]){
			ans[id]=st.query(r);
		}
	}
	for(auto i:ans)cout<<i+1<<"\n";
	// cout<<"\n";
	// for(auto [l,r]:qu){
	// 	ll res=0;
	// 	fore(i,0,n)res+=fb[i]+1<=l&&l<i+1&&fr[i]<=r-1&&r-1<fs[i];
	// 	cout<<res<<"\n";
	// }
	return 0;
}