#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n;
	while(cin>>n){
		ll m,t; cin>>m>>t;
		ll h[t+1]={};
		if(n<=t)h[n]=1;
		ll res=1;
		fore(i,1,t+1){
			res+=h[i];
			if(i+n<=t)h[i+n]+=h[i];
			if(i+m<=t)h[i+m]+=h[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}
