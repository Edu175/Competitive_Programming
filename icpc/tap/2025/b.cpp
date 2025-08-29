#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353,MAXF=1e6+5;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
    if(e<0)return 0;
    ll res=1;
    while(e){
        if(e&1)res=mul(res,b);
        b=mul(b,b); e>>=1;
    }
    return res;
}
ll fc[MAXF],fci[MAXF];
void factos(){
    fc[0]=1;
    fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
    fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
    for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}
ll nCr(ll n, ll k){
    if(n<0||k<0||n-k<0)return 0;
    ll res=1;
    fore(i,0,k)res=mul(res,(n-i)%MOD);
    assert(k<MAXF);
    res=mul(res,fci[k]);
    return res;
}

int main(){
    JET
    factos();
    ll n,k; cin>>n>>k;
    vv s(n-k+1);
    fore(i,0,SZ(s))cin>>s[i];
    vv a(n);
    ll tot=s[0];
    fore(r,0,k){
        ll mn=0;
        for(ll i=r;i<n;i+=k){
            mn=min(mn,a[i]);
            if(i+k<n){
                a[i+k]=a[i]+s[i+1]-s[i];
            }
        }
        tot+=mn;
    }
    // assert(tot>=0);
    ll res=nCr(tot+k-1,k-1);
    if(tot<0)res=0;
    cout<<res<<"\n";
    return 0;
}