#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353,MAXN=5e5+5,MAXF=MAXN*4;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
ll comb(ll a, ll b){
	return nCr(a+b,a);
}
// example that supports range reverse and addition updates, and range sum query
// (commented parts are specific to this  problem)
random_device rd;
mt19937 rng(rd());
typedef struct item *pitem;
struct item {
	int pr,cnt,val;
//	int sum; // (paramters for range query)
//	bool rev;int add; // (parameters for lazy prop)
	pitem l,r;
	item(int val): pr(rng()),cnt(1),val(val),l(0),r(0)/*,sum(val),rev(0),add(0)*/ {}
};
void push(pitem it){
	if(it){
		/*if(it->rev){
			swap(it->l,it->r);
			if(it->l)it->l->rev^=true;
			if(it->r)it->r->rev^=true;
			it->rev=false;
		}
		it->val+=it->add;it->sum+=it->cnt*it->add;
		if(it->l)it->l->add+=it->add;
		if(it->r)it->r->add+=it->add;
		it->add=0;*/
	}
}
int cnt(pitem t){return t?t->cnt:0;}
// int sum(pitem t){return t?push(t),t->sum:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		// t->sum=t->val+sum(t->l)+sum(t->r);
	}
}
void merge(pitem& t, pitem l, pitem r){
	push(l);push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){ // sz:desired size of l
	if(!t){l=r=0;return;}
	push(t);
	if(sz<=cnt(t->l))split(t->l,l,t->l,sz),r=t;
	else split(t->r,t->r,r,sz-1-cnt(t->l)),l=t;
	upd_cnt(t);
}
void output(pitem t){ // useful for debugging
	if(!t)return;
	push(t);
	output(t->l);printf(" %d",t->val);output(t->r);
}
// use merge and split for range updates and queries
int serieparalelo(vector<ll> &e) {
	ll n=SZ(e);
    vector<vector<ll>>w(n);
    vector<ii>A={{0,1}};
    fore(i,0,n){
    	// e[i]--;
    	ll a=A[e[i]].fst,b=A[e[i]].snd;
    	ll j=i+2;
		A.pb({a,j});
		A.pb({j,b});
		w[i]={SZ(A)-2,SZ(A)-1};
	}
    ll m=SZ(A);
	vv dp(m,1),nod(m,0);
    for(ll i=n-1;i>=0;i--){
    	ll a=e[i],b=w[i][0],c=-1;
		c=w[i][1];
		nod[b]+=1;
		dp[a]=dp[a]*dp[b]%MOD*dp[c]%MOD*comb(nod[a],nod[b]+nod[c])%MOD;
		nod[a]+=nod[b]+nod[c];
    }
    return dp[0];
}

vv g[MAXN];

ll a[MAXN];
map<ii,ll> mp;
ll good;
vv e;
pitem rt;
void dfs(ll x){
	// cout<<"dfs "<<x<<": ";
	// output(rt);
	// cout<<"\n";
	if(a[x]+1>=cnt(rt)){good=0;return;}
	pitem L,l,r,R;
	ll pos=a[x];
	split(rt,L,rt,pos);
	split(rt,l,rt,1);
	split(rt,r,rt,1);
	R=rt;
	ll u=l->val,v=r->val;
	
	merge(rt,L,l);
	pitem m = new item(x);
	merge(rt,rt,m);
	merge(rt,rt,r);
	merge(rt,rt,R);
	
	// ll u=p[a[x]],v=p[a[x]+1];
	ll now=SZ(mp);
	ll fat=mp[{u,v}];
	e.pb(fat);
	// imp(p)
	// cout<<"dfs "<<x<<": "<<u<<" "<<v<<"\n";
	mp[{u,x}]=now;
	mp[{x,v}]=now+1;
	// p.insert(p.begin()+a[x]+1,x);
	for(auto y:g[x])dfs(y);
	
	// l m r
	split(rt,l,rt,pos+1);
	split(rt,m,rt,1);
	r=rt;
	
	merge(rt,l,r);
	assert(m->val==x);
	free(m);
}

int main(){
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		fore(i,0,n)cin>>a[i];
		mp.clear();
		good=1;
		e.clear();
		mp[{-1,n}]=0;
		rt=0;
		merge(rt,rt,new item(-1));
		merge(rt,rt,new item(n));
		dfs(0);
		ll res=serieparalelo(e);
		cout<<res*good<<"\n";
	}
}