#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

struct node{
	ll s=0,w=0;
	node(){};
};
bool operator<(node a, node b){
	return min(a.s,b.s-a.w)<min(b.s,a.s-b.w);
}
bool operator<=(node a, node b){
	return min(a.s,b.s-a.w)<=min(b.s,a.s-b.w);
}
string cmp(node a,node b){
	string res;
	res+=to_string(min(a.s,b.s-a.w));
	res.pb(',');
	res+=to_string(min(b.s,a.s-b.w));
	res.pb('=');
	return res;
}
int main(){FIN;
	ll n; cin>>n;
	vector<node>a(n);
	fore(i,0,n)cin>>a[i].s>>a[i].w;
	sort(ALL(a));
	
	/*for(auto i:a)cout<<i.s<<","<<i.w<<" ";
	cout<<"\n";*/
	//vector<ll>b;
	fore(i,0,n)fore(j,i+1,n)assert(a[i]<=a[j]);
	//cout<<(a[0]<=a[1])<<" "<<(a[0]<=a[1])<<" "<<(a[0]<=a[1])<<"\n";
	//cout<<cmp(a[0],a[1])<<(a[0]<=a[1])<<" "<<cmp(a[1],a[2])<<(a[1]<=a[2])<<" "<<cmp(a[0],a[2])<<(a[0]<=a[2])<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
