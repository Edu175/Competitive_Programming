#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());
int main(){
	ll N; cin>>N;
	ll n=rng()%(N-1)+2;
	cout<<n<<"\n";
	fore(i,0,n)cout<<"1 ";;cout<<"\n";
	fore(i,1,n){
		cout<<rng()%i<<" "<<rng()%3<<" ";
	}
	cout<<"\n";
}