#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-10;
int main(){FIN;
	vector<vv> a(3,vv(6));
	fore(i,0,3)fore(j,0,6)cin>>a[i][j];
	vector<vector<ld>> p(3,vector<ld>(3)); // p de que gane i
	
	fore(i,0,3)fore(j,0,3){
		auto &res=p[i][j];
		ll tot=0;
		fore(k,0,6)fore(l,0,6){
			ll v=a[i][k],w=a[j][l];
			if(v!=w){
				tot++;
				res+=v>w;
			}
		}
		if(tot==0)res=0;
		else res/=tot;
	}
	
	vv wins(3,1); // dice i
	fore(i,0,3){
		fore(j,0,3)if(i!=j)wins[i]&=p[i][j]>=0.5-EPS;
	}
	ll w=-1;
	// imp(wins)
	fore(i,0,3)if(wins[i])w=i;
	if(w==-1)cout<<"No dice\n";
	else cout<<w+1<<"\n";
	return 0;
}
