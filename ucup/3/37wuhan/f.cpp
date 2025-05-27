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
const ll MOD=998244353,INF=1e18;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

void expand(ll &r, ll s){
	if(s>60){r=INF;return;}
	fore(i,0,s){
		r=min(2*r,INF);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ii>h(n);
		fore(i,0,n)cin>>h[i].snd>>h[i].fst;
		sort(ALL(h)); reverse(ALL(h));
		ll res=0;
		ll i=0,j=0,c=0,r=0,prev=-1;
		while(i<n){
			auto& [b,a]=h[i];
			if(j==m)j=0;
			// cout<<i<<": "<<j<<" "<<c<<" "<<r<<": "<<prev<<" "<<a<<","<<b<<"\n";
			if(j==0){
				// assert(c==0);
				c=1;
				ll q=a/m; // vueltas enteras
				a-=q*m;
				res=add(res,mul(q,fpow(2,b)));
				// vuelta parcial
				if(a>0){
					res=add(res,fpow(2,b));
					j=a; a=0;
				}
			}
			else {
				ll dif=prev-b;
				expand(c,dif);
				expand(r,dif);
				if(r>0){
					// lleno j de resto r
					ll q=min(r,a);
					a-=q; r-=q;
					if(r==0)j++;
				}
				else {
					ll q=a/c; // tarros enteros
					if(q==0){
						r=c-a;
						a=0;
					}
					else {
						ll cant=min(q,m-j);
						j+=cant;
						a-=cant*c;
					}
				}
			}
			prev=b;
			if(a==0)i++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
