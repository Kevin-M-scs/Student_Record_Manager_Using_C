#include <stdio.h>
int check(char *str1,char *str2){
	int i,flag=0;
	for(i=0;;i++){
		if(str1[i]!=str2[i]){
			flag=1;
			break;
		}
		if(str1[i]==str2[i]&&str1[i]=='\0'){
			break;
		}
	}
	if(flag==0)return 0;//strings are same
	else return 1;//strings are different	
}

int date_check(char *d,int c){
    int i,flag=0;//0 for correct format and 1 for incorrect
    //c=1 for dd/mm/yy date and c=2 for mm/yy date
    if(c==1){
        for(i=0;i<8;i++){
            if(i==2||i==5){
                if(d[i]=='/')flag=0;
                else{
                    flag=1;
                    break;
                }
            }
            else{
                if(d[i]>='0'&&d[i]<='9')flag=0;
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(d[8]!='\0')flag=1;//to avoid buffer overflow
        if(flag==1){
            printf("Invalid Date format,try again\n");
            return 1;//wrong format
        }
        else return 0;//correct format
    }
    if(c==2){
        for(i=0;i<5;i++){
            if(i==2){
                if(d[i]=='/')flag=0;
                else{
                    flag=1;
                    break;
                }
            }
            else{
                if(d[i]>='0'&&d[i]<='9')flag=0;
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(d[5]!='\0')flag=1;//to avoid buffer overflow
        if(flag==1){
            printf("Invalid Date format,try again\n");
            return 1;//wrong format
        }
        else return 0;//correct format
    }
}

int name_check(char *s,int n){
    //find index of null character
    int i,j,check=0;
    for(i=0;;i++){
        if(s[i]=='\0'){
            j=i;break;
        }
    }
    //check index lies in range
    if(j>9){//to handle user entering nothing and buffer overflow
        check=1;
        printf("Name to large or nothing entered\n");
    }
    for(i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            check=1;
            printf("Cant enter integer as name\n");break;
        }
    }
    if(check==1)return 1;//invalid
    else return 0;//valid
    
}

int hour_check(int hr){
    if(hr<0){
        printf("Invalid hours entry\n");
        return 1;
    }
    else return 0;
}

