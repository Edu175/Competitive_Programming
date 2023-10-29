#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,MOD; cin>>n>>MOD;
	ll a[n];
	vector<ll>vis(MOD);
	a[0]=1,a[1]=1;
	fore(i,2,n){
		a[i]=(a[i-1]+a[i-2])%MOD;
		if(i&1)vis[a[i]]=1;
	}
	ll flag=1;
	vector<ll>res;
	fore(i,0,SZ(vis))if(vis[i]&&!vis[(MOD-i)%MOD]){flag=0;res.pb(i);}
	/*imp(a);
	cout<<"\n";
	for(ll i=1;i<n;i+=2)cout<<a[i]<<" ";
	cout<<"\n\n";*/
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	imp(res);
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
