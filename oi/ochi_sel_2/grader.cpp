#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
#define ll int
typedef pair<ll,ll> ii;
int secret;
vector<bool> laboratorio(vector<vector<int>> a){
	//cout<<"labo\n";
	//for(auto i:a){imp(i);}
	ll n=SZ(a);
	vector<bool>ret(n);
	fore(i,0,n){
		bool flag=0;
		for(auto j:a[i])flag|=(j==secret);
		ret[i]=flag;
	}
	//imp(ret);
	return ret;
}
int mote_con_huesito(int N);
int main(){
	int n; cin>>n; //secret;
	secret=rand()%n+1;
	
	cout<<"(answer) "<<secret<<"\n";
	cout<<mote_con_huesito(n)<<"\n";
	return 0;
}
