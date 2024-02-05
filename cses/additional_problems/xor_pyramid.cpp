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
const ll MAXN=2e5+5;

//ll fac[MAXN];

ll nCr(ll n, ll k){
	return (n|k)==n;
}

int main(){FIN;
	//fac[0]=0;
	//fore(i,1,MAXN)fac[i]=fac[i-1]+__builtin_ctzll(i);
	ll n; cin>>n;
	vector<ll>a(n);
	ll res=0;
	fore(i,0,n){
		cin>>a[i];
		if(nCr(n-1,i))res^=a[i];
	}
	cout<<res<<"\n";
	return 0;
}
