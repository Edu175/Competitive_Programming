#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
	
	ll n; cin>>n; ll a[n];
	
	ll l[n],r[n],c[n];
	fore(i,0,n)cin>>l[i]>>r[i]>>c[i];
	
fore(s,1,n+1){
	ll L=*min_element(l,l+s);
	ll R=*max_element(r,r+s);
	vector<ll>v;
	vector<ll>w;
	fore(i,0,s){
		if(L==l[i])v.pb(i);
		if(R==r[i])w.pb(i);
	}
	ll x=1000000001;
	for(auto i:v){
		for(auto j:w){
			ll sumc;
			if(i==j){
			sumc=c[i];
			}else sumc=c[i]+c[j];
			x=min(x,sumc);
		}
	}
	cout<<x<<"\n";
}
	}
	 return 0;
}
