#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXF=1e6+5,MAXN=5005;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll sp[MAXN];
ll comb(ll l, ll r){
	//cout<<"[comb "<<l<<","<<r<<"="<<sp[r]-sp[l]<<"! = "<<fc[sp[r]-sp[l]]<<"] ";
	return fc[sp[r]-sp[l]];
}
int main(){FIN;
	factorials();
	ll m,n; cin>>m>>n;
	vector<ll>a(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	a.pb(m-sum);
	n++;
	sp[0]=0;
	//fore(i,0,m+1)cout<<i<<": "<<fc[i]<<" "<<fci[i]<<"\n";
	fore(i,1,n+1)sp[i]=add(sp[i-1],a[i-1]);
	ll res=comb(0,n);
	//cout<<res<<"\n";
	vector<ll> dp(n+1);
	fore(i,0,n-1){
		ll &resi=dp[i];
		resi=comb(0,i+1);
		//cout<<i<<": ";
		fore(j,1,i+1){
			ll now=dp[j-1]*comb(j,i+1)%MOD;
			resi=sub(resi,now);
			//cout<<((j&1)==(i&1)?"-":"+")<<now<<" ";
		}
		//cout<<"= "<<resi<<"\n";
		res=sub(res,resi*comb(i+1,n)%MOD);
	}
	cout<<res<<"\n";
	return 0;
}
