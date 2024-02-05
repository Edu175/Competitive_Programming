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
#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	ll h;
	vector<ll>pt,;
	Hash (vector<vector<ll>> &a){
		pt.pb(1);
		fore(i,0,n)fore(j,0,m){
			h=(h+a[i][j]*pt.back())%MOD;
			pt.pb(pt.back()*P%MOD);
		}
	}
	void swap(ll x, ll y){
		h=h-
	}
};
ll n,m;
node transf(node a, ll x, ll y){
	fore(i,0,(n+1)/2)fore(j,0,m/2){
		swap(a[i+x][j+y],a[n-(i+1)+x-1][m-(j+1)+y-1]);
		//cout<<i+x<<","<<j+y<<" "<<n-(i+1)+x-1<<","<<m-(j+1)+y-1<<"\n";
	}
	fore(i,0,n){imp(a[i]);}
		cout<<"\n";
		return a; 
}
const ll C=20;
ll bfs(node s, node e){
	queue<node>q;
	map<node,ll>d;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		if(d[x]>C)break;
		fore(i,0,2)fore(j,0,2){
			auto y=transf(x,i,j);
			if(d.count(y))continue;
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	if(!d.count(e)||d[e]>C)return -1;
	return d[e];
}

int main(){FIN;
	cin>>n>>m;
	vector<vector<short>>a(n,vector<short>(m));
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	ll q; cin>>q;
	while(q--){
		ll x,y; cin>>x>>y;
		a=transf(a,x,y);
	}
	return 0;
	node e(n,vector<short>(m));
	fore(i,0,n)fore(j,0,m)e[i][j]=m*i+j+1;
	cout<<bfs(a,e)<<"\n";
	return 0;
}
