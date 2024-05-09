#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<cv(gdljh)<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
	int N,V,M; srand((ll)&N); cin>>N>>V>>M;
	int n=rand()%(N-2)+3;
	vector<ii>a;
	if(n&1)a.pb({0,0});
	fore(i,0,n/2){
		ll x=rand()%(2*V+1)-V,y=rand()%(2*V+1)-V;
		ll m=rand()%M+1;
		a.pb({x*m,y*m});
		m=-(rand()%M+1);
		a.pb({x*m,y*m});
	}
	random_shuffle(ALL(a));
	cout<<n<<"\n";
	fore(i,0,n)cout<<a[i].fst<<" "<<a[i].snd<<"\n";
	return 0;
}
