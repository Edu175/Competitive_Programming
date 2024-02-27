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
const ll MOD=998244353,MAXF=5e6;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
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
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}

ll comb(ll n, ll k){
	//if(n==0)return k==0;
	return nCr(n+k-1,n-1);
}

int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		vector<ll>c(4);
		fore(i,1,5)cin>>c[i%4];
		if(abs(c[1]-c[2])>1){
			cout<<"0\n";
			continue;
		}
		if(c[1]+c[2]==0){
			if(c[0]&&c[3])cout<<"0\n";
			else cout<<"1\n";
			continue;
		}
		ll nz=0,no=0;
		if(c[1]!=c[2])nz=no=max(c[1],c[2]);
		else nz=c[1]+1,no=nz-1;
		//cout<<nz<<" "<<no<<"\n";
		ll res=mul(comb(nz,c[0]),comb(no,c[3]));
		if(c[1]==c[2]){
			swap(nz,no);
			res=add(res,mul(comb(nz,c[0]),comb(no,c[3])));
		}
		cout<<res<<"\n";
	}
	return 0;
}
