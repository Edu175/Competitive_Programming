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
const ll MAXF=1e3+5,MOD=1e9+7;

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
ll nPr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[n-k]%MOD;
}

int main(){FIN;
	factorials();
	ll n,x,p; cin>>n>>x>>p;
	ll a[n]={};
	ll l=0,r=n;
	while(l<r){
		ll m=(l+r)/2;
		//cout<<"["<<l<<","<<r<<") "<<m<<"\n";
		if(p>=m)l=m+1,a[m]=1;
		else r=m,a[m]=2;
	}
	a[p]=3;
	ll c=0,d=0,e=0; //<= > free
	fore(i,0,n){
		if(a[i]==0)e++;
		if(a[i]==1)c++;
		if(a[i]==2)d++;
	}
	//imp(a);
	//cout<<c<<" "<<d<<" "<<e<<"\n";
	ll res=fc[e]*nPr(x-1,c)%MOD*nPr(n-x,d)%MOD;
	cout<<res<<"\n";
	return 0;
}
