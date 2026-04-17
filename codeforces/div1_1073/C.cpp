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

ll ask(ll i, ll j){
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}

vv merge(vv a, vv b){
	ll l=0,r=0;
	vv c;
	while(l<SZ(a)&&r<SZ(b)){
		if(ask(a[l],b[r]))c.pb(a[l++]);
		else c.pb(b[r++]);
	}
	while(l<SZ(a))c.pb(a[l++]);
	while(r<SZ(b))c.pb(b[r++]);
	return c;
}

int main(){
	// FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vv> bags={{n-1}};
		for(ll i=n-2;i>=0;i--){
			if(ask(i,i+1)!=SZ(bags)%2)bags.pb({});
			bags.back().pb(i);
			if(SZ(bags)==3)break;
		}
		if(SZ(bags)<3){
			cout<<"! -1"<<endl;
			continue;
		}
		reverse(ALL(bags[0]));
		vv bag=merge(bags[0],bags[1]);
		ll s=bags[2][0];
		bag.insert(bag.begin(),s);
		ll p=-1;
		fore(i,1,SZ(bag)){
			if(ask(s,bag[i])){
				p=i;
				break;
			}
		}
		assert(p!=-1);
		swap(bag[0],bag[p]);
		vv ans(n); iota(ALL(ans),0);
		fore(i,s,n)ans[i]=bag[i-s];
		cout<<"! ";
		for(auto i:ans)cout<<i+1<<" ";
		cout<<endl;
	}
	return 0;
}
