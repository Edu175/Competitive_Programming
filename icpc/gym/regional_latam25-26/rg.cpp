#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

random_device rd;
mt19937 rng(rd());
const int maxn = 305;
ll vis[maxn][maxn][2];


int main(){
    ll N,M,A,K,V; cin>>N>>M>>A>>K>>V;
    ll n = N, m = M;
	ll a = rng()%A+1, k = rng()%K+1;
    while(a > 2 *n*m -m - n ){
        n = rng()%N+1;
        m = rng()%M+1;
        a = rng()%A;
    }
    // cerr<<"caso\n";
    cout<<n<<" "<<m<<" "<<a<<" "<<k<<"\n";
    ll values[n][m];
    fore(i,0,n)fore(j,0,m){
        ll val = rng()%V+1;
        cout<<val<<(j==m-1?"\n":" ");
        values[i][j] = val;
    }   
    fore(i,0,n)fore(j,0,m){
        ll cam = rng()%V+1;
        if(rng()%2) cam = -cam;
        while(values[i][j] + cam * k <0){
            cam = rng()%V+1;
            if(rng()%2) cam = -cam;
        }
        cout<<cam<<(j==m-1?"\n":" ");
    }
    fore(i,0,a){
        // cerr<<"intento "<<n<<" "<<m<<" "<<a<<"\n";
        ll x = rng()%n+1, y = rng()%m+1;
        ll k = rng()%2;
        while((!k && x == n) || (k && y == m) || (x == n && y == m)) x = rng()%n+1, y = rng()%m+1, k = rng()%2;
        vis[x][y][m] =1;
        cout<<x<<" "<<y<<" ";
        if(!k) cout<<x+1<<" "<<y<<"\n";
        else cout<<x<<" "<<y+1<<"\n";
    }
}