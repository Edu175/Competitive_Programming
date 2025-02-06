#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vv get(ll n){
	vv ds;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			ds.pb(i);
			ds.pb(n/i);
		}
		if(i*i==n)ds.pop_back();
	}
	return ds;
}

int main(){
	JET
	ll n; cin>>n;
	vv ds;
	ll res=0;
	for(auto a:get(n)){
		ll m=n/a-1;
		for(auto b:get(m))if(b>1){
			res+=m/b-1>1;
		}
	}
	cout<<res<<"\n";
	return 0;
}