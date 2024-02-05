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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MOD=998244353,MAXF=5e4;

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
ll bec(ll b, ll c){return nCr(b+c-1,b);}
int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n+1); a[n]=0;
		ll mn=0,mx=0;
		fore(i,0,n)cin>>a[i],mn=min(mn,a[i]),mx=max(mx,a[i]);
		ll s=-mn,m=s+mx+1;
		vector<ll>b(m);
		fore(i,0,n+1)a[i]+=s,b[a[i]]++;
		ll res=0;
		//imp(a); imp(b);
		fore(e,0,m){
			vector<ll>c(m);
			fore(i,s,m)c[i]++;
			fore(i,e,m-1)c[i]++;
			ll resi=1;
			//cout<<e<<": "<<c<<" ";
			for(ll i=m-1;i;i--){
				ll x=b[i]-c[i];
				//cout<<"["<<i<<"|"<<c[i]<<","<<x<<"|"<<bec(x,c[i])<<"] ";
				if(x<0){
					resi=0;
					break;
				}
				resi=resi*bec(x,c[i])%MOD;
				c[i]+=x;
				c[i-1]+=x;
			}
			if(b[0]-c[0])resi=0;
			//cout<<c<<" "<<resi<<"\n";
			res=(res+resi)%MOD;
		}
		cout<<res<<"\n";
		//cout<<"\n";
	}
	return 0;
}
