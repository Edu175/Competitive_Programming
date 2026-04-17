#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

void tle(bool b){
	if(!b){
		auto start=clock();
		while(clock()-start<30*CLOCKS_PER_SEC);
		cerr<<"chota\n";
	}
}

#define WA(b) \
	if(!(b)){\
		cerr<<"fail|";\
		for(auto i:a)cout<<i;;cout<<endl;\
		exit(0);\
	}

ll odd(ll n, ll k){
	return (n|k)==n;
}

void locuras(ll pos, ll w){
	cout<<pos/w+1<<" "<<pos%w+1<<"\n";
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll h,w,k; cin>>h>>w>>k;
		ull mk = 0;
		ll n = h*w;
		fore(i,0,n){
			char c; cin>>c;
			if(c== '#') mk|=1ull<<i;
		}
		// cerr<<((n|k)==n)<<"\n";
		// cerr<<n<<" "<<k<<"\n";
		if(odd(n,k)){
			cout<<"risky"<<endl;
			continue;
		}
		vv a(n);
		fore(i,0,n)a[i]=mk>>i&1;
		// for(auto i:a)cout<<i;;cout<<endl;
		// ll t=0;
		ll c=0,p=-3;
		ll f1=-1,f2=-1;
		fore(i,0,n+1)if(i==n||a[i]){
			if(c){
				ll m=i;
				vv all;
				fore(j,c-1,m)if(odd(j,c-1))all.pb(j);
				ll pos=find(ALL(all),p)-all.begin();
				ll idx=(pos%2==0)^odd(m,c)?pos+1:pos-1;
				// cerr<<"all: ";;for(auto i:all)cout<<i<<" ";;cout<<endl;
				// cerr<<m<<" "<<c<<": "<<p<<" "<<pos<<" "<<idx<<endl;
				assert(pos<SZ(all));
				if(idx>=0){
					WA(idx<m);
					WA(p>=0);
					ll q=all[idx];
					f1=p,f2=q;
					break;
				}
			}
			c++; p=i;
		}
		if(f1==-1){
			cerr<<"fail|";
			for(auto i:a)cout<<i;;cout<<endl;
			continue;
		}
		assert(f1!=-1);
		assert(!(mk>>f2&1));
		// if(mk>>f2&1) swap(f1,f2);
		// cerr<<sz<<": "<<f1<<" "<<f2<<"\n";
		locuras(f1,w);locuras(f2,w);
		cout<<endl;
	}

	return 0;
}