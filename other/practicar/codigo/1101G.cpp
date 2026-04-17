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
const ll B=30;
struct matrix{
	vector<ll>x;
	matrix(): x(B){}
	bool add(ll v){
		if(v==0)return 0;
		for(ll j=B-1;j>=0;j--)v=min(v,v^x[j]);
		if(v){x[31-__builtin_clz(v)]=v;return 1;}
		return 0;
	}
};

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,1,n)a[i]^=a[i-1];
	ll res=0;
	if(a[n-1]==0){
		cout<<"-1\n";
		return 0;
	}
	matrix mt;
	fore(i,0,n)res+=mt.add(a[i]);
	cout<<res<<"\n";
	return 0;
}

