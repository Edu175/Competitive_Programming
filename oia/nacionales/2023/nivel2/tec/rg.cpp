#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

/*vector<ll> rgen(ll n, ll m){ //n distinct numbers from 1 to n
	
}*/

int main(){FIN;
	ll N,Q; srand((ll)&N); cin>>N>>Q;
	ll n=rand()%N+1;
	cout<<n<<" "<<n-1<<"\n";
	fore(i,0,n-1)cout<<i+1<<" "<<i+2<<"\n";
	ll q=rand()%Q+1;
	cout<<q<<"\n";
	while(q--){
		ll m=rand()%n+1;
		cout<<m<<" ";
		vector<ll>is(n);
		ll q=0;
		fore(i,0,m)is[rand()%n]=1;
		fore(i,0,n)q+=is[i];
		fore(i,0,n){
			if(!is[i]&&q<m)is[i]=1,q++;
			if(is[i])cout<<i+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
