#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
const ll MAXN=1e5+5;

vector<ll> g[MAXN],g2[MAXN];set<ll> gst[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){ //tree edge, back edge
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
		// else cross edge
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(){
	//fore(i,0,n)idx[i]=0,cmp[i]=-1,g2[i].clear();gst[i].clear();
	qidx=0; qcmp=0;
	mset(idx,0); // NO TEST CASES
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	fore(i,0,n)for(auto j:gst[i])g2[i].pb(j);
	n2=qcmp;
}
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	scc();
	uf_init();
	/*fore(i,0,n2){
		cout<<i<<": ";
		imp(g2[i]);
	}
	cout<<endl;*/
	if(n2==1){
		cout<<"0\n";
		return 0;
	}
	vector<ll>pa(n2),in(n2),out(n2);
	fore(i,0,n)pa[cmp[i]]=i;
	
	fore(i,0,n2)for(auto j:g2[i]){
		uf_join(i,j);
		in[j]++;
		out[i]++;
	}
	vector<ll> Nout[n2],Nin[n2],a,b;
	vector<vector<ll>> nin,nout;
	fore(i,0,n2){
		ll p=uf_find(i);
		if(!in[i])Nin[p].pb(i);
		if(!out[i])Nout[p].pb(i);
	}
	fore(i,0,n2)if(SZ(Nin[i])){
		cout<<i<<": "<<Nin[i]<<" "<<Nout[i]<<"\n";
		nin.pb(Nin[i]);
		nout.pb(Nout[i]);
		fore(j,1,SZ(Nin[i]))a.pb(Nin[i][j]);
		fore(j,1,SZ(Nout[i]))b.pb(Nout[i][j]);
	}
	//cout<<SZ(nin)<<" "<<SZ(nout)<<endl;
	vector<ii>res;
	if(SZ(nin)==1){
		a.pb(nin[0][0]);
		b.pb(nout[0][0]);
	}
	else {
		fore(i,0,SZ(nin)){
			res.pb({nout[i][0],nin[(i+1)%SZ(nin)][0]});
		}
	}
	cout<<cmp[7]<<"777\n";
	if(SZ(a)||SZ(b)){
		cout<<a<<" "<<b<<"\n";
		if(!SZ(a))a.pb(b[0]?0:1);
		if(!SZ(b))b.pb(a[0]?0:1);
		fore(i,0,max(SZ(a),SZ(b))){
			res.pb({b[i%SZ(b)],a[i%SZ(a)]});
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto [x,y]:res){
		cout<<x<<" "<<y<<" non-parsed\n";
		cout<<pa[x]+1<<" "<<pa[y]+1<<"\n";
	}
	return 0;
}
