#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int check(char a, char b, char c, char str[]){
	stack <char> s;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='A'){
			if(a=='(')
				s.push(a);
			else{
				if(s.empty())
					return 0;
				s.pop();
			}
		}
		if(str[i]=='B'){
			if(b=='(')
				s.push(b);
			else{
				if(s.empty())
					return 0;
				s.pop();
			}
		}
		if(str[i]=='C'){
			if(c=='(')
				s.push(c);
			else{
				if(s.empty())
					return 0;
				s.pop();
			}
		}
	}
	if(s.empty()==0)
		return 0;
	return 1;
}

int main(){
	int T;
	scanf("%d\n", &T);
	while(T--){
		char str[100];
		int answer=0;
		scanf("%s", str);
		if(check('(', '(', ')', str))
			answer=1;
		if(check('(', ')', '(', str))
			answer=1;
		if(check(')', '(', '(', str))
			answer=1;
		if(check('(', ')', ')', str))
			answer=1;
		if(check(')', '(', ')', str))
			answer=1;
		if(check(')', ')', '(', str))
			answer=1;
		if(answer)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
