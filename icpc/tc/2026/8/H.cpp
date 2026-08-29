#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const int MAXN = 1e6+100;

void fail(){
	cout<<"IMPOSSIBLE\n";
	exit(0);
}
int uf[MAXN];
ll mns[MAXN],mxs[MAXN];
void uf_init(){
	mset(uf,-1);
	fore(i,0,MAXN)mns[i]=mxs[i]=i;
}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){ // x is the father
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	mns[x]=min(mns[x],mns[y]);
	mxs[x]=max(mxs[x],mxs[y]);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

int main(){
	JET
	uf_init();
	ll n,m; cin>>n>>m;
	vector<vector<ii>> has(n);
	fore(i,0,m){
		string s;
		ll x,y; cin>>x>>y>>s;x--,y--;
		if(x>=y)fail();
		ll d = s[0] == 'R';
		has[x].pb({y,d});
	}
	vector<ii> g(n,{-1,-1});
	set<ll> st;
	fore(i,0,n)st.insert(i);
	for(ll x=n-1;x>=0;x--){
		ll cl=-1,cr=MAXN,R=-1;
		for(auto [y,d]:has[x]){
			ll py=uf_find(y);
			if(d)cr=min(cr,mns[py]);
			else cl=max(cl,mxs[py]);
			R=max(R,mxs[py]);
		}
		if(cl>=cr)fail();
		if(!x)R=n-1;
		if(cr>x+1&&x+1<=R)g[x].fst=x+1;
		if(cr<MAXN)g[x].snd=cr;
		vv vec;
		for(auto it=st.lower_bound(x+1);it!=st.end()&&*it<=R;){
			uf_join(x,*it);
			vec.pb(*it);
			it=st.erase(it);
		}
		fore(i,0,SZ(vec)-1){
			ll me=vec[i],he=vec[i+1];
			// assert()
			if((me<cr)==(he<cr))g[mxs[me]].snd=mns[he];
		}
	}
	// show(st)
	// cout<<endl;
	// fore(i,0,n)cerr<<i<<": "<<g[i].fst<<","<<g[i].snd<<"\n";
	vv ans;
	auto rec=[&](ll x, auto &&rec)->void {
		if(x==-1)return;
		rec(g[x].fst,rec);
		ans.pb(x);
		rec(g[x].snd,rec);
	};
	rec(0,rec);
	
	for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	// cout<<endl;
	assert(SZ(ans)==n);
	return 0;
}