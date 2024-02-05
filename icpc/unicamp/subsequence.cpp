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
	//assert(0);
	while(1){
		ll n,s; cin>>n>>s;
		if(!n&&!s)break;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll sum=0,p=0,res=n;
		/*fore(i,0,n){
			while(p<n&&sum<s)sum+=a[p++];
			if(sum>=s)res=min(res,p-i);
			sum-=a[i];
		}*/
		fore(i,0,n)fore(j,0,)
		cout<<res<<"\n";
	}
	return 0;
}
