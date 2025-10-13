#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) for(auto pera:v) cout<<pera<<" ";;cout<<endl;
#define imp2(v) for(auto [sandia,melon]:v) cout<<sandia<<","<<melon<<" ";;cout<<endl;
#define inp(v) for(auto &uva:v) cin>>uva;
#define inp2(v) for(auto &[fresa,mora]:v) cin>>fresa>>mora;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef __int128 xl;
typedef long double ld;
typedef vector<vv> mtx;
ld dp[105][105][105];
bool vis[105][105][105];
ll L,H,c[3],p[3],tot;
ld f(ll C, ll N, ll E){
    if(C>c[0]||N>c[1]||E>c[2]) return 0;
    ld &r=dp[C][N][E];
    if(vis[C][N][E]) return r;
    vis[C][N][E]=1;
    r=0.;
    ll w=C*p[0]+N*p[1]+E*p[2];
    // cout<<C<<" "<<N<<" "<<E<<" "<<w<<"\n";
    if(w>H) return r;
    // cout<<"a\n";
    if(w>=L) return r=1.;
    // cout<<"b\n";
    if(C+N+E==tot) return r;
    // cout<<"c\n";
    r+=(ld(c[0]-C)/ld(tot-C-N-E))*f(C+1,N,E);
    r+=(ld(c[1]-N)/ld(tot-C-N-E))*f(C,N+1,E);
    r+=(ld(c[2]-E)/ld(tot-C-N-E))*f(C,N,E+1);
    return r;
}
int main(){
    JET
    cin>>L>>H;
    fore(i,0,3) cin>>p[i];
    fore(i,0,3) cin>>c[i];
    fore(i,0,3) tot+=c[i];
    cout<<fixed<<setprecision(16)<<f(0,0,0)<<"\n";
    return 0;
}