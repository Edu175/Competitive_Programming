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
	ll n,m; cin>>n>>m;
	string a[n];
	fore(i,0,n)cin>>a[i];
	string k[m];
	ll p[m];
	fore(i,0,m)cin>>k[i];
	ll sp; cin>>sp;
	fore(i,0,m)cin>>p[i];
	map<string,ll>mp;
	fore(i,0,m)mp[k[i]]=p[i];
	ll sum=0;
	fore(i,0,n){
		if(mp.count(a[i]))sum+=mp[a[i]];
		else sum+=sp;
	}
	cout<<sum<<"\n";
	return 0;
}
