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
	ll pot10[15];
	pot10[0]=1;
	fore(i,1,15){
		pot10[i]=10*pot10[i-1];
	}
	while(t--){
		ll x; cin>>x;
		ll pot;
		fore(i,0,15)if(x>=pot10[i])pot=pot10[i];
		cout<<x-pot<<"\n";
	}
	return 0;
}
