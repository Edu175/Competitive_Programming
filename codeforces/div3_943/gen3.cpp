#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll sd; srand((long long)&sd);
	cout<<"1\n";
	ll n=2e5,q=2e5;
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n){
		if(i)cout<<" ";
		cout<<"1";
	}
	cout<<"\n";
	vector<ii>qs;
	fore(_,0,q){
		ll l=rand()%(n-5),r=rand()%(n-5);
		if(r<=l)swap(l,r);
		while((r-l+1)<=1||(r-l+1)%2==0)r++;
		l++,r++;
		qs.pb({l,r});
	}
	for(auto i:qs)cout<<i.fst<<" "<<i.snd<<"\n";
	return 0;
}
