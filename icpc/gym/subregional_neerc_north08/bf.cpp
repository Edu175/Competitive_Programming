#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll l(ll x){return x&-x;}
ll h(ll x){return __builtin_ctzll(l(x));}
ll maxv=5;
vector<ll>a,b;
ll n,dif=1000000;
vector<ll>r;
void doit(){
    vector<ll>ret(n,0);
    ll difi=0;
    fore(i,1,n+1){
        difi+=(b[i-1]!=a[i-1]);
        fore(j,i-l(i)+1,i+1)ret[i-1]+=b[j-1];//,cout<<i<<" "<<j<<"\n";
    }
    // cout<<"doit "<<difi<<"\n";
    // for(auto i:ret)cout<<i<<" ";
    // cout<<"\n";
    if(ret==b&&difi<dif){
        r=b,dif=difi;
    }
}

void f(){
    if(SZ(b)==n){doit();return;}
    fore(v,-maxv,maxv+1){
        b.pb(v);
        f();
        b.pop_back();
    }
}

int main(){FIN;
    #ifdef ONLINE_JUDGE
    freopen("fenwick.in","r",stdin);     freopen("fenwick.out","w",stdout);
    #endif
    cin>>n;
    a=vector<ll>(n);
    fore(i,0,n)cin>>a[i];
    f();
    // b={0,-1,1,1,0,9};
    // doit();
    cout<<dif<<"\n";
    for(auto i:r)cerr<<i<<" ";
    cerr<<"\n";


    return 0;
}
