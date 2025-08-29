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

int main(){
    JET
    ll n,m; cin>>n>>m;
    ll oro[n+1]; mset(oro,0);
    fore(i,0,m){
        ll G[2]; cin>>G[0]>>G[1];
        ll d[n];
        ll c=0;
        fore(j,0,n){
            cin>>d[j];
            d[j]--;
            c+=!d[j];
        }
        ll ch=0;
        if(G[0]/(c+1)<G[1]){
            ch=G[1];
        }
        else{
            c++;
            ch=G[0]/(c);
        }
        oro[n]+=ch;
        fore(j,0,n){
            oro[j]+=(d[j]?G[1]:G[0]/c);
        }
    }
    fore(i,0,n+1) cout<<oro[i]<<" ";;cout<<"\n";
    return 0;
}