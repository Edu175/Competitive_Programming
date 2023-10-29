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
const ll INF=1e15;

int main(){FIN;
	ll n,l,r; cin>>n>>l>>r;
	ll a[n];
	fore(i,0,n)cin>>a[i],a[i]=-a[i];
	vector<ll>sp(n+1);
	fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
	multiset<ll>st;
	ll dif=0;
	ll res=INF;
	fore(i,0,n){
		if(i-r>=0)st.erase(st.find(sp[i]-sp[i-r]-dif));
		if(i-l+1>=0)st.insert(sp[i]-sp[i-l+1]-dif);
		dif+=a[i];
		if(SZ(st))res=min(res,*st.begin()+dif);
		//cout<<i<<": "<<dif<<"\n";
		//imp(st);
	}
	cout<<-res<<"\n";
	return 0;
}

