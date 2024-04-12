#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
	ll N,M,V; srand((ll)&N); cin>>N>>M>>V;
	ll n=rand()%N+1,m=rand()%M+1;
	cout<<n<<" "<<m<<" 1\n";
	vector<string>a(n,string(m,'-'));
	fore(i,0,n)fore(j,0,m)a[i][j]='a'+rand()%V;
	fore(i,0,n){
		fore(j,0,m)cout<<a[i][j];
		cout<<"\n";
	}
	ll mk=rand()%(1ll<<(n+m));
	fore(i,0,n){
		if((mk>>i)&1)reverse(ALL(a[i])),reverse(ALL(a[n-1-i]));
	}
	fore(j,0,m){
		if((mk>>(n+j))&1){
			fore(i,0,n/2)swap(a[i][j],a[n-1-i][j]);
			fore(i,0,n/2)swap(a[i][m-1-j],a[n-1-i][m-1-j]);
		}
	}
	fore(i,0,n){
		fore(j,0,m)cout<<a[i][j];
		cout<<"\n";
	}
	return 0;
}
