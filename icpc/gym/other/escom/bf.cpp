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
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXV=2e5+5;
int cr[MAXV];
void cribonha(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(LL j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
vv dame(ll n){
	set<ll>st;
	while(n>1){
		ll p=(cr[n]==-1?n:cr[n]);
		st.insert(p);
		n/=p;
	}
	vv a;
	for(auto i:st)a.pb(i);
	return a;
}
struct UnionFind {
	int n,comp,dif=0;
	vector<int> uf,si,hist;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1),hist(n){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	
	void add(int x){/*cout<<"add "<<x<<"\n";*/dif+=hist[x]++==0;}
	bool join(int x, int y){
		add(x); add(y);
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;
		return true;
	}
	ii get(){return {comp,dif};}
};
int main(){FIN;
	cribonha();
	ll n; cin>>n;
	vector<vv> a(n);
	ll hay=0;
	fore(i,0,n){
		ll x; cin>>x;
		a[i]=dame(x);
		hay|=SZ(a[i])>0;
		// imp(a[i])
	}
	if(!hay){
		cout<<"1 1\n";
		return 0;
	}
	auto upd=[&](UnionFind &uf, ll i){
		if(i>=n)i-=n;
		fore(j,0,SZ(a[i])){
			ll u=a[i][j],v=a[i][(j+1)%SZ(a[i])];
			uf.join(u,v);
		}
	};
	ii obj;
	UnionFind uf(MAXV);
	fore(i,0,n)upd(uf,i);
	obj=uf.get();
	// cout<<obj.fst<<","<<obj.snd<<"\n";
	ll S=-1,E=n+1;
	fore(i,0,n){
		// cout<<"\n"<<i<<"\n";
		UnionFind uf(MAXV);
		ll e=2*n;
		fore(j,i,2*n){
			// cout<<i<<" "<<j<<": "<<uf.get().fst<<","<<uf.get().snd<<"\n";
			if(uf.get()==obj){e=j;break;}
			upd(uf,j);
		}
		if(e-i<E-S)S=i,E=e;
		// cout<<i<<": "<<e<<"\n";
	}
	if(E>n)E-=n;
	cout<<S+1<<" "<<E<<"\n";
	return 0;
}
