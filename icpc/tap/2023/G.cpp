#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

struct seg{
	ll h,l,r;
	seg(){}
	seg(ll h, ll l, ll r):h(h),l(l),r(r){}
};
ll n;
seg a[MAXN];
seg b[2][MAXN];
vector<pair<ll,ii>>ED,ed;

void add(ll i, ll j){
	if(i>j)swap(i,j);
	ED.pb({abs(a[i].h-a[j].h),{i,j}});
}
void put(ll i, ll w, set<ii>&st){
	ll y=b[w][i].h;
	st.insert({y,i});
	auto it=st.lower_bound({y,i});
	if(it!=st.begin())add(prev(it)->snd,i);
	if(next(it)!=st.end())add(i,next(it)->snd);
}

void take(ll i, ll w, set<ii>&st){
	ll y=b[w][i].h;
	auto it=st.lower_bound({y,i});
	if(it!=st.begin()&&next(it)!=st.end())add(prev(it)->snd,next(it)->snd);
	st.erase({y,i});
}

void solve(ll w){
	/*vector<pair<ll,ll*>>id;
	fore(i,0,n)id.pb({b[w][i].l,&b[w][i].l}),id.pb({b[w][i].r,&b[w][i].r});
	sort(ALL(id));
	ll k=0;
	fore(i,0,SZ(id)){
		if(i&&id[i].fst!=id[i-1].fst)k++;
		*(id[i].snd)=k;
	}
	k++;*/
	vector<pair<ii,ll>> ev;
	fore(i,0,n)ev.pb({{b[w][i].l,1},i}),ev.pb({{b[w][i].r,-1},i});
	sort(ALL(ev));
	set<ii>st;
	for(auto i:ev){
		if(i.fst.snd==-1)take(i.snd,w,st);
		else put(i.snd,w,st);
	}
}

ll uf[MAXN];
void uf_init(){mset(uf,-1);}
ll uf_find(ll x){return (uf[x]<0?x:uf_find(uf[x]));}
ll uf_join(ll x, ll y){
	x=uf_find(x); y=uf_find(y);
	if(x==y)return 0;
	if(-uf[x]<-uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
	return 1;
}

ll kruskal(){
	sort(ALL(ed)); uf_init();
	ll res=0;
	for(auto i:ed){
		ll x=i.snd.fst,y=i.snd.snd;
		if(uf_join(x,y))res+=i.fst;
	}
	return res;
}

int main(){FIN;
	cin>>n; n++;
	fore(i,0,n){
		ll h,l,r; 
		if(i<n-1)cin>>h>>l>>r;
		else h=0,l=-3e9,r=3e9;
		r++; //M CH
		a[i]=seg(h,l,r);
		b[0][i]=seg(h,l-h,r-h);
		b[1][i]=seg(h,l+h,r+h);
	}
	//O(n) edges
	solve(0);
	solve(1);
	sort(ALL(ED));
	fore(i,0,SZ(ED)){
		if(!i||ED[i]!=ED[i-1])ed.pb(ED[i]);
	}
	/*for(auto i:ed){
		ll x=i.snd.fst,y=i.snd.snd;
		cout<<x<<","<<y<<" ("<<i.fst<<")\n";
	}*/
	//kruskal
	ll res=kruskal();
	cout<<res<<"\n";
	return 0;
}
