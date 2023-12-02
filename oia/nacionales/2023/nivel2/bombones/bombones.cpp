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
const ll MAXN=1e5+5;

ll a[MAXN];
ll n,k;

bool messirve(ll c){
	ll r=0;
	fore(i,0,n)r+=min(a[i],c);
	return r/c>=k;
}

long long bombones(int K, vector<int> &A) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    n=SZ(A),k=K;
    fore(i,0,n)a[i]=A[i];
    ll l=1,r=1e15;
    while(l<=r){
    	ll m=(l+r)/2;
    	if(messirve(m))l=m+1;
    	else r=m-1;
    }
    return r;
}
