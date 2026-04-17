#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef ll tf;
typedef vector <tf> poly;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const tf MOD=998244353, RT=998244350;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const tf MAXN=1<<18;
ll submod(ll a, ll b){
	a-=b;
	return a<0?a+MOD:a;
}
ll mulmod(LL a, LL b){
	a*=b;
	return a<MOD?a:a%MOD;
}
ll addmod(ll a, ll b){
	a+=b;
	return a>=MOD?a-MOD:a;
}
ll pm(ll a, ll b){
	ll res=1ll;
	while(b){
		if(b&1)res=mulmod(res,a);
		a=mulmod(a,a);b/=2;
	}
	return res;
}
struct CD{
	tf x;
	CD(tf x): x(x){}
	CD() {}
};
CD operator*(const CD& a, const CD& b){return CD(mulmod(a.x,b.x));}
CD operator+(const CD&a, const CD& b){return CD(addmod(a.x,b.x));}
CD operator-(const CD&a, const CD&b){return CD(submod(a.x,b.x));}
poly rts(MAXN+9,-1);
vector <int> INV(MAXN+9,-1);
CD root(int n, bool inv){
	tf r=rts[n]<0?rts[n]=pm(RT,(MOD-1)/n):rts[n];
	return CD(inv?r<=MAXN&&INV[r]<0?INV[r]=pm(r,MOD-2):(r<=MAXN?INV[r]:pm(r,MOD-2)):r);
}
ll inv(ll a){
	return a<=MAXN&&INV[a]<0?INV[a]=pm(a,MOD-2):(a<=MAXN?INV[a]:pm(a,MOD-2));
}

CD cp1[MAXN+9], cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2; m<=n;m=mulmod(m,2)){
		CD wi=root(m,inv);
		for(int j=0; j<n; j+=m){
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
poly multiply(poly& p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1, cnt=0;
	while(m<=n)m+=m, cnt++;
	fore(i,0,m){R[i]=0; fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
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
poly add(poly &a, poly &b){
	int n=SZ(a), m=SZ(b);
	poly ans(max(n,m));
	fore(i,0,max(n,m)){
		if(i<n) ans[i]=addmod(ans[i],a[i]);
		if(i<m) ans[i]=addmod(ans[i],b[i]);
	}
	while(SZ(ans)>1&&!ans.back())ans.pop_back();
	return ans;
}
poly invert(poly &b, int d){
	poly c={inv(b[0])};
	while(SZ(c)<=d){
			int j=2*SZ(c);
			auto bb=b; bb.resize(j);
		poly cb=multiply(c,bb);
		fore(i,0,SZ(cb)) cb[i]=submod(0,cb[i]);
		cb[0]=addmod(cb[0],2);
		c=multiply(c,cb);
		c.resize(j);
	}
	c.resize(d+1);
	return c;
}
pair<poly,poly> divslow(poly &a, poly &b){
	poly q, r=a;
	while(SZ(r)>=SZ(b)){
		q.pb(mulmod(r.back(),inv(b.back())));
		if(q.back()) fore(i,0,SZ(b)){
			r[SZ(r)-i-1]=submod(r[SZ(r)-i-1],mulmod(q.back(),b[SZ(b)-i-1]));
		}
		r.pop_back();
	}
	reverse(ALL(q));
	return {q,r};
}
pair<poly,poly> divide(poly &a, poly &b){
	int m=SZ(a), n=SZ(b), MAGIC=750;
	if(m<n) return {{0},a};
	if(min(m-n,n)<MAGIC)return divslow(a,b);
	poly ap=a; reverse(ALL(ap));
	poly bp=b; reverse(ALL(bp));
	bp=invert(bp,m-n);
	poly q=multiply(ap,bp);
	q.resize(SZ(q)+m-n-SZ(q)+1,0);
	reverse(ALL(q));
	poly bq=multiply(b,q);
	fore(i,0,SZ(bq)) bq[i]=submod(0,bq[i]);
	poly r=add(a,bq);
	return {q,r};
}
vector <poly> tree;
void filltree(poly &x){
	int k=SZ(x);
	tree.resize(2*k);
	fore(i,k,2*k) tree[i]={submod(0,x[i-k]),1};
	for(int i=k-1;i;i--) tree[i]=multiply(tree[2*i],tree[2*i+1]);
}
poly evaluate(poly &a, poly &x){
	filltree(x);
	int k=SZ(x);
	vector <poly> ans(2*k);
	ans[1]=divide(a,tree[1]).snd;
	fore(i,2,2*k) ans[i]=divide(ans[i>>1],tree[i]).snd;
	vector<tf> r; fore(i,0,k) r.pb(ans[i+k][0]);
	return r;
}
poly derivate(poly &p){
	poly ans(SZ(p)-1);
	fore(i,1,SZ(p)) ans[i-1]=mulmod(p[i],i);
	return ans;
}
vector <poly> intree(2*MAXN);
poly interpolate(vector<tf> &x, poly &y){
	filltree(x);
	poly p=derivate(tree[1]);
	int k=SZ(y);
	vector<tf> d=evaluate(p,x);
	fore(i,k,2*k) intree[i]={mulmod(y[i-k],inv(d[i-k]))};
	for(int i=k-1;i;i--){
		poly p1=multiply(tree[2*i],intree[2*i+1]);
		poly p2=multiply(tree[2*i+1],intree[2*i]);
		intree[i]=add(p1,p2);
	}
	return intree[1];
}
int main(){
	JET
	int n,k; cin>>n>>k;
	poly p,t;
	fore(i,0,n+1){
		ll x; cin>>x; p.pb(x);
	}
	fore(i,0,n+1){
		ll x; cin>>x; t.pb(x);
	}
	poly x;
	fore(i,0,n+1){
		x.pb(i);
	}
	poly y1=evaluate(p,x);
	// assert((double)clock()/CLOCKS_PER_SEC<(double)1.);
	poly y2=evaluate(t,x);
	// assert((double)clock()/CLOCKS_PER_SEC<(double)1.); 
	poly x1, x2;
	fore(i,0,n+1){
		x1.pb(submod(i,k));
		x2.pb(addmod(i,k));
	}
	//assert((double)clock()/CLOCKS_PER_SEC<(double)1.4);
	// assert((double)clock()/CLOCKS_PER_SEC<(double)1.); 
	poly p2=interpolate(x1,y1);
	// assert((double)clock()/CLOCKS_PER_SEC<(double)1.);
	poly t2=interpolate(x2,y2);
	poly q=add(p2,t2);
	fore(i,0,n+1) cout<<q[i]<<" ";
	cout<<"\n";
	return 0;
}