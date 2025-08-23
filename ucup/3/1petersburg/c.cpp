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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
set<ii> cand;

void out(ll p){cand.erase({uf[p],p});}
void put(ll p){cand.insert({uf[p],p});}

bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	out(x); out(y);
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	put(x);
	return true;
}

void uf_saca(ll i){ // solo de los 1
	ll p=uf_find(i);
	out(p);
	uf[p]++;
	put(p);
}
ll get(){
	if(!SZ(cand))return 0;
	return -cand.begin()->fst;
}
int main(){FIN;
	ll n,k; cin>>n>>k;
	vv a(n);
	vector<ii>sa;
	set<ll>st;
	fore(i,0,n)cin>>a[i],sa.pb({a[i],i}),st.insert(i);
	string str; cin>>str;
	vv bo(n);
	fore(i,0,n)bo[i]=str[i]=='1';
	uf_init();
	
	fore(i,0,n)if(bo[i])put(i);
	
	fore(i,0,n-1)if(bo[i]&&bo[i+1])uf_join(i,i+1);
	
	// fore(i,0,n)if(uf[i]<0&&bo[i])put(i);
	
	ll res=0;
	sort(ALL(sa));
	
	fore(_,0,n){
		auto [v,i]=sa[_];
		// query
		if(_==0||v!=sa[_-1].fst){
			if(get()>=k)res=v;
		}
		// upd
		auto it=st.lower_bound(i);
		if(bo[i]){
			uf_saca(i);
		}
		else {
			if(it!=st.begin()&&next(it)!=st.end()){
				ll l=*prev(it),r=*next(it);
				if(bo[l]&&bo[r])uf_join(l,r);
			}
		}
		st.erase(i);
	}
	cout<<res<<"\n";
	return 0;
}
