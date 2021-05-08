#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void wcexe(char *filename,char s){
    FILE *fp;
    char buffer[1000];
    char c;
    int bufferlen;
    int isLastBlank = 0; // 上个字符是否是空格(1表示是  0表示不是)
    int charCount=0;
    int wordCount=0;
    int i;
    char x=s;

    if((fp=fopen(filename,"rb"))==NULL){
        printf("文件不能打开\n");
        exit(0);
    }
    while(fgets(buffer,1000,fp)!=NULL){
        bufferlen=strlen(buffer);
        for(i=0;i<bufferlen;i++){
            c=buffer[i];

            if(c==' '|| c=='\t'||c==','){
                if(isLastBlank==0){
                    charCount++;
                    wordCount++;
                }
                isLastBlank=1;
            }else if(c!='\n'&&c!='\r'){
                charCount++;
                isLastBlank=0;
            }

        }
        if(isLastBlank==0)
            wordCount++;
        isLastBlank=1;

    }

    if(x=='c'){
        printf("字符数：%d\n",charCount);
    }
    else if(x=='w'){
        printf("单词数：%d\n",wordCount);
    }


    fclose(fp);
}
int main(){
//    char filename[]="test.txt"
    char s;
    scanf("%s",&s);
    char filename[]="/Users/jiangxueyao/CLionProjects/untitled/test.txt";
    wcexe(filename,s);
    return 0;
}