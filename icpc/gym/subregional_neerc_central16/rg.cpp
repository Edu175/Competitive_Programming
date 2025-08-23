#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
int main(){JET
	ll N; srand((ll)&N); cin>>N;
	ll n=rng()%N+1;
	ll m=rng()%N+1;
	cout<<n<<" "<<m<<"\n";
	// cout<<n<<"\n"<<m<<"\n";
	// vector<ii>ed;
	// fore(i,0,n)fore(j,i+1,n)ed.pb({i,j});
	// random_shuffle(ALL(ed));
	// vector<ll>c(n);
	// fore(i,0,n)c[i]=rng()%3;
	// fore(i,0,m){
	// 	auto [x,y]=ed[i];
	// 	if(rng()&1)swap(x,y);
	// 	cout<<x+1;
	// 	ll r=rng()%3;
	// 	if(c[x]<c[y])cout<<"<";
	// 	if(c[x]==c[y])cout<<"=";
	// 	if(c[x]>c[y])cout<<">";
	// 	cout<<y+1<<"\n";
	// }
	// cout<<"c es ";
	// for(auto i:c)cout<<i<<" ";;cout<<"\n";
}