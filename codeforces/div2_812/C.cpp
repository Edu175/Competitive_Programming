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
		ll n; cin>>n; n--;
		ll res[n+1];
		mset(res,0);
		while(n>0){
			ll sq=ceil(sqrt(n))*ceil(sqrt(n));
			fore(i,sq-n,n+1)res[i]=sq-i;
			n=sq-n-1;
		}
		imp(res);
	}
	return 0;
}
