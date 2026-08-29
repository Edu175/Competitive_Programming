#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll te(ll a, ll b){return (a+b-1)/b;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x,y,z;
		cin>>n>>x>>y>>z;
		ll op1=te(n,x+y);
		ll res=op1;
		n-=z*x;
		ll op2=z+te(n,x+10*y);
		if(n>=0)res=min(res,op2);
		cout<<res<<"\n";
	}
	return 0;
}
