#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main(){
	char str[30];
	int answer=0;
	scanf("%s", str);
	stack <char> s;
	int tmp=1, chk=1;
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='('){
			s.push(str[i]);
			tmp*=2;
		}
		else if(str[i]=='['){
			s.push(str[i]);
			tmp*=3;
		}
		else if(str[i]==']'){
			if(s.empty()){
				chk=0;
				break;
			}
			else if(s.top()=='['){
				if(str[i-1]=='[')
					answer+=tmp;
				s.pop();
				tmp/=3;
			}
			else{
				chk=0;
				break;
			}
		}
		else{
			if(s.empty()){
				chk=0;
				break;
			}
			else if(s.top()=='('){
				if(str[i-1]=='(')
					answer+=tmp;
				s.pop();
				tmp/=2;
			}
			else{
				chk=0;
				break;
			}
		}
	}
	if(chk==0 || s.empty()==0)
		answer=0;
	printf("%d", answer);
	return 0;
}
