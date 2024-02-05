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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,x; cin>>n>>x;
		if(x==0){
			fore(i,0,n)cout<<i+1<<" ";
			cout<<"\n";
			continue;
		}
		if(x>=n-1){
			cout<<"-1\n";
			continue;
		}
		vector<ll>b(n);
		b[0]=x+2;
		fore(i,1,x+2)b[i]=i;
		fore(i,x+2,n)b[i]=i+1;
		imp(b);
	}
	return 0;
}
