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
	ll n;cin>>n;
	vector<ll>v(n);
	fore(i,0,n)cin>>v[i];
	for(auto i:v)cout<<i;
	cout<<"\n";
	reverse(ALL(v));
	ll res;
	fore(i,0,n)res+=v[i]*(1ll<<i);
	cout<<res<<"\n";
	
	
	 return 0;
}
