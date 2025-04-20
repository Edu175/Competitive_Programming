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
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx,bmi,bmi2,popcnt,lzcnt")
#define retrun return
#define vecotr vector
const ll MOD=1e9+7,MAXF=105;
int add(int a, int &b){a+=b;if(a>=MOD)a-=MOD;return a;}
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
ll c[MAXM];
vv g[MAXM];
ll bip=1;
ll tmp[2];
void dfs(ll x, ll w){
	tmp[w]++; c[x]=w;
	for(auto y:g[x]){
		if(c[y]==-1)dfs(y,w^1);
		else bip&=c[y]==(w^1);
	}
}
ll vec[MAXM];
int main(){
	JET
	factos();
	ll t; cin>>t;
	while(t--){
		cin>>n1>>n2>>m;
		ll k; cin>>k;
		vv bad(m,1);
		set<ii>st;
		fore(i,0,k){
			ll a,b; cin>>a>>b; a--,b--;
			if(a>b)swap(a,b);
			st.insert({a,b});
			bad[a]=bad[b]=0;
		}
		vector<ii>ed;
		for(auto i:st)ed.pb(i);
		ll good=0;
		fore(i,0,m)good+=!bad[i];
		fore(bo,0,2){
			ll* ceb=(bo?cebN2:cebN1);
			ll n=(bo?n2:n1);
			// cout<<n<<": ";
			fore(i,0,m+1){
				ll b=n-i,c=i+(m-good);
				ceb[i]=comb(b+c-1,c-1);
				// cout<<ceb[i]<<" ";
			}
			// cout<<"\n";
		}
		ll res=0;
        ll acum[m+1][m+1]; mset(acum,0);
		fore(mk,0,1ll<<m){
			ll hay=0,cnt=0;
			fore(i,0,m)hay|=bad[i]&&(mk>>i&1),cnt+=mk>>i&1;
			if(hay)continue;
			memset(c,-1,m*sizeof(ll));
			fore(i,0,m)g[i].clear();
            memset(vec,0,(m+1)*sizeof(ll));
			vec[0]=1;
			bip=1;
			for(auto [a,b]:ed)if(!(mk>>a&1)&&!(mk>>b&1))
				g[a].pb(b),g[b].pb(a);
			fore(i,0,m)if(!bad[i]&&!(mk>>i&1)&&c[i]==-1){
				mset(tmp,0);
				dfs(i,0);
				ll v[m+1]; memcpy(v,vec,(m+1)*sizeof(ll));
				fore(i,0,m+1)vec[i]=i-tmp[0]>=0?v[i-tmp[0]]:0;
				fore(i,0,m+1)if(i-tmp[1]>=0)
					vec[i]=add(vec[i],v[i-tmp[1]]);
			}
			if(!bip)continue;
			fore(z,0,m+1){
				ll a=cnt+z,b=good-z;
                if(a<=m&&b>=0)acum[a][b]=add(acum[a][b],vec[z]);
			}
		}
        fore(a,0,m+1)fore(b,0,m+1)res=add(mul(acum[a][b],mul(cebN1[a],cebN2[b])),res);
		cout<<res<<"\n";
	}
	return 0;
}