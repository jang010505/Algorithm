#include <stdio.h>
#include <string.h>

void reverseString(char x[], int i) {
	char res[100];
	int j = 0;
	while (x[i] != ' ') {
		res[j] = x[i];
		if (i == strlen(x)) {
			printf("%s ", res);
			return;
		}
		i++;
		j++;
	}
	res[j] = '\0';
	reverseString(x, i + 1);
	printf("%s ", res);
	return;
}

int main(){
	int n;
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		char s[100];
		gets(s);
		printf("Case #%d: ", i+1);
		reverseString(s, 0);
		printf("\n");
	}
}
