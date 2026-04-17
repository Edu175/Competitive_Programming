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
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct vertex {
	map<char,int> next,go;
	int p,link;
	char pch;
	vector<int> leaf;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s, int id){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.pb(id);
}
int go(int v, char c);
int get_link(int v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
int go(int v, char c){
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}
vv vis;

void dfs(ll x){
	vis[x]=1;
	if(!x)return;
	ll y=get_link(x);
	if(!vis[y])dfs(y);
}
const ll MAXN=15,INF=505; // 328
ll cost[MAXN][MAXN];
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<string>_a(n),b(m);
	fore(i,0,n)cin>>_a[i];
	fore(i,0,m)cin>>b[i];
	sort(ALL(_a),[&](const string &a, const string &b){
		return SZ(a)>SZ(b);
	});
	aho_init();
	fore(i,0,n)add_string(_a[i],i);
	vis.resize(SZ(t));
	vector<string> a; // maximal words
	fore(i,0,n){
		ll x=0,good=0;
		for(auto j:_a[i]){
			x=go(x,j);
			good=!vis[x];
			if(good)dfs(x);
		}
		if(good)a.pb(_a[i]);
	}
	n=SZ(a);
	fore(i,0,n)fore(j,0,n){
		
	}
	
	return 0;
}
