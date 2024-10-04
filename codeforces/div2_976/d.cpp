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
const ll MAXN=2e5+5;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
const ll V=11;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n+3){
			uf[i]=-1;
		}
		ll h[V][n+15];
		mset(h,0);
		fore(i,0,m){
			ll a,d,k; cin>>a>>d>>k;
			h[d][a]++,h[d][a+k*d]--;
		}
		fore(d,1,11){
			vv c(d);
			fore(i,1,n+1){
				c[i%d]+=h[d][i];
				if(c[i%d]&&i+d<=n)uf_join(i,i+d);
			}
		}
		set<ll>st;
		fore(i,1,n+1)st.insert(uf_find(i));
		cout<<SZ(st)<<"\n";
	}
	return 0;
}
