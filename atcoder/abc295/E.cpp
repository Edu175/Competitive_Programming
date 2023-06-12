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
const ll MOD=998244353,MAXF=2e3+6;

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
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}

int main(){FIN;
	factorials();
	ll n,m,k; cin>>n>>m>>k; k--;
	ll a[n],s=0;
	fore(i,0,n)cin>>a[i],s+=(!a[i]);
	ll res=0;
	//cout<<s<<"\n";
	fore(v,1,m+1){
		ll c=0,d=0;
		fore(i,0,n){
			if(a[i]){
				if(a[i]<v)c++;
				else d++;
			}
		}
		//if(d>n-k)continue;
		ll p=0,x=k+1-c,y=s-x-1;
		fore(i,max((ll)0,x),s+1){
			p+=fpow(v-1,i)*fpow(m-v+1,s-i)%MOD*nCr(s,i)%MOD;
			p%=MOD;
		}
		/*cout<<v<<": "<<x<<" "<<y<<" "<<p<<"\n";
		cout<<v<<"**"<<x<<" * "<<m-v+1<<"**"<<y<<" * "<<fc[s]<<" / ("<<fci[x]<<"*"<<fci[y]<<")\n";*/
		res=(res+fpow(m,s)-p+MOD)%MOD;
	}
	//cout<<res<<"\n";
	res=res*fpow(fpow(m,s),MOD-2)%MOD;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
