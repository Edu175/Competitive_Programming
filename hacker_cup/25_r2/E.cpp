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
typedef __int128 xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1005;

ll bst[MAXN]; // [cost] = max S
ll n;
vv s; // cost i, rew s[i]

// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<ll,xl> dp;
unordered_map<ll,xl> dp;

xl f(ll m){
	// auto it=dp.find(m);
	// if(it!=dp.end())return it->snd;
	if(dp.count(m))return dp[m];
	auto &res=dp[m];
	if(m<=n){
		fore(i,0,m+1)res=max(res,(xl)bst[i]);
		return res;
	}
	ll h=m/2,l=h-n/2,r=h+(n+1)/2;
	fore(i,l,r){
		xl cur=f(i)+f(m-i);
		res=max(res,cur);
	}
	return res;
}
vv operator+(vv a, vv b){
	assert(SZ(a)==SZ(b));
	fore(i,0,SZ(a))a[i]+=b[i];
	return a;
}
vv operator*(ll t, vv a){
	for(auto &i:a)i*=t;
	return a;
}
vv wh;
vv doit(ll m){
	vv ret(n+1);
	while(m){
		ll w=wh[m];
		ret[w]++;
		m-=w;
	}
	return ret;
}
vv build(ll m){
	vv ret(n+1);
	map<ll,ll> cant;
	cant[m]++;
	while(SZ(cant)){
		auto [m,coef]=*cant.rbegin(); cant.erase(m);
		auto res=f(m);
		assert(res<LLONG_MAX);
		if(m<=n){
			fore(i,0,m+1)if(res==bst[i]){
				ret=ret+coef*doit(i);
				break;
			}
			continue;
		}
		ll h=m/2,l=h-n/2,r=h+(n+1)/2;
		fore(i,l,r){
			ll cur=f(i)+f(m-i);
			if(res==cur){
				cant[i]+=coef;
				cant[m-i]+=coef;
				break;
			}
		}
	}
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	fore(__,0,t){
		cout<<"Case #"<<__+1<<": ";
		ll m; cin>>n>>m;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll sum=0;
		s=vv(n+1);
		fore(i,1,n+1)sum+=a[i-1],s[i]=sum;
		fore(i,0,n+1)bst[i]=0;
		wh=vv(n+1,-1);
		fore(i,0,n+1){
			fore(j,1,n+1)if(i+j<=n){
				ll cur=bst[i]+s[j];
				bst[i+j]=max(bst[i+j],cur);
				if(bst[i+j]==cur)wh[i+j]=j;
			}
		}
		dp.clear();
		ll l=0,r=m+3;
		while(r-l>1){
			ll h=(l+r)/2;
			if(f(h)>=m)r=h;
			else l=h;
		}
		ll h=r;
		cout<<h<<"\n";
		auto sol=build(h);
		for(ll i=n-1;i>=0;i--)sol[i]+=sol[i+1];
		fore(i,1,n+1)cout<<sol[i]<<" ";;cout<<"\n";
		cout<<endl;
	}
	return 0;
}
