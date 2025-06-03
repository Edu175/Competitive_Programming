#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<endl;}
#define tle(v) while(!(v))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll B=60;
typedef __int128 vec;
struct matrix{
	vector<vec>x;
	matrix(): x(B){}
	vec add(vec v, ll idx){
		v=(v<<B)|(1ll<<idx);
		if(v==0)return 0;
		for(ll j=B-1;j>=0;j--)v=min(v,v^x[j]);
		if(v>>B){ll p=__lg(ll(v>>B));x[p]=v;return -1;}
		return v;
	}
};
vv getways(vv a, ll k, ll dep=0){
	// cerr<<"getways "<<dep<<": "<<k<<", "; imp(a)
	// if(!k)return {0};
	if(dep==3)return {};
	ll n=SZ(a);
	matrix mt;
	ll p=-1;
	fore(i,0,n){
		// if(!a[i])
		if(a[i]!=-1)if(mt.add(a[i],i)!=-1)p=i;
	}
	auto v=mt.add(k,0);
	if(v==-1){
		// cout<<"not doable\n";
		return {};
	}
	v^=1; // bc of idx 0
	ll mk=v&((1ll<<B)-1);
	fore(i,0,n)mk|=ll(a[i]==-1)<<i;
	if(p==-1)return {mk};
	ll val=a[p]; a[p]=-1;
	auto ans=getways(a,k^val,dep+1);
	ans.pb(mk);
	return ans;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		if(!k){
			// cout<<"no k"<<endl;
			cout<<"Yes\n";
			cout<<"2\n1 1\n";
			continue;
		}
		vector<ll>res;
		vv to;
		auto ways=getways(a,k);
		// cerr<<"ways "; imp(ways)
		for(auto mk:ways){
			vv is(n);
			fore(i,0,n)is[i]=mk>>i&1;
			ll good=0;
			fore(i,0,n-1)good|=is[i]==is[i+1];
			if(good)to=is;
		}
		if(!SZ(to)){
			cout<<"No\n";
			continue;
		}
		// imp(a)
		// imp(to)
		ll k_=0;
		fore(i,0,n)if(to[i])k_^=a[i];
		assert(k_==k); // salta aca !!
		auto op=[&](ll i, ll w=-1){
			// cerr<<"\n";
			// imp(a)
			// imp(to)
			// cerr<<"op "<<i<<" "<<w<<" "<<"\n";
			assert(i<n-1);
			assert(i>=0);
			res.pb(i);
			ll j=i+1;
			if(to[i]&&to[j]){
				assert(w!=-1);
				to[i]=to[j]=0;
				to[(w?j:i)]=1;
			}
			else {
				if(to[i]||to[j]){
					ll p=i;
					if(!to[p])p=j;
					assert(a[i^j^p]==0);
					swap(to[i],to[j]);
				}
			}
			ll x=a[i]^a[j];
			a[i]=a[j]=x;
		};
		auto mata=[&](ll i){
			// cerr<<"mata "<<i<<"\n";
			op(i);
			op(i);
		};
		auto chain=[&](ll i, ll j, ll d){
			for(ll p=i,did=0;!did;p+=d){
				did|=p==j;
				op(p,d==1);
			}
		};
		auto acum=[&](ll i, ll j){// accumulates in j xor[j..i]
			if(i==j)return;
			if(i<j)chain(i,j-1,1);
			else chain(i-1,j,-1);
		};
		ll p=-1,q=-1;
		fore(i,0,n-1){
			if(!to[i]&&!to[i+1])p=i;
			if(i+2<n){
				if(to[i+1]&&(to[i]||to[i+2]))q=i;
			}
		}
		if(p==-1){
			assert(q!=-1);
			if(to[q]&&to[q+2])acum(q+2,q),p=q+1;
			else if(to[q])op(q,0),p=q+1;
			else op(q+1,1),p=q;
		}
		// to[p,p+1] = [0,0]
		// cerr<<p<<" p\n";
		tle(p<n-1&&!to[p]&&!to[p+1]);
		mata(p);
		while(p<n-2){
			acum(p+2,p);
			mata(p+1);
			p++;
		}
		while(p>1){
			// cerr<<"round "<<p<<" p\n";
			while(p>=1&&!to[p-1])mata(--p);
			assert(p>=1);
			// cerr<<"new "<<p<<" p\n";
			acum(p-1,p+1);
			mata(--p);
			// cerr<<"moved 1\n";
			// cerr<<"start killing from "<<p<<"\n";
			ll q=p;
			while(q>=1&&!to[q-1])mata(--q);
			// cerr<<"finished killing at "<<q<<"\n";
			ll dst=max(q-1,0ll);
			acum(p+2,dst); // max: caso dst = 0
			p=dst+1;
			mata(p);
		}
		cout<<"Yes\n";
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
		tle(a[0]==k); // es este
	}
	return 0;
}
