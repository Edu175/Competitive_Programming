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
		ll a,b,n; cin>>a>>b>>n;
		ll res;
		if(a==b)res=0;
		else if((a^b)<n)res=1;
		else if(ll(log2(a^b))<=ll(log2(n-1)))res=2;
		else res=-1;
		//cout<<ll(log2(a^b))<<" "<<ll(log2(n-1))<<"\n";
		pres;
	}
	return 0;
}
