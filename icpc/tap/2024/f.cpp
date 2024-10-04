#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
    int n; cin>>n;
    int cnt=0;
    int rta=0;
    fore(i,0,n){
        int x; cin>>x;
        if(x==1){
            rta++;
            cnt++;
            if(cnt>2) rta++;
        }
        else{
            rta--;
            cnt=0;
        }
    }
    cout<<rta<<"\n";
    return 0;
}