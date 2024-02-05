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
const ll MAXV=1e7+5;
ll cant[MAXV];
void divisores(){
	fore(i,1,MAXV)for(ll j=i;j<MAXV;j+=i)cant[j]++;
}

int main(){FIN;
	divisores();
	ll n,k,q; cin>>n>>k>>q;
	vector<ll>a(n),b(n);
	fore(i,0,n)cin>>a[i],b[i]=cant[a[i]]>=q;
	vector<ll>p={-1};
	fore(i,0,n)if(b[i])p.pb(i);
	fore(i,0,3*n)p.pb(n);
	//imp(b);
	ll res=0,c=0;
	fore(i,0,n){
		res+=p[c+k+1]-p[c+k];
		//cout<<i<<" "<<c<<": "<<p[c+k]<<" "<<p[c+k+1]<<"\n";
		c+=b[i];
	}
	cout<<res<<"\n";
	return 0;
}
