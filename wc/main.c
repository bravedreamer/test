#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	char command[10];
   	char tag[500];int charNum,wordNum,lineNum;
   	char mainCmd[20][20]={"-c","-w","-l","-a"	};
	
	while(1){
	printf("����:\n");
	printf("   1������ -c �ļ�·��   �����ļ����ַ���\n"); 
	printf("   2������ -w �ļ�·��   �����ļ��Ĵʵ���Ŀ\n"); 
	printf("   3������ -l �ļ�·��   �����ļ�������\n");
	printf("   4������ -a �ļ�·��   �����ļ��Ĵ���������ע������\n"); 
   
   
   int characterCount(char *file);
   int WordCount(char *file);
   int rowCount(char *file);
   int complexCount(char *file);
   
   
   printf("������ָ�wc.exe");
   	scanf("%s",&command);
	 
	printf("�������ļ�·����");
 	scanf("%s",&tag);
 	
 	if(strcmpi(command,mainCmd[0])==0){
 		charNum=characterCount(tag);
   		printf("�ַ�����%d",charNum);
 	}else if(strcmpi(command,mainCmd[1])==0){
 				wordNum=WordCount(tag);
   				printf("�ʻ�����%d",wordNum);
 			}else if(strcmpi(command,mainCmd[2])==0){
 						lineNum=rowCount(tag);
   						printf("������%d",lineNum); 
 					}else if(strcmpi(command,mainCmd[3])==0){
 								complexCount(tag);
 							}else{
 								printf("ָ�����"); 
 							}
 					
 	
 	printf("\n\n"); 
	}
	return 0;
}

int characterCount(char *file){//�ַ���ͳ�ƺ��� 
    FILE *myfile=NULL;
    int charCount=0;//�����ۼƶ������ַ��� 
    myfile=fopen(file,"r");
    if(myfile==NULL){
        printf("�ļ������ڣ�\n");
        exit(-1);
    }
    char mychar;
    mychar = fgetc(myfile);
    while(mychar!=EOF){
        mychar = fgetc(myfile);
        charCount++;
    }
    fclose(myfile);
    return charCount-1;
}


int WordCount(char *file){//������ͳ�ƺ��� 
    FILE *myfile=NULL;
    int wordcount=0;//�����ۼƶ����ĵ������� 
    myfile=fopen(file,"r");
    if(myfile==NULL){
        printf("�ļ������ڣ�\n");
        exit(-1);
    }
    char mychar;
    mychar = fgetc(myfile);
    while(mychar!=EOF){
        if((mychar>='a'&&mychar<='z')||(mychar>='A'&&mychar<='Z')){
            while((mychar>='a'&&mychar<='z')||(mychar>='A'&&mychar<='Z')){ 
                mychar=fgetc(myfile);
            }
            wordcount++;
        }
        mychar=fgetc(myfile);
    }
    fclose(myfile);
    return wordcount;
}

int rowCount(char *file){//����ͳ�ƺ��� 
    FILE *myfile=NULL;
    int linecount=0;//�����ۼƶ������������� 
    myfile=fopen(file,"r");
    if(myfile==NULL){
        printf("�ļ������ڣ�\n");
        exit(-1);
    }
    char mychar;
    mychar = fgetc(myfile);
    while(mychar!=EOF){
        if(mychar=='\n'){
            linecount++;
            mychar = fgetc(myfile);
        }
        else{
            mychar = fgetc(myfile);
        }
    }
    fclose(myfile);
    return linecount;
}

int complexCount(char *file){//ͳ��ע���У����������� 
	FILE *myfile=NULL;
	int noteLine=0;//ע����
	int codeLine=0;//������ 
	
	myfile=fopen(file,"r");
	if(myfile==NULL){
		printf("�ļ������ڣ�\n");
        exit(-1);
	} 
	
	char mychar;
	mychar= fgetc(myfile);
	
    while(mychar!=EOF){
    	if(mychar=='\''||mychar=='\"'){
    		mychar=fgetc(myfile);
    		while(mychar=='\"'||mychar=='\''){
    			mychar=fgetc(myfile);
    		}
    	}
    	
    	
    	if(mychar=='/'){//ע���м��� 
    		mychar=fgetc(myfile);
    		if(mychar=='/'||mychar=='*'){
    			if(mychar=='/'){
    				mychar=fgetc(myfile);
    				while(mychar=="\n"||mychar!=EOF){
    					mychar=fgetc(myfile);
    				}
    				noteLine++;
    				mychar=fgetc(myfile);
    			}
    			if(mychar=='*'){
    				mychar=fgetc(myfile);
    				while(mychar=='*'){
						if(mychar=="\n"||mychar=='*')
							noteLine++;	
						mychar=fgetc(myfile);
    				}
    			} 
    		}
    	}else{
		 			mychar=fgetc(myfile);
		 		}
    	
    }
    
    int rowCount(char *file);
    codeLine=rowCount(file);//�����м��� 
    codeLine-=noteLine;
    
    fclose(myfile);
    printf("ע���У�%d, �����У�%d",noteLine,codeLine);
    return 0;
    
}
