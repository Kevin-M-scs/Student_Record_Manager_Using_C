
int check(char *str1,char *str2);
int date_check(char *d,int c);
int name_check(char *s,int n);
int hour_check(int hr);
void search_date(char *d);

typedef struct{
    char name[10];
    char date[8];
    int hours;
}student;
