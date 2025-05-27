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
const ll MOD=998244353,INF=1e10;
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
	if(s>35){r=INF;return;}
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
		priority_queue<ll>pq;
		fore(i,0,m)pq.push(0);
		ll res=0;
		for(auto [b,a]:h){
			while(a--){
				auto c=pq.top(); pq.pop();
				c-=1ll<<b;
				res=min(res,c);
				pq.push(c);
			}
		}
		cout<<(-res)%MOD<<"\n";
	}
	return 0;
}
