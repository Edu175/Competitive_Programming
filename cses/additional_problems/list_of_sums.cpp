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

vector<ll> assume(vector<ll>b, ll n, ll w){
	if(w>=SZ(b))return {};
	vector<ll>a(n);
	ll s=b[w],r=b[1]-b[0];
	a[2]=(r+s)/2;
	a[1]=s-a[2];
	a[0]=b[0]-a[1];
	//cout<<s<<" "<<r<<": "<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n";
	multiset<ll>st;
	for(auto i:b)st.insert(i);
	fore(i,0,3)fore(j,i+1,3){
		auto it=st.find(a[i]+a[j]);
		if(it==st.end())return {};
		st.erase(it);
	}
	fore(k,3,n){
		a[k]=*st.begin()-a[0];
		fore(i,0,k){
			auto it=st.find(a[i]+a[k]);
			if(it==st.end())return {};
			st.erase(it);
		}
	}
	return a;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>b(n*(n-1)/2);
	fore(i,0,SZ(b))cin>>b[i];
	sort(ALL(b));
	vector<ll>r;
	fore(w,2,SZ(b)){
		auto a=assume(b,n,w);
		if(SZ(a)){
			imp(a);
			exit(0);
		}
	}
	assert(0);
	return 0;
}
