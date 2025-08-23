#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=1e5+5;
short mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN)if(mu[i])for(int j=i+i;j<MAXN;j+=i)mu[j]-=mu[i];
}

int main(){
	JET
	mobius();
	ll n,m; cin>>n>>m;
	vv L(n),R(n);
	fore(i,0,n)cin>>L[i]>>R[i];
	ll res=0;
	fore(g,1,m+1)if(mu[g]){
		vv l(n),r(n);
		fore(i,0,n)l[i]=(L[i]+g-1)/g,r[i]=R[i]/g;
		ll mp=m/g;
		vv now(mp+3),ant(mp+3);
		ant[0]=1;
		fore(i,0,n){
			vv sp(SZ(ant)+1);
			fore(i,0,SZ(ant))sp[i+1]=add(sp[i],ant[i]);
			fore(k,0,mp+3){
				ll s=k-r[i],e=k-l[i]+1;
				s=max(s,0ll);
				e=max(e,0ll);
				now[k]=sub(sp[e],sp[s]);
			}
			swap(now,ant);
		}
		ll sum=0;
		fore(i,0,mp+1)sum=add(sum,ant[i]);
		res=(mu[g]==1?add:sub)(res,sum);
		// cout<<g<<": "<<sum<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}