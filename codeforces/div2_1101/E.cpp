#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
ll mul(ll a, ll b){return a*b%MOD;}
const ll MAXN=5005;
bool a[MAXN][MAXN];

int main(){FIN;
	ll t; cin>>t;
	ll test=0;
	while(t--){
		// cerr<<"test "<<++test<<"\n";
		ll n,k; cin>>n>>k;
		fore(i,0,n)fore(j,0,n)a[i][j]=0;
		vv is(n);
		fore(i,0,k){
			ll s; cin>>s;
			ll r,c; cin>>r>>c; r--,c--;
			is[n-1-s/2]=1;
			string mv; if(s>1)cin>>mv;
			for(ll i=r,j=c,idx=0;idx<s;idx++){
				a[i][j]=1;
				if(idx<SZ(mv)){
					if(mv[idx]=='R')j++;
					else i++;
				}
			}
		}
		ll res=1;
		fore(d,0,n){
			ll q=0,w=0,typ=-1;
			for(ll i=d,j=0;i>=0;i--,j++){
				if(a[i][j])q=0;
				else q++;
				if(!i||a[i-1][j]!=a[i][j]){
					w=q,typ=a[i][j];
					break;
				}
			}
			// cerr<<d<<": "<<typ<<" "<<w<<"\n";
			// cerr<<"v: "; for(auto [i,j]:v)cerr<<i<<","<<j<<" ";;cerr<<"\n";
			assert(is[d]==typ);
			if(!typ)res=mul(res,w);
		}
		// cerr<<"res: ";
		cout<<res<<"\n";
	}
	return 0;
}
