#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) do{for(auto i:v)cout<<i<<" "; cout<<"\n";}while(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

void impm(vector<vv> a){ // only for debugging
	ll n=SZ(a); assert(SZ(a[0])==n);
	vv mx(n);
	fore(i,0,n)fore(j,0,n)mx[j]=max(mx[j],(ll)SZ(to_string(a[i][j])));
	fore(i,0,n){
		fore(j,0,n){
			ll x=a[i][j];
			auto s=to_string(x);
			s=string(2+mx[j]-SZ(s),' ')+s;
			cout<<s;
		}
		cout<<"\n";
	}
}

int main(){FIN;
	ll n; cin>>n;
	vector<vv> a(n,vv(n));
	
	ll d=2*n-1;
	vector<vector<ii>> pos(d);
	fore(i,0,n)fore(j,0,n)pos[i+j].pb({i,j});
	
	auto gets=[&](ll j){
		ll s=0;
		fore(i,0,n)s+=a[i][j];
		return s;
	};
	
	fore(k,1,d-1){
		ll num=0;
		fore(j,0,n)num=max(num,gets(j));
		num++;
		for(auto [i,j]:pos[k])if(j%2==0){
			a[i][j]=num;
		}
		if(k==2)a[1][0]=0;
	}
	a[1][0]=1;
	auto check=[&](){
		set<ll> st;
		ll cnt=0;
		auto f=[&](ll i, ll j, ll s, auto &&f){
			s+=a[i][j];
			if(i==n-1&&j==n-1){
				cnt++;
				st.insert(s);
				return;
			}
			if(i+1<n)f(i+1,j,s,f);
			if(j+1<n)f(i,j+1,s,f);
		};
		f(0,0,0,f);
		cout<<endl;
		cerr<<"mx "<<*st.rbegin()<<"\n";
		cerr<<SZ(st)<<" "<<cnt<<"\n";
		assert(cnt==SZ(st));
	};
	// a[n-1][n-3]=2;
	// a[n-3][n-1]=2;
	// a[n-2][n-1]=1;
	impm(a);
	check();
	// fore(i,0,n)imp(a[i])
	return 0;
}
