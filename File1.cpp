#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 154

char TOLOWER(char c){
	 if (c>='A' && c<='Z'){
		c+=32;
	 }
	 return c;
}


int  STRLEN(const char *str){
	int length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return length;
}


int STRCMP(const char* main_str, const char* compared_str){
	int len1, len2, min;
    int compare = 0;
	min = len1 = STRLEN(main_str);
	len2 = STRLEN(compared_str);
    if (len2 < min)
	{
		min = len2;
	}
	for (int i = 0; i < min; i++)
	{
		compare = TOLOWER(main_str[i]) - TOLOWER(compared_str[i]);
        if (compare != 0)
        {
			return  compare;
        }
	}

    return len1 - len2;
}


void BubbleSort(char **str,int size) {
	char* temp;
	for(int i=0; i < size; i++) {
		for(int j = size-1; j > i; j-- ) {
			if (STRCMP(str[j-1],str[j])>0){
				temp=str[j-1];
				str[j-1]=str[j];
				str[j]=temp;
			}
		}
	}
}


int main()
{
	int n=1;
	int index=1;
	char **str;
	printf("Welcome to our dictionary\n");
	printf("Start enter text\n");
    while(n==1){
		if(index==1){
			if(!(str=(char**)malloc(sizeof (char*)))){
                printf( "Can't allocate memory\n" );
				getch();
				exit(EXIT_FAILURE);
			}
		}
		else if(index>1){
			if(!(str=(char**)realloc(str,sizeof(char*)*index))){
				printf( "Can't allocate memory\n" );
				getch();
				exit(EXIT_FAILURE);
			}
		}
		if(!(str[index-1]=(char*)malloc(SIZE*sizeof(char)))){
            printf( "Can't allocate memory\n" );
			getch();
			exit(EXIT_FAILURE);
		}
		gets(str[index-1]);
		fflush(stdin);
		printf("To continue enter 1, to break enter 0\n");
		if(!(scanf("%d",&n))){
			printf("Invalid input\n");
			getch();
			return -1;
		}
		fflush(stdin);
		if(n!=1&&n!=0){
			printf("Invalid argument\n");
			getch();
			return -1;
		}
		index++;
    }
	index--;
    char **newstr;
	int newindex=1;
	for(int j=0;j<index;j++){
		for(int fixed_ind=0;str[j][fixed_ind]!=0;fixed_ind++){
			if(str[j][fixed_ind]!=' '&&(fixed_ind==0||str[j][fixed_ind-1]==' ')){
				while(str[j][fixed_ind]==','||str[j][fixed_ind]=='!'||str[j][fixed_ind]=='?'||str[j][fixed_ind]=='.'||str[j][fixed_ind]=='>'
					  ||str[j][fixed_ind]=='<'||str[j][fixed_ind]=='('||str[j][fixed_ind]==')'||str[j][fixed_ind]==':'||str[j][fixed_ind]==';'
					  ||str[j][fixed_ind]=='-'){

					fixed_ind++;
				}
				if(str[j][fixed_ind]==' '){
					continue;
				}
				else if(str[j][fixed_ind]==0){
					break;
				}
				if(newindex==1){
					if(!(newstr=(char**)malloc(sizeof (char*)))){
						printf( "Can't allocate memory\n" );
						getch();
						exit(EXIT_FAILURE);
					}
				}
				else if(newindex>1){
					if(!(newstr=(char**)realloc(newstr,sizeof(char*)*newindex))){
                        printf( "Can't allocate memory\n" );
						getch();
						exit(EXIT_FAILURE);
					}
                }
				if(!(newstr[newindex-1]=(char*)malloc(SIZE*sizeof(char)))){
                    printf( "Can't allocate memory\n" );
					getch();
					exit(EXIT_FAILURE);
				}
				int variable_size=0;
				while(str[j][fixed_ind]!=' '&&str[j][fixed_ind]!=','&&str[j][fixed_ind]!=0&&str[j][fixed_ind]!='!'&&str[j][fixed_ind]!='?'
					  &&str[j][fixed_ind]!='.'&&str[j][fixed_ind]!='>'&&str[j][fixed_ind]!='<'&&str[j][fixed_ind]!='('&&str[j][fixed_ind]!=')'
					  &&str[j][fixed_ind]!=':'&&str[j][fixed_ind]!=';'&&str[j][fixed_ind]!='-'){
					newstr[newindex-1][variable_size]=str[j][fixed_ind];
					fixed_ind++;
					variable_size++;
				}
				newstr[newindex-1][variable_size]=0;
				newindex++;
            }
        }
    }
	newindex--;
	BubbleSort(newstr,newindex);
	int kolvo=1;
	if(newindex>1){
	for(int j=0;j<newindex;j++){
			if(j==0&&STRCMP(newstr[j],newstr[j+1])!=0){
				printf("%s:%d\n",newstr[j],kolvo);
                continue;
			}
			if(j==0&&STRCMP(newstr[j],newstr[j+1])==0){
				j++;
				kolvo++;
			}
			else if(j!=0&&j<newindex-1){
				while(STRCMP(newstr[j],newstr[j+1])==0){
					j++;
					kolvo++;
					if(j==newindex-1){
						break;
					}
				}
			}
			printf("%s:%d\n",newstr[j],kolvo);
			kolvo=1;
		}
	}
	else if(newindex==1){
		printf("%s:%d\n",newstr[0],kolvo);
	}
	for(int j=0;j<newindex;j++){
		free(newstr[j]);
	}
	free(newstr);
	for(int j=0;j<index;j++){
		free(str[j]);
	}
	free(str);
	getch();
    return 0;
}

