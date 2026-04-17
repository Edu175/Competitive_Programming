#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define push_back pb
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int k,n,m; 
const int maxn = 3001;
ll g[maxn][maxn];
ll snake[maxn][maxn];


int main(){
	JET
	cin>>k>>n>>m;
	fore(i,0,k){
		ll x,y; cin>>x>>y;
		x--,y--;
		snake[x][y]++;
	}
	fore(i,0,n)fore(j,0,m)cin>>g[i][j];
	return 0;
}