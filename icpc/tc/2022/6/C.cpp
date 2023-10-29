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

int main(){FIN;
	ll a,b; cin>>a>>b;
	ll res=0;
	ll m=max(a,b);
	ll n=min(a,b);
	while(m>1&&n>1){
		res+=m/n;
		m=m%n;
		swap(m,n);
		//cout<<m<<" "<<n<<"\n";
	}
	res+=max(m,n);
	pres;
	return 0;
}
