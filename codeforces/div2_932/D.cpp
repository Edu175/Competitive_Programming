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
		ll n,c; cin>>n>>c;
		ll res=(c+1)*(c+2)/2;
		//cout<<res<<"\n";
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>p(2);
		for(ll i=n-1;i>=0;i--){
			res+=-(c-a[i]+1)-a[i]/2+p[a[i]&1];
			p[a[i]&1]++;
			//cout<<a[i]<<": "<<-(c-a[i]+1)+p[a[i]&1]<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
