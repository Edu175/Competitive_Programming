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
#define xl __int128

xl exp(xl a, ll b){
	xl r=1;
	while(b){
		if(b&1)r*=a;
		a*=a,b>>=1;
	}
	return r;
}
ll root(ll k, ll n){
	ll r=pow(n,1./k)-4;
	
	for(;r<0||exp(r,k)<=n;r++)if(r<0)continue;
	return r-1;
}
xl mcm(ll a, ll b){
	return (xl)a*b/gcd(a,b);
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a=-1,b=-1;
		auto cand=[&](ll x, ll y){
			cout<<"cand "<<x<<" "<<y<<"\n";
			if(a==-1){a=x,b=y;return;}
			if(x<a){a=x,b=y;return;}
			if(x==a&&y<b){a=x,b=y;return;}
		};
		for(ll k=60;k>0;k--){
			ll ro=root(k,n);
			cout<<k<<": "<<ro<<"\n";
			vv l(k,-1),r(k,-1);
			xl num=1;
			for(ll i=ro,j=1;j<k&&i>0&&num<=n;i--,j++){
				num=mcm(num,i);
				cout<<i<<" i\n";
				l[j]=num;
			}
			num=1;
			for(ll i=ro+1,j=1;j<k&&num<=n;i++,j++){
				num=mcm(num,i);
				r[j]=num;
			}
			fore(i,1,k){
				xl x=l[i],y=r[k-i];
				if(x!=-1&&y!=-1&&x<=n&&y<=n&&mcm(x,y)==n){
					cand(ro-i+1,ro-i+k);
				}
			}
		}
		if(a==-1)cout<<"NIE\n";
		else cout<<a<<" "<<b<<"\n";
	}
	return 0;
}