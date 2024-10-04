#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());
int main(){FIN;
	ll N; cin>>N;
	ll n=rng()%N+1;
	ll g[n][n];
	fore(i,1,n){
		ll p=rng()%i;
		g[p][i]=g[i][p]=1;
	}
	vector<ii>ed;
	fore(i,0,n)fore(j,i+1,n)if(!g[i][j]){
		ed.pb({i,j});
	}
	shuffle(ALL(ed),rng);
	ll m=rng()%max(SZ(ed),1);
	// cout<<SZ(ed)<<" "<<m<<endl;
	fore(i,0,m)g[ed[i].fst][ed[i].snd]=1;
	vector<ll>per(n);
	iota(ALL(per),0);
	shuffle(ALL(per),rng);
	vector<ii>res;
	fore(i,0,n)fore(j,i+1,n)if(g[i][j])res.pb({per[i],per[j]});
	cout<<n<<" "<<SZ(res)<<"\n";
	for(auto [u,v]:res)cout<<u+1<<" "<<v+1<<"\n";
	return 0;
}