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

vector<ll> pos(vector<ll>a){
	ll n=SZ(a);
	vector<ll>p(n);
	fore(i,0,n)p[a[i]]=i;
	return p;
}
vector<ll> op(vector<ll>a, ll k){
	ll n=SZ(a);
	vector<ll>l,r;
	fore(i,0,k)l.pb(a[i]);
	fore(i,k+1,n)r.pb(a[i]);
	vector<ll>ret=r;
	ret.pb(a[k]);
	//cout<<"op "<<k<<", "; imp(a); imp(l); imp(r); cout<<endl<<endl;
	for(auto i:l)ret.pb(i);
	return ret;
}
/*ll good(vector<ll>a){
	ll n=SZ(a);
	fore(i,0,n)if((a[i]+1)%n!=a[(i+1)%n])return 0;
	return 1;
}*/
vector<ll> solve(vector<ll>a){
	ll n=SZ(a);
	vector<ll>ret;
	fore(i,0,n){
		if(a[0]==i)a=op(a,0),ret.pb(0);
		else{
			ll k=pos(a)[i];
			a=op(a,k),ret.pb(k);
			k=pos(a)[i]; k=(k+1)%n;
			a=op(a,k),ret.pb(k);
		}
	}
	//while(a[0]!=0)cout<<"direc"<<endl,a=op(a,0),ret.pb(0);
	return ret;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>a(n),b(m);
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,m)cin>>b[i],b[i]--;
	vector<ll>p=solve(a),q=solve(b);
	if(abs(SZ(p)-SZ(q))&1){
		if(n&1){
			fore(i,0,n)p.pb(0);
		}
		else if(m&1){
			fore(i,0,m)q.pb(0);
		}
		else{
			cout<<"-1\n";
			return 0;
		}
	}
	if(SZ(p)<SZ(q)){
		while(SZ(p)<SZ(q))p.pb(0),p.pb(n-1);
	}
	else {
		while(SZ(p)>SZ(q))q.pb(0),q.pb(m-1);
	}
	cout<<SZ(p)<<"\n";
	fore(i,0,SZ(p)){
		cout<<p[i]+1<<" "<<q[i]+1<<"\n";
	}
	return 0;
}
