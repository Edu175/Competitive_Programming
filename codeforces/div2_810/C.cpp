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
		ll n,m,k; cin>>n>>m>>k;
		ll a[k];
		fore(i,0,k)cin>>a[i];
		ll sm=0,sn=0;
		ll fln=1,flm=1;
		fore(i,0,k){
			if(a[i]/n>=2)sn+=a[i]/n;
			if(a[i]/n>2)fln=0;
			//cout<<"n: "<<a[i]/n<<"\n";
			if(a[i]/m>=2)sm+=a[i]/n;
			if(a[i]/m>2)flm=0;
			//cout<<"m: "<<a[i]/m<<"\n";
		}
		//cout<<sn<<" "<<sm<<"\n";
		bool resm=sm>=n;
		if(flm&&n%2)resm=0;
		bool resn=sn>=m;
		if(fln&&m%2)resn=0;
		if(resm||resn)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
