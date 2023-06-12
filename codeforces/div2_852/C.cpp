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
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		ll s=0,e=n-1,l=s,r=e;
		vector<ll>vis(n+1);
		while(l<=r&&(a[l]==s||a[l]==e||a[r]==s||a[r]==e)){
			if(a[l]==s||a[l]==e)vis[a[l]]=1,l++;
			if(a[r]==s||a[r]==e)vis[a[r]]=1,r--;
			while(vis[s])s++;
			while(e>=0&&vis[e])e--;
		}
		if(l<=r)cout<<l+1<<" "<<r+1<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
