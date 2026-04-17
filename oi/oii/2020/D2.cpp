#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll MOD=1e9;
const ll M[2]={512,1953125}; // 2**9 , 5**9

ll fpow(ll b, ll e, ll M=MOD){
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%M;
		b=b*b%M,e>>=1;
	}
	return ret;
}
const ll C=1e5;

//inline ll cut(ll a){return a<MOD?a:a-MOD;}
vector<ll> dp[2];
//ll inv=0;// 109

ll chino(ll a0, ll a1){
	//cout<<a0<<" "<<a1<<"\n";
	return ((a0-a1+MOD)*109%MOD*M[1]%MOD+a1)%MOD;
}

ll fs(ll n){
	vector<ll>a(2);
	fore(i,0,2)a[i]=(n/M[i]*dp[i].back()+dp[i][n%M[i]])%M[i];
	ll res=chino(a[0],a[1]);
	//cout<<"fs "<<n<<": "<<res<<"\n";
	return res;
}


int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(h,0,2){
		dp[h].resize(M[h]);
		dp[h][0]=fpow(0,k,M[h]);
		fore(i,1,M[h])dp[h][i]=(dp[h][i-1]+fpow(i,k,M[h]))%M[h];
	}
	//cout<<fs(n)<<"\n";
	//return 0;
	/*fore(i,0,M[0])if(i*M[1]%M[0]==1){
		inv=i;
		break;
	}
	cout<<inv<<"\n";*/
	ll res=0;
	fore(x,1,C){
		res=(res+(fs(n/x)-fs(n/(x+1))+MOD)*x)%MOD;
	}
	fore(d,1,n){
		if(n/d<C)break;
		res=(res+n/d*fpow(d,k))%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
