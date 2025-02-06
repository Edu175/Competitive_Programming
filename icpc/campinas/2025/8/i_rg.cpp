#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b; i<jet;i++)
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

random_device rd;
mt19937 rng(rd());

int main(){
    JET
    ll N,M,V; cin>>N>>M>>V;
	ll n=rng()%(N-1)+2;
	M=max(M,n-1);
	M=min(M,n*(n-1)/2);
	ll g[n][n]; mset(g,0);
	fore(i,1,n)g[rng()%i][i]=1;
	vector<ii>all;
	fore(i,0,n)fore(j,i+1,n)if(!g[i][j])all.pb({i,j});
	ll m=rng()%(M-(n-1)+1);
	shuffle(ALL(all),rng);
	fore(i,0,m)g[all[i].fst][all[i].snd]=1;
	ll deg=count(g[0],g[0]+n,1);
	cout<<n<<" "<<m+n-1<<" "<<rng()%deg+1<<"\n";
	fore(i,0,n)fore(j,i+1,n)if(g[i][j]){
		cout<<i+1<<" "<<j+1<<" "<<rng()%(V+1)<<"\n";
	}
}