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
    ll n,m;
    cin>>n>>m;
    char g[n][m];
    fore(i,0,n)fore(j,0,m) cin>>g[i][j];
    ll t=0,a=0,p=0;
    for(int i=n-1;i>=0;i--){
        fore(j,0,m){
            if(g[i][j]=='#'){
                if(g[i-2][j+1]=='.'){
                    t++;
                    fore(x,0,5){
                        g[i-x][j]='.';
                    }
                    g[i-4][j+1]='.';
                    g[i-4][j-1]='.';
                    // cout<<i<<" "<<j<<"\n";
                }
                else if(g[i][j+2]=='#'){
                    a++;
                    fore(x,0,5){
                        g[i-x][j]='.';
                        g[i-x][j+2]='.';
                    }
                    g[i-2][j+1]='.';
                    g[i-4][j+1]='.';
                }
                else{
                    p++;
                    fore(x,0,5){
                        
                        g[i-x][j]='.';
                        g[i-x][j+2]='.';
                        g[i-x][j+1]='.';
                    }
                }
            }
        }
    }
    cout<<t<<" "<<a<<" "<<p<<"\n";
    return 0;
}