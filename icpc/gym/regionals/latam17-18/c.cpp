#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v).sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){ET;
	ll k,n; cin>>k>>n;
	vv oc(k);
	fore(i,0,n){
		ll x; cin>>x; x--;
		oc[x]++;
	}
	ll can=0;
	vv x,y;
	fore(v,max(oc[0]-1,0ll),oc[0]+2){
		vv xs,ys; ll flag=1;
		fore(i,0,k){
			flag&=abs(oc[i]-v)<=1;
			if(oc[i]<v)ys.pb(i);
			if(oc[i]>v)xs.pb(i);
		}
		if(flag&&SZ(xs)<=1&&SZ(ys)<=1){
			can=1;
			x=xs,y=ys;
		}
	}
	if(!can){
		cout<<"*\n";
	}
	else {
		for(auto i:x)cout<<"-"<<i+1<<" ";
		for(auto i:y)cout<<"+"<<i+1<<" ";
		cout<<"\n";
	}
}