#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=3e5+5;

ll tr[2][MAXN][55], qidx[2], d[MAXN];
vector<ll>p[MAXN];
vector<vector<ll>>id;
ll add(ll b, ll x, char h){
	ll w;
	if(h>='a'&&h<='z')w=h-'a';
	else w=26+h-'A';
	ll &res=tr[b][x][w];
	if(res)return res;
	else return res=++qidx[b];
}
ll n,res=0;
vector<string> a;
vector<ll>s;

void cnt(vector<ll>v){
	vector<ll>b; ll m=SZ(v);
	for(auto i:v)b.pb(s[i]);
	sort(ALL(b));
	fore(i,0,m)res+=b[i]*(i-(m-1-i));
}
void dfs(ll x){
	vector<pair<ll,ll>>v;
	ll j=d[x];
	for(auto i:p[x]){
		ll m=SZ(a[i]);
		if(j+2<=m)v.pb({id[i][j+2],i});
	}
	sort(ALL(v));
	vector<ll>gr;
	fore(i,0,SZ(v)){
		if(i&&(v[i].fst!=v[i-1].fst))cnt(gr),gr.clear();
		gr.pb(v[i].snd);
	}
	cnt(gr);
}
long long curry(vector<string> &palabras, vector<int> &significados) {
	a=palabras;
	for(auto i:significados)s.pb(i);
	n=SZ(a);
	fore(i,0,2)qidx[i]=0;
	d[0]=-1;
	fore(i,0,n){
		ll x=0;
		p[x].pb(i);
		fore(j,0,SZ(a[i])){
			x=add(0,x,a[i][j]);
			d[x]=j;
			p[x].pb(i);
		}
	}
	id.resize(n);
	fore(i,0,n){
		ll x=0,m=SZ(a[i]);
		id[i].resize(m+1);
		id[i][m]=x;
		for(ll j=m-1;j>=0;j--){
			x=add(1,x,a[i][j]);
			id[i][j]=x;
		}
	}
	fore(i,0,qidx[0])dfs(i);
	return res;
}
