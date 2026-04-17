#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asdf:v)cout<<asdf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

struct STree{
	vector<ll>t; ll n;
	STree(ll m): t(2*(m+5)+5),n(m+5){}
	void upd(ll p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
	void upd(ll l, ll r, ll v){
		upd(l,v);upd(r,-v);
	}
	ll query(ll p){
		return query(0,p+1);
	}
};

void transf(vector<ll>&a){
	ll n=SZ(a);
	ll mn=0;
	fore(i,0,n)if(a[i]<=a[mn])mn=i;
	vector<ll>b(n);
	fore(i,0,n)b[(i+n-1-mn+4*n)%n]=a[i];
	a=b;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	transf(a);
	//imp(a);
	vector<ll>r(n,n);
	for(ll i=n-1;i>=0;i--)for(r[i]=i+1;r[i]!=n&&a[r[i]]>=a[i];r[i]=r[r[i]]);
	vector<ll>l(n,-1);
	fore(i,0,n)for(l[i]=i-1;l[i]!=-1&&a[l[i]]>a[i];l[i]=l[l[i]]);
	//imp(r);
	STree st(n);
	fore(i,0,n){
		//cout<<i<<" "<<l[i]<<","<<r[i]<<":\n";
		if(r[i]<n)st.upd(r[i]-i,r[i]-l[i],a[i]-a[r[i]]);
		//,cout<<i<<"x "<<r[i]<<"rx "<<"["<<r[i]-i<<","<<r[i]-l[i]<<")+="<<a[i]-a[r[i]]<<"\n";
	}
	ll sum=0;
	fore(i,0,n)sum+=a[i];
	fore(i,1,n+1){
		sum-=st.query(i);
		cout<<sum<<"\n";
	}
	return 0;
}
