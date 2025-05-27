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
	b.clear();
	fore(i,0,n+10) a[i] = '#';
	a[0] = '0'+x;
	ll i = 0;
	while(SZ(b)<m){
		ll obj;
		if(c(v[i])==0){
			i++;
			b.pb('0');
			continue;
		}
		if(c(v[i])>=x){
			obj = c(v[i]);
			i++;
		}
		else{
			if(i+1 == SZ(v)) return false;
			obj = c(v[i])*10 + c(v[i+1]);
			i+=2;
		}
		if(obj * x == 0){
			if(obj == c(v[i])) b.pb('0');
			else return false;
			continue;
		}
		if(obj%x!=0) return false;
		b.pb('0' + obj/x);
	}
	ll j=0,k=1;
	cout<<"con "<<x<<" b se forma y es \n";
	for(auto x:b) cout<<x;
	cout<<"\n";
	while(i<SZ(v)){
		cout<<"muere viendo i "<<i<<" j "<<j<<" k "<<k<<"\n";
		// cout<<"a en la posicion "<<j<<" es "<<a[j]<<"\n";
		ll obj;
		if(b[j] == '0' && v[i]!='0') return false;
		if(v[i]=='0'){
			obj = 0;
			i++;
		}
		else{
			if(v[i]>=b[j]){
				obj = c(v[i]);
				i++;
			}
			else{
				if(i+1 == SZ(v)) return false;
				obj = c(v[i])*10+c(v[i+1]);
				i+=2;
			}
		}
		
		ll num;
		if(obj*c(b[j])==0){
			if(obj==c(b[j])){
				num = 0;
			}
			else return false;
		}
		else{
			if(obj%c(b[j])!=0) return false;
			num = obj/c(b[j]);
		}
		
		if(j==0) a[k] = '0' + num;
		else if(num!=c(a[k])) return false;
		j++;
		if(j>=SZ(b)){
			j=0;
			k++;
		}
	}
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
		bool bo = false;
		fore(i,1,10){
			if(f(i)){
				bo = true;
				break;
			}
		}
		// f(1);
		if(!bo){
			cout<<"Impossible\n";
		}
		else{
			int i = 0;
			while(a[i]!='#'){
				cout<<a[i];
				i++;
			}
			cout<<" ";
			for(auto x:b) cout<<x;
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