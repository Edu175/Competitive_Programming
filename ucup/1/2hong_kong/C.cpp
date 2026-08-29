#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

vector<vv> gen(ll n, ll k, ll q){
	assert(k<=n);
	vv per(n); fore(i,n-k,n)per[i]=1;
	assert(q>0);
	vector<vv> ret;
	do{
		ret.pb(per);
		if(SZ(ret)>=q)return ret;
	}while(next_permutation(ALL(per)));
	return ret;
}

vector<vv> get(ll n, ll m){
	assert(n>=m);
	if((n*m)&1)return {};
	if(m<20&&n>(1ll<<m))return {};
	ll w=0;
	auto geth=[&](ll z){
		if(z%2==0)return z/2;
		ll ret=(z+!w)/2;
		w^=1;
		return ret;
	};
	assert(n>1);
	vector<vv> ind={{}};
	fore(i,0,n)ind[0].pb(i);
	vector<vv> a(n,vv(m));
	ll s=m;
	fore(j,0,m){
		ll hay=0;
		for(auto &v:ind)hay|=SZ(v)>1;
		if(!hay){s=j;break;}
		vector<vv> prox;
		for(auto v:ind){
			ll h=geth(SZ(v));
			vector<vv> el(2);
			fore(id,0,SZ(v)){
				ll ty=id>=h;
				ll i=v[id];
				a[i][j]=ty;
				el[ty].pb(i);
			}
			fore(ty,0,2){
				auto u=el[ty];
				if(SZ(u))prox.pb(u);
			}
		}
		ind=prox;
	}
	// cerr<<"ended:\n";
	// fore(i,0,n)show(a[i])
	// cerr<<"s: "<<s<<"\n";
	if(s==m)return a;
	vector<vector<vv>> mks={gen(n,n/2,m),gen(n,(n+1)/2,m)};
	ll od=n&1;
	if(!od)mks.pop_back();
	vector<vv> cols;
	fore(j,0,s){
		vv col;
		fore(i,0,n)col.pb(a[i][j]);
		cols.pb(col);
	}
	set<vv> st(ALL(cols));
	auto dame=[&](ll ty){
		while(1){
			assert(SZ(mks[ty]));
			auto v=mks[ty].back(); mks[ty].pop_back();
			if(!st.count(v))return v;
		}
	};
	fore(j,s,m){
		vv col;
		if(!od)col=dame(0);
		else {
			col=dame(w);
			w^=1;
		}
		assert(SZ(col)==n);
		fore(i,0,n)a[i][j]=col[i];
	}
	return a;
}

vector<vv> trans(vector<vv> a){
	ll n=SZ(a),m=SZ(a[0]);
	vector<vv> b(m,vv(n));
	fore(i,0,n)fore(j,0,m)b[j][i]=a[i][j];
	return b;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll sw=0;
		if(n<m)swap(n,m),sw=1;
		auto a=get(n,m);
		if(!SZ(a)){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		if(sw)a=trans(a),swap(n,m);
		fore(i,0,n){
			fore(j,0,m)cout<<a[i][j];
			cout<<"\n";
		}
	}
	return 0;
}


