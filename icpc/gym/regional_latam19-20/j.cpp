#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {cout<<#v<<": ";for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;

int main(){ET
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	set<ll>pre,suf;
	ll mx=-1;
	fore(i,0,n){
		mx=max(mx,a[i]);
		if(mx==a[i])pre.insert(i);
	}
	mx=-1;
	for(ll i=n-1;i>=0;i--){
		mx=max(mx,a[i]);
		if(mx==a[i])suf.insert(i);	
	}
	auto upd=[&](ll i){
		//pre
		auto lwb=pre.upper_bound(i);
		lwb--;
		if(!pre.count(i)&&a[*lwb]<a[i])pre.insert(i),lwb++;
		// lwb in i
		while(lwb!=prev(pre.end())&&a[i]>a[*next(lwb)])
			pre.erase(next(lwb));
		
		//suf
		lwb=suf.lower_bound(i);
		if(!suf.count(i)&&a[i]>a[*lwb])suf.insert(i),lwb--;
		// lwb in i
		while(lwb!=suf.begin()&&a[*prev(lwb)]<a[i])
			suf.erase(prev(lwb));
	};
	
	while(q--){
		char ty; cin>>ty;
		if(ty=='U'){
			ll i,v; cin>>i>>v; i--;
			a[i]=v;
			upd(i);
		}
		else {
			ll i; cin>>i; i--;
			if(ty=='R'&&suf.count(i)){cout<<i+1<<"\n";continue;}
			if(ty=='L'&&pre.count(i)){cout<<i+1<<"\n";continue;}
			// imp(pre);
			// imp(suf);
			auto lwb=pre.upper_bound(i);
			ll res=-1;
			if(lwb!=pre.end())res=*lwb;
			else res=*prev(suf.lower_bound(i));
			cout<<res+1<<"\n";
		}
	}
}