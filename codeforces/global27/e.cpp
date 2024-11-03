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
const ll INF=1e17;
ll x,y,Z,k;

ll fn(ll n){return n*(n+1)/2;}
ll csum(ll l, ll r){// []
	if(l>r)return 0;
	return fn(r)-fn(l-1);
}

ll cost(ll n, ll db=0){
	if(n<=0)return INF;
	ll z=Z;
	ll c=0;
	z-=fn(n/k)*k;
	c+=x*n+y*(n/k);
	if(z<=0)return c;
	ll a=(z+n-1)/n;
	c+=a*y;
	if(db){
		cout<<"cost "<<(ll)n<<": "<<(ll)z<<"z "<<(ll)a<<"a = "<<(ll)c<<"c \n";
		// cout<<ll(csum(r,n)*k)<<"\n";
	}
	return c;
}
ll getm(ll n){
	ll z=Z;
	ll res=n/k;
	z-=fn(n/k)*k;
	if(z<=0)return res;
	ll a=(z+n-1)/n;
	res+=a;
	return res;
}
ll ult(ll n){
	ll z=Z;
	z-=fn(n/k)*k;
	if(z<=0)return 0;
	ll a=(z+n-1)/n;
	return a;
}
const ll B=1e4+100;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>x>>y>>Z>>k;
		ll res=INF;
		fore(i,1,B)res=min(res,cost(i));
		fore(m,1,B){
			ll l=1,r=Z;
			while(l<=r){
				ll n=(l+r)/2;
				if(ult(n)>m)l=n+1;
				else r=n-1;
			}
			res=min(res,cost(l));
		}
		// fore(i,1,300){
		// 	ll m=getm(i);
		// 	cout<<i<<" "<<m<<": "<<ll(x*i+m*y)<<" "<<(ll)cost(i)<<"\n";
		// }
		cout<<(ll)res<<"\n";
		// cout<<endl;
	}
	return 0;
}
