#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

random_device rd;
mt19937 rng(rd());

const int B=150; // tiro para menos de sqrt

const ull R1=0x96bb4f9ac3cfb5e4,R2=0xcd2f2e2dbd209ce7,R3=0x9cc5399b1da8476;

ull falopa(ull x, ll y=0, ll fg=0){
	if(!fg)x+=R1;
	else x+=falopa(y);
	x=(x^(x>>30))*R2;
	x=(x^(x>>27))*R3;
	return x^(x>>31);
}

int main(){
	ET;
	int n,k; cin>>n>>k;
	vector<int> a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	if(k<B){ // pesado
		vector<int> sp(n+1),ant(n+1);
		vector<ull> hs(n+1);
		vv per(k); iota(ALL(per),0); shuffle(ALL(per),rng);
		ll did=0;
		for(auto v:per){
			fore(i,1,n+1)sp[i]=sp[i-1]+(a[i-1]==v);
			if(did){
				fore(i,0,n+1){
					hs[i]=falopa(hs[i],v,1)+(sp[i]-ant[i]);
					// hs[i]=(hs[i]*P+(sp[i]-ant[i])+MOD)%MOD; // !!
				}
			}
			did=1;
			swap(ant,sp);
		}
		map<ull,int>mp;
		int res=0;
		fore(i,0,n+1){
			auto h=hs[i];
			if(mp.count(h))res=max(res,i-mp[h]);
			else mp[h]=i;
		}
		assert(res%k==0);
		// res/=k;
		cout<<res<<"\n";
	}
	else {
		vector<ull> sp(n+1);
		ull h=0;
		fore(i,1,n+1)h+=falopa(a[i-1]),sp[i]=h;
		ull id=0;
		fore(i,0,k)id+=falopa(i);
		int res=0;
		fore(l,0,n){
			ull h=sp[l];
			for(int r=l,m=0;r<=n;r+=k,m++,h+=id){
				if(sp[r]==h)res=max(res,m);
			}
		}
		cout<<res*k<<"\n";
	}
}