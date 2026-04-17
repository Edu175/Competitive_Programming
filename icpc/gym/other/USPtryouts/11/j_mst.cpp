#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;
#define maxig(a,b) a=max(a,b)
typedef array<ll,3> tri;

void agr(set<tri> &st, tri v){
	tri fi={v[0]+1,-1,-1};
	auto it=st.upper_bound(fi);
	if(it!=st.begin()){
		auto elem=*prev(it);
		if(elem[1]>=v[1])return;
		if(elem[0]==v[0])st.erase(prev(it));
	}
	auto [my,bo]=st.insert(v);
	while(next(it)!=st.end()){
		auto elem=*next(it);
		if(v[1]>=elem[1])st.erase(next(it));
		else break;
	}
}
ii NEUT={0,-1};
ii query(set<tri> &st, ll y){
	tri fi={y,-1,-1};
	auto it=st.lower_bound(fi);
	if(it==st.begin())return NEUT;
	auto elem=*it;
	return {elem[1],elem[2]};
}
struct MST{
	vector<set<tri>> t; ll n;
	MST(ll n):t(2*n+5),n(n){}
	void upd(ll p, ll q, ii v){
		tri v2={q,v.fst,v.snd};
		for(p+=n;p>0;p>>=1)agr(t[p],v2);
	}
	ii get(ll r, ll y){
		ii res=NEUT;
		for(r+=n;0<r;r>>=1){
			if(r&1)maxig(res,query(t[--r],y));
		}
		return res;
	}
};
struct FTree1d{
	ii ft[MAXN+1];
	void upd(int i0, ii v){
		for(int i=i0+1;i<=MAXN;i+=i&-i)
			maxig(ft[i],v);
	}
	ii get(int i0){ // [0,i0)
		ii r={0,-1};
		for(int i=i0;i;i-=i&-i)
			maxig(r,ft[i]);
		return r;
	}
};

bool good(vv a, vv b){
	ll fg=1;
	fore(i,0,SZ(a))fg&=a[i]<b[i];
	return fg;
}
FTree1d ft;
MST mst(0);

vector<vv> a;
vv val;
ll m;
ii get(ll i){
	if(m==1)return ft.get(a[i][0]);
	if(m==2)return mst.get(a[i][0],a[i][1]);
	ii mx={0,-1};
	fore(j,0,i){
		ii cur={val[j],j};
		if(good(a[j],a[i]))maxig(mx,cur);
	}
	return mx;
}
void upd(ll i){
	ii v={val[i],i};
	if(m==1)ft.upd(a[i][0],v);
	if(m==2)mst.upd(a[i][0],a[i][1],v);
}

int main(){FIN;
	ll n; cin>>m>>n;
	a=vector<vv>(n,vv(m));
	fore(j,0,m)fore(i,0,n)cin>>a[i][j];
	mst=MST(n);
	vv fa(n);
	val=vv(n);
	fore(i,0,n){
		auto rq=get(i);
		fa[i]=rq.snd;
		val[i]=rq.fst+1;
		upd(i);
	}
	ll mx=0;
	fore(i,0,n)if(val[i]>val[mx])mx=i;
	vv res;
	while(mx!=-1)res.pb(mx),mx=fa[mx];
	reverse(ALL(res));
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
