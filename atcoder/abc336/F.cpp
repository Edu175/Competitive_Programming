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
typedef vector<vector<ll>> node;
ll n,m;
node transf(node a, ll x, ll y){
	ll h[n][m]={};
	//cout<<x<<" "<<y<<"\n";
	//fore(i,0,n){imp(a[i]);}cout<<"----\n";
	fore(i,0,n-1)fore(j,0,m-1){
		if(h[i+x][j+y])continue;
		swap(a[i+x][j+y],a[n-(i+1)+x-1][m-(j+1)+y-1]);
		h[i+x][j+y]=h[n-(i+1)+x-1][m-(j+1)+y-1]=1;
	}
	//fore(i,0,n){imp(a[i]);}cout<<"\n";
	return a;
}
const ll C=10;
map<node,ll> bfs(node s){
	queue<node>q;
	map<node,ll>d;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		if(d[x]>=C)break;
		fore(i,0,2)fore(j,0,2){
			auto y=transf(x,i,j);
			if(d.count(y))continue;
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}

int main(){FIN;
	cin>>n>>m;
	vector<vector<ll>>a(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m){cin>>a[i][j],a[i][j]--;}
	node e(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)e[i][j]=m*i+j;
	auto d=bfs(a);
	ll res=40;
	for(auto [i,w]:bfs(e))if(d.count(i))res=min(res,w+d[i]);
	if(res>20)cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
