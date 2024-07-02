#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
void imp(vector<ii>v) {for(auto dfgdfh:v)cout<<dfgdfh.fst<<","<<dfgdfh.snd<<" ";cout<<"\n";}
void imp(vector<ll>v) {for(auto dfgdfh:v)cout<<dfgdfh<<" ";cout<<"\n";}
// void imp(vector<int>v) {for(auto dfgdfh:v)cout<<dfgdfh<<" ";cout<<"\n";}
const ll B=500; //316 447

struct BL{
	ll sq,q,n,cnt=0; vector<ii>val,a;
	BL(){}
	BL(ll N):sq(sqrt(N)+0.5),q((N+sq-1)/sq),n(N),cnt(0),
	val(q,{-1,-1}),a(n,{-1,-1}){
		// cout<<"init "<<N<<": "<<sq<<" sq | "<<n<<" n | "<<q<<" q\n"; imp(a);
		// imp(val);
		// cout<<"\n";
	}
	void upd(ll l, ll r, ll _v){ //assign
		// if(l==0&&r==0)return;
		if(l>=r){
			if(l)upd(0,l,_v);
			upd(r,n,_v);return;}
		// cout<<"upd range "<<l<<","<<r<<" "<<_v<<"\n";
		ii v={cnt++,_v};
		auto doit=[&](ll s, ll e){
			fore(i,s,e)a[i]=v;
		};
		if(l/sq==r/sq){
			doit(l,r);
			return;
		}
		doit(l,(l/sq+1)*sq);
		doit(r/sq*sq,r);
		fore(i,l/sq+1,r/sq)val[i]=v;
	}
	ll query(ll p){
		return max(a[p],val[p/sq]).snd;
	}
};

vector<int> El_Robot_Shor(int n, int q, vector<int> a,
vector<int> u, vector<int> v) {
	vector<int>res(q+1);
	vector<ll>pos(n),fat(n);
	BL h[n];
	vector<ll>bag,bad(n);
	
	auto count=[&](){ // O(sqrt(n)) counts
		bag.clear();
		bad=vector<ll>(n,0);
		fore(i,0,n)h[i]=BL();
		vector<ll>vis(n);
		ll res=0;
		fore(x,0,n)if(!vis[x]){
			ll j=0;
			for(ll y=x;!vis[y];y=a[y],j++)
				vis[y]=1,pos[y]=j,fat[y]=res;
			h[res]=BL(j);
			res++;
		}
		return res;
	};
	auto upd=[&](ll x){ // O(n) upds
		if(bad[x])return;
		bad[x]=1;
		ll l=x,d=n+5;
		for(auto y:bag)if(fat[y]==fat[x]){
			ll dist=(pos[x]-pos[y]+n)%n;
			if(dist<d)d=dist,l=y;
		}
		// cout<<"upd "<<x<<": "<<l<<","<<x<<"\n";
		h[fat[x]].upd(pos[l],pos[x],x);
		// imp(h[fat[x]].a);
		// imp(h[fat[x]].val);
		// cout<<"\n";
		bag.pb(x);
	};
	ll c=count();
	auto calc=[&](){
		return (n-c)&1?-1:(n-c)/2;
	};
	res[0]=calc();
	auto nxt=[&](ll x){
		return h[fat[x]].query(pos[x]);
	};
	
	// fore(x,0,n)cout<<x<<": "<<bad[x]<<"| "<<fat[x]<<" "<<pos[x]<<" "<<nxt(x)<<"\n";
	fore(i,1,q+1){
		ll x=u[i-1],y=v[i-1];
		// cout<<"query "<<i-1<<": "<<x<<","<<y<<":\n";
		// imp(a);
		// imp(bag);
		// fore(x,0,n)cout<<x<<": "<<bad[x]<<" "<<nxt(x)<<"\n";
		// imp(bad);
		// cout<<"\n";
		if(x!=y){
			ll same=0;
			if(SZ(bag)>=B)c=count(),same=fat[x]==fat[y];
			else {
				ll px=bad[x]?x:nxt(x),py=bad[y]?y:nxt(y);
				// cout<<px<<" --> "<<py<<"\n";
				if(px==-1||py==-1){
					if(px==-1&&py==-1&&fat[x]==fat[y])same=1;
				}
				else if(px==py)same=1;
				else {
					ll z=a[px];
					while(z!=px&&z!=py){
						// cout<<z<<"\n";
						if(bad[z])z=a[z];
						else z=nxt(z);
					}
					same=z==py;
				}
			}
			if(same)c++;
			else c--;
			// cout<<same<<" same\n";
			swap(a[x],a[y]);
			upd(x); upd(y);
		}
		// imp(a);
		// cout<<c<<" c\n";
		res[i]=calc();
	}
	// imp(res);
	/*for(auto &i:res){
		if(n>2005&&i!=-1)
	}*/
	return res;
}