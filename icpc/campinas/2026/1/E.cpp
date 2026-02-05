#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define impr(v) for(auto i:v)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;

ll knap(vector<ii> a, ll V){ // (v,c)
    ll n=SZ(a);
    vector<vv> dp(2,vv(V+1));
    for(ll i=n-1;i>=0;i--)fore(v,0,V+1){
        auto &res=dp[i&1][v];
        res=dp[(i+1)&1][v];
        if(a[i].fst<=v)res=max(res,a[i].snd+dp[(i+1)&1][v-a[i].fst]);
    }
    return dp[0][V];
}
ll knap3(vector<ii> a, ll V){ // (v,c)
    ll n=SZ(a);
    vector<vector<vv>> dp(2,vector<vv>(V+1,vv(4)));
    fore(v,0,V+1)fore(q,1,4)dp[n&1][v][q]=-INF;
    for(ll i=n-1;i>=0;i--)fore(v,0,V+1)fore(q,0,4){
        auto &res=dp[i&1][v][q];
        res=dp[(i+1)&1][v][q];
        if(q>=1&&a[i].fst<=v)res=max(res,a[i].snd+dp[(i+1)&1][v-a[i].fst][q-1]);
    }
    return dp[0][V][3];
}

int main(){
    JET
    ll t; cin>>t;
    while(t--){
        ll n,V; cin>>n>>V;
        vector<ii> a(n);
        fore(i,0,n)cin>>a[i].fst;
        fore(i,0,n)cin>>a[i].snd;
        if(V<=410){
            ll res=knap(a,V);
            cout<<res<<"\n";
            continue;
        }
        sort(ALL(a));
        // impr(a)
        vector<ii> mx(n+1); // best, second best: [0,i)
        fore(i,0,n){
            auto &cur=mx[i+1];
            cur=mx[i];
            vv vec={cur.fst,cur.snd,a[i].snd};
            sort(ALL(vec));
            cur={vec[2],vec[1]};
        }
        // impr(mx)
        ll res=0;
        fore(i,0,n){
            auto &[v,c]=a[i];
            ii par={V-v,INF};
            ll p=upper_bound(ALL(a),par)-a.begin();
            ii cur=mx[p];
            ll ans=cur.fst;
            if(2*v<=V&&ans==c)ans=cur.snd;
            ans+=c;
            res=max(res,ans);
            // cout<<i<<": "<<v<<","<<c<<": "<<V-v<<" "<<p<<": ";
            // cout<<cur.fst<<","<<cur.snd<<": ";
            // cout<<ans<<"\n";
        }
        fore(i,0,n){
            auto &[v,c]=a[i];
            v*=3;
            v-=V-100;
            assert(v>=0);
        }
        res=max(res,knap3(a,300));
        cout<<res<<"\n";
    }
    return 0;
}


