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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(2*n),b(2*n);
		ll suma=0;
		fore(i,0,n)cin>>a[i],a[i+n]=a[i],suma+=a[i];
		fore(i,0,n)cin>>b[i],b[i+n]=b[i];
		vv to(n); iota(ALL(to),0);
		set<ll>st,ast;
		fore(i,0,2*n)st.insert(i),ast.insert(i);
		priority_queue<ii>pq;
		auto put=[&](ll i){pq.push({-(to[i]-i),i});};
		auto actu=[&](ll i){
			if(!b[to[i]])to[i]=*st.lower_bound(i);
		};
		if(suma<=k){
			cout<<"0\n";
			continue;
		}
		ll res=0;
		fore(i,0,n){
			ll c=min(a[i],b[i]);
			a[i]-=c,b[i]-=c; suma-=c;
			a[i+n]=a[i]; b[i+n]=b[i];
			if(!b[i])st.erase(i),st.erase(n+i);
			if(!a[i])ast.erase(i),ast.erase(n+i);
		}
		fore(i,0,n)if(a[i]){
			actu(i);
			put(i);
		}
		while(SZ(pq)&&SZ(ast)&&suma>k){
			auto [d,i]=pq.top(); pq.pop(); d=-d;
			
			// imp(a)
			// imp(b)
			// cout<<d<<" "<<i<<": "<<to[i]<<endl;
			if(!(to[i]-i==d&&a[i]&&b[to[i]])||*prev(ast.upper_bound(to[i]))!=i)continue;
			// if(to[i]-i!=d||!a[i])continue;
			// if(!b[to[i]]){
			// 	actu(i);
			// 	put(i);
			// 	continue;
			// }
			res=max(res,d);
			ll j=to[i]; ll j_=j+(j<n?n:-n);
			ll c=min(a[i],b[j]);
			a[i]-=c,b[j]-=c; suma-=c;
			a[i+n]=a[i]; b[j_]=b[j];
			if(!b[j])st.erase(j),st.erase(j_);
			if(!a[i])ast.erase(i),ast.erase(n+i);
			auto it=ast.upper_bound(n+i);
			if(it==ast.begin())break;
			ll p=*prev(it)%n;
			actu(p);
			put(p);
		}
		cout<<res+1<<"\n";
	}
	return 0;
}
