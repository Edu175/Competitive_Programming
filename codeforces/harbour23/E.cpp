#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}


#define ppc __builtin_popcountll
bool ispot(ll n){return ppc(n)==1;}

const ll B=30;
const ll MAXN=B*2e5+5;
ll tr[MAXN][2],qidx=0,cant[MAXN];

ll agr(ll x, ll j){
	auto &res=tr[x][j];
	if(res!=-1)return res;
	return res=++qidx;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		
		fore(i,0,n*B+3){
			tr[i][0]=tr[i][1]=-1;
			cant[i]=0;
		}
		qidx=0;
		
		vv a(n);
		fore(i,0,n){
			cin>>a[i];
			ll x=0;
			cant[x]++;
			forr(j,0,B){
				x=agr(x,a[i]>>j&1);
				// cerr<<i<<" "<<j<<": "<<x<<"\n";
				cant[x]++;
			}
		}
		ll res=0;
		for(auto v:a){
			ll x=0,c=0;
			forr(j,0,B){
				ll bo=v>>j&1;
				ll y=tr[x][bo^1];
				if(y!=-1){
					ll coef=cant[y];
					ll cur=c+1;
					if(c%2==0)cur+=bo;
					else cur+=!bo;
					res+=cur*coef;
					// cerr<<v<<" "<<j<<": "<<x<<" "<<y<<": "<<cur<<" "<<coef<<" += "<<cur*coef<<"\n";
				}
				x=tr[x][bo];
				c+=bo;
			}
			// iguales
			ll coef=cant[x];
			ll cur=c+1;
			res+=cur*coef;
			// cerr<<v<<" final: "<<cur<<" "<<coef<<" += "<<cur*coef<<"\n";
		}
		// cerr<<res<<": ";
		res%=MOD;
		res=mul(res,fpow(mul(n,n),MOD-2));
		cout<<res<<"\n";
	}
	return 0;
}
