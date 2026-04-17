#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int K = 20;
const int MAXN = 1<<K;
ll l[MAXN],r[MAXN], D[MAXN], F[MAXN][K];


void bad_o(){
	cout<<"Bad oriented forest"<<endl;
	exit(0);
}

void bad_s(int x){
	cout<<"Bad segment at "<<x<<endl;
	exit(0);
}

ll uf[MAXN];
void uf_init(){
	mset(uf,-1);
	fore(i,0,MAXN)l[i] = i, r[i] = i;
	mset(F,-1);
}

ll uf_find(int x){
	if(uf[x] < 0) return x;
	ll y=uf[x];
	uf[x]=uf_find(uf[x]);
	D[x] += D[y];
	return uf[x];
}


ll padre(int x, int k){
	if(x == -1) return -1;
	if(F[x][k] != -1) return F[x][k];
	if(!k) return -1;
	ll p = padre(padre(x,k-1),k-1);
	F[x][k] = p;
	return F[x][k];
}

void hijo(int x, int y){
	assert(uf_find(x) == uf_find(y));
	if(D[x] > D[y]) bad_s(x);
	ll k = K;
	while(D[y] > D[x]){
		while(D[x] + (1<<k) > D[y]) k--;
		y = padre(y,k);
		if(y == -1) bad_s(x);
		uf_find(y);
	}
	if(x!=y) bad_s(x);
}

void uf_join(int a, int b){
	int x = uf_find(a), y = uf_find(b);
	if(x == y || b!=y) bad_o();

	if(r[x] == l[b] - 1) hijo(a,r[x]), r[x] = r[b];
	else if(l[x] == r[b] + 1) hijo(a,l[x]), l[x] = l[b];
	else bad_s(x);
	uf[b] = x;
	D[b] = D[a] + 1;
	F[b][0] = a;
}

int main(){
	uf_init();
	ll n; cin>>n;
	fore(i,1,n){
		ll x, y;  cin>>x>>y;
		uf_join(x,y);
		cout<<"Good"<<endl;
	}	
	return 0;
}