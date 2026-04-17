#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=ll(4e18)+5,LIM=405,MAXN=2e5+5;
ll add(ll a, ll b){a+=b;if(a>=INF)a=INF;return a;}


ll dp[MAXN][LIM];
ll maxiter=0;
ll f(ll n, ll inv){ // count
	auto &res=dp[n][inv];
	if(res!=-1)return res;
	if(n==1)return inv==0;
	res=0;
	fore(i,0,min(n,inv+1)){
		res=add(res,f(n-1,inv-i));
		maxiter=max(maxiter,i);
		if(res==INF)break;
	}
	// cout<<"f "<<n<<" "<<inv<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	ll n; cin>>n;
	// brute
	// vv c={1};
	// fore(m,2,n+1){
	// 	vv ci(min(LIM,SZ(c)+m-1));
	// 	fore(i,0,SZ(c))fore(j,0,min(m,LIM-i))ci[i+j]=add(ci[i+j],c[i]);
	// 	swap(c,ci);
	// 	c.resize(min(SZ(c),LIM));
	// }
	// cerr<<"done c"<<endl;
	// ll cota=INF;
	// fore(i,0,SZ(c)){
	// 	if(cota<c[i]){
	// 		cout<<"found en "<<i<<"\n";
	// 		break;
	// 	}
	// 	cota-=c[i];
	// }
	// imp(c)
	mset(dp,-1);
	ll k; cin>>k; k--;
	ll inv=0;
	fore(i,0,n*n+5){
		ll num=f(n,i);
		// cerr<<i<<": "<<k<<" "<<num<<endl;
		if(k<num){inv=i;break;}
		k-=num;
	}
	// cout<<k<<" "<<inv<<", k inv\n";
	vv res(n,-1);
	fore(i,0,n-1){
		// cerr<<i<<endl;
		ll m=n-i;
		fore(j,0,m){
			ll num=f(m-1,inv-j);
			// cout<<i<<" "<<j<<": "<<num<<"\n";
			maxiter=max(maxiter,j);
			if(k<num){
				res[i]=j;
				inv-=j;
				break;
			}
			k-=num;
		}
	}
	res[n-1]=0;
	// imp(res); cout<<endl;
	// relabel
	cerr<<"relabel"<<endl;
	deque<ll>ind;
	for(ll i=n-1;i>=0;i--){
		ind.insert(ind.begin()+res[i],i);
	}
	fore(i,0,n)res[ind[i]]=i+1;
	imp(res);
	cerr<<maxiter<<"\n";
	return 0;
}