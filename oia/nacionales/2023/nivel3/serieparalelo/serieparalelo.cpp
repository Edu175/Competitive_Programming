#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXN=250005,MAXM=2*MAXN,MAXF=MAXN;

ll fpow(ll b, ll e){
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		e/=2; b=b*b%MOD;
	}
	return ret;
}
ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXN-1]=fpow(fc[MAXN-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){
	if(n<0||n-k<0||k<0)return 0;
	return fc[n]*fci[n-k]%MOD*fci[k]%MOD;
}

ll comb(ll a, ll b){
	return nCr(a+b,a);
}
ll dp[MAXM],nod[MAXM];

int serieparalelo(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    factorials();
    ll n=SZ(e);
    vector<vector<ll>>w(n);
    vector<ii>A={{0,1}};
    fore(i,0,n){
    	e[i]--;
    	ll a=A[e[i]].fst,b=A[e[i]].snd;
    	ll j=i+2;
    	if(t[i]==1){
    		A.pb({a,j});
    		A[e[i]]={j,b};
    		w[i]={SZ(A)-1};
    	}
    	else {
    		A.pb({a,j});
    		A.pb({j,b});
    		w[i]={SZ(A)-2,SZ(A)-1};
    	}
    }
    ll m=SZ(A);
    fore(i,0,m)dp[i]=1;
    for(ll i=n-1;i>=0;i--){
    	ll a=e[i],b=w[i][0],c=-1;
    	if(t[i]==1){
    		dp[a]=dp[a]*dp[b]%MOD;
    		nod[a]+=nod[b]+1;
    	}
    	else {
    		c=w[i][1];
    		nod[b]+=1;
    		dp[a]=dp[a]*dp[b]%MOD*dp[c]%MOD*comb(nod[a],nod[b]+nod[c])%MOD;
    		nod[a]+=nod[b]+nod[c];
    	}
    }
    return dp[0];
}
