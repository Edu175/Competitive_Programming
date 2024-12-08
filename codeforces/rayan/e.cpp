#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;


vector<vv> make3(ll n){
	vector<vv>a;
	vv per(n); iota(ALL(per),0);
	a.pb(per);
	rotate(per.begin(),per.begin()+n/2,per.end());
	a.pb(per);
	vector<ii>ind;
	fore(i,0,n)ind.pb({a[0][i]+a[1][i],i});
	sort(ALL(ind));
	reverse(ALL(ind));
	fore(i,0,n)per[ind[i].snd]=i;
	a.pb(per);
	return a;
}
vv op(vv a){
	ll n=SZ(a);
	for(auto &i:a)i=n-1-i;
	return a;
}
vector<vv> get(ll n, ll k){
	set<vv>st;
	vector<vv>a;
	if(k&1){
		auto b=make3(n);
		for(auto i:b)a.pb(i),st.insert(i);
	}
	vv per(n); iota(ALL(per),0);
	do{
		if(SZ(a)==k)break;
		if(!st.count(per)&&!st.count(op(per))){
			a.pb(per); st.insert(per);
			a.pb(op(per)); st.insert(op(per));
		}
		
	}while(next_permutation(ALL(per)));
	return a;
}
bool good(vector<vv>a){
	set<ll>st;
	ll n=SZ(a[0]),k=SZ(a);
	fore(i,0,n){
		ll sum=0;
		fore(j,0,k)sum+=a[j][i];
		st.insert(sum);
	}
	return SZ(st)==1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll fac=1,INF=k+5;
		fore(i,1,n+1)fac=min(fac*i,INF);
		if(n==1&&k==1)cout<<"YES\n1\n";
		else if(k==1||k>fac||k==fac-1||(k%2==1&&n%2==0)){
			cout<<"NO\n";
		}
		else {
			cout<<"YES\n";
			auto a=get(n,k);
			assert(good(a));
			for(auto v:a){
				for(auto i:v)cout<<i+1<<" ";
				cout<<"\n";
			}
		}
	}
	return 0;
}
