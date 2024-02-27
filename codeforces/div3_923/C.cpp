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
		ll n,m,k; cin>>n>>m>>k;
		vector<ll>a(n),b(m);
		set<ll>sta,stb;
		fore(i,0,n)cin>>a[i],sta.insert(a[i]);
		fore(i,0,m)cin>>b[i],stb.insert(b[i]);
		ll ca=0,cb=0;
		for(auto i:sta)if(i<=k&&!stb.count(i))ca++;
		for(auto i:stb)if(i<=k&&!sta.count(i))cb++;
		ll res=ca<=k/2&&cb<=k/2;
		fore(i,1,k+1)if(!sta.count(i)&&!stb.count(i))res=0;
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
