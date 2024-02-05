#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll lis(vector<ll>&a){
	ll n=SZ(a);
	vector<ll>lis;
	fore(i,0,n){
		ll lwb=lower_bound(ALL(lis),a[i])-lis.begin();
		if(lwb==SZ(lis))lis.pb(a[i]);
		else lis[lwb]=a[i];
	}
	return SZ(lis);
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a;
	fore(i,0,n)a.pb(i);
	vector<vector<ll>> ks[n+1];
	ll res=n;
	do{
		vector<ll>ai=a;
		for(auto &i:ai)i=-i;
		ll x=max(lis(a),lis(ai));
		ks[x].pb(a);
		res=min(res,x);
	}
	while(next_permutation(ALL(a)));
	fore(k,0,n+1){
		cout<<k<<":\n";
		for(auto i:ks[k]){imp(i);}
		cout<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}
