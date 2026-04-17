#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool good(vv a){
	ll sum=0;
	for(auto i:a){
		sum+=i;
		if(sum<0)return 0;
	}
	return 1;
}
ll val(vv a){
	ll n=SZ(a),res=0;
	fore(l,0,n){
		vv b;
		fore(r,l,n){
			b.pb(a[r]);
			res+=good(b);
		}
	}
	return res;
}
int main(){
	ET
	ll k,n; cin>>k>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll res=0,mx=0;
	fore(i,0,n){
		a[i]+=k;
		res=max(res,val(a));
		if(res==val(a))mx=i+1;
		cerr<<i+1<<": "<<val(a)<<"\n";
		a[i]-=k;
		
	}
	cout<<res<<"\n";
	cerr<<"esta en "<<mx<<"\n";
}