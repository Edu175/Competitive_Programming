#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;

vector<ll> a;
ll n;

pair<bool,ll> messirve(ll res){
	ll t=-1;
	ll c,flag=0;
	vector<ll>ere;
	fore(i,0,n){
		ll li=a[i]-res,ri=a[i]+res;
		ere.pb(ri);
		ll lwb=lower_bound(ALL(ere),li)-ere.begin();
		c=SZ(ere)-lwb;
		//imp(ere);
		//cout<<i<<" "<<li<<": "<<lwb<<" "<<c<<"\n";
		if(c>=(n+1)/2)flag=1,t=li;//,cout<<i-1<<" "<<t<<"\n";
	}
	return {flag,t};
}

int mad(vector<int> &x) {
	a.clear();
	for(auto i:x)a.pb(i);
    sort(ALL(a));
    n=SZ(a);
    ll l=0,r=a[n-1]-a[0];
    while(l<=r){
    	ll m=(l+r)/2;
    	if(messirve(m).fst)r=m-1;
    	else l=m+1;
    }
    //cout<<l<<"\n";
    //while(1){ll q; cin>>q; pair<ll,ll> res=messirve(q);cout<<res.fst<<" "<<res.snd<<"\n";}
    return messirve(l).snd;
}
