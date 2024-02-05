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
		ll n; cin>>n;
		ii a[n];
		vector<ll>c(4,1);
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
			if(a[i].fst<0)c[0]=0;
			if(a[i].fst>0)c[1]=0;
			if(a[i].snd<0)c[2]=0;
			if(a[i].snd>0)c[3]=0;
		}
		ll res=0;
		fore(i,0,4)if(c[i])res++;
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
