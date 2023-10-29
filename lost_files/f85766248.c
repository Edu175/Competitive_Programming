#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto djfhg:v)cout<<djfhg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
	ll N,V; srand((ll)&N); cin>>N>>V;
	ll n=rand()%(N-1)+2;
	cout<<n<<"\n";
	fore(i,0,n)cout<<rand()%V<<" ";
	cout<<"\n";
}


