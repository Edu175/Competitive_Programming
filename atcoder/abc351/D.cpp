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
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

vector<ll>g[MAXN];
char a[MAXN];
ll n,m;
ll cv(ll i, ll j){return m*i+j;}
bool valid(ll i, ll j){
	if(i<0||j<0||i>=n||j>=m)return 0;
	if(a[cv(i,j)]=='#')return 0;
	return 1;
}
ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
ll q=0;
ll vis[MAXN];
set<ll>st;
void dfs(ll x){
	//cout<<x<<"\n";
	if(a[x]=='o'){st.insert(x);return;}
	vis[x]=1;
	q++;
	for(auto y:g[x])if(!vis[y])dfs(y);
}
int main(){FIN;
	cin>>n>>m;
	vector<ii>dir={{1,0},{0,1},{-1,0},{0,-1}};
	fore(i,0,n)fore(j,0,m)cin>>a[m*i+j];
	fore(i,0,n)fore(j,0,m)if(!valid(i,j)){
		for(auto d:dir){
			auto i1=i+d.fst,j1=j+d.snd;
			if(valid(i1,j1))a[cv(i1,j1)]='o';
		}
	}
	/*fore(i,0,n){
		fore(j,0,m)cout<<a[cv(i,j)];;cout<<"\n";
	}*/
	fore(i,0,n)fore(j,0,m)for(auto d:dir){
		auto i1=i+d.fst,j1=j+d.snd;
		auto x=cv(i,j),y=cv(i1,j1);
		if(valid(i,j)&&valid(i1,j1)){
			g[x].pb(y);
			g[y].pb(x);
		}
	}
	ll res=0;
	fore(i,0,n*m)if(!vis[i]){
		//cout<<"comp "<<i<<"\n";
		q=0; st.clear();
		dfs(i);
		res=max(res,q+SZ(st));
	}
	cout<<res<<"\n";
	return 0;
}
