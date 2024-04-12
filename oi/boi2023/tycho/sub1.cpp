#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,boi=b;i<boi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skdauf:v)cout<<skdauf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll b,p,d,n; cin>>b>>p>>d>>n;
	vector<ll>a;
	map<ll,ll>mp;
	fore(i,0,n){
		ll x; cin>>x; a.pb(x);
		mp[x%p]++;
	}
	ll res=b+d*b;
	fore(t,0,p){
		ll q=(b+t+p-1)/p-1;
		q-=mp[(p-t)%p];
		res=min(res,q*d+b+t);
	}
	cout<<res<<"\n";
	return 0;
}
