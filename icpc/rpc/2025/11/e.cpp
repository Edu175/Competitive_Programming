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



int main(){
    JET
    ld L1,L2,h,w,t;
    cin>>L1>>L2;
    fore(i,0,2) cin>>t;
    cin>>t; L1=t-L1; cin>>t; L2=t-L2;
    fore(i,0,2) cin>>t;
    cin>>w>>h;
    ld r=h/w;
    w=min(L2/r,L1);
    cout<<fixed<<setprecision(16)<<r*w*w<<"\n";
    return 0;
}