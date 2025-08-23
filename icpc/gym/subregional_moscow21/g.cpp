#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	map<string,string> mp;
	fore(i,0,16){
		string a,b; cin>>b>>a;
		if(a[0]=='0'){
			if(SZ(a)==2) mp[b]="13-16";
			else if(SZ(a)==3) mp[b]="9-12";
			else if(SZ(a)==4) mp[b]="7-8";
			else if(SZ(a)==5) mp[b]="5-6";
			else if(SZ(a)==6) mp[b]="4";
			else if(SZ(a)==7) mp[b]="3";
			else{
				if(a.back()=='0') mp[b]="2";
				else mp[b]="1";
			}
		}
		else if(a[1]=='0'){
			if(SZ(a)==3) mp[b]="9-12";
			else if(SZ(a)==4) mp[b]="7-8";
			else if(SZ(a)==5) mp[b]="5-6";
			else if(SZ(a)==6) mp[b]="4";
			else if(SZ(a)==7) mp[b]="3";
			else{
				if(a.back()=='0') mp[b]="2";
				else mp[b]="1";
			}
		}
		else if(a[2]=='0'){
			if(SZ(a)==4) mp[b]="5-6";
			else if(SZ(a)==5) mp[b]="4";
			else if(SZ(a)==6) mp[b]="3";
			else{
				if(a.back()=='0') mp[b]="2";
				else mp[b]="1";
			}
		}
		else if(a[3]=='0'){
			if(SZ(a)==5) mp[b]="3";
			else{
				if(a.back()=='0') mp[b]="2";
				else mp[b]="1";
			}
		}
		else{
			if(a.back()=='0') mp[b]="2";
			else mp[b]="1";
		}
	}
	for(auto x: mp){
		if(x.snd=="1") cout<< x.snd<<" "<<x.fst<<"\n";
	}
	for(auto x: mp){
		if(x.snd=="2") cout<< x.snd<<" "<<x.fst<<"\n";
	}
	for(auto x: mp){
		if(x.snd=="3") cout<< x.snd<<" "<<x.fst<<"\n";
	}
	for(auto x: mp){
		if(x.snd=="4") cout<< x.snd<<" "<<x.fst<<"\n";
	}
	for(auto x: mp){
		if(x.snd=="5-6") cout<< x.snd<<" "<<x.fst<<"\n";
	}
	for(auto x: mp){
		if(x.snd=="7-8") cout<< x.snd<<" "<<x.fst<<"\n";
	}
	for(auto x: mp){
		if(x.snd=="9-12") cout<< x.snd<<" "<<x.fst<<"\n";
	}
	for(auto x: mp){
		if(x.snd=="13-16") cout<< x.snd<<" "<<x.fst<<"\n";
	}
}