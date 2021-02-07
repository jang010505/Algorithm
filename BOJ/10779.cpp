#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main(){
	char str[100001];
	int answer=0;
	scanf("%s", str);
	stack <char> s;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='(')
			s.push(str[i]);
		else{
			s.pop();
			if(str[i-1]=='(')
				answer+=s.size();
			else
				answer++;
		}
	}
	printf("%d", answer);
	return 0;
}
