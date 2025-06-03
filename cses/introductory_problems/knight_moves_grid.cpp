#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
vector<ii> dir;
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}

const ll MAXN=1005;

ll dis[MAXN][MAXN];
ll n;
bool allowed(ii x){return x.fst>=0&&x.fst<n&&x.snd>=0&&x.snd<n;}
void bfs(ii s){
	#define D(i) dis[(i).fst][(i).snd]
	mset(dis,-1);
	queue<ii>q;
	D(s)=0; q.push(s);
	while(q.size()){
		auto x=q.front(); q.pop();
		for(auto di:dir){
			auto y=x+di;
			if(allowed(y)&&D(y)==-1){
				D(y)=D(x)+1;
				q.push(y);
			}
		}
	}
}

int main(){FIN;
	fore(i,0,2)fore(j,0,2)fore(k,1,3){
		ll l=k^1^2;
		dir.push_back({(i*2-1)*k,(j*2-1)*l});
	}
	cin>>n;
	bfs({0,0});
	fore(i,0,n){
		fore(j,0,n)cout<<dis[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}