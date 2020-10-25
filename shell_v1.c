#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LINE 80
#define NO_OF_COMMANDS 10
int InputParser(char x[],char* y[]){
	int j=0;
	int l=strlen(x),l2=0;
	char tempstr[MAX_LINE]="";
	for(int i=0;i<=l;i++){
		if(x[i]==' '||x[i]=='\0'){
			y[j]=malloc(strlen(tempstr)+1);
			strcpy(y[j],tempstr);
			//printf("%s\n",y[j]);
			j++;
			l2=0;
			memset(tempstr, '\0', sizeof tempstr);
			continue;
		}
		tempstr[l2]=x[i];
		l2++;		
		//printf("Iteration %d\n",i);		
	}
	//y[j]=malloc(strlen(tempstr)+1);
	//strcpy(y[j],tempstr);
	//printf("Loop Done\n");
	return j;
}

int main(void){
	char* args[MAX_LINE/2 + 1]={0}; /*args is an array of strings, that will store an individual command given by a user as a space separated strings.*/
	int flag = 1;
	while(flag){
		printf("shell>>");
		fflush(stdout);
		char input[MAX_LINE];
		scanf("%[^\n]%*c",input);
		//printf("%s\n",input);
		
		int no_of_args = 0;
		no_of_args = InputParser(input,args);
		
		//printf("The FUnction has been completed\n");
		/*for(int i=0; i<(no_of_args);i++){
			printf("%s\n",args[i]);
		}*/
		
		/*if(args[no_of_args]=='\0')
			printf("WELL YEAH, THIS IS NULL\n");
		else
			printf("NOT NULL.\n");*/
		flag = 0;
	}
return 0;
} 
