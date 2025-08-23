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
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXV=1e5+5;
vector<ll> divs[MAXV];
void divisores(){
	fore(i,1,MAXV)for(int j=i;j<MAXV;j+=i)divs[j].pb(i);
}
short mu[MAXV] = {0,1}; // ojo
void mobius(){
	fore(i,1,MAXV)if(mu[i])for(int j=i+i;j<MAXV;j+=i)mu[j]-=mu[i];
}
vv BADS={98280,83160,95760,92820,92400,90090,87780,85680,78540,65520};
// ll BAD=90720;
#define BAD (BADS[rng()%SZ(BADS)])
random_device rd;
mt19937 rng(rd());
int main(){FIN;
	ll n,q; cin>>n>>q;
	cout<<n<<"\n";
	fore(i,0,n)cout<<BAD<<" ";
	cout<<"\n"<<q<<"\n";;
	fore(_,0,q)cout<<"2 "<<BAD<<"\n";
	return 0;
}
