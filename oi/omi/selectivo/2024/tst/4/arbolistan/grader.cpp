
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdjkgh:v)cout<<sdjkgh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
long long int Arbolstian(int N, vector<int> u,
vector<int> v, vector<int> w);

int main(){
	ll t; cin>>t;
	fore(_,0,t){
		ll n; cin>>n;
		vector<vector<int>>a(3,vector<int>(n-1));
		fore(h,0,3)fore(i,0,n-1)cin>>a[h][i];
		cout<<"Caso "<<_+1<<": "<<Arbolstian(n,a[0],a[1],a[2])<<"\n";
	}
}