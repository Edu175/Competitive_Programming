#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll INF=1e15;
ll A,B,C,a,b,c,a1,b1,c1; 


ll checka(ll x){
	if(a==x) return 0;
	if(A<x) return INF;
	if(a<x){
		if(b>=x-a) return 1;
		if(c>=x-a) return 1;
		if(b+c>=x-a) return 2;
		return INF;
	}
	if(b1>=a-x) return 1;
	if(c1>=a-x) return 1;
	if(b1+c1>=a-x) return 2;
	return INF;	
}

ll checkb(ll x){
	if(b==x) return 0;
	if(B<x) return INF;
	if(b<x){
		if(a>=x-b) return 1;
		if(c>=x-b) return 1;
		if(a+c>=x-b) return 2;
		return INF;
	}
	if(a1>=b-x) return 1;
	if(c1>=b-x) return 1;
	if(a1+c1>=b-x) return 2;
	return INF;	
}

ll checkc(ll x){
	if(c==x) return 0;
	if(c<x){
		if(b>=x-c) return 1;
		if(a>=x-c) return 1;
		if(b+a>=x-c) return 2;
		return INF;
	}
	if(b1>=c-x) return 1;
	if(a1>=c-x) return 1;
	if(b1+a1>=c-x) return 2;
	return INF;	
}


int main(){
	JET
	cin>>A>>B>>C>>a>>b>>c;
	a1=A-a,b1=B-b,c1=C-c;
	fore(i,0,C+1){
		ll rta=INF;
		if(i==8) cout<<"\n"<<rta;
		rta = min(rta,checka(i));
		if(i==8) cout<<"\n"<<rta;
		rta = min(rta,checkb(i));
		if(i==8) cout<<"\n"<<rta;
		rta = min(rta,checkc(i));
		if(i==8) cout<<"\n"<<rta;
		
		if(rta>1e8){
			cout<<-1<<" ";
			continue;
		}
		cout<<rta<<" ";
	}
	cout<<"\n";
	return 0;
}