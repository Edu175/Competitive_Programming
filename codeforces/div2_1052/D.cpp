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

ll opu(ll n, ll k){
	ll all=(1ll<<k)-1;
	ll s=(~n)&all;
	return s;
}

vv res;
ll L;
void f(ll l, ll r){
	if(r-l==0)return;
	ll k=-1,c=-1;
	// cout<<l<<" "<<r<<endl;
	if(r-l==1){
		res[l-L]=l;
		return;
	}
	for(ll j=33;j>=0;j--){
		ll co=l>>j<<j;
		co|=(1ll<<j);
		if(!(l>>j&1)&&co<r){
			c=co,k=j;
			break;
		}
	}
	assert(c!=-1);
	ll z=min(r-c,c-l);
	fore(i,0,z){
		ll x=c-1-i,y=c+i;
		res[x-L]=y;
		res[y-L]=x;
	}
	f(l,c-z);
	f(c+z,r);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll l,r; cin>>l>>r; r++;
		res=vv(r-l,-1);
		L=l;
		f(l,r);
		ll tot=0;
		fore(i,l,r)tot+=(res[i-l]|i);
		cout<<tot<<"\n";
		imp(res)
	}
	return 0;
}
