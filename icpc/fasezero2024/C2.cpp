#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;


random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll n,m; cin>>n>>m; n--;
	vector<ll>ev(n+1);
	ll rnd[m];
	fore(i,0,m)rnd[i]=(rng()<<31)^rng();
	fore(i,0,m){
		ll l,r; cin>>l>>r; r--;
		ev[l]^=rnd[i];
		ev[r]^=rnd[i];
	}
	ll h=0;
	map<ll,ll>c;
	ll res=0;
	fore(x,0,n){
		h^=ev[x];
		res=max(res,++c[h]);
	}
	cout<<res+1<<"\n";
	return 0;
}
