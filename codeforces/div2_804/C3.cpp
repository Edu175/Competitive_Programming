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
ll MOD=1000000007;

ll factorial(ll x){
	ll res=1;
	fore(i,1,x+1)res=(res*i)%MOD;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		ll oc[n];
		fore(i,0,n){
			cin>>a[i];
			oc[a[i]]=i;
		}
		ll l=min(oc[0],oc[1]);
		ll r=max(oc[0],oc[1]);
		ll res=1;
		ll ins=r-l-1;
		//cout<<l<<" "<<r<<" "<<ins<<"\n";
		fore(i,2,n){
			if(oc[i]<r&&oc[i]>l)res*=ins,ins--;
			else if(oc[i]<l)ins+=l-oc[i]-1,l=oc[i];
			else if(oc[i]>r)ins+=oc[i]-r-1,r=oc[i];
			res%=MOD;
			//cout<<i<<": "<<l<<" "<<r<<" "<<ins<<"\n";
		}
		pres;
	}
	return 0;
}
