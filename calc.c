#include <stdio.h>
#include "operators.h"
#include "my_fscanf.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	int line = 0;
	float result;
	float (*resultFunc)(int, int);
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		my_fscanf(fp, "%d", &line);
	
		for(int i=0; i<line; i++) {
			my_fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			if(feof(fp)) break;
			switch(operator) {
				case '+':
				resultFunc = add;
				break;
				case '-':
				resultFunc = minus;
				break;
				case '*':
				resultFunc = mul;
				break;
				case '/':
				resultFunc = div;
				break;
			}		
			result = resultFunc(operand1, operand2);
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

