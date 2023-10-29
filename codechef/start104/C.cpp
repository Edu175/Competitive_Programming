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
		ll n,m; cin>>n>>m;
		vector<ll>a(n),b(n),vis(m);
		fore(i,0,n)cin>>a[i],a[i]--;
		ll j=0;
		fore(i,0,n){
			if(i%m==0)vis.clear(),vis.resize(m,0),j=0;
			if(!vis[a[i]])b[i]=a[i],vis[a[i]]=1;
			else {
				while(vis[j])j++;
				b[i]=j;
				vis[j]=1;
			}
		}
		fore(i,0,n)cout<<b[i]+1<<" ";
		cout<<"\n";
	}
	return 0;
}
