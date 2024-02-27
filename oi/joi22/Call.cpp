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
typedef int ll;
typedef pair<ll,ll> ii;

#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=6e6+5;

ll a[MAXN];
ll n,m,k;
ii mem[MAXN];
vector<vector<ll>>mem2;
//inline ll cv(ii x){return m*x.fst+x.snd;}
//inline ii cv(ll x){return {x/m,x%m};}
inline ll cv(ii x){return mem2[x.fst][x.snd];}
inline ii cv(ll x){return mem[x];}
vector<ll>dir;
//vector<ii>diir={{0,1},{-1,0},{0,-1},{1,0}};
//ii operator+(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
//void operator+=(ii &a, ii b){a=a+b;}
bool allowed(ll x, ll w){
	auto [i,j]=cv(x);
	if(w==0&&j>=m-1)return 0;
	if(w==1&&i<=0)return 0;
	if(w==2&&j<=0)return 0;
	if(w==3&&i>=n-1)return 0;
	return 1;
}
ll d[MAXN],vis[MAXN];
deque<pair<ll,bool>>q;
set<ll>r[MAXN],c[MAXN];
/*struct list{
	vector<ll>L,R;
	ll ini,fin;
	list(ll n):L(n),R(n),ini(n),fin(n+1){
		L.pb(n),L.pb(n);
		R.pb(n+1),R.pb(n+1);
	}
	void push(ll x){ //back
		R[L[fin]]=x;
		L[x]=L[fin];
		R[x]=fin;
		L[fin]=x;
	}
	void erase(x){
		R[L[x]]=R[x];
		
	}
};*/

vector<ll>pop;
void go(ll x, ll y, ll g){
	if(vis[y])return;
	d[y]=d[x]+g;
	q.push_front({y,0});
	vis[y]=1;
	pop.pb(y);
}
void popit(){
	for(auto x:pop){
		auto [i,j]=cv(x);
		r[i].erase(j);
		c[j].erase(i);
	}
	pop.clear();
}
ll reach(ll _x, ll _e){
	ii x=cv(_x),e=cv(_e);
	return (max(abs(x.fst-e.fst),abs(x.snd-e.snd))<=k&&
	       abs(x.fst-e.fst)+abs(x.snd-e.snd)<2*k);
}

ll bfs(ll s, ll e){
	mset(d,-1);
	d[s]=0;
	q.push_front({s,0});
	while(SZ(q)){
		auto [x,g]=q.front(); q.pop_front();
		if(!g){
			fore(w,0,4){
				auto y=x+dir[w];
				if(!allowed(x,w)||(!g&&a[y]))continue;
				go(x,y,0);
				popit();
			}
			q.pb({x,1});
		}
		else {
			auto [i,j]=cv(x);
			if(reach(x,e)){
				go(x,e,1);
				return d[e];
			}
			if(i-k>=0)
				for(auto it=r[i-k].upper_bound(j-k);
				it!=r[i-k].end()&&*it<j+k;it++)go(x,cv({i-k,*it}),1);
			if(i+k<n)
				for(auto it=r[i+k].upper_bound(j-k);
				it!=r[i+k].end()&&*it<j+k;it++)go(x,cv({i+k,*it}),1);
			if(j-k>=0)
				for(auto it=c[j-k].upper_bound(i-k);
				it!=c[j-k].end()&&*it<i+k;it++)go(x,cv({*it,j-k}),1);
			if(j+k<m)
				for(auto it=c[j+k].upper_bound(i-k);
				it!=c[j+k].end()&&*it<i+k;it++)go(x,cv({*it,j+k}),1);
			popit();
		}
	}
	return d[e];
}

int main(){FIN;
	cin>>n>>m>>k;
	mem2.resize(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m){
		mem2[i][j]=m*i+j;
		mem[m*i+j]={i,j};
	}
	dir={1,-m,-1,m};
	ii s,e; cin>>s.fst>>s.snd>>e.fst>>e.snd; s.fst--,s.snd--,e.fst--,e.snd--;
	fore(i,0,n*m){
		char c; cin>>c;
		a[i]=(c=='#');
	}
	fore(i,0,n)fore(j,0,m)r[i].insert(j),c[j].insert(i);
	cout<<bfs(cv(s),cv(e))<<"\n";
	return 0;
}
