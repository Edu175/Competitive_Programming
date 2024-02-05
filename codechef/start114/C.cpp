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
		ll n; cin>>n;
		ll a[n][n]={};
		if(n==2){
			cout<<"-1\n";
			continue;
		}
		if(n==3){
			cout<<"9 1 7\n5 4 8\n6 3 2\n";
			continue;
		}
		ll c=(n*n+1)/2;
		a[0][0]=1; c--;
		if(n%2==0)a[n-1][0]=a[n-2][0]=a[n-2][1]=1,c-=3;
		vector<ii>g[n];
		fore(i,0,n)fore(j,0,n)if(i&&j&&!a[i][j])g[max(i,j)].pb({i,j});
		fore(i,0,n){
			//cout<<i<<" "<<c<<": ";
			//for(auto [x,y]:g[i])cout<<x<<","<<y<<" ";;cout<<"\n";
			for(ll j=1; j<SZ(g[i]); j+=2){
				if(c)a[g[i][j].fst][g[i][j].snd]=a[g[i][j-1].fst][g[i][j-1].snd]=1,c-=2;
			}
		}
		//cout<<c<<"\n";
		ll b[n][n];
		ll cnt[2]={2,1};
		fore(i,0,n)fore(j,0,n){
			b[i][j]=cnt[a[i][j]];
			cnt[a[i][j]]+=2;
		}
		//fore(i,0,n){
		//	imp(a[i]);
		//}
		fore(i,0,n){
			imp(b[i]);
		}
	}
	return 0;
}
