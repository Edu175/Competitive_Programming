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

vector<ll> mex[200005];

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		ll s=0;
		if(a[i]<0)s=(-a[i]+i)/(i+1);
		for(ll j=a[i]+(i+1)*s,k=s;j<n&&k<=m;j+=(i+1),k++)mex[k].pb(j);
	}
	//cout<<"return\n";return 0;
	fore(i,1,m+1){
		sort(ALL(mex[i]));
		//imp(mex[i]);
		ll res=0;
		fore(j,0,n+1){
			if(j>=SZ(mex[i])||mex[i][j]>res)break;
			if(mex[i][j]==res)res++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
