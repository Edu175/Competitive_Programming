#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct Cmp{
	bool operator()(const ii &a, const ii &b)const{
		return ii({a.fst,-a.snd})<ii({b.fst,-b.snd});
	}
};
multiset<ii,Cmp> st;

bool dom(ii a, ii b){
	return a.fst<b.fst&&a.snd<b.snd;
}

void add(ii x){
	auto it=st.lower_bound(x);
	if(it!=st.end()&&dom(x,*it))return;
	st.insert(x);
	auto po=st.lower_bound(x);
	while(po!=st.begin()&&dom(*prev(po),x))st.erase(prev(po));
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n){
		ii x; cin>>x.fst>>x.snd;
		add(x);
		cout<<SZ(st)<<"\n";
	}
	return 0;
}