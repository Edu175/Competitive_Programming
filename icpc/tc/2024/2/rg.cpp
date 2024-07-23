#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){JET
	ll N,V; cin>>N>>V;
	ll n=rng()%(N-1)+2;
	cout<<n<<"\n";
	ll a[n][n];
	fore(i,0,n)fore(j,0,n)a[i][j]=rng()%(V+1);
	fore(i,0,n)a[i][i]=-1;
	fore(i,0,n)fore(j,0,i)if(!rng()%n)a[i][j]=a[j][i]=-1;
	fore(i,0,n){
		fore(j,0,n)cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}