#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	cout<<"1\n";
	ll N; cin>>N;
	ll n=rng()%(N-1)+2; cout<<n<<" ";
	
	ll k=rng()%(n-1)+n; cout<<k<<"\n";
	
	fore(i,0,n)cout<<rng()%n+1<<" ";;cout<<"\n";
	
	return 0;
}