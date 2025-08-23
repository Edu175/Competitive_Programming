#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef unordered_map<ll,ll> table;
typedef unordered_set<ll> conju;
const ll MAXS=1e6+5,MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;

#define bint __int128
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(bint a, bint b){return a*b%MOD;}

// struct Hash{
	
// };

struct Trie{
	ll tr[MAXS][26],qidx=0,idx[MAXS];
	Trie(){mset(tr,-1);qidx=0;mset(idx,-1);}
	ll add(ll x, char c){
		auto &res=tr[x][c-'a'];
		if(res!=-1)return res;
		return res=++qidx;
	}
	void add_string(string s, ll id){
		ll x=0;
		for(auto i:s)x=add(x,i);
		idx[x]=id;
		// cerr<<"added "<<id<<" at "<<x<<"\n";
	}
};

ll pot[MAXS];

vector<table> get(vector<string> a, ll fg){
	Trie tr;
	ll n=SZ(a);
	// cerr<<"get "<<n<<"\n";
	fore(i,0,n)tr.add_string(a[i],i);
	vector<table> ans(n);
	fore(i,0,n){
		auto &s=a[i];
		ll x=0,m=SZ(s);
		auto ori=s;
		if(fg)reverse(ALL(ori));
		
		ll hsh=0;
		fore(j,0,m)hsh=add(hsh,mul(ori[j],pot[j]));
		auto &r=ans[i];
		
		// cerr<<"calc r "<<i<<": "<<m<<"\n";
		fore(i,1,m){
			
			if(!fg){
				hsh=sub(hsh,ori[i-1]);
				hsh=mul(hsh,PI);
			}
			else {
				ll p=m-i;
				hsh=sub(hsh,mul(ori[p],pot[p]));
			}
			x=tr.add(x,s[i-1]);
			ll id=tr.idx[x];
			if(id!=-1)r[hsh]=id;
			// cerr<<i<<": "<<x<<"\n";
		}
	}
	// cerr<<"\n\n";
	return ans;
}

int main(){
	JET
	pot[0]=1;
	fore(i,1,MAXS)pot[i]=mul(pot[i-1],P);
	ll n,m; cin>>n>>m;
	vector<string>a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i],reverse(ALL(b[i]));
	
	auto l=get(a,0);
	auto r=get(b,1);
	
	// for(auto v:l){
	// 	for(auto i:v)cout<<i<<" ";
	// 	cout<<"\n";
	// }
	// cout<<"\n";
	// for(auto v:r){
	// 	for(auto i:v)cout<<i<<" ";
	// 	cout<<"\n";
	// }
	// cout<<"\n";
	
	conju hayl,hayr;
	fore(i,0,n)for(auto [h,asd]:l[i])hayl.insert(h);
	fore(i,0,m)for(auto [h,asd]:r[i])hayr.insert(h);
	
	auto doit=[&](ll n, vector<table> &l, vv &good, conju &hay){
		fore(i,0,n){
			for(auto [h,idx]:l[i]){
				if(hay.count(h))good[i]=good[idx]=0;
			}
		}
	};
	
	vv goodl(n,1),goodr(m,1);
	doit(n,l,goodl,hayr);
	doit(m,r,goodr,hayl);
	
	// for(auto i:goodl)cout<<i;;cout<<"\n";
	// for(auto i:goodr)cout<<i;;cout<<"\n";
	
	cout<<count(ALL(goodl),1)<<" "<<count(ALL(goodr),1)<<"\n";
	return 0;
}