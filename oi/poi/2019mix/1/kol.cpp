#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define forr(i,a,b) for(ll i=b-1,skopul=a;i>=skopul;i--)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll K=17,MAXN=1e5+5,INF=MAXN*(1e6+5);

vector<ii>g[MAXN];
ll F[K][MAXN],S[MAXN],E[MAXN],D[MAXN],Dw[MAXN];
ll cnt=0;
void dfs(ll x){
	S[x]=cnt++;
	for(auto [y,w]:g[x])if(y!=F[0][x]){
		D[y]=D[x]+1;
		Dw[y]=Dw[x]+w;
		F[0][y]=x;
		dfs(y);
	}
	E[x]=cnt;
}
ll n;
void lca_init(){
	D[0]=0; F[0][0]=-1;
	dfs(0);
	fore(k,1,K)fore(x,0,n){
		F[k][x]=(F[k-1][x]==-1)?-1:F[k-1][F[k-1][x]];
	}
}
ll lca(ll x, ll y){
	if(D[x]<D[y])swap(x,y);
	forr(k,0,K)if(F[k][x]!=-1&& D[F[k][x]]>=D[y])x=F[k][x];
	if(x==y)return x;
	forr(k,0,K)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}


vector<ii>t[MAXN];
ll d[MAXN];
ll is[MAXN];
void dijkstra(vector<ll>&h){
	priority_queue<ii>pq;
	for(auto i:h)if(is[i])d[i]=0,pq.push({0,i});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(d[x]<dis)continue;
		for(auto [y,w]:t[x]){
			ll nd=dis+w;
			if(d[y]==-1||nd<d[y])d[y]=nd,pq.push({-nd,y});
		}
	}
}
struct qu{ll x,y,idx;};
ll ans[MAXN];
ll T[K][MAXN],V[K][MAXN];
void doit(vector<ll>h, vector<qu>qs){
	if(!SZ(h)){
		for(auto q:qs)ans[q.idx]=-1;
		return;
	}
	set<ll>st;
	for(auto i:h)st.insert(i),is[i]=1;
	for(auto q:qs)st.insert(q.x),st.insert(q.y);
	
	h.clear();
	for(auto i:st)h.pb(i);
	sort(ALL(h),[&](ll a, ll b){return S[a]<S[b];});
	
	fore(i,0,SZ(h)-1)st.insert(lca(h[i],h[i+1]));
	
	h.clear();
	for(auto i:st)h.pb(i);
	sort(ALL(h),[&](ll a, ll b){return S[a]<S[b];});
	
	// cout<<"doit "; imp(h);
	// for(auto i:h)if(is[i])cout<<i<<" ";;cout<<"\n";
	auto add_edge=[&](ll x, ll y, ll w){
		// cout<<"add_edge "<<x<<","<<y<<" "<<w<<"\n";
		t[x].pb({y,w});
		t[y].pb({x,w});
		T[0][y]=x;
	};
	vector<ll>s={h[0]};
	fore(i,1,SZ(h)){
		auto x=h[i];
		while(!(S[s.back()]<=S[x]&&S[x]<E[s.back()]))s.pop_back();
		add_edge(s.back(),x,Dw[x]-Dw[s.back()]);
		s.pb(x);
	}
	dijkstra(h);
	// for(auto i:h)cout<<i<<","<<d[i]<<" ";;cout<<"\n";
	// for(auto i:qs)cout<<i.x<<","<<i.y<<","<<i.idx<<" ";;cout<<"\n";
	for(auto i:h)V[0][i]=d[i];
	T[0][h[0]]=-1;
	fore(k,1,K)for(auto x:h){
		if(T[k-1][x]==-1)T[k][x]=-1;
		else T[k][x]=T[k-1][T[k-1][x]],
		V[k][x]=min(V[k-1][x],V[k-1][T[k-1][x]]);
	}
	for(auto q:qs){
		ll p=lca(q.x,q.y);
		auto query=[&](ll x){ // excluding p
			ll res=INF;
			forr(k,0,K)if(T[k][x]!=-1&&D[T[k][x]]>=D[p]){
				res=min(res,V[k][x]);
				x=T[k][x];
			}
			assert(x==p);
			return res;
		};
		ll &res=ans[q.idx];
		res=2*min({query(q.x),query(q.y),d[p]});
		ll dis=Dw[q.x]+Dw[q.y]-2*Dw[p];
		// cout<<q.idx<<": "<<res<<"+"<<dis<<" = "<<res+dis<<"\n";
		res+=dis;
	}
	for(auto i:h){
		d[i]=-1,is[i]=0;
		t[i].clear();
	}
	// cout<<"\n";
}

int main(){FIN;
	ll r; cin>>n>>r;
	mset(d,-1);
	vector<ll> nod[r];
	vector<qu>qs[r];
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--,nod[a[i]].pb(i);
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	lca_init();
	ll q; cin>>q;
	fore(_,0,q){
		ll x,y,c; cin>>x>>y>>c; x--,y--,c--;
		// nod[c].insert(x);
		// nod[c].insert(y);
		qs[c].pb({x,y,_});
	}
	fore(i,0,r){
		// vector<ll>h;
		// for(auto j:nod[i])h.pb(j);
		// cout<<"color "<<i<<":\n";
		doit(nod[i],qs[i]);
	}
	fore(i,0,q){
		cout<<ans[i]<<"\n";
	}
	return 0;
}