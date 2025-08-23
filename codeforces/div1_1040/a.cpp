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
		ll n; cin>>n;
		vector<array<ll,3>> a(n);
		fore(i,0,n)cin>>a[i][0]>>a[i][1],a[i][2]=i,a[i][1]*=-1;
		sort(ALL(a));
		vv good;
		ll R=-1;
		for(auto [l,r,i]:a){
			r=-r;
			if(r>R){
				good.pb(i);
				R=r;
			}
		}
		cout<<SZ(good)<<"\n";
		for(auto i:good)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
