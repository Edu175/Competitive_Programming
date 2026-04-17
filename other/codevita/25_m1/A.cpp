#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// doesn't specify what to output if we can't reach through green bricks
vector<vv> g;

ll bfs(ll s, ll e){
	vv d(SZ(g),-1);
	queue<ll> q;
	d[s]=0;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d[e];
}

int main(){FIN;
	ll n; cin>>n;
	vector<vv> a(n,vv(n));
	ll cnt=0;
	vector<char>ty;
	fore(i,0,n){
		string s; cin>>s;
		string tmp;
		ll po=0;
		for(auto c:s){
			if('0'<=c&&c<='9')tmp.pb(c);
			else {
				ll q=stoll(tmp); tmp.clear();
				ty.pb(c);
				fore(j,po,po+q)a[i][j]=cnt;
				po+=q; cnt++;
			}
		}
		// imp(a[i])
	}
	// imp(ty)
	g.resize(cnt);
	auto agr=[&](ll x, ll y){
		if(ty[x]=='R'||ty[y]=='R')return;
		g[x].pb(y);
		g[y].pb(x);
		// cout<<"added "<<x<<" "<<y<<endl;
	};
	fore(i,0,n)fore(j,0,n){
		if(i)agr(a[i][j],a[i-1][j]);
		if(j)agr(a[i][j],a[i][j-1]);
	}
	ll s=-1,e=-1;
	fore(i,0,SZ(ty)){
		if(ty[i]=='S')s=i;
		if(ty[i]=='D')e=i;
	}
	assert(s!=-1&&e!=-1);
	cout<<bfs(s,e)-1<<"\n";
	return 0;
}
