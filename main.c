//Menu Driven Program to Maintain Class records for fee calculation
/*Program uses simple logic but is lengthy as it is
built to tackle almost every possible situation
that may be encountered during usage by any type of user*/ 
//Length of program may be reduced by creating more functions

#include<stdio.h>
#include<stdlib.h>//for system() function
#include<windows.h>//for Sleep() function

typedef struct{
    char name[10];
    char date[8];
    int hours;
}student;

int check(char *str1,char *str2);
int date_check(char *d,int c);
int name_check(char *s,int n);
int hour_check(int hr);
void search_date(char *d);

int main(){
    FILE *f;student Ai,Ao;//Ai for input ,Ao for output
    int chk;int r;//chk=0 for first ever entry
    char str[10];int flag;int e=0;
    char pwd[]="abcd";int c=256;//random value
    printf("Enter Password(case sensitive)(10 characters max): ");
    while(c!=0){
        fflush(stdin);
        scanf("%s",str);
        c=(check(str,pwd)==0?0:1);// 1 is exit
        if(c==1)printf("Wrong Password Try again:");
    }
    system("cls");
    printf("Welcome to The Tuition Records\n");
    int ch=256;
    while(ch!=9){
        char s1[]="1.Add",s2[]="2.Modify",s3[]="3.Remove",s4[]="4.Display Datewise";
        char s5[]="5.Display Monthwise",s6[]="6.Display All",s7[]="7.Clear screen",s8[]="8.Guidelines",s9[]="9.Exit";
        printf("%-*s%-*s%-*s%-*s %s\n",19,s1,19,s2,19,s3,19,s4,s5);
        printf("%-*s%-*s%-*s%-*s\n",19,s6,19,s7,19,s8,19,s9);
        printf("Enter choice:");
        fflush(stdin);
        scanf("%d",&ch);
        if(ch==1){
            //input name
            printf("Enter student name:");
            fflush(stdin);
            scanf("%s",Ai.name);
            if(Ai.name[0]=='0'&&Ai.name[1]=='\0') goto menu;//back to menu option
            //prevent buffer overflow
            r=name_check(Ai.name,10);
            while(r!=0){
                printf("Enter student name:");
                fflush(stdin);
                scanf("%s",Ai.name);
                if(Ai.name[0]=='0'&&Ai.name[1]=='\0') goto menu;//back to menu option
                r=name_check(Ai.name,10);
            }
            //input date
            printf("Enter date dd/mm/yy:");
            fflush(stdin);
            scanf("%s",Ai.date);
            if(Ai.date[0]=='0'&&Ai.date[1]=='\0') goto menu;//back to menu option
            //ensure correct format
            r=date_check(Ai.date,1);
            while(r!=0){
                printf("Enter date dd/mm/yy:");
                fflush(stdin);
                scanf("%s",Ai.date);
                if(Ai.date[0]=='0'&&Ai.date[1]=='\0') goto menu;//back to menu option
                r=date_check(Ai.date,1);
            }
            //input hours
            printf("Enter number of hours:");
            fflush(stdin);
            scanf("%d",&(Ai.hours));
            if(Ai.hours==0)goto menu;//back to menu option
            //ensure valid hours input
            r=hour_check(Ai.hours);
            while(r!=0){
                printf("Enter number of hours:");
                fflush(stdin);
                scanf("%d",&(Ai.hours));
                if(Ai.hours==0)goto menu;//back to menu option
                r=hour_check(Ai.hours);
            }
            f=fopen("ATR.txt","r");
            if(fscanf(f,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))==EOF)chk=0;//file empty
            else chk=1;
            fclose(f);
            //ensure exact combination of name+date doesnt already exist
            if(chk==0){
                //no need to check just write into file
                f=fopen("ATR.txt","a");
                fprintf(f,"%s %s %d\n",Ai.name,Ai.date,Ai.hours);
                fclose(f);
                printf("Record Added\n");
            }
            else{
                //need to check as some entries already exist
                flag=0;
                f=fopen("ATR.txt","r");
                while(fscanf(f,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))!=EOF){
                    if(check(Ao.name,Ai.name)==0&&check(Ao.date,Ai.date)==0){
                        flag=1;break;//matching record found
                    }
                }
                fclose(f);
                if(flag==0){
                    f=fopen("ATR.txt","a");
                    fprintf(f,"%s %s %d\n",Ai.name,Ai.date,Ai.hours);
                    fclose(f);
                    printf("Record Added\n");
                }
                else{
                    printf("This record already exists,please use modify for this.\n");
                }
            }
        }
        else if(ch==2){
            f=fopen("ATR.txt","r");
            if(fscanf(f,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))==EOF)chk=0;//file empty
            else chk=1;//file not empty
            fclose(f);
            if(chk==0)printf("File is Empty\n");
            else{//forgot to indent here
            //input name
            printf("Enter student name for mod:");
            fflush(stdin);
            scanf("%s",Ai.name);
            if(Ai.name[0]=='0'&&Ai.name[1]=='\0') goto menu;//back to menu option
            //prevent buffer overflow
            r=name_check(Ai.name,10);
            while(r!=0){
                printf("Enter student name for mod:");
                fflush(stdin);
                scanf("%s",Ai.name);
                if(Ai.name[0]=='0'&&Ai.name[1]=='\0') goto menu;//back to menu option
                r=name_check(Ai.name,10);
            }
            //input date
            printf("Enter date dd/mm/yy for mod:");
            fflush(stdin);
            scanf("%s",Ai.date);
            if(Ai.date[0]=='0'&&Ai.date[1]=='\0') goto menu;//back to menu option
            //ensure correct format
            r=date_check(Ai.date,1);
            while(r!=0){
                printf("Enter date dd/mm/yy for mod:");
                fflush(stdin);
                scanf("%s",Ai.date);
                if(Ai.date[0]=='0'&&Ai.date[1]=='\0') goto menu;//back to menu option
                r=date_check(Ai.date,1);
            }
            //check for inputted record
            flag=0;
            f=fopen("ATR.txt","r");
            while(fscanf(f,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))!=EOF){
                if(check(Ao.name,Ai.name)==0&&check(Ao.date,Ai.date)==0){
                    flag=1;break;//matching record found
                }
            }
            fclose(f);
            if(flag==0)printf("No such record found\n");
            else{
                FILE *f1,*f2;
                f1=fopen("ATR.txt","r");
                f2=fopen("temp.txt","w");
                while((fscanf(f1,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))!=EOF)){
                    if(check(Ao.name,Ai.name)==0&&check(Ao.date,Ai.date)==0){
                        //input name
                        printf("Enter new student name:");
                        fflush(stdin);
                        scanf("%s",Ai.name);
                        if(Ai.name[0]=='0'&&Ai.name[1]=='\0') goto menu;//back to menu option
                        //prevent buffer overflow
                        r=name_check(Ai.name,10);
                        while(r!=0){
                            printf("Enter new student name:");
                            fflush(stdin);
                            scanf("%s",Ai.name);
                            if(Ai.name[0]=='0'&&Ai.name[1]=='\0') goto menu;//back to menu option
                            r=name_check(Ai.name,10);
                        }
                        //input date
                        printf("Enter new date dd/mm/yy:");
                        fflush(stdin);
                        scanf("%s",Ai.date);
                        if(Ai.date[0]=='0'&&Ai.date[1]=='\0') goto menu;//back to menu option
                        //ensure correct format
                        r=date_check(Ai.date,1);
                        while(r!=0){
                            printf("Enter new date dd/mm/yy:");
                            fflush(stdin);
                            scanf("%s",Ai.date);
                            if(Ai.date[0]=='0'&&Ai.date[1]=='\0') goto menu;//back to menu option
                            r=date_check(Ai.date,1);
                        }
                        //input hours
                        printf("Enter new number of hours:");
                        fflush(stdin);
                        scanf("%d",&(Ai.hours));
                        if(Ai.hours==0)goto menu;//back to menu option   
                        //ensure valid hours input
                        r=hour_check(Ai.hours);
                        while(r!=0){
                            printf("Enter new number of hours:");
                            fflush(stdin);
                            scanf("%d",&(Ai.hours));
                            if(Ai.hours==0)goto menu;//back to menu option   
                            r=hour_check(Ai.hours);
                        }
                        fprintf(f2,"%s %s %d\n",Ai.name,Ai.date,Ai.hours);
                    }
                    else{
                        fprintf(f2,"%s %s %d\n",Ao.name,Ao.date,Ao.hours);
                    }
                }
                fclose(f1);fclose(f2);
                f1=fopen("ATR.txt","w");
                f2=fopen("temp.txt","r");
                //now just transfer modified data from temp to ATR
                while((fscanf(f2,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))!=EOF)){
                    fprintf(f1,"%s %s %d\n",Ao.name,Ao.date,Ao.hours);
                }
                fclose(f1);fclose(f2);
                printf("Data Modified\n");
            }
            }
        }
        else if(ch==3){
            f=fopen("ATR.txt","r");
            if(fscanf(f,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))==EOF)chk=0;//file empty
            else chk=1;//file not empty
            fclose(f);
            if(chk==0)printf("File is Empty\n");
            else{//forgot to indent here
            //input name
            printf("Enter student name for removal:");
            fflush(stdin);
            scanf("%s",Ai.name);
            if(Ai.name[0]=='0'&&Ai.name[1]=='\0') goto menu;//back to menu option
            //prevent buffer overflow
            r=name_check(Ai.name,10);
            while(r!=0){
                printf("Enter student name for removal:");
                fflush(stdin);
                scanf("%s",Ai.name);
                if(Ai.name[0]=='0'&&Ai.name[1]=='\0') goto menu;//back to menu option
                r=name_check(Ai.name,10);
            }
            //input date
            printf("Enter date dd/mm/yy for removal:");
            fflush(stdin);
            scanf("%s",Ai.date);
            if(Ai.date[0]=='0'&&Ai.date[1]=='\0') goto menu;//back to menu option
            //ensure correct format
            r=date_check(Ai.date,1);
            while(r!=0){
                printf("Enter date dd/mm/yy for removal:");
                fflush(stdin);
                scanf("%s",Ai.date);
                if(Ai.date[0]=='0'&&Ai.date[1]=='\0') goto menu;//back to menu option
                r=date_check(Ai.date,1);
            }
            //check for inputted record
            flag=0;
            f=fopen("ATR.txt","r");
            while(fscanf(f,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))!=EOF){
                if(check(Ao.name,Ai.name)==0&&check(Ao.date,Ai.date)==0){
                    flag=1;break;//matching record found
                }
            }
            fclose(f);
            if(flag==0)printf("No such record found\n");
            else{
                FILE *f1,*f2;
                f1=fopen("ATR.txt","r");
                f2=fopen("temp.txt","w");
                while((fscanf(f1,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))!=EOF)){
                    if(check(Ao.name,Ai.name)==0&&check(Ao.date,Ai.date)==0);
                    else{
                        fprintf(f2,"%s %s %d\n",Ao.name,Ao.date,Ao.hours);
                    }
                }
                fclose(f1);fclose(f2);
                f1=fopen("ATR.txt","w");
                f2=fopen("temp.txt","r");
                //now just transfer data from temp to ATR
                //temp contains all data except removed data
                while((fscanf(f2,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))!=EOF)){
                    fprintf(f1,"%s %s %d\n",Ao.name,Ao.date,Ao.hours);
                }
                fclose(f1);fclose(f2);
                printf("Record Removed\n");
            }
            }
        }
        else if(ch==4){
            char dt[8];
            //input date
            printf("Enter date dd/mm/yy for display:");
            fflush(stdin);
            scanf("%s",dt);
            if(dt[0]=='0'&&dt[1]=='\0') goto menu;//back to menu option
            //ensure correct format
            r=date_check(dt,1);
            while(r!=0){
                printf("Enter date dd/mm/yy for display:");
                fflush(stdin);
                scanf("%s",dt);
                if(dt[0]=='0'&&dt[1]=='\0') goto menu;//back to menu option
                r=date_check(dt,1);
            }
            search_date(dt);
        }
        else if(ch==5){
            //variables created in else if block have local scope
            char sdate[5];//date for display
            printf("Enter mm/yy for display:");
            fflush(stdin);
            scanf("%s",sdate);
            if(sdate[0]=='0'&&sdate[1]=='\0') goto menu;//back to menu option
            r=date_check(sdate,2);
            while(r!=0){
                printf("Enter mm/yy for display:");
                fflush(stdin);
                scanf("%s",sdate);
                if(sdate[0]=='0'&&sdate[1]=='\0') goto menu;//back to menu option
                r=date_check(sdate,2);
            }
            FILE *f1,*f2;int flag=0;//first entry into temp.txt
            f1=fopen("ATR.txt","r");
            char tname[10];//for temp
            //the & caused so much trouble 
            while(fscanf(f1,"%s%s%d",Ai.name,Ai.date,&(Ai.hours))!=EOF){
                if(flag==0){//first entry into temp
                    f2=fopen("temp.txt","w");
                    flag=1;
                    fprintf(f2,"%s\n",Ai.name);fclose(f2);
                }
                else{//need to check if name exists in temp as temp isnt empty
                    f2=fopen("temp.txt","r");int checker=0;
                    while(fscanf(f2,"%s",tname)!=EOF){
                        if(check(tname,Ai.name)==0){
                            checker=1;break;//name exists in temp
                        }
                    }      
                    fclose(f2);
                    if(checker==0){
                        f2=fopen("temp.txt","a");
                        fprintf(f2,"%s\n",Ai.name);
                        fclose(f2);
                    }
                }
            }
            fclose(f1);
            //calculation of hours per student on given date
            printf("-----------------------------------------------------\n");
            f2=fopen("temp.txt","r");
            while(fscanf(f2,"%s",Ai.name)!=EOF){
                int hrs=0;
                f1=fopen("ATR.txt","r");//open it every time!
                while(fscanf(f1,"%s%s%d",Ao.name,Ao.date,&(Ao.hours))!=EOF){
                    if(check(Ai.name,Ao.name)==0){
                        int j,ind=0,res=0;//ind is index for sdate
                        for(j=3;j<8;j++){
                            if(sdate[ind]!=(Ao.date)[j]){
                                res=1;break;
                            }
                            ind++;
                        }
                        if(res==0)hrs+=Ao.hours;//date matches      
                    }
                }
                fclose(f1);
                //we want to display only those who had class in that month
                if(hrs!=0)printf("Name:%s\tHours:%d\tNet Fee:%d\n",Ai.name,hrs,hrs*500);    
            }
            printf("-----------------------------------------------------\n");
            fclose(f2);
        }
        else if(ch==6){
            printf("-----------------------------------------------------\n");
            printf("Entire content stored:\n");
            FILE *f;
            f=fopen("ATR.txt","r");
            while(fscanf(f,"%s%s%d",Ai.name,Ai.date,&(Ai.hours))!=EOF){
                printf("Name:%s\tDate:%s\tHours:%d\n",Ai.name,Ai.date,Ai.hours);
            }
            fclose(f);
            printf("-----------------------------------------------------\n");
        }
        else if(ch==7){
            Sleep(1000);//1 second pause
            system("cls");//clear screen
        }
        else if(ch==8){
            printf("-----------------------------------------------------\n");
            printf("The Guidelines of this program are as follows:\n");
            printf("-->While entering student name kindly enter only one word without any space.\n");
            printf("-->The entire program is case sensitive.\n");
            printf("-->Kindly follow the formats for dates as mentioned when accepting input.\n");
            printf("-->To jump to Main Menu at any point in program,enter 0.\n");
            printf("-----------------------------------------------------\n");
        }
        else if(ch==9){
           printf("EXITED\n");
           Sleep(1000);
           system("cls");
           break;
        }
        else printf("Invalid Option Number\n");
    menu:
         printf("\n");//back to menu
    }
    return 0;
}


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

void search_date(char *d){
    student A;
    FILE *f;int flag=0;
    f=fopen("ATR.txt","r");
    while(fscanf(f,"%s%s%d",A.name,A.date,&(A.hours))!=EOF){
        if(check(d,A.date)==0)flag=1;//record found
    }
    fclose(f);
    if(flag==0){
        printf("No records exist on inputted date\n");
    }
    else{
        printf("-----------------------------------------------------\n");
        f=fopen("ATR.txt","r");
        printf("All records for date %s:\n",d);
        while(fscanf(f,"%s%s%d",A.name,A.date,&(A.hours))!=EOF){
            if(check(d,A.date)==0)printf("Name:%s  Hours:%d\n",A.name,A.hours);    
        } 
        printf("-----------------------------------------------------\n");
        fclose(f);
    }
}