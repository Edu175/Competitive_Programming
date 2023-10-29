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
typedef int ll;
const ll MAXN=1e5+4;
ll a[MAXN];
ll oc[MAXN];
vector<ll>v;
vector<ll> sump[MAXN];

int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,n){
		cin>>a[i];
		if(a[i]<=n)oc[a[i]]++;
	}
	fore(i,1,n+1){
		if(oc[i]>=i)v.pb(i),sump[i].pb(0);
	}
	for(auto &i:v){
		fore(j,0,n){
			sump[i].pb(sump[i][j]);
			if(a[j]==i)sump[i][j+1]++;
		}
	}
	while(q--){
		ll l,r; cin>>l>>r;
		ll res=0;
		for(auto &i:v){
			if(sump[i][r]-sump[i][l-1]==i)res++;
		}
		pres;
	}
	//imp(sump[2]);
	return 0;
}
