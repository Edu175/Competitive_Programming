#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define fst first
#define snd second
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
#define impr(v) {cout<<#v<<": ";;for(auto i:v)cout<<i.fst<<","<<i.snd<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll cuad(vv b){
	ll m=SZ(b);
	vv vis(m+3);
	for(auto i:b)if(i<SZ(vis))vis[i]=1;
	ll mex=0;
	while(vis[mex])mex++;
	if(!mex)return m;
	ll cnt=mex; // of 0s in oc
	vv oc(mex);
	ll res=0;
	for(auto i:b){
		if(i<mex){
			cnt-=!oc[i];
			oc[i]++;
		}
		if(!cnt)res++,oc=vv(mex),cnt=mex;
	}
	return res;
}

vector<int> solve(int _n, vector<int>& _V, int _q, vector<pair<int,int>>& _queries)
{
	ll n=_n,q=_q; assert(n|q|1);
	vv a(ALL(_V));
	vector<ii> qs(ALL(_queries));
	for(auto &i:a)i--;
	for(auto &[l,r]:qs)r++;
	
	ll mx=*max_element(ALL(a));
	vector<int> ans;
	if(mx<=1){
		// cerr<<"sub\n";
		vv dif;
		fore(i,0,n-1)if(a[i]!=a[i+1])dif.pb(i);
		vv u(2,n),to(n+2,n+1);
		for(ll i=n-1;i>=0;i--){
			u[a[i]]=i;
			to[i]=u[a[i]^1]+1;
		}
		const ll K=20;
		vector<vv> F(K,vv(n+2));
		fore(x,0,n+2)F[0][x]=to[x];
		fore(k,1,K)fore(x,0,n+2)F[k][x]=F[k-1][F[k-1][x]];
		for(auto [l,r]:qs){
			ll res=0;
			ll x=l;
			for(ll k=K-1;k>=0;k--){
				ll y=F[k][x];
				if(y<=r)res+=1ll<<k,x=y;
			}
			if(!res)res=r-l;
			ans.pb(res);
			if(0){
				vv b;
				fore(i,l,r)b.pb(a[i]);
				ll brute=cuad(b);
				assert(res==brute);
			}
			// cerr<<l<<","<<r<<": "<<d<<": "<<res<<"\n";
		}
		return ans;
	}
	
	for(auto [l,r]:qs){
		vv b;
		fore(i,l,r)b.pb(a[i]);
		ll res=cuad(b);
		ans.pb(res);
	}
	return ans;
}
