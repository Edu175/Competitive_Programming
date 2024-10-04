#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kjfg:v)cout<<kjfg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;

const ll MAXN=2e6+5,MAXV=1e5+5;
ll uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
void uf_join(ll x, ll y){
	x=uf_find(x);
	y=uf_find(y);
	if(x==y)return;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
}

ll get(ll v, ll h, ll ty){
	if(ty==0)return max(v,h);
	else return min(v,h);
}
struct BL{
	ll B,n;
	vector<deque<ii>>dq;
	vector<vector<ll>>comp;
	vector<vector<ll>>comp2;
	vector<ll>a;
	BL(ll N):B(sqrt(N)+0.5),n((N+B-1)/B*B),dq(n/B),comp(n),comp2(MAXV),a(n){
		// cout<<N<<": "<<B<<" "<<n<<endl;
		fore(i,0,n/B){
			fore(j,i*B,i*B+B-1)uf_join(j,j+1);
			dq[i].pb({0,uf_find(i*B)});
		}
	}
	void single(ll i, ll l, ll r, ll h, ll ty){
		auto go=[&](ll idx, ll v){
			if(l<=idx&&idx<r)return get(v,h,ty);
			return v;
		};
		vector<ll>limpio;
		fore(j,i*B,i*B+B){
			ll p=uf_find(j);
			comp[p].pb(j);
			limpio.pb(p);
		}
		fore(j,i*B,i*B+B)uf[j]=-1;
		for(auto i:limpio){
			for(auto j:comp[i]){
				comp2[go(j,a[i])].pb(j);
			}
			comp[i].clear();
		}
		vector<ll>ord;
		ll done=0;
		for(auto [v,x]:dq[i]){
			if(h==v)done=1;
			if(!done&&v>h)ord.pb(h),done=1;
		}
		if(!done)ord.pb(h);
		dq[i].clear();
		for(auto v:ord)if(SZ(comp2[v])){
			auto &vec=comp2[v];
			fore(i,0,SZ(vec)-1)uf_join(vec[i],vec[i+1]);
			ll rep=uf_find(vec[0]);
			a[rep]=v;
			dq[i].pb({v,rep});
			vec.clear();
		}
	}
	void hole(ll i, ll h, ll ty){
		if(!ty){
			ll rep=-1;
			while(SZ(dq[i])&&dq[i].front().fst<=h){
				ll x=dq[i].front().snd; dq[i].pop_front();
				if(x==-1)rep=x;
				else {
					uf_join(rep,x);
					rep=uf_find(rep);
				}
			}
			dq[i].push_front({h,rep});
			a[rep]=h;
		}
		else {
			ll rep=-1;
			while(SZ(dq[i])&&dq[i].back().fst>=h){
				ll x=dq[i].back().snd; dq[i].pop_back();
				if(x==-1)rep=x;
				else {
					uf_join(rep,x);
					rep=uf_find(rep);
				}
			}
			dq[i].push_back({h,rep});
			a[rep]=h;
		}
	}
	void upd(ll l, ll r, ll h, ll ty){
		if(l/B==r/B){single(l/B,l,r,h,ty);return;}
		single(l/B,l,r,h,ty);
		single(r/B,l,r,h,ty);
		fore(i,l/B+1,r/B)hole(i,h,ty);
	}
};

void buildWall(int n, int q, int op[], int l[], int r[], int h[], int ret[]){
	mset(uf,-1);
	vector<ll>a(n);
	fore(i,0,q)r[i]++,op[i]--;
	BL bl(n);
	fore(i,0,q)bl.upd(l[i],r[i],h[i],op[i]);
	fore(i,0,n){
		a[i]=bl.a[uf_find(i)];
	}
	// fore(i,0,q){
	// 	fore(j,l[i],r[i]){
	// 		if(op[i]==1)a[j]=max(a[j],h[i]);
	// 		else a[j]=min(a[j],h[i]);
	// 	}
	// }
	fore(i,0,n)ret[i]=a[i];
}
