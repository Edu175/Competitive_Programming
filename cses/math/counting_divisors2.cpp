#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e6+5;

ll divs[MAXN];
void div_cri(){
	fore(i,1,MAXN)for(ll j=i;j<MAXN;j+=i)divs[j]++;}
}

int main(){FIN;
	ll n;cin>>n;
	div_cri();
	while(n--){
		ll x; cin>>x;
		cout<<divs[x]<<"\n";
	}
	return 0;
}
