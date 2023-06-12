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
const ll MAXN=1e5+5;

vector<ll>divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
}
int main(){FIN;
	divisores();
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		ll res=MAXN;
		ll l=0,r=-1,c=m;
		vector<ll>vis(m+1,0);
		while(l<n&&r<n){
			//cout<<l<<" "<<r<<" "<<c<<":\n"; 
			while(c&&l<n&&r<n){
				r++;
				if(r==n)continue;
				for(auto i:divs[a[r]]){
					if(i<=m)c-=(vis[i]==0),vis[i]++;
				}
				//cout<<r<<" "<<c<<"\n";
			}
			if(r<n)res=min(res,a[r]-a[l]);
			for(auto i:divs[a[l]]){
				if(i>m)break;
				vis[i]--,c+=(vis[i]==0);
				//cout<<i<<" v "<<vis[i]<<"\n";
			}
			l++;
		}
		if(res==MAXN)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
