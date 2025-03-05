#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353,MAXN=3e5+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vv g[MAXN];
ll D[MAXN],S[MAXN],cnt=0;
void dfs(ll x){
	S[x]=cnt++;
	for(auto y:g[x]){
		D[y]=D[x]+1;
		dfs(y);
	}
}
bool cmp(ll i, ll j){
	return S[i]<S[j];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		cnt=0;
		
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		dfs(0);
		vv nod[n+1];
		vv pos(n);
		// ll mx=0;
		fore(i,0,n)nod[D[i]].pb(i);
		fore(i,0,n){
			sort(ALL(nod[i]),cmp);
			fore(j,0,SZ(nod[i]))pos[nod[i][j]]=j;
			// if(SZ(nod[i]))mx=max(mx,i);
		}
		vv sp;
		for(ll d=n;d>=1;d--){
			vv a;
			for(auto i:nod[d]){
				sort(ALL(g[i]),cmp);
				ll s=0,e=0;
				if(SZ(g[i]))s=pos[g[i][0]],e=pos[g[i].back()]+1;
				ll resi=sp.back();
				resi=sub(resi,sub(sp[e],sp[s]));
				a.pb(resi);
			}
			a.pb(1); // terminarla
			sp=vv(SZ(a)+1);
			fore(i,1,SZ(a)+1)sp[i]=add(sp[i-1],a[i-1]);
		}
		cout<<sp.back()<<"\n";
	}
	return 0;
}
