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
typedef int ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n){
		string s; cin>>s;
		fore(j,0,k)a[i]^=s[j]-'0',a[i]<<=1;
	}
	ll res=k;
	fore(i,0,n)fore(j,i+1,n)res=min(res,__builtin_popcount(a[i]^a[j]));
	cout<<res<<"\n";
	return 0;
}
