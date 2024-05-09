#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto mjgltr:v)cout<<mjgltr.fst<<","<<mjgltr.fst<<" ";cout<<"\n";}
#define impr(v) {for(auto mjgltr:v)cout<<mjgltr<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=70;
string pieza;
ll vis[MAXN],d[MAXN];
ll a[MAXN];
ll n=8;
ll cv(ii x){return x.fst*8+x.snd;}
ii cv(ll x){return {x/8,x%8};}
ii cv(string s){
	ii r={8-(s[1]-'0'),s[0]-'a'};
//	cout<<"cv "<<s<<": "<<r.fst<<","<<r.snd<<"\n";
	return r;
}

bool allowed(ii x){
	return x.fst>=0&&x.fst<8&&x.snd>=0&&x.snd<8&&!a[cv(x)];
}
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}

vector<ll>mov(ll x, string pie=pieza){
	vector<ii>r;
	if(pie=="caballo"){
		vector<ii>d;
		fore(i,-2,3)fore(j,-2,3)if(i&&j){
			vector<ll>v={abs(i),abs(j)};
			sort(ALL(v));
			if(v[0]!=1||v[1]!=2)continue;
			d.pb({i,j});
		}
//		cout<<"caballo: "; imp(d);
		for(auto dir:d)r.pb(cv(x)+dir);
	}
	else if(pie=="rey"){
		vector<ii>d;
		fore(i,-1,2)fore(j,-1,2)if(i||j){
			d.pb({i,j});
		}
//		cout<<"rey: "; imp(d);
		for(auto dir:d)r.pb(cv(x)+dir);
	}
	else if(pie=="dama"){
		auto v0=mov(x,"torre");
		auto v1=mov(x,"alfil");
		for(auto i:v1)v0.pb(i);
		return v0;
	}
	else if(pie=="torre"){
		vector<ii>dir={{1,0},{0,1},{-1,0},{0,-1}};
		for(auto d:dir)for(auto y=cv(x)+d;allowed(y);y=y+d)r.pb(y);
	}
	else if(pie=="alfil"){
		vector<ii>dir={{1,-1},{-1,1},{-1,-1},{1,1}};
		for(auto d:dir)for(auto y=cv(x)+d;allowed(y);y=y+d)r.pb(y);
	}
	else assert(0);
	vector<ll>ret;
	for(auto x:r)if(allowed(x))ret.pb(cv(x));
//	cout<<"mov "<<pie<<" "<<cv(x).fst<<","<<cv(x).snd<<": ";
//	for(auto i:ret)cout<<cv(i).fst<<","<<cv(i).snd<<" ";;cout<<"\n";
	return ret;
}

ll bfs(ll s, ll e){
	mset(d,-1);
	vis[s]=1,d[s]=0;
	queue<ll>q;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:mov(x))if(!vis[y]){
			vis[y]=1;
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d[e];
}

int tablero(string &PIEZA, string &salida, string &llegada, vector<string> &casilla) {
	pieza=PIEZA;
	ii s=cv(salida),e=cv(llegada);
	fore(i,0,n)fore(j,0,n)a[cv(ii({i,j}))]=casilla[i][j]=='X';
	return bfs(cv(s),cv(e));
}
