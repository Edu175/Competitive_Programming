#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;

ll n,m;
vector<char> v;
const ll maxn = 1e7;
char a[maxn];
vector<char> b;
ll c(char x){
	return x-'0';
}

bool f(ll x){
	fore(i,0,n+10) a[i] = '#';
	b.clear();
	a[0]='0' + x;
	ll i = 0;
	while(SZ(b)<m){
		if(v[i] == '0'){
			b.pb('0');
			i++;
			continue;
		}
		ll obj;
		if(c(v[i])<x){
			if(i+1>=SZ(v)) return false;
			obj = c(v[i])*10 + c(v[i+1]);
			i+=2;
		}
		else{
			obj = c(v[i]);
			i++;
		}
		if(obj%x!=0) return false;
		b.pb('0'+obj/x);
	}
	ll j=0,k=1;
	// cout<<"se formo b y es\n";
	// for(auto x:b) cout<<x;
	// cout<<"\n";
	while(i<SZ(v)){
		ll obj;
		if(v[i]=='0'){
			i++;
			if(b[j]!='0'){
				if(a[k]=='#') a[k]='0';
				else if(a[k]!='0') return false;
			}
		}
		else{
			// cout<<"entrando con i,j,k "<<i<<" , "<<j<<" , "<<k<<"\n";
			if(b[j]=='0') return false;
			if(v[i]<b[j]){
				if(i+1>=SZ(v)) return false;
				obj = c(v[i])*10 + c(v[i+1]);
				i+=2;
			}
			else{
				obj = c(v[i]);
				i++;
			}
			// cout<<"obj bj and ak "<<obj <<" "<<b[j]<<" "<<a[k]<<"\n";
			if(obj%c(b[j])!=0) return false;
			if(a[k]=='#') a[k] = '0'+obj/c(b[j]);
			else if(c(a[k])!=obj/c(b[j])) return false;
		}
		j++;
		if(j>=SZ(b)){
			j=0;
			k++;
		}
	}
	// cout<<"j es y k "<<j<<" "<<k<<"\n";
	return j==0 && k==n;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		v.clear();
		cin>>n>>m;
		string s; cin>>s;
		fore(i,0,SZ(s)) v.pb(s[i]);
		if(v[0]=='0'){
			cout<<"Impossible\n";
			continue;
		}
		bool bo = false;
		fore(i,1,10){
			if(f(i)){
				bo = true;
				break;
			}
		}
		// f(2);
		if(!bo){
			cout<<"Impossible\n";
		}
		else{
			fore(i,0,n){
				if(a[i]=='#') cout<<'0';
				else cout<<a[i];
			}
			cout<<" ";
			fore(i,0,m){
				cout<<b[i];
			}
			cout<<"\n";
		}
	}
	return 0;
}

/*
4
2 2
8101215
3 4
100000001000
2 2
80101215
3 4
1000000010000
con 1 b se forma y es 
81
muere viendo i 2 j 0 k 1
con 2 b se forma y es 
45
muere viendo i 3 j 0 k 1
muere viendo i 5 j 1 k 1
23 45
con 1 b se forma y es 
8112
muere viendo i 5 j 0 k 1
Impossible
con 1 b se forma y es 
81
muere viendo i 2 j 0 k 1
con 2 b se forma y es 
45
muere viendo i 3 j 0 k 1
muere viendo i 5 j 1 k 1
muere viendo i 7 j 0 k 2
Impossible
con 1 b se forma y es 
8112
muere viendo i 5 j 0 k 1
Impossible



*/