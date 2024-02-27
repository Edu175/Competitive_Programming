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
const ll MAXN=1000;
ll n,m;
vector<ii>dir={{0,1},{-1,0},{0,-1},{1,0}};
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll cv(ii p){return p.fst*m+p.snd;}
ii cv(ll x){return {x/m,x%m};}
char a[MAXN*MAXN];
bool allowed(ii p){
	auto [i,j]=p;
	if(i<0||j<0||i>=n||j>=m||a[cv(p)]=='#')return 0;
	return 1;
}
ll p[MAXN*MAXN];
void bfs(ii s){
	queue<ii>q;
	p[cv(s)]=-2;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		fore(d,0,SZ(dir)){
			auto y=x+dir[d];
			if(allowed(y)&&p[cv(y)]==-1){
				p[cv(y)]=cv(x);
				q.push(y);
			}
		}
	}
}
int main(){FIN;
	cin>>n>>m;
	ii s,e;
	s=e=dir[0];
	fore(i,0,n*m){
		cin>>a[i];
		if(a[i]=='A')s=cv(i);
		if(a[i]=='B')e=cv(i);
	}
	mset(p,-1);
	bfs(s);
	if(p[cv(e)]==-1){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	vector<ii>v;
	for(auto x=cv(e);x!=-2;x=p[x])v.pb(cv(x));
	reverse(ALL(v));
	string let="RULD",path;
	fore(i,0,SZ(v)-1){
		fore(d,0,4)if(v[i]+dir[d]==v[i+1])path.pb(let[d]);
	}
	cout<<SZ(path)<<"\n"<<path<<"\n";
	return 0;
}
