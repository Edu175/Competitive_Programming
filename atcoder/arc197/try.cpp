#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXOP=1e5+5;
const ll MAXN=1e8;

bitset<MAXN>vis;

int main(){FIN;
	ll cnt=0;
	fore(i,2,MAXN)if(!vis[i]){
		if(cnt>MAXOP){
			cout<<"ans "<<i<<"\n";
			break;
		};
		cnt++;
		for(ll j=i*i;j<MAXN;j+=i)vis[j]=1;
	}
	return 0;
}
