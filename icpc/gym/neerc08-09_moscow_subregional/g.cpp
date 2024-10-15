#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ii operator+(ii &a, ii &b){
	return ii({a.fst+b.fst, a.snd+b.snd});
}
int main(){
	JET
	ll n; cin>>n;
	ii p[n];
	fore(i,0,n) cin>>p[i].fst>>p[i].snd;
	if(n<=3) {cout<<"0\n"; return 0;}
	priority_queue <ii> pq;
	fore(i,0,n){
		fore(j,0,i) pq.push(p[i]+p[j]);
	}
	ii A=pq.top(); pq.pop();
	while(SZ(pq)){
		if(A==pq.top()) {cout<<"1\n"; return 0;}
		A=pq.top();
		pq.pop();
	}
	cout<<"2\n";
	return 0;
}
