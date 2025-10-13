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

ll ask(vv a){
	cout<<"? "<<SZ(a)<<" ";
	for(auto i:a)cout<<i+1<<" ";
	cout<<endl;;
	ll ret; cin>>ret; ret--;
	return ret;
}

int main(){
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv per,dup;
		vv a(2*n,-1);
		fore(i,0,2*n){
			per.pb(i);
			auto rq=ask(per);
			if(rq!=-1){
				a[i]=rq;
				dup.pb(i);
				per.pop_back();
			}
		}
		fore(i,0,2*n)if(a[i]==-1){
			vv cur=dup; cur.pb(i);
			auto rq=ask(cur);
			assert(rq!=-1);
			a[i]=rq;
		}
		cout<<"! ";
		for(auto i:a)cout<<i+1<<" ";;cout<<endl;
	}
	return 0;
}
