#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, edu=b; i<edu; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,bool> iib;
const ll MAXN=1000005,MAXC=1005;
//INDEXADO DE 1
ll c;
set<pair<ll,ll>>bl;
struct nodo{
	ll x,y;
	ll ax;
};
bool allowed(nodo v){
	return (!(bl.count({v.x,v.y})||v.x<=0||v.y<=0||v.x>c||v.y>c));
}
nodo dir(nodo v){
	nodo ret=v;
	if(!v.ax){
		if(v.y%4==3)ret.x+=2;
		else ret.x-=2;
	}
	else{
		if(v.x%4==0)ret.y+=2;
		else ret.y-=2;
	}
	return ret;
}
bool vis[MAXC][MAXC];
ll p[MAXC][MAXC];

void bfs(pair<ll,ll> x){
	queue<nodo>q;
	vis[x.fst][x.snd]=1;
	p[x.fst][x.snd]=-1;
	fore(i,0,2){
		nodo next=dir({x.fst,x.snd,(i)});
		if(allowed(next)){
			q.push(next);
			//cout<<next.x<<","<<next.y<<" ";
			vis[x.fst][x.snd]=1;
			p[x.fst][x.snd]=-1;
		}
	}
	cout<<"\n";
	while(SZ(q)){
		auto f=q.front();
		q.pop();
		while(allowed(f)){
			vis[f.x][f.y]=1;
			nodo vec=dir({f.x,f.y,((f.ax)^1)});
			//cout<<f.x<<","<<f.y<<" ";
			if(allowed(vec)&&!vis[vec.x][vec.y]){
				q.push(vec);
				vis[vec.x][vec.y]=1;
				if(vec.ax==1)p[vec.x][vec.y]=f.x;
				else p[vec.x][vec.y]=f.y;
			}
			nodo next=dir(f);
			p[next.x][next.y]=p[f.x][f.y];
			f=next;
			
		}
		//cout<<"\n";
	}
}

 int main(){FIN;
 	cin>>c;
 	pair<ll,ll> s,e;
 	cin>>s.fst>>s.snd>>e.fst>>e.snd;
 	ll n; cin>>n;
 	fore(i,0,n){
 		pair<ll,ll> ni; cin>>ni.fst>>ni.snd;
 		bl.insert(ni);
 	}
 	bfs(s);
 	vector<ll>calle;
 	if(!vis[e.fst][e.snd]){
 		cout<<0;
 		return 0;
 	}
 	ll pdr=p[e.x][e.y];
 	while(pdr!=-1){
 		res.pb(pdr);
 		pdr=p[]
 	}
 	reverse(ALL(calle));
 	vector<ll>res;
 	res.pb(calle[0]);
 	fore(i,1,SZ(calle)){
 		if(calle[i]!=calle[i-1])res.pb(calle[i]);
 	}
 	cout<<1<<"\n";
 	cout<<SZ(res)<<"\n";
 	for(auto i:res)cout<<i<<"\n";
 	return 0;
 }
