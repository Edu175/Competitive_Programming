#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define str to_string
string cv(ii a){return str(a.fst)+","+str(a.snd);}

void operator&=(ii &a, ii b){ // with parity
	ii c={max(a.fst,b.fst),min(a.snd,b.snd)};
	if((c.fst&1)!=(a.fst&1))c.fst++;
	if((c.snd&1)!=(a.snd&1))c.snd--;
	a=c;
}
ii simu(ii s, vector<ii> a){ // {-1,-1} if bad
	// cerr<<"simu "<<cv(s)<<":\n";
	fore(i,0,SZ(a)){
		if(i)s.fst--,s.snd++;
		s&=a[i];
		// cerr<<i<<" "<<cv(a[i])<<": "<<cv(s)<<"\n";
		if(s.fst>s.snd)return {-1,-1};
	}
	return s;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii> a(n+1,{0,n});
		fore(i,1,n){
			ll x; cin>>x;
			if(x>0)a[i].fst=x;
			else a[i].snd=n+x;
		}
		string ans;
		ll fg=n&1;
		fore(od,0,2){
			// careful with n !
			reverse(ALL(a));
			ii e=simu({-(od^fg),2*n+10+(od^fg)},a);
			reverse(ALL(a));
			if(e.fst==-1)continue;
			assert(e.fst%2==e.snd%2);
			auto left=[&](ll m){
				ll otr=n-m;
				// cerr<<"\nleft "<<m<<" "<<otr<<":\n";
				ii got=simu({m,m},a);
				assert(got.fst%2==otr%2);
				return otr>got.snd;
			};
			ll l=e.fst-2,r=e.snd+2;
			while(r-l>2){
				ll m=(l+r)/2;
				m=(m|1)-1+od;
				if(left(m))l=m;
				else r=m;
			}
			if(r>e.snd)continue;
			ll b0=r;
			ii got=simu({b0,b0},a);
			ll otr=n-b0;
			assert(otr<=got.snd);
			if(otr<got.fst)continue;
			vector<ii> rans(n+1);
			ii s={b0,b0};
			fore(i,0,SZ(rans)){
				if(i)s.fst--,s.snd++;
				s&=a[i];
				rans[i]=s;
			}
			vv b(n+1);
			ll t=otr;
			for(ll i=SZ(b)-1;i>=0;i--){
				assert(rans[i].fst<=t&&t<=rans[i].snd);
				b[i]=t;
				if(i>0){
					auto [s,e]=rans[i-1];
					if(s<=t-1&&t-1<=e)t--;
					else t++;
				}
			}
			assert(b[0]+b.back()==n);
			string cur;
			fore(i,0,SZ(b)-1){
				ll dif=b[i+1]-b[i];
				assert(abs(dif)==1);
				if(dif<0)cur.pb('<');
				else cur.pb('>');
			}
			ans=cur;
			// show(b)
			// for(auto i:a)cerr<<cv(i)<<" ";;cerr<<"\n";
		}
		assert(SZ(ans));
		cout<<ans<<"\n";
	}
	return 0;
}