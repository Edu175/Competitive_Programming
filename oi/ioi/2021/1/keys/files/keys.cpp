#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fjhg:v)cout<<fjhg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=3e5+5;


ll uf[MAXN];
vector<ll>nxt[MAXN];
set<ll>col[MAXN];
map<ll,vector<ll>>mp[MAXN];
ll find(ll x){return uf[x]<0?x:uf[x]=find(uf[x]);}
void join(ll x, ll y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;

	if(SZ(nxt[x])<SZ(nxt[y]))swap(nxt[x],nxt[y]);
	for(auto i:nxt[y])nxt[x].pb(i);; nxt[y].clear();
	
	if(sizeof(col[x])+sizeof(mp[x])<sizeof(col[y])+sizeof(mp[y])){
		swap(col[x],col[y]);
		swap(mp[x],mp[y]);
		
	}
	// if(sizeof(mp[x])<sizeof(mp[y]))swap(mp[x],mp[y]);
	for(auto i:col[y]){
		col[x].insert(i);
		for(auto j:mp[x][i])nxt[x].pb(j);
		mp[x][i].clear();
	}
	col[y].clear();
	for(auto &[c,v]:mp[y]){
		auto &u=mp[x][c];
		// if(SZ(u)<SZ(v))swap(u,v);
		ll flag=col[x].count(c);
		for(auto i:v){
			if(flag)nxt[x].pb(i);
			else u.pb(i);
		}
		v.clear();
	}
	mp[y].clear();
}
vector<int> find_reachable(vector<int> r, vector<int> u, vector<int> v, vector<int> c){
	ll n=SZ(r);
	mset(uf,-1);
	vector<ll>viv(n,-1);
	fore(i,0,n)col[i]={r[i]};
	auto add_edge=[&](ll u, ll v, ll c){
		if(r[u]==c)nxt[u].pb(v);
		else mp[u][c].pb(v);
	};
	fore(i,0,SZ(u)){
		add_edge(u[i],v[i],c[i]);
		add_edge(v[i],u[i],c[i]);
	}
	auto fin=[&](ll x, auto &&fin)->ll{
		x=find(x);
		return viv[x]==-1?x:viv[x]=fin(viv[x],fin);};
	auto get=[&](ll x){
		x=find(x);
		auto r=fin(x,fin);
		return x==r?-1:r;
	};
	fore(i,0,n){
		// cout<<i<<":\n";
		while(SZ(nxt[find(i)])){
			auto x=find(i),j=nxt[x].back(),y=find(j);
			// cout<<x<<": ";
			// fore(i,0,n)if(find(i)==find(x))cout<<i<<" ";
			// cout<<"\n";
			// cout<<"col ";;for(auto i:col[x])cout<<i<<" ";;cout<<"\n\n";
			
			if(x==y){
				nxt[x].pop_back();
				continue;
			}
			if(get(y)!=-1&&get(y)==x){
				viv[y]=-1;
				nxt[x].pop_back();
				join(x,y);
			}
			else{
				viv[x]=y;
				break;
			}
			
		}
		// cout<<i<<": "<<viv[i]<<"\n";
	}
	
	ll res=n+5;
	vector<vector<ll>>cand(n+1);
	fore(x,0,n)if(viv[find(x)]==-1){
		ll q=-uf[find(x)];
		cand[q].pb(x);
		res=min(res,q);
	}
	// cout<<res<<endl;
	vector<int>ret(n);
	for(auto i:cand[res])ret[i]=1;
	return ret;
}
