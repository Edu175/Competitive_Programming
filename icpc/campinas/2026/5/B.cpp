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
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

vv divs(ll n){
	vv ret;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0)ret.pb(i),ret.pb(n/i);
		if(i*i==n)ret.pop_back();
	}
	sort(ALL(ret));
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,X; cin>>n>>m>>X;
		auto ds=divs(X); assert(ds[0]==1);
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv b(m);
		fore(i,0,m)cin>>b[i];
		ll MXA=*max_element(ALL(a))+5;
		vector<bool> cr(MXA);
		sort(ALL(b));
		b.resize(unique(ALL(b))-b.begin());
		
		m=SZ(ds);
		vector<vector<bool>> go(n,vector<bool>(m));
		ll po=SZ(b)-1;
		for(ll j=m-1;j>=0;j--){
			ll d=ds[j];
			while(po>=0&&b[po]>d){
				for(ll p=0;p<MXA;p+=b[po])cr[p]=1;
				po--;
			}
			fore(i,0,n)if(a[i]-d>=0&&cr[a[i]-d])go[i][j]=1;
		}
		vv good(n);
		fore(i,0,n)good[i]=go[i][0];
		vector<vv> to(n+2,vv(m,n)); // to[i][j] first pos of div j in [i..n) (only good columns)
		for(ll i=n-1;i>=0;i--){
			to[i]=to[i+1];
			if(good[i]){
				fore(j,0,m)if(go[i][j])to[i][j]=i;
			}
		}
		// gp_hash_table<ll,int> ht;
		// fore(i,0,m)ht[ds[i]]=i;
		auto get_idx=[&](ll d){
			return lower_bound(ALL(ds),d)-ds.begin();
			// return ht[d];
		};
		
		vv dis(m,n+1); // min r) such that you can from div i from [0,r) with only good cols
		dis[0]=0;
		vv vis(m);
		fore(_,0,m){
			ll p=-1;
			fore(i,0,m)if(!vis[i]){
				if(p==-1||dis[i]<dis[p])p=i;
			}
			if(p==-1)break;
			vis[p]=1;
			ll d=ds[p];
			fore(j,0,m){
				if(d>X/ds[j])break;
				ll y=d*ds[j];
				if(X%y)continue;
				ll k=get_idx(y);
				ll nd=to[dis[p]][j]+1;
				dis[k]=min(dis[k],nd);
			}
		}
		ll mnpr=1;
		vector<ll> dp={1};
		vv ans(n);
		fore(i,0,n){
			if(!good[i]){
				vv prox;
				ll mn=X+5;
				fore(j,0,m)if(go[i][j]){
					ll d=ds[j];
					mn=min(mn,d);
					for(auto x:dp){
						if(x>X/d)break;
						ll y=x*d;
						if(X%y)continue;
						prox.pb(y);
					}
				}
				sort(ALL(prox)); // heavy
				prox.resize(unique(ALL(prox))-prox.begin());
				swap(dp,prox);
				if(mnpr>X/mn)break;
				mnpr*=mn;
			}
			ll &res=ans[i];
			for(auto d:dp){
				ll nec=X/d;
				ll j=get_idx(nec);
				res|=dis[j]<=i+1;
			}
		}
		fore(i,0,n){
			if(ans[i])cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}