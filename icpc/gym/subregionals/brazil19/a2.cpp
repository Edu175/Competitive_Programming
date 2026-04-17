#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
const int MAXN=1e3+10;
int uf[MAXN];
ll rpnoahorat (ll a){
	ll rta=sqrt(a);
	rta-=2;
	while(rta*rta<a){
		rta++;
	}
	return rta;
}
ll dist(ii a, ii b){
	ll x=a.fst-b.fst;
	ll y=a.snd-b.snd;
	return rpnoahorat(y*y+x*x);
}
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x); y=uf_find(y);
	if(x==y) return false;
	if(uf[x]>uf[y]) swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
	return true;
}
int main(){
	int N,M,K;
	cin>>M>>N>>K;
	pair <ll,ii> P[K];
	uf_init();
	fore(i,0,K){
		cin>>P[i].snd.fst>>P[i].snd.snd>>P[i].fst;
		if(P[i].snd.fst<=P[i].fst)uf_join(1,4+i);
		if(M-P[i].snd.fst<=P[i].fst)uf_join(3,4+i);
		if(P[i].snd.snd<=P[i].fst)uf_join(0,4+i);
		if(N-P[i].snd.snd<=P[i].fst)uf_join(2,4+i);
		//cout<<uf_find(0)<<" "<<uf_find(1)<<" "<<uf_find(3)<<" "<<uf_find(2)<<"\n";
	}
	fore(i,0,K){
		fore(j,i+1,K){
			if(dist(P[i].snd,P[j].snd)<=P[i].fst+P[j].fst) uf_join(4+i,4+j);
			//cout<<uf_find(0)<<" "<<uf_find(1)<<" "<<uf_find(3)<<" "<<uf_find(2)<<"\n";
		}
	}
	if(uf_find(0)==uf_find(1) || uf_find(1)==uf_find(3) || uf_find(2)==uf_find(3) || uf_find(0)==uf_find(2)  ){
		cout<<"N"<<"\n";
	}
	else cout<<"S"<<"\n";
}
