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
	if(w>=n)return {};
	vector<ll>a(n);
	ll s=b[w],r=b[1]-b[0];
	a[2]=(r+s)/2;
	a[1]=s-a[2];
	a[0]=b[0]-a[1];
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
	ll N,V; srand((ll)&N); cin>>N>>V;
	fore(_,0,10000){
		ll n=rand()%(N-2)+3;
		vector<ll>a(n);
		fore(i,0,n)a[i]=rand()%V+1;
		sort(ALL(a));
		vector<ll>b;
		fore(i,0,n)fore(j,i+1,n)b.pb(a[i]+a[j]);
		sort(ALL(b));
		auto r1=assume(b,n,2),r2=assume(b,n,3);
		if(!(r1==a||r2==a)){
			cout<<n<<"\n";
			imp(b);
			cout<<"(answer) "; imp(a);
			exit(0);
		}
		cout<<"ok "<<_+1<<"\n";
	}
	return 0;
}
