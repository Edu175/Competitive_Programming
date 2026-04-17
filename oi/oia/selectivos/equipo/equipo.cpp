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
const ll MAXN=500*5000+5;
int tr[MAXN][30], qid=0, c[MAXN], d[MAXN], p[MAXN];
char h[MAXN];
vector<ll>g[MAXN];
ll add(ll x, char j){
	int &res=tr[x][j-'a'];
	if(res!=-1)return res;
	else {
		++qid; h[qid]=j;
		g[x].pb(qid);
		return res=qid;
	}
}
ll res=0, ans=0;
void dfs(ll u){
	if(c[u]>1&&c[u]*d[u]*d[u]>res)res=c[u]*d[u]*d[u],ans=u;
	//cout<<u<<" "<<h[u]<<": "<<c[u]<<" "<<d[u]<<": "<<c[u]*d[u]*d[u]<<"\n";
	for(auto v:g[u]){
		d[v]=d[u]+1;
		p[v]=u;
		dfs(v);
	}
}

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("equipo.in", ios::in);
	cout.open("equipo.out", ios::out);
	ll m,n; cin>>m>>n;
	string a[n];
	fore(i,0,n)cin>>a[i];
	mset(tr,-1);
	fore(i,0,n){
		ll x=0; c[x]++;
		for(auto j:a[i])x=add(x,j), c[x]++;
	}
	d[0]=0; dfs(0);
	string s;
	while(ans!=0)s.pb(h[ans]),ans=p[ans];
	reverse(ALL(s));
	cout<<res<<"\n"<<s<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

