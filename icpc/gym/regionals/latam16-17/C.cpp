#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXN=2005;

int add(int a, int b){a+=b; if(a>=MOD)a-=MOD; return a;}
int sub(int a, int b){a-=b; if(a<0)a+=MOD; return a;}
int mul(ll a, ll b){return a*b%MOD;}

ll mem[MAXN][MAXN];
ll nCr(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	auto &res=mem[n][k];
	if(res!=-1)return res;
	if(n==0)return res=1;
	return res=add(nCr(n-1,k-1),nCr(n-1,k));
}

int main(){
    JET
	mset(mem,-1);
	ll n; cin>>n;
	vector<ii> a(n);
	set<ii>st;
	map<ii,ll>mp;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		x*=2; y*=2;
		a[i]={x,y};
		st.insert(a[i]);
		mp[a[i]]=0;
	}
	fore(i,0,n)fore(j,i+1,n){
		ii p=a[i];
		ii q=a[j];
		ii m={(p.fst+q.fst)/2,(p.snd+q.snd)/2};
		mp[m]++;
	}
	
	ll mx=n+5;
	
	vector<vv> hist(mx,vv(2));
	for(auto [asd,c]:mp){
		hist[c][st.count(asd)]++;
	}
	vv res(n+1);
	fore(c,0,mx)fore(od,0,2){
		ll coef=hist[c][od];
		if(!coef)continue;
		fore(p,0,c+1)fore(bo,0,od+1){
			ll pos=2*p+bo;
			ll cur=nCr(c,p);
			cur=mul(cur,coef);
			res[pos]=add(res[pos],cur);
		}
	}
	fore(i,1,n+1)cout<<res[i]<<" ";;cout<<"\n";
    return 0;
}