#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet =b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll K=127;

ll to2(ll k){
    return k*(k-1)/2;
}
ll to3(ll k){
    return k*(k-1)*(k-2)/6;
}

int main(){
    JET
    ll t; cin>>t;
    while(t--){
        ll G,C; cin>>G>>C;
        vv c(K),g(K); // then reverse
        for(ll k=K-1;k>=1;k--){
            auto doit=[&](ll num, vv &w, ll &S){
                if(!num)return;
                ll q=S/num;
                w[k]=q;
                S-=q*num;
            };
            doit(to2(k+1),c,C);
            doit(to3(k+1),g,G);
        }
        assert(G==0&&C==0);
        reverse(ALL(c)); c.pop_back();
        reverse(ALL(g)); g.pop_back();
        string res;
        fore(k,0,SZ(c)){
            res+=string(c[k],'C');
            res+=string(g[k],'G');
            res+="AT";
        }
        cout<<res<<"\n";
        assert(SZ(res)<=500);
    }

    return 0;
}