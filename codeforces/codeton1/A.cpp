#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n;cin>>n;ll a[n];
		map<ll,ll>v;
		fore(i,0,n)cin>>a[i],v[a[i]]=i+1;
		sort(a,a+n);
		cout<<v[a[0]]<<" "<<v[a[n-1]]<<"\n";
	}
	 return 0;
}
