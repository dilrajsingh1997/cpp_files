#include<iostream>
#include<string>
using namespace std;

string C401C(int n, int m){
	string ans;
	if(n>m+1 || m>2*(n+1)){
		ans.clear();
		ans="-1";
	}
	else{
		
		if(n==0 && m<3){
			while(m--){
				ans.append("1");
			}
		}
		else if(m==0 && n<2){
			while(n--){
				ans.append("0");
			}
		}
		else if(m==n){
			while(m--){
				ans.append("10");
			}
		}
		else if(m==n-1){
			ans.append("0");
			while(m--){
				ans.append("10");
			}

		}
		else if(m>n){
			while(n && m>n){
				if(m>=2){
					ans.append("11");
					m-=2;
				}
				else if(m){
					m-=1;
					ans.append("1");
				}
				n-=1;
				ans.append("0");
			}
			ans.append(C401C(n,m));
		}
		
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		string ans= C401C(n,m);
		cout<<ans<<endl;			
	}
	
}

