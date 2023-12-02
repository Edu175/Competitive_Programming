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

int main(){FIN;
	ll M,C,V; srand((ll)&M); cin>>M>>C>>V;
	ll c=rand()%C+1,m=rand()%M+1; cout<<c<<" "<<m<<"\n";
	fore(i,0,m){
		ll a=rand()%V+1,b=rand()%V+1;
		if(a>b)swap(a,b);
		if(a==b){
			if(a>1)a--;
			else b++;
		}
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
}
