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

ll f(ll x){
	if(!x)return 0;
	return x<0?x+1:x-1;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv nums(n),nims(n);
	fore(i,0,n){
		string s; cin>>s;
		ll l=-1,r=-1;
		fore(i,0,m)if(s[i]!='.'){
			if(l==-1)l=i;
			r=i;
		}
		ll d=l-(m-1-r);
		ll k=-1;
		if(s[l]=='g')k=r-l-1;
		if(k==-1)nums[i]=2*d;
		else {
			if(k%2&&abs(d)<=1){
				nums[i]=d;
				if(!d)nims[i]=2;
			}
			else nums[i]=2*f(d);
		}
		// cerr<<i<<": "<<nums[i]<<" "<<nims[i]<<"\n";
	}
	fore(mk,0,1ll<<n){
		ll num=0,nim=0;
		fore(i,0,n)if(mk>>i&1)num+=nums[i],nim^=nims[i];
		ll gn=num-nim,bn=num+nim;
		// cerr<<"\n"<<mk<<": "<<gn<<" "<<bn<<":\n";
		cout<<(gn<0?"g":"b");
		cout<<(bn>0?"b":"g");
	}
	cout<<"\n";
	return 0;
}