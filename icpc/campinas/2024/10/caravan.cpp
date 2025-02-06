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
const ll MAXF=50,MAXN=1e4+5,MOD=1e9+7;
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
string s;
ll n;
ll prox[MAXN];
ll dp[MAXN][30];
ll d;
ll f(ll i, ll c){
	ll &res=dp[i][c];
	if(res!=-1)return res;
	if(i==n-1){
		//cout<<"reached "<<c<<" "<<d<<": "<<nCr(26-d,c-(d-1))*fc[c-(d-1)]%MOD<<"\n";
		return res=nCr(26-d,c-(d-1))*fc[c-(d-1)]%MOD;
	}
	res=f(i+1,c);
	if(s[i]!='?'&&s[i]==s[i+1])return res;
	//cout<<i<<" "<<c<<"\n";
	if(c<28)res=(res+f(i+1,c+1))%MOD;
	
	if(s[i]!='?'&&prox[i]!=n)res=(res-f(prox[i],c)+MOD)%MOD;
	
	return res;
}

int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		cin>>s;
		n=SZ(s);
		fore(i,0,n+3)fore(j,0,30)dp[i][j]=-1;
		ll p=n;
		set<char>st;
		for(ll i=n-1;i>=0;i--){
			prox[i]=p;
			if(s[i]!='?')p=i;
			st.insert(s[i]);
		}
		st.erase('?');
		d=SZ(st);
		fore(i,0,n){
			if(s[i]!='?'&&prox[i]<n&&s[prox[i]]==s[i]){
				fore(j,i+1,prox[i])s[j]=s[i];
			}
		}
		//cout<<n<<" "<<s<<endl;
		cout<<f(0,0)<<"\n";
	}
	return 0;
}
