#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
	
const int MAXN=2e5+9;
ll a[MAXN];
ll vis[MAXN];
ll n;

bool valido(){
	if(a[0]>n) return false;
	bool flag=0;
	fore(i,1,n){
		if(a[i]>n) return false;
		if(a[i]<a[i-1]) flag=1;
		if(a[i]>a[i-1] && flag) return false;
	}
	return true;
}
void invalido(){
	cout<<"*\n";
}

void arr(){
	int i=0;
	fore(i,0,n) cout<<a[i]<<" ";
	cout<<"\n";
}

int main(){
	JET
	cin>>n;
	bool flag=0;
	ll ant=-1;
	ll primero=-1;
	ll ultimo=-1;
	ll med=-1;
	fore(i,0,n){
		ll x; cin>>x;
		a[i]=x;
		if(x==0) continue;
		if(primero==-1) primero=i;
		ultimo=i;
		if(flag && x>ant){
			cout<<"*\n";
			return 0;
		}
		if(x<ant && !flag) flag=1,med=i;
		ant=x;
		vis[x]=1;
	}
	ll vis2[MAXN];
	ll a2[MAXN];
	fore(i,0,MAXN)vis2[i]=vis[i],a2[i]=a[i];
	if(primero==-1){
		fore(i,0,n) cout<<i+1<<" ";
		cout<<"\n";
		return 0;
	}
	if(primero==ultimo){
		if(a[primero]>primero){
			fore(i,0,primero) a[i]=i+1,vis[i+1]=1;
			int j=n;
			fore(i,primero+1,n){
				while(vis[j])j--;
				a[i]=j;
				vis[j]++;
			}
		}
		else if(n-primero<=a[primero]){
			for(ll i=n-1; i>primero;i--) a[i]=n-i,vis[n-i]=1;
			int j=n;
			for(ll i=primero-1;i>=0;i--){
				while(vis[j])j--;
				a[i]=j;
				vis[j]++;
			}
		}
		else{
			invalido();
			return 0;
		}
		arr();
		return 0;
	}
	bool solob = true;
	bool solos = true;
	ant=-1;
	fore(i,0,n) if(a[i]!=0) if(a[i]<ant) solos=false;
	ant=n+5;
	fore(i,0,n) if(a[i]!=0) if(a[i]>ant) solob=false;
	if(solos){
		int j=a[ultimo];
		int penul=ultimo-1;
		bool yata=1;
		while(a[penul]==0) penul--;
		for(int i=ultimo;i>=0;i--){
			if(a[i]!=0){
				continue;
			}
			while(vis[j]){
				if(j==1){
					yata=0;
					break;
				}
				j--;
				
			}
			if(!yata) break;
			a[i]=j;
			vis[j]++;
		}
		j=n;
		fore(i,ultimo,n){
			if(a[i]!=0) continue;
			while(vis[j])j--;
			a[i]=j;
			vis[j]++;
		}
		if(yata){
			arr();
			return 0;
		}
		fore(i,0,MAXN) vis[i]=vis2[i],a[i]=a2[i];
		yata=1;
		j=a[ultimo];
		fore(i,ultimo,n){
			if(a[i]!=0) continue;
			while(vis[j]){
				if(j==1){
					yata=0;
					break;
				}
				j--;
				
			}
			if(!yata) break;
			a[i]=j;
			vis[j]++;
		}
		j=a[penul];
		for(ll i=penul;i>=0;i--){
			if(a[i]!=0) continue;
			while(vis[j]){
				if(j==1){
					yata=0;
					break;
				}
				j--;
				
			}
			if(!yata) break;
			a[i]=j;
			vis[j]++;
		}
		j=a[ultimo];
		for(ll i=ultimo;i>=penul;i--){
			if(a[i]!=0) continue;
			while(vis[j]) j++;
			a[i]=j;
			vis[j]++;
		}
		if(!yata){
			invalido();
			return 0;
		}
		yata=valido();
		if(!yata) invalido();
		if(yata) arr();
		return 0;
	}
	if(solob){
		int j=a[primero];
		int seg=primero+1;
		while(a[seg]!=0) seg++;
		bool yata=1;
		fore(i,primero,n){
			if(a[i]!=0){
				j=a[i];
				continue;
			}
			while(vis[j])j--;
			a[i]=j;
			vis[j]++;
		}
		j=n;
		for(ll i=primero;i>=0;i--){
			if(a[i]!=0) continue;
			while(vis[j])j--;
			a[i]=j;
			vis[j]++;
		}
		fore(i,0,n) cout<<a[i]<<" ";
		cout<<"\n";
		return 0;
	}
	assert(med!=-1);
	int x=med-1,y=med+1;
	while(a[x]==0) x--;
	while(a[y]==0) y++;
	int j=1;
	if(a[primero]<a[ultimo]){
		fore(i,0,primero){
			if(j==a[primero]){
				cout<<"*\n";
				return 0;
			}
			a[i]=j;
			vis[j]=1;
			j++;
		}
		fore(i,0,ultimo){
			if(j>=a[ultimo]){
				cout<<"*\n";
				return 0;
			}
			a[i]=j;
			vis[j]=1;
			j++;
		}
	}
	else{
		fore(i,0,ultimo){
			if(j==a[ultimo]){
				cout<<"*\n";
				return 0;
			}
			a[i]=j;
			vis[j]=1;
			j++;
		}
		fore(i,0,primero){
			if(j>=a[primero]){
				cout<<"*\n";
				return 0;
			}
			a[i]=j;
			vis[j]=1;
			j++;
		}
	}
	
	int j=1;
	while(primero<x && ultimo>y){
		if(a[primero]!=0)primero++;
		else if(a[ultimo]!=0) ultimo++;
		else{
			while(vis[j])j++;
			if(a[primero-1]<a[ultimo+1]){
				a[primero]=j;
				vis[j]=1;
				primero++;
			}
			else{
				a[ultimo]=j;
				vis[j]=1;
				ultimo--;
			}
		}
	}
	if(primero<x){
		fore(i,primero,x){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]=1;
		}
	}
	else{
		for(ll i=ultimo;i>=y;i--){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]=1;
		}
	}
	fore(i,1,x){
		if(a[i]<a[i+1]){
			cout<<"*\n";
			return 0;
		}
	}
	fore(i,y+1,n){
		if(a[i]>a[i+1]){
			cout<<"*\n";
			return 0;
		}
	}
	if(a[med]==n){
		int j=a[x];
		fore(i,x,med){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]=1;
		}
		int j=a[y];
		for(ll i; i>=med;i--){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]=1;
		}
		fore(i,1,med){
			if(a[i]>=a[i-1] || a[i]>n){
				cout<<"*\n";
				return 0;
			}
		}
		fore(i,med+1,n){
			if(a[i]<=a[i-1] || a[i]>n){
				cout<<"*\n";
				return 0;
			}
		}
		fore(i,0,n) cout<<a[i]<<" ";
		cout<<"\n";
	}
	else{
		j=a[x];
		fore(i,0,MAXN) vis2[i]=vis[i];
		fore(i,x,med){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]++;	
		}
		j=a[y];
		for(ll i=y;y>=med;i--){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]++;
		}
		bool yata=1;
		fore(i,1,med){
			if(a[i]<a[i-1] || a[i]>n){
				yata=0;
			}
		}
		if(a[med]>n) yata=0;
		fore(i,med+1,n){
			if(a[i]>a[i-1] || a[i]>n){
				yata=0;
			}
		} 
		if(yata){
			fore(i,0,n) cout<<a[i]<<" ";
			cout<<"\n";
			return 0;
		}
		fore(i,0,MAXN) vis[i]=vis2[i];
		j=a[y];
		for(ll i=y;y>=med;i--){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]++;
		}
		j=a[x];
		fore(i,x,med){
			if(a[i]!=0) continue;
			while(vis[j])j++;
			a[i]=j;
			vis[j]++;
		}
		fore(i,1,med){
			if(a[i]<a[i-1] || a[i]>n){
				cout<<"*\n";
				return 0;
			}
		}
		if(a[med]>n){
			cout<<"*\n";
			return 0;
		}
		fore(i,med+1,n){
			if(a[i]>a[i-1] || a[i]>n){
				cout<<"*\n";
				return 0;
			}
		} 
		fore(i,0,n) cout<<a[i]<<" ";
		cout<<"\n";
		return 0;
	}
	
	
	return 0;
}