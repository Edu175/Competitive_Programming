#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

string col;
const ll inf = 1e14;

ll f(vv a){
	assert(SZ(a) == SZ(col)-1);
	a.pb(0);
	ll r = 0;
	fore(i,0,SZ(a)){
		if(col[a[i]] == col[a[(i+1)%SZ(a)]]) return inf;
		r += abs(a[i] - a[(i+1)%SZ(a)]);
	}
	return r;
}


void red(ll &a, ll &b){
	ll q=min(a,b);
	a-=q,b-=q;
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;n*=2;
		col.resize(n);
		fore(i,0,n) cin>>col[i];
		ll gr=0;
		if(0){
			queue<ll> c,u;
			fore(i,0,n){
				if(col[i] == 'B')c.push(i);
				else u.push(i);
			}
			ll pu = u.front(),pc = c.front();
			ll x = 0; gr = 0;
			if(col[x] == 'B')c.pop();
			else u.pop();
			fore(_,0,n-1){
				if(col[x] == 'B'){
					gr += abs(u.front()-x);
					x = u.front();
					u.pop();
				}
				else{
					gr += abs(c.front()-x);
					x=c.front();
					c.pop();
				}
			}
			if(col[x] == 'B')gr+=abs(x-pu);
			else gr+=abs(x-pc);
		}
		
		// cout<<"asdnoasd"<<endl;
		cerr<<"col "<<col<<"\n";
		fore(i,1,n){
			vv l(col.begin(),col.begin()+i);
			vv r(col.begin()+i,col.end());
			ll al=count(ALL(l),'W');
			ll bl=count(ALL(l),'B');
			ll ar=count(ALL(r),'W');
			ll br=count(ALL(r),'B');
			red(al,bl);
			red(ar,br);
			ll c=max(al,bl);
			assert(c==max(ar,br));
			c=max(c,1ll);
			gr+=2*c;
			cout<<c<<" ";
			// cerr<<i<<": "<<al<<","<<bl<<" "<<ar<<","<<br<<"\n";
		}
		cout<<"\n";
		vv ord(n-1); iota(ALL(ord),1);
		map<ll,ll> mp;
		do{
			ll x = f(ord);
			mp[x]++;
			if(x == 10)show(ord);
		}while(next_permutation(ALL(ord)));
		auto it = mp.begin();
		cout<<(*it).fst<<" "<<(*it).snd/2<<"\n";
		if(gr != (*it).fst)cout<<"GREEDY MAL!!!!!! "<<gr<<" vs "<<((*it).fst)<<"\n";		
		cout<<endl;
	}
	
	
	return 0;
}