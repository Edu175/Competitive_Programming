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
vv operator*(const vv &a, const vv &b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
int main(){
	JET
	factos();
	ll t; cin>>t;
	while(t--){
		cin>>n1>>n2>>m;
		ll k; cin>>k;
		vv bad(m,1);
		vector<ii>ed;
		fore(i,0,k){
			ll a,b; cin>>a>>b; a--,b--;
			ed.pb({a,b});
			bad[a]=bad[b]=0;
		}
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
		fore(mk,0,1ll<<m){
			ll hay=0,cnt=0;
			fore(i,0,m)hay|=bad[i]&&(mk>>i&1),cnt+=mk>>i&1;
			if(hay)continue;
			ll bip=1;
			// vv zs;
			// vector<vv>ps;
			vv c(m,-1);
			vector<vv> g(m);
			for(auto [a,b]:ed)if(!(mk>>a&1)&&!(mk>>b&1))
				g[a].pb(b),g[b].pb(a);
			vv tmp={0,0};
			auto dfs=[&](ll x, ll w, auto &&dfs)->void{
				tmp[w]++; c[x]=w;
				for(auto y:g[x]){
					if(c[y]==-1)dfs(y,w^1,dfs);
					else bip&=c[y]==(w^1);
				}
			};
			vv vec={1};
			fore(i,0,m)if(!bad[i]&&!(mk>>i&1)&&c[i]==-1){
				tmp={0,0};
				dfs(i,0,dfs);
				// zs.pb(tmp);
				// cout<<tmp<<" tmp\n";
				vv v(max(tmp[0],tmp[1])+1);
				fore(i,0,2)v[tmp[i]]++;
				vec=vec*v;
			}
			// cout<<"cont?\n";
			if(!bip)continue;
			// for(auto i:ps)vec=vec*i;
			// cout<<mk<<" mk ";fore(i,0,m)cout<<(mk>>i&1);;cout<<":\n";
			ll resi=0;
			fore(z,0,SZ(vec)){
				ll a=cnt+z,b=good-z;
				ll term=mul(vec[z],mul(cebN1[a],cebN2[b]));
				// cout<<z<<": "<<a<<" "<<b<<": "<<vec[z]<<": "<<term<<"\n";
				resi=add(resi,term);
			}
			// cout<<resi<<"\n\n";
			res=add(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}