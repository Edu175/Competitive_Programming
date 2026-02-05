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
void criba(ll n){ // n]
	n++;
	vv is,ps;
	is=vv(n,1);
	is[0]=is[1]=0;
	fore(i,2,n)if(is[i]){
		for(ll j=i*i;j<n;j+=i)is[j]=0;
		ps.pb(i);
	}
	imp(ps)
}

int main(){FIN;
	ll n=200;
	criba(n);
	return 0;
}
