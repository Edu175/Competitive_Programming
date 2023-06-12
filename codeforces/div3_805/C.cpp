#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll u[n];
		map<ll,vector<ll>>oc;
		fore(i,0,n)cin>>u[i],oc[u[i]].pb(i);
		while(k--){
			ll a,b; cin>>a>>b;
			if(SZ(oc[a])&&SZ(oc[b])){
				if(oc[a][0]<=oc[b][SZ(oc[b])-1])cout<<"YES\n";
				else cout<<"NO\n";
			}
			else cout<<"NO\n";
		}
	}
	return 0;
}
