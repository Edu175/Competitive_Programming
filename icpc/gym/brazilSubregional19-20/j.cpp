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

int p=2;

int f (char x){
	if(x=='A') return 0;
	else if(x=='D') return 9;
	else if (x=='Q') return 10;
	else if (x=='J') return 11;
	else if (x=='K') return 12;
	else{
		return x-'1';
	}
}

int mi (vi a){
	ll k=15;
	ll c=5;
	map<int,int> m;
	fore(i,0,5) m[a[i]]++;
	for(auto x : m){
		if(x.fst==-1 && p>0) continue;
		if(x.snd<c){
			c=x.snd;
			k=x.fst;
		}
		if(x.snd==c && x.fst<k){
			k=x.fst;
		}
	}
	return k;
}

int main(){
	FIN
	int n,k; cin>>n>>k;
	vi arr[n];
	
	fore(i,0,n){
		fore(j,0,4){
			char c;
			cin>>c;
			arr[i].pb(f(c));
		}
		if(i+1==k) arr[i].pb(-1);		
	}
	ii mini={20,n-1};
	bool b1=false;;
	fore(i,0,n){
		if(SZ(arr[i])!=4) continue;
		bool b0=true;
		int aux=arr[i][0];
		fore(j,0,3){
			if(arr[i][j]!=arr[i][j+1]) b0=false;
		}
		if(b0){
			b1=true;
			if(aux<mini.fst){
				mini={aux,i+1};
			}
		}
	}
	if(b1){
		cout<<mini.snd<<"\n";
		return 0;
	}
	bool b=true;
	int i=k-1;
	while(b){
		
		int r= mi(arr[i]);
		//cout<<r<<" ";
		if(r==-1) p=2;
		vi aux;
		fore(j,0,5){
			if(arr[i][j]!=r){
				aux.pb(arr[i][j]);
			}
		}
		while(SZ(aux)<4) aux.pb(r);
		arr[i]=aux;
		aux.clear();
		bool s=true;
		fore(j,0,3){
			if(arr[i][j]!=arr[i][j+1]) s=false;
		}
		b=!s;
		i++;
		if(i>=n) i-=n;
		arr[i].pb(r);
		p--;
	}
	if(i==0) cout<<n<<"\n";
	else{
		cout<<i<<"\n";
	}
	
	return 0;
} 