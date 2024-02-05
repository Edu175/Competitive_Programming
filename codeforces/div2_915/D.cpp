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

ll n;
ll dis(ll i, ll j){
	ll res=(j-i+n)%n;
	if(res==0)res=n;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll>a(n),p(n);
		fore(i,0,n)cin>>a[i],p[a[i]]=i;
		deque<ii>q;
		ll res=0;
		fore(i,0,n){
			ll x=a[i],c=1;
			while(SZ(q)&&x<q.back().fst)c+=q.back().snd,q.pop_back();
			q.pb({x,c});
		}
		deque<ii>q2=q;
		while(SZ(q2)){
			auto [x,c]=q2.front(); q2.pop_front();
			res+=(n-p[x])*c;
			cout<<x<<","<<c<<" ";
		}
		cout<<"\n";
		ll resi=res;
		cout<<"0: "<<resi<<"\n";
		fore(e,1,n){
			cout<<e<<": ";
			resi+=n-1;
			cout<<"+"<<n-1<<" ";
			auto &[x0,c0]=q.front();
			resi-=dis(p[x0],e-1);
			cout<<"-"<<dis(p[x0],e-1)<<" ";
			c0--;
			if(c0==0)q.pop_front();
			ll x=a[e-1],c=1;
			while(SZ(q)&&x<q.back().fst){
				auto [x1,c1]=q.back();
				c+=c1;
				resi-=dis(p[x1],e)*c1;
				cout<<"-"<<dis(p[x1],e)*c1<<" ";
				q.pop_back();
			}
			resi+=c*dis(p[x],e);
			cout<<"+"<<c*dis(p[x],e)<<" ";
			q.pb({x,c});
			res=max(res,resi);
			cout<<resi<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
