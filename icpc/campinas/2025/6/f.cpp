#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int MAXN=2e5+8;
ii uf[MAXN];
ll cant[MAXN];
int g[MAXN];
int neg=0;
priority_queue<ii> pq;
void uf_init(){
	fore(i,0,MAXN) uf[i]={-1,0};
}
ii uf_find(int x){
	if(uf[x].fst<0) return (ii){x,0};
	ii a=uf_find(uf[x].fst);
	uf[x].fst=a.fst;uf[x].snd+=a.snd;
	return uf[x];
}

bool uf_join(int x, int y){
	// cout<<"connecting "<<x<<" with "<<y<<endl;
	ii a=uf_find(x),b = uf_find(y);//aca va el ciclo
	// cout<<"connecting "<<x<<" with "<<y<<" 2 "<<endl;
	assert(a.fst==x);
	if(a.fst == b.fst){
		return false;
	}
	cant[b.fst]+=cant[x];
	ll aux=cant[x];
	cant[x]=0;
	uf[x].fst=b.fst;
	uf[x].snd+=uf[y].snd+1;
	if(cant[b.fst]<0) return true;
	if(cant[b.fst]>=0 && cant[b.fst]-aux<0){
		neg--;
		pq.push({cant[b.fst],-b.fst});
		return true;
	}
	return uf_join(b.fst,g[b.fst]);
}

int main(){
	JET
	int n; cin>>n;
	uf_init();
	fore(i,0,n){
		cin>>cant[i];
		if(cant[i]<0) neg++;
		pq.push({cant[i],-i});
	}
	fore(i,0,n){
		cin>>g[i];
	}
	ll rta=0;
	while(neg){
		auto [c,x]=pq.top();
		pq.pop();
		x=-x;
		// cout<<"fuck "<<c<<" "<<x<<endl;
		if(cant[x]==0) continue;
		if(cant[x]<0){
			cout<<-1<<"\n";
			return 0;
		}
		if(uf_join(x,g[x])){
			rta+=uf_find(x).snd;
			// cout<<"go from "<<x<<" to "<<uf_find(x).fst<<endl;
		}
		else{
			cout<<-1<<"\n";
			return 0;
		}
	}
	cout<<rta<<"\n";
	return 0;
}

// 4
// -3 0 2 1
// 3 0 1 2
// fuck 2 2
// connecting 2 with 1 1 
// connecting 1 with 0 1 
// go from 2 to 2
// fuck 1 3
// connecting 3 with 2 1 
// go from 3 to 3
// 0
