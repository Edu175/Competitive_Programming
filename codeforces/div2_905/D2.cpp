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
		ll n,m; cin>>n>>m;
		vector<ll>a(n-1),b(n);
		fore(i,0,n-1)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		sort(ALL(a)); sort(ALL(b));
		vector<ll>to;
		ll p=0;
		fore(i,0,n-1){
			while(p<n&&a[i]>=b[p])p++;
			if(p==n)break;
			to.pb(p);
			p++;
		}
		//imp(b);
		//imp(to);
		ll res=m*(n-SZ(to));
		ll pos=n;
		for(ll i=n-1,j=SZ(to)-1;j>=0;i--,j--){
			if(to[j]!=i)break;
			pos=i;
		}
		//cout<<res<<" - ("<<min(m,b[pos-1])<<"-1)\n";
		if(pos)res-=min(m,b[pos-1]-1);
		//cout<<pos<<": ";
		cout<<res<<"\n";
		//cout<<"\n";
	}
	return 0;
}
