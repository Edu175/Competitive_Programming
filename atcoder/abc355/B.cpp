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

int main(){FIN;
	vector<ii>v;
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		ll x; cin>>x;
		v.pb({x,0});
	}
	fore(i,0,m){
		ll x; cin>>x;
		v.pb({x,1});
	}
	sort(ALL(v));
	ll flag=0;
	fore(i,0,SZ(v)-1)flag|=v[i].snd==0&&v[i+1].snd==0;
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
