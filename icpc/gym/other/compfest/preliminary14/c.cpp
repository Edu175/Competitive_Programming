#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=998244353,MAXF=2e6+5;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){
		if(b&1)r=mul(r,a);
		b>>=1,a=mul(a,a);
	}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

int main(){
	JET
	factos();
	ll n,m; cin>>n>>m;
	vv dis(n);
	set<ll>st;
	ll d=0;
	fore(i,0,n){
		ll x; cin>>x;
		d+=x;
		st.insert(d);
		dis[i]=d;
	}
	ll a=0,b=0;
	fore(i,0,n)if(d%2==0&&st.count(dis[i])){
		if(st.count(dis[i]+d/2)){
			a++;
			st.erase(dis[i]);
			st.erase(dis[i]+d/2);
		}
	}
	b=SZ(st);
	// cerr<<a<<" "<<b<<" a b\n";
	ll res=0;
	fore(k,0,m+1){
		ll c=m-k,z=a-k;
		ll lhs=mul(nCr(a,k),mul(nCr(m,k),fc[k]));
		ll rhs=mul( fpow(mul(c,c-1),z) , fpow(c,b));
		ll resi=mul(lhs,rhs);
		res=add(res,resi);
	}
	cout<<res<<"\n";
    return 0;
}