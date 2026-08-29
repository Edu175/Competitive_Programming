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
typedef vector<vv> mat;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

mat brute(ll n, ll k){
	mat a(n,vv(n));
	fore(mk,0,1ll<<(n*n)){
		ll mk2=mk;
		fore(i,0,n)fore(j,0,n)a[i][j]=mk2&1,mk2>>=1;
		ll cur=0;
		fore(i,0,n)fore(j,0,n){
			if(i+1<n)cur+=(a[i][j]!=a[i+1][j]);
			if(j+1<n)cur+=(a[i][j]!=a[i][j+1]);
		}
		if(cur==k)return a;
	}
	return {};
}
const ll MAXN=1005;

bool dp[MAXN][4*MAXN][2];
ii ch[MAXN][4*MAXN][2];
// ll dbg=0;

vv getr(vv up, ll n, ll k, ll row){ // up is full of -1 in case of first row
	if(k<0||k>4*n)return {};
	// fore(i,0,n+1)fore(c,0,n+1)dp[i][c]=0;
	fore(w,0,2){
		fore(c,1,k+1)dp[n][c][w]=0;
		dp[n][0][w]=1;
	}
	for(ll i=n-1;i>=0;i--)fore(c,0,k+1)fore(w,0,2){
		auto &res=dp[i][c][w];
		res=0;
		fore(p,0,2){
			ll cur=up[i]!=-1&&up[i]!=p;
			cur+=i&&w!=p;
			cur+=row<n-1&&p;
			if(c-cur>=0&&dp[i+1][c-cur][p]){
				res=1;
				ch[i][c][w]={cur,p};
			}
		}
	}
	if(!dp[0][k][0])return {};
	ll c=k,w=0;
	vv ans(n);
	fore(i,0,n+1){
		assert(c>=0&&dp[i][c][w]);
		if(i==n)break;
		auto [cur,p]=ch[i][c][w];
		ans[i]=p;
		c-=cur,w=p;
	}
	return ans;
}

mat get(ll ty, ll n, ll k){
	mat a(n,vv(n));
	auto got0=getr(vv(n,-1),n,k,0);
	if(SZ(got0)){
		a[0]=got0;
		return a;
	}
	ll cnt=0;
	fore(i,1,n){
		ll c1=0;
		ll old=cnt;
		fore(j,0,n){
			a[i-1][j]=(i-1+j+ty)&1;
			c1+=a[i-1][j];
			if(i-1)cnt+=a[i-2][j]!=a[i-1][j];
			if(j)cnt+=a[i-1][j]!=a[i-1][j-1];
		}
		k-=cnt-old;
		ll doit=i==n-1; // always try n-1
		if(!doit){
			ll c0=n-c1;
			ll mn=c1,mx=n+n-1+c0;
			assert(mn<=mx);
			// if(dbg){
			// 	cout<<i<<" "<<mn<<","<<mx<<": "<<cnt<<" "<<k<<"\n";
			// }
			if(mn<=k&&k<=mx){ // O(1) rows will hold (probably just 1)
				doit=1;
			}
		}
		if(doit){
			auto got=getr(a[i-1],n,k,i);
			// if(dbg){
			// 	cerr<<"doit "<<got<<"\n";
			// }
			if(SZ(got)){
				a[i]=got;
				return a;
			}
		}
	}
	return {};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		// cerr<<"test "<<n<<" "<<k<<"\n";
		// dbg=n==4&&k==11;
		mat ans;
		if(n<=3)ans=brute(n,k);
		else {
			fore(ty,0,2){
				auto got=get(ty,n,k);
				if(SZ(got))ans=got;
			}
		}
		if(!SZ(ans)){
			cout<<"Impossible\n";
		}
		else {
			cout<<"Possible\n";
			ll has=0;
			fore(i,0,n)fore(j,0,n){
				if(i)has+=ans[i-1][j]!=ans[i][j];
				if(j)has+=ans[i][j-1]!=ans[i][j];
			}
			fore(i,0,n){
				fore(j,0,n)cout<<"RB"[ans[i][j]];
				cout<<"\n";
			}
			// cout<<endl;
			assert(has==k);
		}
		// cout<<endl;
		ll mx=2*n*(n-1);
		bool bad=k==1||k==mx-1;
		assert(!SZ(ans) == bad);
	}
	return 0;
}
