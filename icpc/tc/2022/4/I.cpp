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
		ll n,x; cin>>n>>x;
		ll gr=0;
		fore(i,0,n-1){
			ll a,b; cin>>a>>b;
			if(a==x||b==x)gr++;
		}
		ll res;
		if(gr<2)res=1;
		else res=(n-3)%2;
		if(res)cout<<"Ayush\n";
		else cout<<"Ashish\n";
	}
	return 0;
}
