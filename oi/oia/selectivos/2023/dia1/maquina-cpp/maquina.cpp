#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;

ll tr[MAXN][30],qidx=0;
ll id[355],h[MAXN];
vector<ll>g[MAXN];
ll add(ll x, char c){
	ll &res=tr[x][c-'A'];
	if(res!=-1)return res;
	res=++qidx;
	g[x].pb(res);
	g[res].pb(x);
	return res;
}
ll d[355][MAXN];
/*void dfs(ll x, ll f, ll s){
	for(auto y:g[x])if(y!=f){
		d[s][y]=d[s][x]+1;
		dfs(y,x,s);
	}
}*/
void bfs(ll s){
	queue<pair<ll,ll>>q;
	q.push({id[s],-1});
	while(SZ(q)){
		auto i=q.front(); q.pop();
		ll x=i.fst,f=i.snd;
		for(auto y:g[x])if(y!=f){
			d[s][y]=d[s][x]+1;
			q.push({y,x});
		}
	}
}
int maquina(int T, vector<string> &lineas, vector<string> &orden) {
	mset(tr,-1); mset(h,-1);
	ll n=SZ(lineas),t=T;
	vector<string>a=lineas;
	fore(i,0,n){
		ll x=0;
		for(auto j:a[i]){
			x=add(x,j);
		}
		id[i]=x;
		h[x]=i;
	}
	/*fore(i,0,qidx+1){
		cout<<i<<": ";
		imp(g[i]);
	}*/
	fore(i,0,n)bfs(i);
	/*fore(i,0,n){
		cout<<i<<" "<<a[i]<<" "<<id[i]<<": "<<d[i][0]<<" ";
		fore(j,0,n)cout<<d[i][id[j]]<<" ";
		cout<<"\n";
	}*/
	ll RES=1e9*MAXN*400;
	fore(i,0,n)if(SZ(g[id[i]])==1){
		//cout<<i<<": ";
		ll res=0;
		ll x=i;
		vector<ll>ans;
		set<pair<ll,ll>>st;
		ll q=0;
		fore(i,0,n)if(SZ(g[id[i]])==1){
			st.insert({d[i][0],i});
			q++;
		}
		res+=d[x][0];
		vector<ll>vis(n);
		vis[x]=1; st.erase({d[x][0],x});
		ans.pb(x);
		q--;
		while(q){
			//cout<<x<<","<<res<<" ";
			vector<pair<ll,ll>>b;
			fore(i,0,n)if(!vis[i]&&SZ(g[id[i]])==1){
				b.pb({d[x][id[i]],i});
			}
			sort(ALL(b));
			ll y=b[0].snd;
			if(b[0].fst>t+d[y][0])x=(*st.begin()).snd,res+=t+d[x][0];
			else x=y,res+=b[0].fst;
			vis[x]=1;
			st.erase({d[x][0],x});
			q--;
			ans.pb(x);
		}
		RES=min(res,RES);
		//cout<<x<<","<<res<<"\n";
	}
	/*orden.clear();
	for(auto i:ans)orden.pb(a[i]);*/
	return RES+n;
	//return res+n;
}
