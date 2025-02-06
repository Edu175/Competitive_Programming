#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
// typedef vector<ll> poly;
typedef pair<ll,ll> ii;
const ll MOD=998244353,MAXN=1<<18;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll pm(ll b, ll e){
	// if(e<0)return 0;
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b),e>>=1;
	}
	return res;
}

typedef ll tf;
typedef vector<tf>poly;
const tf RT=3;
// NTT

struct CD {
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){return CD(mul(a.x,b.x));}
CD operator+(const CD& a, const CD& b){return CD(add(a.x,b.x));}
CD operator-(const CD& a, const CD& b){return CD(sub(a.x,b.x));}
vector<tf> rts(MAXN+9,-1);
CD root(int n, bool inv){
	tf r=rts[n]<0?rts[n]=pm(RT,(MOD-1)/n):rts[n];
	return CD(inv?pm(r,MOD-2):r);
}
CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD *a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		CD wi=root(m,inv);
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k]; CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv){
		CD z(pm(n,MOD-2));
		fore(i,0,n)a[i]=a[i]*z;
	}
}
poly multiply(poly &p1, poly &p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	fore(i,0,n)res.pb(cp1[i].x);
	return res;
}

// vv multiply2(vv a, vv b){ // CHANGE IT
// 	vv c(SZ(a)+SZ(b)-1);
// 	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
// 	return c;
// }
// const ll MAXN=1e5+5;
vv g[MAXN];
ll vis[MAXN];
ll sz=0;
void dfs(ll x){
	sz++; vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){
	JET
	// assert(pm(3,(MOD-1)/2)!=1&&pm(3,(MOD-1)/7)!=1&&pm(3,(MOD-1)/17)!=1);
	ll n,m; cin>>n>>m;
	vv us(m),vs(m);
	fore(i,0,m)cin>>us[i];
	fore(i,0,m)cin>>vs[i];
	fore(i,0,m){
		g[us[i]].pb(vs[i]);
		g[vs[i]].pb(us[i]);
	}
	vv szs;
	fore(i,0,n)if(!vis[i]){
		dfs(i);
		szs.pb(sz);
		sz=0;
	}
	// cout<<"szs: ";for(auto i:szs)cout<<i<<"\n";
	vector<vv>p;
	for(auto i:szs){
		vv v(i+1);
		v[0]=1;
		v[i]=1;
		p.pb(v);
	}
	while(SZ(p)>1){
		// for(auto v:p){
		// 	cout<<"{ ";
		// 	for(auto i:v)cout<<i<<" ";
		// 	cout<<"} ";
		// }cout<<"\n";
		vector<vv>pi;
		fore(i,0,SZ(p))if(i%2==0){
			if(i+1<SZ(p))pi.pb(multiply(p[i],p[i+1]));
			else pi.pb(p[i]);
		}
		swap(p,pi);
	}
	// for(auto i:p[0])cout<<i<<" ";;cout<<"\n";
	ll tot=n*(n-1)/2,res=0;
	fore(z,0,n+1){
		ll c=p[0][z];
		if(tot-m-z*(n-z)<0)continue;
		ll val=pm(2,tot-m-z*(n-z));
		ll now=mul(val,c);
		res=add(res,now);
	}
	cout<<res<<"\n";
	return 0;
}