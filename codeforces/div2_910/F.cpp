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
const ll MAXN=1005,MAXM=MAXN*MAXN;

ll n,m;
char a[MAXM];
vector<ll>dir;
ll go(ll x, ll d){
	if(d==0&&x%m==m-1)return -1;
	if(d==2&&x%m==0)return -1;
	x+=dir[d];
	if(x<0||x>=n*m)return -1;
	if(a[x]=='#')return -1;
	return x;
}

ll d[MAXM],vis[MAXM],dis[MAXM];
set<ll> st[MAXM];

void bfs(){
	queue<pair<ll,ii>>q;
	fore(i,0,n*m){
		if(a[i]=='#')continue;
		if(i/m==0||i/m==n-1||i%m==0||i%m==m-1){
			q.push({i,{0,i}});
			d[i]+=0;
			vis[i]++;
			st[i].insert(i);
		}
	}
	while(SZ(q)){
		auto [x,p]=q.front(); q.pop();
		fore(w,0,4){
			auto y=go(x,w);
			if(y==-1||vis[y]>=2||st[y].count(p.snd))continue;
			st[y].insert(p.snd);
			vis[y]++;
			d[y]+=p.fst+1;
			q.push({y,{p.fst+1,p.snd}});
		}
	}
}

void bfs2(ll s){
	queue<ll>q;
	q.push(s);
	dis[s]=0;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		fore(w,0,4){
			auto y=go(x,w);
			if(y==-1||dis[y]!=-1)continue;
			dis[y]=dis[x]+1;
			q.push(y);
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		dir={1,-m,-1,m};
		ll s=0,c=0;
		fore(i,0,n*m){
			vis[i]=0;
			d[i]=0;
			st[i].clear();
			dis[i]=-1;
		}
		fore(i,0,n*m){
			cin>>a[i];
			if(a[i]=='V')s=i;
			if(a[i]=='#')c++;
		}
		bfs();
		bfs2(s);
		ll res=MAXM;
		if(vis[s]<2)res=d[s];
		else {
			fore(i,0,n*m)if(a[i]!='#'&&dis[i]!=-1){
				res=min(res,dis[i]+d[i]);
			}
		}
		//cout<<vis[s]<<" "<<d[s]<<" "<<res<<" ";
		cout<<n*m-1-c-res<<"\n";
	}
	return 0;
}
