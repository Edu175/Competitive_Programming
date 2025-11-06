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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

const ll MAXN=1e6+5;

set<vv> st;
ll n;
void dfs(vv a){
	st.insert(a);
	fore(i,0,n){
		vv b=a;
		ll p=b[i];
		swap(b[i],b[p]);
		if(!st.count(b))dfs(b);
	}
}

int main(){FIN;
	cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	dfs(a);
	cout<<SZ(st)<<"\n";
	return 0;
}
