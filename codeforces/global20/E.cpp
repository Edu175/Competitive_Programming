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

ll ask(ll w){
	cout<<"? "<<w<<endl;
	ll ret; cin>>ret;
	return ret;
}

int main(){
	// FIN;
	ll n; cin>>n;
	ll l=0,r=1e8;
	while(r-l>1){
		ll m=(l+r)/2;
		if(ask(m)==1)r=m;
		else l=m;
	}
	ll sum=r;
	sum-=(n-1);
	ll res=sum+n-1;
	fore(h,1,n+1){
		ll w=(sum+n-h+h-1)/h;
		ll got=ask(w);
		if(got)res=min(res,w*got);
	}
	cout<<"! "<<res<<endl;
	return 0;
}
