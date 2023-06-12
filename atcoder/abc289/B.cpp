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

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[m];
	vector<ll>p(n,-5);
	fore(i,0,m)cin>>a[i],a[i]--,p[a[i]]=i;
	ll s=0;
	vector<ll>res;
	fore(i,0,n){
		if(p[i]>=0){
			//cout<<i-1<<" - "<<i<<"\n";
			continue;
		}
		for(ll j=i;j>=s;j--)res.pb(j);
		//cout<<s<<","<<i<<"\n";
		s=i+1;
	}
	if(s!=n)for(ll j=n-1;j>=s;j--)res.pb(j);
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
