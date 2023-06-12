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
		ll n,l,r; cin>>n>>l>>r;
		ll a[n];
		ll flag=1;
		fore(i,0,n){
			a[i]=r-(r%(i+1));
			if(a[i]<l||a[i]>r)flag=0;
		}
		if (flag){
			cout<<"YES\n";
			imp(a);
		}
		else cout<<"NO\n";
	}
	return 0;
}
