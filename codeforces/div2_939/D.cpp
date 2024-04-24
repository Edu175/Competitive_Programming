#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=20;
ll a[MAXN];
ll n;
ll cost(ll mk){
	ll s=0,l=-1;
	fore(i,0,n){
		if(!((mk>>i)&1)){
			s+=(i-l-1)*(i-l-1);
			l=i;
			s+=a[i];
		}
	}
	s+=(n-l-1)*(n-l-1);
	//cout<<"cost "<<mk<<": "<<s<<"\n";
	return s;
}
vector<ii>res;
void doit(ll l, ll r){
	res.pb({l,r});
	vector<ll>v(r-l+5);
	fore(i,l,r)if(a[i]<SZ(v))v[a[i]]=1;
	ll mex=0;
	fore(i,0,SZ(v))if(!v[i]){mex=i;break;}
	fore(i,l,r)a[i]=mex;
}
void make(ll l, ll r){
	//cout<<"make "<<l<<","<<r<<"\n";
	if(r-l<=0)return;
	ll flag=1;
	fore(i,l,r)if(a[i]!=i-l)flag=0;
	/*if(flag){
		cout<<"flag ";
		fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
	}*/
	if(flag)return;
	make(l,r-1);
	flag=1;
	fore(i,l,r)if(a[i]!=i-l)flag=0;
	if(flag)return;
	doit(l,r);
	flag=1;
	fore(i,l,r)if(a[i]!=i-l)flag=0;
	if(flag)return;
	make(l,r-1);
	flag=1;
	fore(i,l,r)if(a[i]!=i-l)flag=0;
	if(flag)return;
}

/*void see(){
	cout<<"\n";
	vector<ll>b(n);
	fore(i,0,n)b[i]=a[i];
	for(auto [l,r]:res){
		vector<ll>v(r-l+5);
		fore(i,l,r)if(b[i]<SZ(v))v[b[i]]=1;
		ll mex=0;
		fore(i,0,SZ(v))if(!v[i]){mex=i;break;}
		fore(i,l,r)b[i]=mex;
		imp(b);
	}
	
}*/

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	ll mk=0;
	fore(m,0,1ll<<n){
		if(cost(m)>cost(mk))mk=m;
	}
	ll l=-1,s=cost(mk);//,z=0;
	/*fore(i,0,n){
		if(((mk>>i)&1)&&a[i])res.pb({i,i+1});
	}*/
	fore(i,0,n+1){
		if(!((mk>>i)&1)){
			if(l+1!=i){
				//if(z)res.pb({l+1,i});
				make(l+1,i);
				doit(l+1,i);
			}
			l=i;
			//z=0;
		}
		//else z|=a[i]==0;
	}
	assert(SZ(res)<=5e5);
	cout<<s<<" "<<SZ(res)<<"\n";
	for(auto [l,r]:res)cout<<l+1<<" "<<r<<"\n";
	//fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
	return 0;
}
