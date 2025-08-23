#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll dis(ii a, ii b){
	return abs(a.fst-b.fst)+abs(a.snd-b.snd);
}
ll ask(ii a){
	cout<<"SCAN "<<a.fst+1<<" "<<a.snd+1<<endl;
	ll ret; cin>>ret;
	return ret;
}
ll mitad(ll a){
	assert(a%2==0);
	return a/2;
}
bool dig(ii a){
	cout<<"DIG "<<a.fst+1<<" "<<a.snd+1<<endl;
	ll ret; cin>>ret;
	return ret;
}

int main(){JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		
		vector<ii> e = {{0,0},{0,m-1},{n-1,0},{n-1,m-1}};
		
		ll q0=ask(e[0]);
		ll q1=ask(e[2]);
		
		ll sumx=mitad(q0+q1-2*(n-1));
		ll sumy=q0-sumx;
		
		ll q2=ask({sumy/2,0});
		ll q3=ask({0,sumx/2});
		
		ll difx=q3-sumy;
		ll dify=q2-sumx;
		
		ll x2=mitad(sumx+difx);
		ll x1=sumx-x2;
		
		ll y2=mitad(sumy+dify);
		ll y1=sumy-y2;
		
		// cout<<sumx<<" "<<sumy<<": "<<difx<<" "<<dify<<"\n";
		
		if(dig({y1,x1}))dig({y2,x2});
		else dig({y1,x2}),dig({y2,x1});
	}
	return 0;
}
