#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(a) for(auto messi:a)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
// odd -> gr= (n-1)/2
/*ll n;

void cnt(vector<vector<ll>>a){
	vector<ll>p;
	fore(i,0,n)p.pb(i);
	vector<ll>res;
	do{
		ll b[n][n]; mset(b,0);
		fore(i,0,n)fore(j,0,n)if(i!=j){
			b[p[i]][p[j]]=!a[i][j];
		}
		ll flag=1;
		fore(i,0,n)fore(j,0,n)if(a[i][j]!=b[i][j])flag=0;
		if(flag)res=p;
	}
	while(next_permutation(ALL(p)));
	if(SZ(res)){
		fore(i,0,n){
			fore(j,0,n)cout<<a[i][j];
			cout<<"\n";
		}
		imp(res);
		cout<<"\n";
	}
	fore(i,0,n){imp(a[i]);}
	cout<<"\n";
	//else cout<<"no\n\n";
}
void f(vector<vector<ll>>a, ll i, ll j, ll c){
	if(i==0)c=(n-1)/2;
	if(i<=j){
		if(j==n-1){
			if(i==n-1)cnt(a);
			else f(a,i+1,j,c-a[i][j]);
		}
		else f(a,i,j+1,c-a[i][j]);
	}
	fore(h,0,2){
		a[i][j]=h,a[j][i]=h;
		if(!c&&h)break;
		if(j==n-1){
			if(i==n-1)cnt(a);
			else f(a,i+1,j,c-h);
		}
		else f(a,i,j+1,c-h);
	}
}*/
//vector<ll>db={0,1,1,0,1, 1,0,1,1,0, 1,1,0,0,0, 0,1,0,0,0, 1,0,0,0,0};
int main(){
	ll n; cin>>n;
	assert(n&1);
	vector<vector<ll>>a(n);
	vector<ll>mk(n*n-n*(n-1)/2);
	fore(i,0,n*(n-1)/2)mk.pb(1);
	ll tle=0;
	do{
		tle++;
		//imp(mk);
		/*ll a[n][n];
		fore(i,0,SZ(mk))a[i/n][i%n]=mk[i];
		ll br=0;
		fore(i,0,n)fore(j,0,n)if((a[i][j]&&i==j)||a[i][j]!=a[j][i])br=1;
		/*if(mk==db){
			fore(i,0,n){imp(a[i]);}
			cout<<br<<"\n";
		}
		if(br)continue;
		vector<ll>p;
		fore(i,0,n)p.pb(i);
		vector<ll>res;
		do{
			ll b[n][n]; mset(b,0);
			fore(i,0,n)fore(j,0,n)if(i!=j){
				b[p[i]][p[j]]=!a[i][j];
			}
			ll flag=1;
			fore(i,0,n)fore(j,0,n)if(a[i][j]!=b[i][j])flag=0;
			if(flag)res=p;
		}
		while(next_permutation(ALL(p)));
		if(SZ(res)){
			fore(i,0,n){
				fore(j,0,n)cout<<a[i][j];
				cout<<"\n";
			}
			imp(res);
			cout<<"\n";
		}*/
	}
	while(next_permutation(ALL(mk)));
	cout<<"op: "<<tle<<" * "<<n*n<<": "<<tle*n*n<<"\n";
	return 0;
}
