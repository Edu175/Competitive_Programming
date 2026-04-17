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

#define maxig(a,b) a=max(a,b)
ll mem[50][50];
ll nCr(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	auto &res=mem[n][k];
	if(res!=-1)return res;
	if(n==0)return res=1;
	return res=nCr(n-1,k-1)+nCr(n-1,k);
}

ll cam(ll i, ll j){
	return nCr(i+j,i);
}

int main(){FIN;
	mset(mem,-1);
	assert(nCr(5,2)==10);
	ll n; cin>>n;
	vector<vv> a(n,vv(n));
	
	fore(i,1,n)for(ll j=n-2;j>=0;j--){
		a[i][j]=cam(i-1,j)+a[i-1][j+1];
	}
	
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
		ll mx=*st.rbegin();
		cerr<<"mx "<<mx<<"\n";
		assert(mx==cam(n-1,n-1)-1);
		// cerr<<SZ(st)<<" "<<cnt<<"\n";
		assert(cnt==SZ(st));
	};
	fore(i,0,n){
		imp(a[i])
	}
	// check();
	return 0;
}
