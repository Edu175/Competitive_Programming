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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n),b(m);
		ll x=0,nx=0;
		fore(i,0,n)cin>>a[i],x=x^a[i],nx=nx^(~a[i]);
		fore(i,0,m)cin>>b[i];
		vector<ll>mx=b,mn=b;
		//cout<<x<<" "<<nx<<"\n";
		for(ll bt=35;bt>=0;bt--){
			vector<ll>mxi,mni;
			cout<<bt<<": ";
			fore(i,0,SZ(mx)){
				if(((mx[i]&nx)^x)&(1ll<<bt))mxi.pb(mx[i]);
				else cout<<"saco"<<mx[i]<<" ";
			}
			cout<<"\n";
			fore(i,0,SZ(mn))if(!(((mn[i]&nx)^x)&(1ll<<bt)))mni.pb(mn[i]);
			//imp(mx); cout<<"v\n"; imp(mxi); 
			//imp(mn); cout<<"v\n"; imp(mni); cout<<"\n";
			if(SZ(mxi))/*rmx|=1ll<<bt,*/mx=mxi,cout<<"si\n";
			else cout<<"no\n";
			if(SZ(mni))/*rmn&=~(1ll<<bt),*/mn=mni;
		}
		ll rmn=0,rmx=0;
		ll s0=0,s1=0;
		fore(i,0,SZ(mx))s0|=mx[i];
		fore(i,0,SZ(mn))s1|=mn[i];
		imp(mx); imp(mn);
		cout<<s0<<" "<<s1<<"\n";
		fore(i,0,n)rmx^=s0|a[i],rmn^=s1|a[i];
		cout<<min(x,rmn)<<" "<<max(x,rmx)<<"\n";
	}
	return 0;
}
