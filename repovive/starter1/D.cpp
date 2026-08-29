#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n);
	ll m=n+5;
	vv oc(m);
	fore(i,0,n)cin>>a[i],oc[a[i]]++;
	ll res=-1;
	fore(i,0,m){
		auto &c=oc[i];
		if(!c){res=i;break;}
		if(c>1){
			ll p=i+k;
			if(p<m)oc[p]+=c-1;
			c=1;
		}
	}
	cout<<res<<"\n";
	return 0;
}
