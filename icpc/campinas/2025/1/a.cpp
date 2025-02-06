#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
bool vis[40];
int main(){
	JET
	ll n,m; cin>>n>>m;
	ii a[m];
	fore(i,0,m){
		cin>>a[i].fst>>a[i].snd; a[i].fst--,a[i].snd--;
	}
	reverse(a,a+m);
	vector<bool> rta;
	fore(i,1,n+1){
		bool res=0;
		fore(j,0,n+1-i){
			mset(vis,0);
			fore(u,j,j+i) vis[u]=1;
			bool y=1;
			fore(u,0,m){
				if(vis[a[u].fst]&&!vis[a[u].snd]){y=0; break;}
				swap(vis[a[u].fst],vis[a[u].snd]);
				fore(i,0,n) cout<<vis[i]<<" ";;cout<<"\n";
			}
			res=res^y;
		}
		rta.pb(res);
	}
	fore(i,0,n) cout<<rta[i]<<" ";
	cout<<"\n";
	return 0;
}


/*
0 1 0 0 
0 1 0 0 
1 0 0 0 
0 0 0 1 
0 0 1 0 
1 0 0 0 
1 0 0 0 
0 1 1 0 
1 0 1 0 
1 1 1 0 
1 1 1 1 
1 1 1 1 
1 1 1 1 
1 1 1 1 
1 0 0 1 

*/