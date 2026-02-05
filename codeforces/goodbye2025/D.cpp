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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n); vector<ii> sa;
		fore(i,0,n)cin>>a[i],sa.pb({a[i],i});
		sort(ALL(sa));
		vector<ii> ans;
		vv att(n),h=a;
		auto mop=[&](ll i, ll j){
			ll x=sa[i].snd,y=sa[j].snd;
			// cerr<<"att "<<x+1<<" "<<y+1<<"\n";
			assert(min(h[x],h[y])>0);
			assert(!att[x]);
			ans.pb({x,y});
			h[x]-=a[y];
			h[y]-=a[x];
			att[x]=1;
			// imp(att) imp(h) cout<<endl;
		};
		auto stops=[&](){
			ll cant=0,hay=0;
			fore(i,0,n)if(h[i]>0)cant++,hay|=!att[i];
			assert(cant<2||!hay);
		};
		auto say=[&](){
			cout<<SZ(ans)<<"\n";
			for(auto [x,y]:ans){
				cout<<x+1<<" "<<y+1<<"\n";
			}
		};
		ll ult=sa.back().fst;
		auto good=[&](ll n, ll sum){
			if(m==0){
				return sum-ult>=ult;
			}
			return n/2==m;
		};
		ll np=n,s=-1,sum=accumulate(ALL(a),0ll);
		if(!(m<=n/2)||(m==0&&!good(n,sum))){
			cout<<"-1\n";
			continue;
		}
		fore(i,0,n){
			ll psum=sum-sa[i].fst;
			if(good(np,sum)&&(m||!good(np-1,psum))){
				s=i;
				break;
			}
			// mato i
			mop(i+1,i);
			np--; sum=psum;
		}
		// cerr<<np<<" "<<s<<"\n";
		assert(good(np,sum));
		// if(!good(np,sum)){
		// 	assert(m==0&&np==n);
		// 	cout<<"-1\n";
		// 	continue;
		// }
		if(m==0){
			fore(i,s,n-1){
				ll x=i,y=n-1;
				if(x==s)swap(x,y);
				mop(x,y);
			}
		}
		else{
			fore(i,s,n)if(i%2==s%2){
				ll x=i+1,y=i;
				if(x>=n)x=i,y=i-1;
				mop(x,y);
			}
		}
		// imp(att) imp(h) cout<<endl;
		stops();
		say();
		// cout<<endl;
	}
	return 0;
}
