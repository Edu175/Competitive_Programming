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
		ll n; cin>>n;
		ll a[n];
		vector<ll> v, vp;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]<i+1)v.pb(a[i]),vp.pb(i+1);
		}
		ll avp[SZ(vp)];
		fore(i,0,SZ(vp))avp[i]=vp[i];
		ll res=0;
		//imp(avp);
		fore(i,1,SZ(v)){
			res+=lower_bound(avp,avp+i,v[i])-avp;
			//cout<<i<<" "<<v[i]<<" "<<lower_bound(avp,avp+i,v[i])-avp<<"\n";
		}
		pres;
	}
	return 0;
}
