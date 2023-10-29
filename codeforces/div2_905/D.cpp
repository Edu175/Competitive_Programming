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
		vector<ll>a(n),b(n);
		fore(i,1,n)cin>>a[i];
		a[0]=1;
		fore(i,0,n)cin>>b[i];
		sort(ALL(a)); sort(ALL(b));
		ll res=0,p=0;
		fore(i,0,n){
			while(p<n&&a[i]>=b[p])p++;
			if(p==n)res=n-i;
			p++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
