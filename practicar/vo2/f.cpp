#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct vertex {
	map<char,int> next,go;
	int p,link;
	char pch;
	ll cnt=0;
	// vector<int> leaf;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1),cnt(0){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
	// t[v].leaf.pb(id);
	// cout<<"added string "<<s<<": "<<v<<"\n";
	t[v].cnt++;
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
const ll MAXS=2e5+5;
ll mem[MAXS];
ll cant(ll x){
	auto &res=mem[x];
	if(res!=-1)return res;
	if(!x){
		assert(t[x].cnt==0);
		return res=0;
	}
	return res=t[x].cnt+cant(get_link(x));
}
vv cuantas_terminales_y_sigo_sin_poder_encontrarte(vector<string> a, string s){ // preso en buenos aires
	// cerr<<"\ncuantas terminales\n";
	aho_init();
	for(auto i:a)add_string(i);
	mset(mem,-1);
	vv res(SZ(s));
	ll x=0;
	fore(i,0,SZ(s)){
		x=go(x,s[i]);
		res[i]=cant(x);
		// cout<<i<<": "<<x<<"\n";
	}
	// imp(res);
	return res;
}

int main(){FIN;
	string s; cin>>s;
	ll n; cin>>n;
	vector<string> a(n);
	fore(i,0,n)cin>>a[i];
	auto l=cuantas_terminales_y_sigo_sin_poder_encontrarte(a,s);
	// imp(l)
	for(auto &i:a)reverse(ALL(i));
	reverse(ALL(s));
	auto r=cuantas_terminales_y_sigo_sin_poder_encontrarte(a,s);
	reverse(ALL(r));
	// imp(r)
	ll res=0;
	fore(i,0,SZ(s)-1){
		res+=l[i]*r[i+1];
	}
	cout<<res<<"\n";
	return 0;
}
