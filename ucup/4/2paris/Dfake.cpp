#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>k;
		if(k==1){
			cout<<"1\n";
			continue;
		}
		ll ord=0,pot=1;
		fore(i,1,k+5){
			pot=pot*10%k;
			if(pot==1){
				ord=i;
				break;
			}
		}
		cerr<<"ord "<<ord<<"\n";
		cerr<<k<<" k\n";
		vv a(ord),val(ord);
		pot=1;
		fore(i,0,SZ(a)){
			ll bo=(i<20*k%ord);
			a[i]=(20*k/ord+bo)*9;
			cerr<<k/ord<<" ratio\n";
			cerr<<k<<" k\n";
			val[i]=pot;
			pot=pot*10%k;
		}
		imp(a)
		imp(val)
		ll c=k;
		vv us(ord);
		for(ll i=ord-1;i>=0;i--){
			ll q=min(a[i],c/val[i]);
			us[i]=q;
			c-=val[i]*q;
		}
		assert(c==0);
		vv res(20*k);
		fore(i,0,ord){
			ll q=us[i];
			for(ll p=i;q;p+=ord){
				ll act=min(9ll,q);
				res[p]=act;
				q-=act;
			}
			// assert()
		}
		while(SZ(res)&&res.back()==0)res.pop_back();
		reverse(ALL(res));
		for(auto i:res)cout<<i;
		cout<<"\n";
	}
	return 0;
}
