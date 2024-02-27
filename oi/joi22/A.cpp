#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	map<ll,vector<ll>>pos;
	fore(i,0,n)cin>>a[i],pos[a[i]].pb(i);
	ll p=0;
	while(p<n){
		auto lwb=lower_bound(ALL(pos[a[p]]),p+1);
		if(lwb==pos[a[p]].end())p++;
		else {
			ll pi=*lwb;
			fore(i,p,pi)a[i]=a[p];
			p=pi;
		}
	}
	for(auto i:a)cout<<i<<"\n";
	return 0;
}
