#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll fv=1234567890; //flag value

pair<ll,ll> operator+(pair<ll,ll>p1,pair<ll,ll>p2){
		return {p1.fst+p2.fst,p1.snd+p2.snd};
	}

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("ladrillos.in", ios::in);
	cout.open("ladrillos.out", ios::out);
	ll n; cin>>n;
	ll a[n];
	ll count=0,pos;
	fore(i,0,n){
		string s; cin>>s;
		//cout<<s;
		if(s=="*")a[i]=fv;
		else {
			a[i]=stoll(s);
			if(count==0)pos=i;
			count++;
			//cout<<" uno";
		}
		//cout<<"\n";
	}
	ll res[n];
	if(n==1&&a[0]!=fv){
		cout<<a[0]<<"\n";
		return 0;
	}
	if(count){
		if(count>1){
			pair<ll,ll>unk[n];
			unk[pos]={0,a[pos]};
			unk[pos+1]={1,0};
			ll &x=a[pos+1];
			fore(i,pos+2,n){
				if(x!=fv)break;
				unk[i]=unk[i-2]+unk[i-1];
				if(a[i]!=fv)x=(a[i]-unk[i].snd)/unk[i].fst;
			}
			res[pos]=a[pos];
			res[pos+1]=x;
		}
		else {
			res[pos]=a[pos];
			if(pos<n-1){
				res[pos+1]=0;
			}
			else pos--,res[pos]=0;
		}
		fore(i,pos+2,n){
			res[i]=res[i-1]+res[i-2];
		}
		for(int i=pos-1;i>=0;i--){
			res[i]=res[i+2]-res[i+1];
		}
		fore(i,0,n){
			cout<<res[i]<<" ";
		}
	}
	else fore(i,0,n)cout<<0<<" ";
	cout<<"\n";
	return 0;
}
