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

vector<ll> f(vector<ll>a){
	ll n=SZ(a),p=0;
	vector<ll>vis(n,0);
	vector<ll>b(n);
	vis[0]=1;
	//imp(a);
	fore(i,1,n){
		//cout<<"i "<<i<<":\n";
		//imp(vis);
		//cout<<p<<endl;
		if(a[i]>a[i-1])b[i]=a[i],vis[b[i]]=1;
		else {
			while(vis[p])p++;
			b[i]=p;
			vis[p]=1;
		}
	}
	return b;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll>a(n);
		fore(i,0,n)k-=a[i]=i;
		if(k<0){
			cout<<"-1\n";
			continue;
		}
		for(ll i=n-1;i>0;i--){
			ll s=n-1-i;
			if(k<=s){
				a[i]+=k;
				k=0;
				break;
			}
			else {
				k-=s;
				a[i]=n-1;
			}
		}
		if(k){
			cout<<"-1\n";
			continue;
		}
		vector<ll>res=f(a);
		for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
