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

ii wh(vv a){
	ll inc=1,dec=1;
	fore(i,0,SZ(a)-1){
		inc&=a[i]<a[i+1];
		dec&=a[i]>a[i+1];
	}
	return {inc, dec};
}

ll tam(vv a){
	ll n=SZ(a);
	vv inc(n),dec(n);
	ll mxi=0,mxd=0;
	fore(mk,0,1ll<<n){
		vv b;
		fore(i,0,n)if(mk>>i&1)b.pb(a[i]);
		ll m=SZ(b);
		auto [in,de]=wh(b);
		if(in){
			fore(i,0,n)if(mk>>i&1)inc[i]=max(inc[i],m);
			mxi=max(mxi,m);
		}
		if(de){
			fore(i,0,n)if(mk>>i&1)dec[i]=max(dec[i],m);
			mxd=max(mxd,m);
		}
	}
	ll cnt=0;
	fore(i,0,n)if(inc[i]==mxi&&dec[i]==mxd){
		cnt++;
	}
	return cnt;
}

int main(){FIN;
	ll n; cin>>n;
	vv per(n); iota(ALL(per),1);
	vector<vector<vv>> h(n+3);
	do{
		h[tam(per)].pb(per);
	}while(next_permutation(ALL(per)));
	
	fore(i,0,2){
		cout<<"pers con tam "<<i<<":\n";
		for(auto v:h[i]){
			imp(v);
		}
		cout<<"\n";
	}
	
	return 0;
}
