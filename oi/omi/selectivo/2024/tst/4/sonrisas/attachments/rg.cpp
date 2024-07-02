#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdjkgh:v)cout<<sdjkgh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

const ll MAXN=1005;

vector<ll>g[MAXN];
ll dist[MAXN][MAXN];
void bfs(ll s){
	auto d=dist[s];
	queue<ll>q;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
}

int main(){
	ll N; cin>>N;
	ll n=rng()%(N-1)+2;
	if(n&1)n++;
	
	ll k=n/2/*rng()%(n-1)+1*/,caso=rng()&1;
	fore(i,0,n)fore(j,0,n)if(rng()%(caso?k:n)==0){
		g[i].pb(j);
		g[j].pb(i);
		// cout<<p<<","<<i<<" edge\n";
	}
	mset(dist,-1);
	fore(x,0,n){
		bfs(x);
	}
	cout<<"1\n"<<n<<" "<<k<<"\n";
	ll con=1;
	fore(i,0,n){
		fore(j,0,n)cout<<dist[i][j]<<" ",con&=dist[i][j]!=-1;
		cout<<"\n";
	}
	cout<<con<<" "<<(2*n*n+k-1)/k<<"\n";
	cout<<"\n\nel grafo es\n";
	fore(i,0,n)for(auto j:g[i])if(i<=j)cout<<i<<" "<<j<<"\n";
	cout<<"conectividad "<<con<<"\n";
	return 0;
}