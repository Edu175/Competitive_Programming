#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first 
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const int MOD = 998244353;

ll mul(ll x, ll y){
	x*=y;
	return x%MOD;
}

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

int main(){
	JET
	ll n; cin>>n;
	priority_queue<ll> k,u,p,c;
	fore(i,0,n){
		char x; cin>>x;
		if(x == 'K')k.push(i+1);
		if(x == 'U')u.push(i+1);
		if(x == 'P')p.push(i+1);
		if(x == 'C')c.push(i+1);
	}
	ll res = 0;
	while(SZ(c)){
		ll pos = c.top();c.pop();
		ll acc = pos;
		
		while(SZ(p) && p.top() > pos) p.pop();
		if(!SZ(p)) break;
		pos = p.top(); p.pop();
		acc = mul(acc,pos);
		
		while(SZ(u) && u.top() > pos) u.pop();
		if(!SZ(u)) break;
		pos = u.top(); u.pop();
		acc = mul(acc,pos);
		
		while(SZ(k) && k.top() > pos) k.pop();
		if(!SZ(k)) break;
		pos = k.top(); k.pop();
		acc = mul(acc,pos);
		
		res = add(res,acc);
		
	}
	cout<<res<<"\n";
	return 0;
}