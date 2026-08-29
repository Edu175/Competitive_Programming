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
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const ll V=2e5+5,B=200;

ll mxBlockH(vv a){
	gp_hash_table<ll,int> ht;
	// unordered_map<ll,int>ht;
	int res=0;
	for(auto i:a)res=max(res,++ht[i]);
	return res;
}
ll mxBlockS(vv a){
	sort(ALL(a));
	ll n=SZ(a);
	ll q=0;
	ll res=0;
	fore(i,0,n){
		q++;
		if(i==n-1||a[i]!=a[i+1])res=max(res,q),q=0;
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	
	ll res=0;
	fore(d,-B,B+1){
		vv all(n);
		fore(i,0,n)all[i]=a[i]-d*i;
		res=max(res,mxBlockS(all));
	}
	// abs(d) > B => j-i < V/B
	ll len=V/B+5;
	fore(i,0,n){
		vv all;
		fore(j,i+1,min(i+len,n)){
			ll nu=a[j]-a[i];
			ll de=j-i;
			if(nu%de==0){
				ll val=nu/de;
				if(abs(val)>B)all.pb(val);
			}
		}
		res=max(res,mxBlockS(all)+1);
	}
	cout<<n-res<<"\n";
	return 0;
}
