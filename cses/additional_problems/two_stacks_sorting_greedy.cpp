#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i+1<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

// WA
// 8
// 7 2 4 1 6 3 8 5
// expected an answer, found IMPOSSIBLE

const ll MAXN=2e5+5;
int uf[MAXN];
set<ll> comp[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	for(auto i:comp[y])comp[x].insert(i);; comp[y].clear();
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
bool same(ll x, ll y){return uf_find(x)==uf_find(y);}
void fail(ll b){if(b){cout<<"IMPOSSIBLE\n";exit(0);}}
int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--,comp[i]={i};
	vv ans(n),vis(n+1);
	ll mex=0;
	set<ll>st;
	uf_init();
	for(auto v:a){
		while(vis[mex]){
			ll p=uf_find(mex);
			comp[p].erase(mex);
			st.erase(mex++);
			if(SZ(comp[p]))st.insert(*comp[p].begin());
		}
		vv h;
		while(SZ(st)&&*st.begin()<v){
			auto it=st.begin();
			h.pb(*it);
			st.erase(it);
		}
		fore(i,0,SZ(h)-1)uf_join(h[i],h[i+1]);
		if(SZ(h))st.insert(h[0]);
		st.insert(v);
		vis[v]=1;
	}
	fore(i,0,n)cerr<<uf_find(i)<<" ";;cerr<<"\n";
	// return 0;
	queue<ll> prox[n];
	fore(i,0,n)prox[uf_find(i)].push(i);
	fore(i,0,n)prox[i].push(n+5);
	vv s[2];
	mex=0;
	auto pop=[&](ll w){
		if(SZ(s[w])&&s[w].back()==mex){
			s[w].pop_back(),mex++;
			return 1;
		}
		return 0;
	};
	auto ne=[&](ll w){return prox[uf_find(s[w].back())].front();};
	fore(i,0,n){
		while(pop(0)||pop(1));
		ll go=0,v=a[i];
		cout<<"starting "<<i<<" "<<a[i]+1<<":\n";
		imp(s[0])
		imp(s[1])
		cout<<"\n";
		
		fore(j,0,2)if(SZ(s[j])){
			if(same(s[j].back(),v))go|=1<<j;
			if(s[j].back()<v)go|=1<<(j^1);
		}
		fail(go==3);
		if(!go){
			go=SZ(s[1])&&(!SZ(s[0])||ne(1)<ne(0));
			go^=1;
		}else go--;
		
		ans[i]=go;
		// fail(SZ(s[go])&&s[go].back()<v);
		prox[uf_find(v)].pop();
		s[go].pb(v);
		
		cout<<"ending "<<i<<" "<<a[i]+1<<":\n";
		imp(s[0])
		imp(s[1])
		cout<<"\n";
	}
	for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}