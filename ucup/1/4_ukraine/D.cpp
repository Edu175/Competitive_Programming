#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn = 505;
ll a[maxn][maxn];

const ll inf = 1000000005;

void fw(int n){
	fore(m,0,n)fore(x,0,n)fore(y,0,n)if(a[x][m] < inf && a[m][y] < inf) a[x][y] = min (a[x][y],a[x][m] + a[m][y]);
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii> ar;
		bool b = 1;
		fore(i,0,n)fore(j,0,n){
			char c; cin>>c;
			if(i == j && c == '1')b = 0;
			if(c == '1'){
				a[i][j] = 1;
				if(i<j) ar.pb({i+1,j+1});
			}
			else a[i][j] = inf;
			if(i>j && a[i][j]!=a[j][i])b=0;
		}
		fw(n);
		fore(i,0,n)fore(j,0,n) if(a[i][j]!=1 && a[i][j]&1) b = 0;
		if(!b)cout<<"NO\n";
		else{
			cout<<"YES\n"<<SZ(ar)<<"\n";
			for(auto [x,y]:ar)cout<<x<<" "<<y<<"\n"; 
		}
		
	}
	
	
	return 0;
}