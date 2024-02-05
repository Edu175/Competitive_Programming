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
	ll t; cin>>t;
	while(t--){
		ii a[4];
		fore(i,0,4)cin>>a[i].fst>>a[i].snd;
		ll res=0;
		fore(i,0,3){
			if(a[i].fst==a[i+1].fst)res=abs(a[i].snd-a[i+1].snd);
			else if(a[i].snd==a[i+1].snd)res=abs(a[i].fst-a[i+1].fst);
		}
		cout<<res*res<<"\n";
	}
	return 0;
}
