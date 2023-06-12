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
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	ll a[n]; fore(i,0,n)cin>>a[i];
	ll res=2e10+5;
	fore(i,0,1ll<<n){
		ll g0=0,g1=0;
		fore(j,0,n){
			if(i&(1ll<<j))g1+=a[j];//,cout<<1<<" ";
			else g0+=a[j];//,cout<<0<<" ";
		}
		res=min(res,abs(g1-g0));
		//cout<<"| "<<g1<<" "<<g0<<" = "<<abs(g1-g0)<<"\n";
	}
	pres;
	return 0;
}
