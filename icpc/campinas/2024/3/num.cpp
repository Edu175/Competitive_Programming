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
const ll MOD=10007;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return fpow(fpow(a,-b),MOD-2);
	int r=1;
	while(b){
		if(b&1)r=mul(r,a);
		b/=2;
		a=mul(a,a);
	}
	return r;
}
const ll MAXF=MOD;
ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}
ll nCr(ll n, ll k){
	n%=MOD;
	if(n<0||k<0||n-k<0)return 0;
	return mul(fc[n],mul(fci[k],fci[n-k]));
	
}

ll num(ll n, ll k){ //number of strings with length-k s as a subsequence
	if(k==0)return fpow(26,n);
	ll res=0,a0=0;
	//fore(m,k,n+1)res=add(res,mul(nCr(m,k),mul(fpow(25,m-k),fpow(26,n-m))));
	fore(m,0,MOD)a0=add(a0,mul(nCr(m,k-1),mul(fpow(25,m-(k-1)),fpow(26,n-m-1))));
	ll d=n/MOD;
	fore(m,0,n%MOD){
		
		res=add(res,mul(nCr(m,k-1),mul(fpow(25,m+d-(k-1)),fpow(26,n-(m+d)-1))));
	}
	ll r=mul(25,fpow(26,MOD-2));
	ll prog=mul(a0,mul(sub(fpow(r,d),1),fpow(sub(r,1),MOD-2)));
	/*cout<<"num "<<n<<" "<<k<<":\n";
	cout<<res<<"\n"<<d<<" "<<r<<" "<<a0<<": "<<prog<<"\n";
	//cout<<fpow(r,d)<<" "<<sub(fpow(r,d),1)<<"\n";
	cout<<add(res,prog)<<"\n\n";*/
	return add(res,prog);
}

int main(){FIN;
	factorials();
	ll n,k; cin>>n>>k;
	cout<<num(n,k)<<"\n";
	return 0;
}
