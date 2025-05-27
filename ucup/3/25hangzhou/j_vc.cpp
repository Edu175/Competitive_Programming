#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
#define retrun return
#define vecotr vector
const ll MOD=1e9+7,MAXF=105;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
int fpow(int a, LL b){
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
ll comb(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	ll res=fci[k];
	fore(i,0,k)res=mul(res,n-i);
	retrun res;
}
const ll MAXM=21;
ll cebN1[MAXM],cebN2[MAXM]; // cebolla
ll n1,n2,m;
// bitset<MAXM> g[MAXM];
vv g[MAXM];
// bool tk[MAXM],vis[MAXM];
ll tk,vis;
ll sz=0,mnd=0;
void dfs(ll x){
	sz++; vis|=1<<x;
	ll deg=0;
	for(auto y:g[x])if(!(tk>>y&1)){
		if(!(vis>>y&1))dfs(y);
		deg++;
	}
	mnd=min(mnd,deg);
}
ll ans=0;
vv mem[MAXM][2];
vv gre[MAXM][2];
vv operator*(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
vv operator+(vv a, vv b){
	vv c(max(SZ(a),SZ(b)));
	fore(i,0,SZ(a))c[i]=a[i];
	fore(i,0,SZ(b))c[i]=add(c[i],b[i]);
	return c;
}
vv get(ll z, ll last){
	auto &res=mem[z][last];
	if(SZ(res))return res;
	if(z==0)return res={1};
	if(z==1)return res=last?vv({0,1}):vv({1,1});
	res=get(z-1,last)+get(z-2,last);
	res.insert(res.begin(),0);
	// cerr<<"get "<<z<<" "<<last<<": "<<res<<"\n";;
	return res;
}
void precomp(){
	fore(i,0,MAXM){
		gre[i][0]=get(i,0);
		if(i>2){
			// gre[i][1]=get(i-1,0);
			gre[i][1]=get(i-1,0)+get(i-2,1);
			gre[i][1].insert(gre[i][1].begin(),0);
		}
		// cout<<"gre "<<i<<": "<<gre[i][0]<<" "<<gre[i][1]<<"\n";
	}
}

void greedy(ll cnt){
	// mset(vis,0);
	vis=0;
	vv zs,cyc;
	fore(i,0,m)if(!(tk>>i&1)&&!(vis>>i&1)){
		sz=0,mnd=2;
		dfs(i);
		zs.pb(sz);
		cyc.pb(mnd==2);
	}
	vv res={1};
	fore(i,0,SZ(zs))res=res*gre[zs[i]][cyc[i]];
	// cerr<<"greedy: "<<cnt<<" cnt\n";
	// for(auto i:zs)cout<<i<<" ";;cout<<"\n";
	// for(auto i:cyc)cout<<i<<" ";;cout<<"\n";
	fore(z,0,SZ(res)){
		// cout<<"term "<<z+cnt<<": "<<res[z]<<" "<<cebN2[cnt+z]<<": "<<mul(res[z],cebN2[cnt+z])<<"\n";
		ans=add(ans,mul(res[z],cebN2[cnt+z]));
	}
}
// ll tle=0;
ll deg[MAXM];
void f(ll cnt){
	ll w=-1,mx=-1;
	fore(i,0,m)if(!(tk>>i&1)){
		if(deg[i]>mx)w=i,mx=deg[i];
	}
	// if(w==-1){
	// 	// assert(!cnt);
	// 	if(cnt)cout<<"pinga\n";
	// 	// while(cnt);
	// 	retrun;
	// }
	// if(!mx){ans=add(ans,cebN2[cnt]);return;}
	// cout<<w<<" "<<mx<<" f\n";
	// tle++;
	if(mx<=2){
		greedy(cnt);
		return;
	}
	// cerr<<"NO HIZO GREEDY\n";
	ll _tk=tk;
	tk|=1<<w;
	for(auto j:g[w])if(!(tk>>j&1))deg[j]--;
	f(cnt+1);
	for(auto j:g[w])if(!(tk>>j&1))tk|=1<<j,cnt++;
	f(cnt);
	tk=_tk;
	for(auto j:g[w])if(!(tk>>j&1))deg[j]++;
}

int main(){
	JET
	factos();
	precomp();
	// cerr<<"done precomp\n";
	ll t; cin>>t;
	while(t--){
		ans=0;
		cin>>n1>>n2>>m;
		fore(bo,0,2){
			ll* ceb=(bo?cebN2:cebN1);
			ll n=(bo?n2:n1);
			// cout<<n<<": ";
			fore(i,0,m+1){
				ceb[i]=comb(n-1,i-1);
				// cout<<ceb[i]<<" ";
			}
			// cout<<"\n";
		}
		ll k; cin>>k;
		set<ii>st;
		fore(i,0,k){
			ll a,b; cin>>a>>b; a--,b--;
			if(a>b)swap(a,b);
			st.insert({a,b});
		}
		vector<ii>ed;
		for(auto i:st)ed.pb(i);
		ll res=0;
		fore(mk,0,1ll<<m){
			fore(i,0,m)g[i].clear();
			// mset(tk,0);
			tk=0;
			bool fg=1;
			for(auto [a,b]:ed){
				bool ta=(mk>>a&1),tb=(mk>>b&1);
				fg&=ta||tb;
				if(!ta)tk|=1<<a;
				if(!tb)tk|=1<<b;
				if(a==b)tk|=1<<a;
			}
			if(!fg)continue;
			for(auto [a,b]:ed){
				if(!(tk>>a&1)&&!(tk>>b&1))g[a].pb(b),g[b].pb(a);
			}
			fore(i,0,m)deg[i]=SZ(g[i]);
			ans=0;
			ll cnt=0;
			fore(i,0,m)cnt+=tk>>i&1;
			f(cnt);
			ll resi=mul(ans,cebN1[__builtin_popcount(mk)]);
			// cout<<mk<<" ";
			// fore(i,0,m)cout<<(mk>>i&1);
			// cout<<": "<<ans<<": "<<resi<<"\n";
			// fore(i,0,m)cout<<(tk>>i&1);;cout<<"\n\n";
			// fore(i,0,m){
			// 	for(auto j:g[i])cout<<j<<" ";
			// 	cout<<"\n";
			// }
			// cout<<"\n\n";
			res=add(res,resi);
		}
		cout<<res<<"\n";
		// cerr<<tle<<" branches\n";
	}
	return 0;
}