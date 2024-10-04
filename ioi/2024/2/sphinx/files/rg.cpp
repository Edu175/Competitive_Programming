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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	FIN;
	ll N; cin>>N;
	ll n=rng()%(N-1)+2;
	ll maxm=n*(n-1)/2,minm=n-1;
	ll m=rng()%(maxm-minm+1)+minm;
	ll g[n][n]; mset(g,0);
	fore(i,1,n)g[rng()%i][i]=1;
	vector<ii>ed;
	fore(i,0,n)fore(j,i+1,n)if(!g[i][j])ed.pb({i,j});
	shuffle(ALL(ed),rng);
	fore(i,0,m-minm)g[ed[i].fst][ed[i].snd]=1;
	cout<<n<<" "<<m<<"\n";
	fore(i,0,n)cout<<rng()%n<<" ";;cout<<"\n";
	fore(i,0,n)fore(j,i+1,n)if(g[i][j])cout<<i<<" "<<j<<"\n";
}