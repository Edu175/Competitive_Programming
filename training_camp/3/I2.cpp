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
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll l=-1,res=0;
	map<ll,vector<ll>> oc;
	fore(i,0,n){
		oc[a[i]].pb(i);
		ll sz=SZ(oc[a[i]]);
		if(sz>=k)l=max(l,oc[a[i]][sz-k]);
		res+=l+1;
		//cout<<i<<": "<<l<<"\n";
	}
	pres;
	return 0;
}
