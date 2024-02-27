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
vector<ii>dir;
ll n,m,k;
ii cvi(ll x){return {x/m,x%m};}
ll cv(ll i, ll j){return m*i+j;}
ll go(ll x, ii d){
	auto [i,j]=cvi(x);
	auto [i1,j1]=d;
	i+=i1,j+=j1;
	if(i>=0&&i<n&&j>=0&&j<m)return cv(i,j);
	else return -1;
}
vector<ll> bfs(vector<ll>&s){
	queue<ll>q;
	vector<ll>d(n*m,-1);
	for(auto i:s)d[i]=0,q.push(i);
	vector<ll>ret;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		ret.pb(x);
		if(d[x]==k)continue;
		for(auto i:dir){
			auto y=go(x,i);
			if(y==-1||d[y]!=-1)continue;
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k;
		dir={{0,1},{-1,0},{0,-1},{1,0}};
		vector<ll>blue,red;
		fore(i,0,n*m){
			char c; cin>>c;
			if(c=='x')blue.pb(i);
			else red.pb(i);
		}
		vector<ll>s,bl(n*m);
		for(auto i:bfs(red))bl[i]=1;
		fore(i,0,n*m)if(!bl[i])s.pb(i);
		vector<ll>reach=bfs(s);
		sort(ALL(reach));
		if(reach==blue)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
