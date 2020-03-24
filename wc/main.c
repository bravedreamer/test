#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	char command[10];
   	char tag[500];int charNum,wordNum,lineNum;
   	char mainCmd[20][20]={"-c","-w","-l","-a"	};
	
	while(1){
	printf("功能:\n");
	printf("   1：输入 -c 文件路径   返回文件的字符数\n"); 
	printf("   2；输入 -w 文件路径   返回文件的词的数目\n"); 
	printf("   3：输入 -l 文件路径   返回文件的行数\n");
	printf("   4：输入 -a 文件路径   返回文件的代码行数和注释行数\n"); 
   
   
   int characterCount(char *file);
   int WordCount(char *file);
   int rowCount(char *file);
   int complexCount(char *file);
   
   
   printf("请输入指令：wc.exe");
   	scanf("%s",&command);
	 
	printf("请输入文件路径：");
 	scanf("%s",&tag);
 	
 	if(strcmpi(command,mainCmd[0])==0){
 		charNum=characterCount(tag);
   		printf("字符数：%d",charNum);
 	}else if(strcmpi(command,mainCmd[1])==0){
 				wordNum=WordCount(tag);
   				printf("词汇数：%d",wordNum);
 			}else if(strcmpi(command,mainCmd[2])==0){
 						lineNum=rowCount(tag);
   						printf("行数：%d",lineNum); 
 					}else if(strcmpi(command,mainCmd[3])==0){
 								complexCount(tag);
 							}else{
 								printf("指令错误！"); 
 							}
 					
 	
 	printf("\n\n"); 
	}
	return 0;
}

int characterCount(char *file){//字符数统计函数 
    FILE *myfile=NULL;
    int charCount=0;//用于累计读到的字符数 
    myfile=fopen(file,"r");
    if(myfile==NULL){
        printf("文件不存在！\n");
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


int WordCount(char *file){//单词数统计函数 
    FILE *myfile=NULL;
    int wordcount=0;//用于累计读到的单词数量 
    myfile=fopen(file,"r");
    if(myfile==NULL){
        printf("文件不存在！\n");
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

int rowCount(char *file){//行数统计函数 
    FILE *myfile=NULL;
    int linecount=0;//用于累计读到的行数量· 
    myfile=fopen(file,"r");
    if(myfile==NULL){
        printf("文件不存在！\n");
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

int complexCount(char *file){//统计注释行，代码行数量 
	FILE *myfile=NULL;
	int noteLine=0;//注释行
	int codeLine=0;//代码行 
	
	myfile=fopen(file,"r");
	if(myfile==NULL){
		printf("文件不存在！\n");
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
    	
    	
    	if(mychar=='/'){//注释行计算 
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
    codeLine=rowCount(file);//代码行计算 
    codeLine-=noteLine;
    
    fclose(myfile);
    printf("注释行：%d, 代码行：%d",noteLine,codeLine);
    return 0;
    
}
