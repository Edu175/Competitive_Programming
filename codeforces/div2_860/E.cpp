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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>c(n+1),vis(2*n);
		vis[0]++;
		for(ll i=n-1;i>=0;i--){
			ll g=i+a[i]+1;
			if(g>n||c[g]==-1)c[i]=-1;
			else c[i]=c[g]+1,vis[c[i]]++;
		}
		vis[c[0]]--;
		vector<ll>res(n-1,2);
		fore(i,0,n-1){
			//imp(vis);
			if(c[i+1]!=-1)vis[c[i+1]]--;
			cout<<i<<": "<<a[i]<<" "<<c[i+1]<<" "<<vis[a[i]-1]<<": ";
			if(a[i]==c[i+1])res[i]=0,cout<<"=";
			else if(c[i+1]!=-1)res[i]=1,cout<<"t";
			else if(vis[a[i]-1])res[i]=1,cout<<"->";
			else cout<<"x";
			cout<<"\n";
		}
		imp(vis);
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
