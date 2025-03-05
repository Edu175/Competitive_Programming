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

// se me corto la luz xd

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		// imp(a)
		vv ans={};
		// dif<2e
		set<ii>dif;
		auto get=[&](ll i)->ii{return {a[i+1]-a[i],i};};
		fore(i,0,n-1)dif.insert(get(i));
		fore(i,0,n-1)if(a[i]==a[i+1]){
			if(i)dif.erase(get(i-1));
			dif.erase(get(i));
			if(i+2<n)dif.erase(get(i+1));
			
			
			if(SZ(dif)&&2*a[i]>dif.begin()->fst){
				ans={i,i+1,dif.begin()->snd,dif.begin()->snd+1};
			}
			
			if(i-1>=0&&i+2<n){
				if(a[i+2]-a[i-1]<2*a[i]){
					ans={i-1,i,i+1,i+2};
				}
				
			}
			
			if(i)dif.insert(get(i-1));
			dif.insert(get(i));
			if(i+2<n)dif.insert(get(i+1));

		}
		
		
		if(!SZ(ans))cout<<"-1\n";
		else {
			for(auto i:ans)cout<<a[i]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
