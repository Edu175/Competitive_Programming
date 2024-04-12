#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,balkoi=b;i<balkoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdkj:v)cout<<cv(sdkj)<<" ";cout<<endl
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll N; srand((ll)&N); cin>>N;
	ll n=rand()%N+1;
	cout<<n<<"\n";
	fore(i,1,n)cout<<rand()%i<<" ";;cout<<"\n";
	fore(i,0,n)cout<<1<<" ";;cout<<"\n";
	return 0;
}
