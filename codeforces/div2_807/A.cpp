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
		ll a[2*n];
		fore(i,0,2*n)cin>>a[i];
		sort(a,a+(2*n));
		ll flag=1;
		fore(i,0,n){
			if(a[i]+x>a[i+n])flag=0;
		}
		//imp(a);
		if (flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
