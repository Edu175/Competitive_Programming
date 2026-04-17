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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x,y; cin>>x>>y;
		ll n=abs(x-y);
		ll res=1;
		if(n!=0){
			res=0;
			fore(d,1,n+1)res+=n%d==0;
		}
		cout<<res<<"\n";
		fore(i,0,x)cout<<"1 ";
		fore(i,0,y)cout<<"-1 ";
		cout<<"\n";
	}
	return 0;
}
