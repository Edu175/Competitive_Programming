#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// veo que sea conexo para toda linea, plano y espacio.
// conexo en el sentido de moverse en alguna direccion
// demostrado que eso es equivalente al problema original

vector<vv> dirs[4];
vv operator+(vv a, vv b){
	assert(SZ(a)==SZ(b));
	fore(i,0,SZ(a))a[i]+=b[i];
	return a;
}

template <typename T, typename = void>
struct is_container : std::false_type {};
template <typename T>
struct is_container<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};
template <typename T>
string cv(const T& x) {
    if constexpr (is_container<T>::value) {
        // std::cout << "This is a container.\n";
		string ret="{ ";
		for(auto i:x)ret+=cv(i)+" ";
		ret+="}";
		return ret;
    }
	else {
		// std::cout << "This is NOT a container.\n";
		return to_string(x);
	}
}

bool check(vector<vv> &a, ll d){
	auto &dir=dirs[d];
	cout<<"check "<<cv(a)<<" "<<d<<":\n";
	set<vv>st;
	for(auto i:a)st.insert(i);
	set<vv>vis;
	auto dfs=[&](vv x, auto &&dfs)->void{
		cout<<"dfs "<<cv(x)<<"\n";
		vis.insert(x);
		for(auto d:dir){
			auto y=x+d;
			if(st.count(y)&&!vis.count(y))dfs(y,dfs);
		}
	};
	dfs(*a.begin(),dfs);
	for(auto x:a)if(!vis.count(x))return 0;
	cout<<"good\n\n";
	return 1;
}

int main(){
	JET
	fore(d,1,4){
		auto &dir=dirs[d];
		fore(fg,0,2)fore(w,0,d){
			vv now(d); now[w]=fg?1:-1;
			dir.pb(now);
		}
	}
	ll n; cin>>n;
	vector<vv>a(n,vv(3));
	fore(h,0,3){
		fore(i,0,n)cin>>a[i][h];
	}
	ll flag=1;
	fore(d,1,4){
		vv is(3); fore(i,3-d,3)is[i]=1;
		do{
			cout<<"\n\n\nis: "<<cv(is)<<"\n";
			map<vv,vector<vv>>mp;
			fore(i,0,n){
				vv k,v;
				fore(j,0,3)(is[j]?v:k).pb(a[i][j]);
				mp[k].pb(v);
			}
			for(auto [k,b]:mp)flag&=check(b,d);
		}while(next_permutation(ALL(is)));
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}