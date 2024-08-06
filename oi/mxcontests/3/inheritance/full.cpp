#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,hgfmdg=b;i<hgfmdg;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sldhg:v)cout<<sldhg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<short,short> ii;
const short MAXN=1000,MAXK=1e4,B=100,KB=100;

// #define bint __int128
int P=1777781,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

int pt[MAXK];
struct BL{
	short n;
	short a[MAXK];
	int sum[KB];
	BL(){}
	void upd(short p, short v){
		v+=91;
		short b=p/B;
		int dif=sub(v,a[p]);
		sum[b]=add(sum[b],mul(dif,pt[p]));
		a[p]=v;
	}
};
BL bl[MAXN];
short find(short x, short y){
	fore(i,0,KB)if(bl[x].sum[i]!=bl[y].sum[i]){
		fore(j,i*B,i*B+B)if(bl[x].a[j]!=bl[y].a[j])return j;
	}
	return -1;
}
short datai[MAXK][MAXN];
struct UF{
	short* id; short idx;
	vector<short>*po[MAXN];
	UF(){}
	UF(short n, short idx):idx(idx){
		id=datai[idx];
		// comp=datac[idx];
		fore(i,0,n){
			id[i]=i;//,comp[i].pb(i);
			bl[i].upd(idx,i);
		}
	}
	void join(short x, short y){
		x=id[x],y=id[y];
		if(!po[x])po[x]=new vector<short>({x});
		if(!po[y])po[y]=new vector<short>({y});
		if(SZ(*po[x])<SZ(*po[y]))swap(x,y);
		while(SZ(*po[y])){
			auto i=(*po[y]).back(); (*po[y]).pop_back();
			id[i]=x,(*po[x]).pb(i),bl[i].upd(idx,x);
		}
		delete po[y];
		// for(auto i:comp[y])id[i]=x,comp[x].pb(i),bl[i].upd(idx,x);
		// comp[y].clear();
	}
};
UF uf[MAXK];
int main(){FIN;
	pt[0]=1; fore(i,1,MAXK)pt[i]=mul(pt[i-1],P);
	short n,k; int m; cin>>n>>m>>k;
	vector<pair<pair<int,int>,ii>>ed;
	fore(i,0,m){
		short u,v;
		int w; cin>>u>>v>>w; u--,v--;
		ed.pb({{-w,i},{u,v}});
	}
	sort(ALL(ed));
	
	fore(i,0,k)uf[i]=UF(n,i);
	vector<int>ans(m,-1);
	for(auto [par,ar]:ed){
		auto [x,y]=ar;
		int idx=par.snd; short p=-1;
		p=find(x,y);
		if(p==-1)continue;
		ans[idx]=p;
		uf[p].join(x,y);
	}
	fore(i,0,m)cout<<ans[i]+1<<"\n";
	return 0;
}