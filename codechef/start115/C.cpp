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
const ll MAXF=1e6+5,MOD=1e9+7;

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

int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		char s[n][m]; ll a[n][m];
		fore(i,0,n)fore(j,0,m){
			cin>>s[i][j];
			a[i][j]=s[i][j]-'0';
		}
		if(n==1){
			cout<<"1\n";
			continue;
		}
		for(ll i=n-2;i>0;i--){
			ll fl=0,cnt=0;
			fore(j,0,m){
				if(a[i][j]==1&&a[i+1][j]==1)fl=1;
				cnt+=a[i][j];
			}
			if(cnt<2||!fl)continue;
			fore(j,0,m)a[i][j]|=a[i+1][j];
		}
		ll c0=0,c1=0;
		fore(j,0,m){
			c1+=a[1][j];
			c0+=(a[0][j]&&a[1][j]);
		}
		ll res=nCr(c1,c0);
		cout<<res<<"\n";
	}
	return 0;
}
