#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

pair<ll,ll> operator+(pair<ll,ll>p1, pair<ll,ll>p2){
	return {p1.fst+p2.fst,p1.snd+p2.snd};
}
vector<pair<ll,ll>>dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
set<pair<ll,ll>>valid;
map<pair<ll,ll>,bool> vis;
map<pair<ll,ll>,ll> d;

void bfs(pair<ll,ll> s){
	queue<pair<ll,ll>>q;
	q.push(s);
	vis[s]=1;
	d[s]=0;
	while(SZ(q)){
		auto f=q.front();
		q.pop();
		for(auto i:dir){
			auto fi=f+i;
			if(valid.count(fi)){
				if(!vis[fi]){
					q.push(fi);
					vis[fi]=1;
					d[fi]=d[f]+1;
				}
			}
		}
	}
}


int main(){FIN;
	pair<ll,ll> s, e; cin>>s.fst>>s.snd>>e.fst>>e.snd;
	ll n; cin>>n;
	fore(i,0,n){
		ll r,a,b; cin>>r>>a>>b;
		fore(j,a,b+1)valid.insert({r,j});
	}
	bfs(s);
	if(vis[e])cout<<d[e];
	else cout<<-1;
	return 0;
}
