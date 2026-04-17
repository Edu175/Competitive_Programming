#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef ll xl;
typedef pair<xl,xl> xxl;
typedef pair<ll,ll> ii;

xl gcd(xl a, xl b){while(b){ll t = a%b;a=b;b=t;}return a;}
xxl extendedEuclid(xl a, xl b){
	xl x,y; 
	if(b == 0) return {(xl)1,(xl)0};
	auto p = extendedEuclid(b,a%b);
	x = p.snd;
	y = p.fst - (a/b)*x;
	if(a*x + b*y == -gcd(a,b)) x =-x, y = -y;
	return {x,y};
}

pair<xxl,xxl> diophantine(xl a, xl b, xl r){
	xl d = gcd(a,b);
	a/=d;b/=d;r/=d;
	auto p = extendedEuclid(a,b);
	p.fst*=r; p.snd*=r;
	assert(a*p.fst + b*p.snd == r);
	return {p,{-b,a}};
}

xl inv(xl a, xl m){
	assert(gcd(a,m) == 1);
	xl x = diophantine(a,m,1).fst.fst;
	return((x%m) + m)%m;
}

#define mod(a,m) (((a)%m+m)%m)
xxl sol(tuple<xl,xl,xl> c){
	xl a = get<0>(c), x1 =get<1>(c), m =get<2>(c), d= gcd(a,m);
	if(d == 1)return{mod(x1*inv(a,m),m),m};
	else return x1%d ? xxl({(xl)-1,(xl)-1}) : sol(make_tuple(a/d,x1/d,m/d));
}

xxl crt(vector<tuple<xl,xl,xl>> cond){
	xl x1 = 0, m1 = 1, x2, m2;
	for(auto t:cond){
		tie(x2,m2) = sol(t);
		if(m2<0 || (x1-x2)%gcd(m1,m2)) return {-1,-1};
		if(m1 == m2)continue;
		xl k = diophantine(m2,-m1,x1-x2).fst.snd, l = m1*(m2/gcd(m1,m2));
		x1 = mod((__int128)m1*k+x1,l);m1=l;
	}
	return(sol(make_tuple(1,x1,m1)));
}

ll hard = 105;
ll util = 1e17;

void imp(xl x){
	
	ll k = x%(util);
	x/=util;
	ll k2 = x;
	if(k2)cout<<k2;
	cout<<k<<"\n";
}

int main(){
	JET
	ll n,z; cin>>n>>z;
	// cout<<util<<endl;
	// xl f = 1234567891011LL;
	// f *= ((ll)1e10);
	// f += 1213141516LL;
	// imp(f);
	// cout<<"\n"; 
	vector<pair<vv,ll>> cyc(n);
	// cout<<LLONG_MAX<<"\n";
	ll pos[n][hard];
	fore(i,0,n){
		ll p; cin>>p;
		p--;
		vv g(z);
		fore(j,0,z){
			ll x; cin>>x;
			x--;
			g[j] = x;
		}
		vv vis(z,-1);
		ii aux = {-1,-1};
		ll t = 0;
		while(t<hard){
			pos[i][t] = p;
			if(vis[p] >=0 && aux.fst<0) aux = {p,vis[p]}; 
			vis[p] = t;
			p = g[p];
			t++;
		}
		ll x = aux.fst, y = g[aux.fst];
		cyc[i].fst.pb(x);
		t = aux.snd;
		while(y!=x){
			cyc[i].fst.pb(y);
			y=g[y];
		}
		cyc[i].snd = aux.snd;
	}
	fore(i,0,hard){
		bool b = true;
		fore(j,1,n)if(pos[j][i] != pos[0][i]) b = false;
		if(b){
			cout<<pos[0][i]+1<<" "<<i<<"\n";
			return 0;
		}
	}
	// cout<<"ajsda"<<endl;
	const xl inf = LLONG_MAX;
	pair<xl,int> res = {inf,-1};
	fore(i,0,z){
		vector<tuple<xl,xl,xl>> v;
		fore(j,0,n){
			fore(k,0,SZ(cyc[j].fst)){
				#define mt make_tuple
				ll x = cyc[j].fst[k];
				if(x!=i) continue;
				v.pb(mt((xl)1,(xl)(k + cyc[j].snd)%SZ(cyc[j].fst),(xl)SZ(cyc[j].fst)));
				break;
			}
		}
		if(SZ(v) != n) continue;
		auto[c,m] = crt(v);
		if(c == -1) continue;
		// cout<<SZ(v)<<" "<<(ll)c<<" "<<(ll)m<<endl;
		// cout<<"find solution, equations: ";
		// for(auto x:v){
			// ll a = get<0>(x), x1 =get<1>(x), m =get<2>(x);
			// cout<<a<<" *x= "<<x1<<" ("<<m<<")\n";
		// }
		while(c<105) c+=m;
		res = min(res,{c,i});
		assert(m <= (xl)LLONG_MAX);
	}
	if(res.snd == -1){
		cout<<"*\n";
		return 0;
	}
	cout<<res.snd+1<<" ";
	imp(res.fst);
	
	
	
	return 0;
}