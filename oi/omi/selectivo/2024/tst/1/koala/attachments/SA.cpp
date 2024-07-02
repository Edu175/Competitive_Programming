#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhj:v)cout<<dfhj<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll n;
ll cv(ii x){return x.fst*n+x.snd;}
ii cv(ll x){return {x/n,x%n};}
vector<ii>ed;
ll neg(ll x){
	ii p=cv(x);
	return cv({n-1-p.fst,n-1-p.snd});
}
ll res=0,cnt=0;
void f(vector<ll>id, vector<vector<ll>>comp, ll idx){
	if(idx==SZ(ed)){res=max(res,cnt);return;}
	auto join=[&](ll x, ll y){
		x=id[x],y=id[y];
		if(x==y)return 0;
		if(SZ(comp[x])<SZ(comp[y]))swap(x,y);
		for(auto i:comp[y]){
			if(id[neg(i)]==x)return -1;
			id[i]=x;
			comp[x].pb(i);
		}
		comp[y].clear();
		return 1;
	};
	f(id,comp,idx+1);
	if(join(ed[idx].fst,ed[idx].snd)!=-1){
		cnt++;
		f(id,comp,idx+1);
		cnt--;
	}
}

int Flamante_Koala(int K, int N, vector<int> r1, vector<int> c1,
vector<int> r2, vector<int> c2) {
	n=K;
	ed.clear();
	res=cnt=0;
	fore(i,0,N)ed.pb({cv({r1[i]-1,c1[i]-1}),cv({r2[i]-1,c2[i]-1})});
	random_shuffle(ALL(ed));
	vector<ll>id; vector<vector<ll>>comp;
	fore(i,0,n*n)id.pb(i),comp.pb({i});
	f(id,comp,0);
	return res;
}
