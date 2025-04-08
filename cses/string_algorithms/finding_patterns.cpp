#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

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

int main(){FIN;
	string s; cin>>s;
	ll k; cin>>k;
	aho_init();
	fore(i,0,k){
		string t; cin>>t;
		add_string(t,i);
	}
	vv good(SZ(t));
	ll x=0;
	for(auto c:s){
		x=go(x,c);
		good[x]=1;
	}
	vv vis(SZ(t));
	auto dfs=[&](ll x, auto &&dfs){
		if(vis[x])return;
		vis[x]=1;
		if(x)dfs(get_link(x),dfs);
	};
	fore(i,0,SZ(t))if(good[i])dfs(i,dfs);
	vv ans(k);
	fore(i,0,SZ(t))if(vis[i]){
		for(auto id:t[i].leaf)ans[id]=1;
	}
	fore(i,0,k){
		if(ans[i])cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}