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
const ll MOD=1e9+7,MAXN=3005,MAXF=MAXN;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

const ll db=0;

ll n,c,k;
ll dp[MAXN][MAXN];
ll sp[MAXN][MAXN];
ll qs[MAXN];
ll query(ll g){
	ll &res=qs[g];
	if(res!=-1)return res;
	if(g<=c)return res=(c+k==n);
	ll q=c+k-c*(n/g);
	if(q<0)return res=0;
	q=q/(n/g)+c;
	res=0;
	fore(i,0,q+1)res=add(res,nCr(g,i));
	ll r=0;
	//if(db)cout<<"query: "<<g<<" "<<q<<":\n"<<res<<"\n";
	
	fore(i,0,min({c,q+1,g})){ // # of ones
		r=add(r,mul(dp[g-i][q-i],i+1));
		/*if(db){
			cout<<i<<": "<<mul(dp[g-i][q-i],i+1)<<"\n";
			cout<<"dp"<<g-i<<","<<q-i<<"("<<dp[g-i][q-i]<<") * "<<i+1<<"\n";
		}*/
	}
	//if(db)cout<<"-"<<r;
	res=sub(res,r);
	//if(db)cout<<" = "<<res<<"\n";
	//if(db)cout<<"end\n";
	return res;
}

int main(){FIN;
	factorials();
	cin>>n>>c>>k;
	mset(qs,-1);
	//dp
	fore(i,0,n+1)dp[1][i]=sp[2][i+1]=1;
	fore(m,2,n+1)fore(h,0,n+1){
		ll &res=dp[m][h];
		ll d=min({h,m-2,c-1});
		res=sub(sp[m][h+1],sp[m-d-1][h-d]);
		sp[m+1][h+1]=add(sp[m][h],res);
		//if(db)cout<<"dp "<<m<<" "<<h<<" = "<<res<<"\n";
	}
	//cout<<dp[1][1]<<" dp 1,1 !\n";
	ll res=0;
	fore(r,0,n){
		ll g=gcd(r,n);
		ll rq=query(g);
		//if(db)cout<<r<<": "<<g<<" = "<<rq<<"\n";
		res=add(res,rq);
	}
	//if(db)cout<<"res "<<res<<"\n";
	res=mul(res,fpow(n,MOD-2));
	cout<<res<<"\n";
	return 0;
}
