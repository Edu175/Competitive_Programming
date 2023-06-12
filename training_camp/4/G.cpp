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
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n){
		cin>>a[i];
	}
	while(q--){
		ll l,r,x; cin>>l>>r>>x;
		bool messi=0;
		ll range=r-l+1;
		ll med=range/2;
		if(range%2)if(l+med==x)messi=1;
		cout<<range<<" "<<med<<"\n";
		if(messi)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
