#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size());
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define fst first
#define snd second
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXF=1005,MOD=(119<<23)+1;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}

ll mem[MAXF][MAXF];
ll nCr(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	auto &res=mem[n][k];
	if(res!=-1)return res;
	if(n==0)return res=1;
	return res=add(nCr(n-1,k-1),nCr(n-1,k));
}

ll n,m;
vector<vv> a;
vector<vv> pos;

ll doit(vv l, vv h, vv r){
	// cerr<<"doit\n";
	// imp(l)
	// imp(h)
	// imp(r)
	
	ll res=1;
	while(1){
		ll cl=0,cr=0;
		vector<vv> whs(2,vv(m));
		vv goods(2,1);
		fore(ty,0,2){
			auto &wh=whs[ty];
			auto &good=goods[ty];
			ll val=a[0][(ty?r[0]:l[0])];
			if(!ty&&l[0]>=h[0]){good=0;continue;}
			if(ty&&r[0]>=n){good=0;continue;}
			fore(i,0,m){
				if(l[i]<h[i]&&a[i][l[i]]==val)wh[i]=0;
				else if(r[i]<n&&a[i][r[i]]==val)wh[i]=1;
				else {good=0;break;}
			}
		}
		// imp(goods)
		// fore(ty,0,2)imp(whs[ty])
		if(!goods[0]&&!goods[1]){ // no puedo seguir
			fore(i,0,m){ // quiero que haya terminado
				if(l[i]<h[i]){res=0;break;}
				if(r[i]<n){res=0;break;}
			}
			break;
		}
		fore(ty,0,2){ // sacamos wh[ty] mientras good
			auto &wh=whs[ty];
			auto &good=goods[ty];
			auto &c=(ty?cr:cl);
			while(good){
				c++;
				vv us(m);
				fore(i,0,m){ // es good
					if(wh[i]){
						r[i]++;
						// para la proxima
						good&=r[i]<n;
						us[i]=a[i][r[i]];
					}
					else {
						l[i]++;
						// para la proxima
						good&=l[i]<h[i];
						us[i]=a[i][l[i]];
					}
				}
				good&=us==vv(m,us[0]);
			}
		}
		ll cur=nCr(cl+cr,cl);
		res=mul(res,cur);
	}
	// cout<<"= "<<res<<"\n\n";
	return res;
}

ll f(vv l, vv r, vv h, vv vis){ // add cnt of rs in -1 for speedup
	ll res=0;
	if(count(ALL(vis),0)==0)return 1;
	if(count(ALL(r),-1)==0)return doit(l,h,r);
	fore(mn,0,n)if(!vis[mn]){
		ll good=1;
		fore(i,0,m){
			if(a[i][l[i]]==mn)continue; // good
			if(r[i]!=-1&&a[i][r[i]]!=mn){good=0;break;}
		}
		if(!good)continue;
		vv nl=l,nr=r,nh=h;
		vv nvis=vis; nvis[mn]=1;
		fore(i,0,m){
			if(a[i][nl[i]]==mn)nl[i]++;
			else if(nr[i]==-1)nr[i]=(nh[i]=pos[i][mn])+1;
			else nr[i]++;
		}
		res=add(res,f(nl,nr,nh,nvis));
	}
	return res;
}

int solve(int _n, int _m, vector<vector<int>>& _a)
{
	mset(mem,-1);
	n=_n,m=_m;
	a.resize(m);
	fore(i,0,m){
		a[i]=vv(ALL(_a[i]));
		for(auto &v:a[i])v--;
		a[i].pb(n+i+1);
	}
	sort(ALL(a));
	pos.resize(m);
	fore(i,0,m){
		pos[i].resize(n);
		fore(j,0,n)pos[i][a[i][j]]=j;
	}
	ll res=f(vv(m),vv(m,-1),vv(m,-1),vv(n));
	return res;
}
