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
const ll V=2e5+5;
int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	// vv hay(V);
	fore(i,0,n)cin>>a[i];//,hay[a[i]]=1;
	sort(ALL(a));
	a.resize(unique(ALL(a))-a.begin());
	ll res=0;
	fore(d,1,V/n+5){
		map<ll,ll> oc;
		ll po=0;
		for(auto i:a){
			while(po<SZ(a)&&a[po]<=i+d*(n-1))oc[a[po++]%d]++;
			ll cur=oc[i%d]--;
			if(cur>2)cerr<<d<<": "<<i<<": "<<cur<<"\n";
			res=max(res,cur);
		}
	}
	res=n-res;
	cout<<res<<"\n";
	return 0;
}
