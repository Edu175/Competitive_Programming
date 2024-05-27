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
	ll n; cin>>n;
	vector<ll>p(n),a(n);
	fore(i,0,n)cin>>p[i],a[p[i]]=i;
	map<ii,vector<ll>>mp;
	fore(mk,0,1ll<<n){
		ll l=-1,r=n;
		vector<ll>is(n,1);
		for(auto i:a)if(is[i]){
			if(mk>>i&1){
				fore(j,i,n)is[j]=0;
				r=min(r,i);
			}
			else {
				fore(j,0,i+1)is[j]=0;
				l=max(l,i);
			}
		}
		mp[{l,r}].pb(mk);
	}
	for(auto [par,ms]:mp){
		auto [l,r]=par;
		cout<<l<<","<<r<<": ("<<SZ(ms)<<")\n";
		for(auto mk:ms){
			fore(i,0,n)cout<<(mk>>i&1)+1;
			cout<<"\n";
		}
		cout<<"\n\n";
	}
	return 0;
}
