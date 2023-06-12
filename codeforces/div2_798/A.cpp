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
		string a,b;
		cin>>a>>b;
		sort(ALL(a));
		sort(ALL(b));
		ll posa=0,posb=0;
		ll tia=0,tib=0;
		string res;
		while(posa<n&&posb<m){
			if(a[posa]==b[posb]){
				if(tia<k&&n-posa<m-posb)res+=a[posa],posa++,tia++,tib=0;
				else if(tib<k)res+=b[posb],posb++,tib++,tia=0;
				else res+=a[posa],posa++,tia++,tib=0;
			}
			else{
			if(tia<k&&a[posa]<b[posb])res+=a[posa],posa++,tia++,tib=0;
			else if(tib<k)res+=b[posb],posb++,tib++,tia=0;
			else res+=a[posa],posa++,tia++,tib=0;
			}
		}
		for(auto i:res)cout<<i;
		cout<<"\n";
	}
	return 0;
}
