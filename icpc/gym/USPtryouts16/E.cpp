#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define imp(v) {for(auto i:v) cout << i << " ";cout << "\n";}
using namespace std;
typedef int ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct vertex {
	int next[10],go[10];
	// map<char,int> next,go;
	int p,link;
	char pch;
	vector<int> leaf;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1){
		mset(next,-1),mset(go,-1);}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s, int id){
	int v=0;
	for(char c:s){
		c-='a';
		if(t[v].next[c]==-1){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.pb(id);
}
int go(int v, char c); // c is in [0,10)
int get_link(int v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
int go(int v, char c){
	if(t[v].go[c]==-1)
		if(t[v].next[c]!=-1)t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}
vv dp;

ll dfs(ll x){
	auto &res=dp[x];
	if(res!=-1)return res;
	res=0;
	if(x)res=dfs(get_link(x));
	for(auto id:t[x].leaf)res|=1<<id;
	// cout<<"dfs "<<x<<": "<<res<<"\n";
	return res;
}
const ll MAXN=15,INF=505,MAXS=305; // 328

ll dis[MAXS][1<<MAXN];
pair<ii,char> fa[MAXS][1<<MAXN];

void bfs(ll x, ll mk){
	queue<ii>q;
	mset(dis,-1);
	dis[x][mk]=0; q.push({x,mk});
	fa[x][mk].fst.fst=-1;
	while(SZ(q)){
		auto [x,mk]=q.front(); q.pop();
		// cout<<x<<" "<<mk<<"\n";
		fore(i,0,10){
			ll y=go(x,i),mki=mk|dp[y];
			if(dis[y][mki]==-1){
				dis[y][mki]=dis[x][mk]+1;
				fa[y][mki]={{x,mk},'a'+i};
				q.push({y,mki});
			}
		}
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	aho_init();
	fore(i,0,n+m){
		string s; cin>>s;
		add_string(s,i);
	}
	
	dp.resize(SZ(t),-1);
	fore(i,0,SZ(t))dfs(i);
	bfs(0,0);
	ll x=0,mk=(1<<n)-1;
	fore(i,0,SZ(t))if(dis[i][mk]!=-1)
		if(dis[x][mk]==-1||dis[i][mk]<dis[x][mk])x=i;
	if(dis[x][mk]==-1){
		cout<<"-\n";
		return 0;
	}
	// cout<<x<<" "<<mk<<": "<<dis[x][mk]<<"\n";
	string ans;
	while(x!=-1){
		auto [prox,c]=fa[x][mk];
		ans.pb(c);
		x=prox.fst,mk=prox.snd;
	}
	ans.pop_back();
	reverse(ALL(ans));
	cout<<ans<<"\n";
	return 0;
}
