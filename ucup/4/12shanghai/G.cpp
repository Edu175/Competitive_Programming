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
const ll B=60;
struct matrix{
	vector<ll>x;
	matrix(): x(B){}
	bool add(ll v){
		if(v==0)return 0;
		for(ll j=B-1;j>=0;j--)v=min(v,v^x[j]);
		if(v){x[__lg(v)]=v;return 1;}
		return 0;
	}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		ll tot=0;
		fore(i,0,n)cin>>a[i],tot^=a[i];
		ll res=tot;
		fore(i,0,n)fore(j,0,B)if((tot>>j&1)&&(a[i]>>j&1))a[i]^=1ll<<j;
		matrix mt;
		fore(i,0,n)mt.add(a[i]);
		ll v=0;
		for(ll j=B-1;j>=0;j--)v=max(v,v^mt.x[j]);
		res=max(res,v);
		cout<<res<<"\n";
	}
	return 0;
}
