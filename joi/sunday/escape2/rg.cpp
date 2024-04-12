#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,joi=b;i<joi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto djfg:v)cout<<djfg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll N,V,M,Q; srand((ll)&N); cin>>N>>M>>V>>Q;
	ll n=rand()%(N-1)+2,t=rand()%(V-1)+2;
	cout<<n<<" "<<t<<"\n";
	fore(i,0,n-1){
		ll m=rand()%M+1;
		cout<<m<<"\n";
		fore(_,0,m){
			ll x=rand()%(t-1),y=rand()%(t-1);
			if(x>y)swap(x,y);
			y++;
			cout<<x<<" "<<y<<"\n";
		}
	}
	ll q=rand()%Q+1;
	cout<<q<<"\n";
	while(q--){
		ll x=rand()%(n-1),y=rand()%(n-1);
		if(x>y)swap(x,y);
		y++;
		cout<<x+1<<" "<<y+1<<"\n";
	}
	return 0;
}
