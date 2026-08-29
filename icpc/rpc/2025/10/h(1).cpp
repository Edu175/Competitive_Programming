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
    ll n; cin>>n;
    set<pair<string,ll>> s;
    vector<string> v;
    fore(i,0,n){
        string t; cin>>t;
        v.pb(t);
    }
    fore(i,0,n)fore(j,0,n){
        s.insert({v[i]+v[j],2});
    }
    fore(i,0,n){
        s.insert({v[i],1});
    }
    ll m; cin>>m;
    fore(i,0,m){
        string t; cin>>t;
        auto it=s.lower_bound((pair<string,ll>){t,0});
        if(it->fst==t){
            cout<<(it->snd)<<"\n";
        }
        else{
            cout<<"0\n";
        }
    }
    return 0;
}