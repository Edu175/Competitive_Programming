#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5,INF=1e14;

ll n,k;
ii A[MAXN];

bool can(ll x){
	// cout<<"\n\ncan "<<x<<"\n";
	// vector<ll>h[k];
	vector<ii>a;
	fore(i,0,n)a.pb(A[i]);
	priority_queue<ii>pq;
	auto get=[&](ll i)->ll{
		return a[i].snd/a[i].fst+1;
	};
	fore(i,0,n)pq.push({-get(i),i});
	fore(t,1,k){
		// fore(i,0,n)cout<<a[i].fst<<","<<a[i].snd<<" ";;cout<<"\n";
		auto [pos,i]=pq.top(); pq.pop();
		a[i].snd+=x;
		pos=-pos;
		// cout<<t<<": le agrego a "<<i<<" con pos "<<pos<<"\n";
		if(pos<t)return 0;
		pq.push({-get(i),i});
	}
	// cout<<-pq.top().fst<<","<<pq.top().snd<<"\n";
	return 1;//-pq.top().fst>=k;
}


int main(){JET
	cin>>n>>k; k++;
	fore(i,0,n)cin>>A[i].snd;
	fore(i,0,n)cin>>A[i].fst;
	// ll flag=1;
	// fore(i,0,n){
	// 	flag&=A[i].snd-A[i].fst*k>=0;
	// }
	// if(flag)cout<<"0\n";
	// else {
		ll l=0,r=INF;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))r=m-1;
			else l=m+1;
		}
		if(l>=INF)cout<<"-1\n";
		else cout<<l<<"\n";
	// }
}


/*
can 5
4,3 2,2 
1: le agrego a 0 con pos 1
4,8 2,2 
2: le agrego a 1 con pos 2
4,8 2,7 
3: le agrego a 0 con pos 3
4,13 2,7 
4: le agrego a 1 con pos 4
4,0






*/