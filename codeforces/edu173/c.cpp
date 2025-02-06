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

vv solve(vv a){ // ones
	ll mxr=0,mnr=0;
	ll mxp=0,mnp=0,p=0;
	ll n=SZ(a);
	fore(i,0,n){
		p+=a[i];
		mxp=max(mxp,p);
		mnp=min(mnp,p);
		mxr=max(mxr,p-mnp);
		mnr=min(mnr,p-mxp);
	}
	vv ret;
	fore(i,mnr,mxr+1)ret.pb(i);
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		ll p=-1;
		fore(i,0,n){
			cin>>a[i];
			if(abs(a[i])!=1)p=i;
		}
		vv ret;
		if(p==-1)ret=solve(a);
		else {
			vv pre={0},suf={0};
			for(ll i=p-1;i>=0;i--)suf.pb(suf.back()+a[i]);
			fore(i,p+1,n)pre.pb(pre.back()+a[i]);
			sort(ALL(pre));
			sort(ALL(suf));
			ll l=0,r=0;
			while(l<SZ(pre)&&r<SZ(suf)){
				ret.pb(pre[l]+suf[r]+a[p]);
				ll go=0;
				if(l==SZ(pre)-1)go=1;
				else if(r!=SZ(suf)-1&&suf[r]<pre[l])go=1;
				if(!go)l++;
				else r++;
			}
			vv lhs,rhs;
			fore(i,0,n)if(i!=p){
				if(i<p)lhs.pb(a[i]);
				else rhs.pb(a[i]);
			}
			for(auto i:solve(lhs))ret.pb(i);
			for(auto i:solve(rhs))ret.pb(i);
			sort(ALL(ret));
			vv ans;
			for(auto i:ret)if(!SZ(ans)||ans.back()!=i)ans.pb(i);
			swap(ans,ret);
		}
		cout<<SZ(ret)<<"\n";
		imp(ret);
	}
	return 0;
}
