/* Use admin as a user name and admin as a password
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
int Ns, Nt;
char auser_name[]="admin";
char apassword[]="admin";
struct student{
char name[50];
int roll;
char address[50];
char mobile[20];
char email[30];
int marks[100][100];
char password[50];
//student structure
};
struct teacher{
char name[50];
char mobile[20];
char email[30];
char course[100][50];
char password[50];
int total_course;
}; //Teacher structure
void menu(){
char ch;
FILE *fptr;
char user_name[50];
char pass[50];
int r,i,x,flag=0;
int num[2]; // Main menu of the program
system("cls");
printf("\n\t\tWelcome to Department Management System.\n");
printf("\n\t#####################################################\n\n"
);
printf("1. Admin Panel\n");
printf("2. Teacher Panel\n");
printf("3. Student Panel\n");
printf("Enter your choice : ");
int c;
scanf("%d",&c);
fptr = fopen("record.bin","rb+");
fscanf(fptr,"%d",&Nt);
struct teacher tech[Nt];
fread(&tech,sizeof(tech),1,fptr );fscanf(fptr,"%d",&Ns);
struct student stud[Ns];
fread(&stud,sizeof(stud),1,fptr );
if(c==1){
system("cls");
printf("Admin Panel\n");
printf("Enter Name: ");
fflush(stdin);
gets(user_name);
printf("Enter password: ");
fflush(stdin);
gets(pass);
if(strcmp(user_name,auser_name)==0 &&
strcmp(pass,apassword)==0){
flag=1;
}
if(flag==1){
system("cls");
admin();
}
else{
system("cls");
printf("Wrong Username or Password! Press any key to
continue...\n");
getchar();
menu();
}
}
else if(c==2){
jump3:
system("cls");
printf("Teacher Panel\n");
printf("Enter Name: ");
fflush(stdin);
gets(user_name);
printf("Enter password: ");
fflush(stdin);
gets(pass);
for( i=0;i<Nt;i++){
if(strcmp(user_name,tech[i].name)==0 &&
strcmp(pass,tech[i].password)==0){
flag=1;
x=i;
}
}
if(flag==1){
system("cls");
fclose(fptr);
teacher_panel(x);
}
else{
system("cls");
printf("Wrong Username or Password!\n Press any key to
continue...\n ");
getchar();
menu();
}}
else if(c==3){
system("cls");
printf("Student Panel");
printf("Enter Name: ");
fflush(stdin);
gets(user_name);
printf("Enter password: ");
fflush(stdin);
gets(pass);
for( i=0;i<Ns;i++){
if(strcmp(user_name,stud[i].name)==0 &&
strcmp(pass,stud[i].password)==0){
flag=1;
x=i;
}
}
if(flag==1){
system("cls");
fclose(fptr);
student_panel(x);
}
else{
system("cls");
printf("Wrong Username or Password!\n Press any key to
continue...\n ");
getchar();
menu();
}
}
else
menu();
}
void admin()
{
// Admin panel function
printf("\n\t\tWelcome to Admin Panel.\n");
printf("\n\t***********************************\n\n");
printf("1. Update Teachers & Students Information\n");
printf("2. Assign Courses To Teachers & Update.\n");
printf("3. Go Back.\n");
printf("Enter your choice : ");
int c;
scanf("%d",&c);
switch(c){
case 1:
system("cls");
update();
break;
case 2:
system("cls");
assigning();
break;
case 3:
system("cls");
menu();
break;}
default:
system("cls");
admin();
break;
}
void teachers()
{
system("cls");
char ch;
//Adding teacher info to record function
FILE *fptr;
fptr = fopen("record.bin","wb+");
if(fptr == NULL){
printf("Error!");
exit(1);
}
printf("Admin Panel\n");
printf("Create Teachers Account\n");
printf("Press any key to continue... \n");
getchar();
system("cls");
printf("Admin Panel\n");
printf("How many teacher do you want to add: ");
scanf("%d",&Nt);
fprintf(fptr,"%d",Nt);
system("cls");
struct teacher tech[Nt];
for(int i=0;i<Nt;i++){
printf("Teacher Account.\n");
printf("Enter name: ");
fflush(stdin);
gets(tech[i].name);
printf("Enter mobile: ");
fflush(stdin);
gets(tech[i].mobile);
printf("Enter E-mail: ");
fflush(stdin);
gets(tech[i].email);
printf("Enter New Password: ");
fflush(stdin);
gets(tech[i].password);
system("cls");
}
fwrite(&tech, sizeof(tech), 1, fptr);
fclose(fptr);
printf("Done!\n Press enter to continue.... \n");
getchar();
students();
}
void students()
{
system("cls");
char ch;
FILE *fptr;fptr = fopen("record.bin","ab+");
if(fptr == NULL){
printf("Error!");
exit(1);
}
printf("Admin Panel\n");
printf("Create Students Account\n");
printf("Press any key to continue...\n ");
getchar();
system("cls");
printf("Admin Panel\n");
printf("How many Student do you want to add: ");
scanf("%d",&Ns);
fprintf(fptr,"%d",Ns);
system("cls");
struct student stud[Ns];
for(int i=0;i<Ns;i++){
printf("Student Account\n");
printf("Enter name: ");
fflush(stdin);
gets(stud[i].name);
printf("Enter Roll: ");
fflush(stdin);
scanf("%d",&stud[i].roll);
printf("Enter E-mail: ");
fflush(stdin);
gets(stud[i].email);
printf("Enter Mobile: ");
fflush(stdin);
gets(stud[i].mobile);
printf("Enter Address: ");
fflush(stdin);
gets(stud[i].address);
printf("Enter Password: ");
fflush(stdin);
gets(stud[i].password);
system("cls");
}
fwrite(&stud, sizeof(stud), 1, fptr);
fclose(fptr);
printf("Done!\nPress Enter to continue.. \n");
system("cls");
menu();
}
void update()
{
    char ch;
    FILE *fptr;
    char tname[20];
    int r;
    fptr = fopen("record.bin","rb+");
    printf("Update Teachers & Students Information\n");
    int c;
    printf("1. Update Teacher Information\n");
    printf("2. Update Student Information\n");
    printf("3. Go Back\n");
    printf("Enter your choice : ");scanf("%d",&c);
    if(c==1){
        system("cls");
        printf("Update Teacher Information\n");
        printf("Search Teacher by Full Name: ");
        fflush(stdin);
        gets(tname);
        fscanf(fptr,"%d",&Nt);
        struct teacher tech[Nt];
        fread(&tech,sizeof(tech),1,fptr );
        system("cls");
        for(int i=0;i<Nt;i++)
        {
            if((strcmp(tname,tech[i].name)) == 0){
                printf("Update Teacher Information\n");
                printf("Enter name: ");
                fflush(stdin);
                gets(tech[i].name);
                printf("Enter mobile: ");
                fflush(stdin);
                gets(tech[i].mobile);
                printf("Enter E-mail: ");
                fflush(stdin);
                gets(tech[i].email);
                printf("Enter New Password: ");
                fflush(stdin);
                gets(tech[i].password);
                system("cls");
            }
        }
        fseek(fptr ,-sizeof(tech),SEEK_CUR);
        fwrite(&tech, sizeof(tech), 1, fptr);
        printf("Update Teacher Information\n");
        printf("Press any key to continue... \n");
        getchar();
        fclose(fptr);
        update();
    }
    else if(c==2){
        system("cls");
        printf("Update Student Information\n");
        printf("Search Student by Roll: ");
        scanf("%d",&r);
        system("cls");
        fscanf(fptr,"%d",&Nt);
        struct teacher tech[Nt];
        fread(&tech,sizeof(tech),1,fptr );
        fscanf(fptr,"%d",Ns);
        struct student stud[Ns];
        fread(&stud,sizeof(stud),1,fptr );
        for(int i=0;i<Ns;i++){
            if(r==stud[i].roll){
                printf("Update Student Information");
                fflush(stdin);
                printf("Enter name: ");
                gets(stud[i].name);
                printf("Enter Roll: ");
                scanf("%d",&stud[i].roll);
                printf("Enter E-mail: ");
                fflush(stdin);
                gets(stud[i].email);
                printf("Enter Mobile: ");
                fflush(stdin);
                gets(stud[i].mobile);
                printf("Enter Address: ");
                fflush(stdin);
                gets(stud[i].address);
                printf("Enter Password: ");
                fflush(stdin);
                gets(stud[i].password);
                system("cls");
            }
        }
        fseek(fptr ,-sizeof(stud),SEEK_CUR);
        fwrite(&stud, sizeof(stud), 1, fptr);
        printf("Update Student Information\n");
        printf("Press any key to continue...\n ");
        getchar();
        fclose(fptr);
        update();
    }
    else if(c==3){
        system("cls");
        fclose(fptr);
        admin();
    }
    else{
        system("cls");
        fclose(fptr);
        update();
    }
}
void assigning()
{
    char ch;
    char tname[20];
    int c;
    FILE *fptr;
    fptr = fopen("record.bin","rb+");
    fscanf(fptr,"%d",&Nt);
    struct teacher tech[Nt];
    fread(&tech,sizeof(tech),1,fptr );
    printf("Assign & Update Courses to the Teachers\n");printf("1.Assign Courses\n");
    printf("2. Update Courses\n");
    printf("3. Go Back\n");
    printf("Enter your choice (i.g enter number) : ");
    scanf("%d",&c);
    if(c==1){
        if(fptr == NULL)
        {
            printf("Error!\n");
            admin();
        }
        system("cls");
        for(int i=0;i<Nt;i++){
            printf("Assign Courses\n");
            printf("How courses you want add for %s: ",tech[i].name);
            scanf("%d",&tech[i].total_course);
            system("cls");
            for(int j=0;j<tech[i].total_course;j++){
                printf("Assign Courses\n");
                printf("Assign Course for %s: ",tech[i].name);
                fflush(stdin);
                gets(tech[i].course[j]);
                system("cls");
            }
        }
        fseek(fptr ,-sizeof(tech),SEEK_CUR);
        fwrite(&tech, sizeof(tech), 1, fptr);
        fclose(fptr);
        system("cls");
        printf("Done! Press Enter to continue...\n");
        getchar();
        admin();
    }
    else if(c==2){
        jump:
        if(fptr == NULL){
            printf("Error!");
            admin();
        }
        system("cls");
        printf("Update Course\n");
        printf("Search Teacher by Full Name: ");
        fflush(stdin);
        gets(tname);
        for(int i=0;i<Nt;i++){
            if((strcmp(tname,tech[i].name)) == 0){
                system("cls");
                printf("Update Course\n");
                printf("Assign New Course for %d. %s: ",i+1,tech[i].name);
                fflush(stdin);
                gets(tech[i].course);
                system("cls");
            }
        }
        jump2:
        printf("Assign Courses\n");printf("Updating Again? Y/N :\t");
        scanf("%c",&ch);
        if(ch=='Y'){
            goto jump;
        }
        else if(ch=='N'){
            system("cls");
            fclose(fptr);
            admin();
        }
        else{
            system("cls");
            goto jump2;
        }
        fseek(fptr ,-sizeof(tech),SEEK_CUR);
        fwrite(&tech, sizeof(tech), 1, fptr);
        fclose(fptr);
        }
    }
    else if(c==3){
        system("cls");
        fclose(fptr);
        admin();
    }
}
void teacher_panel( int x)
{
    FILE *fptr;
    int c,i,j=0;
    char ch;
    char name[20];
    jump:
    system("cls");
    printf("Teachers Panel\n");
    printf("1. Provide Class Test Marks\n");
    printf("2. Find Student\n");
    printf("3. Count of Student\n");
    printf("4. Go Back\n");
    printf("Enter your choice) : ");
    scanf("%d",&c);
    fptr = fopen("record.bin","rb+");
    fscanf(fptr,"%d",&Nt);
    struct teacher tech[Nt];
    fread(&tech,sizeof(tech),1,fptr );
    fscanf(fptr,"%d",&Ns);
    struct student stud[Ns];
    fread(&stud,sizeof(stud),1,fptr );
    if(c==1){
        system("cls");
        for(i=0;i<Ns;i++){
            system("cls");
            printf("Provide Class Test Marks\n");
            printf("Class Test Mark for Roll-%d: ",stud[i].roll);
            for( j=0;j<tech[x].total_course;j++){
                printf("%s:",tech[x].course[j]);
                scanf("%d",&stud[i].marks[x][j]);
            }
        }
        fseek(fptr ,-sizeof(stud),SEEK_CUR);
        fwrite(&stud, sizeof(stud), 1, fptr);
        fclose(fptr);
        system("cls");
        printf("Done! Press Enter to continue... /n");
        getchar();
        goto jump;
    }
    else if(c==2){
        system("cls");
        printf("Find Student/n");
        printf("Search Student by First Name: ");
        fflush(stdin);
        gets(name);
        for( i=0;i<Ns;i++){
            if(compare(stud[i].name,name)){
                system("cls");
                printf("Name: %s\t",stud[i].name);
                printf("Roll: %d\t",stud[i].roll);
                printf("Address: %s\t",stud[i].address);
                printf("Mobile: %s\t",stud[i].mobile);
                printf("Email: %s\n", stud[i].email);
                printf("Class Test Marks:");
                for( j=0;j<tech[x].total_course;j++){
                    printf("%s:",tech[x].course[j]);
                    printf("%d",stud[i].marks[x][j]);
                    printf("Press Enter to continue... \n");
                    getchar();
                    goto jump;
                }
            }
            if(j==0){
                printf("No match found! Press enter to continue.../n ");
                getchar();
                goto jump;
            }
        }
    }
    else if(c==3){
        system("cls");
        printf("Count of Student\n");
        printf("Total Students: %d\n",Ns);
        printf("Press enter to continue... \n");
        getchar();
        goto jump;
    }
    else if(c==4){
        system("cls");
        menu();
    }
    else{
        goto jump;
    }
}
void student_panel(int x)
{
    int c;
    FILE *fptr;
    fptr = fopen("record.bin","rb+");
    if(fptr == NULL){
        printf("Error! Pess enter to continue....\n");
        getchar();
        menu();
    }
    fscanf(fptr,"%d",&Nt);
    struct teacher tech[Nt];
    fread(&tech,sizeof(tech),1,fptr );
    fscanf(fptr,"%d",&Ns);
    struct student stud[Ns];
    fread(&stud,sizeof(stud),1,fptr );
    system("cls");
    printf("1. Check Test Marks\n");
    printf("Enter your choice : ");
    scanf("%d",&c);
    if(c==1){
        system("cls");
        printf("Test Marks\n");
        printf("Name: %s\n",stud[x].name);
        printf("Roll: %d\n",stud[x].roll);
        printf("\n");
        printf("Test marks are: ");
        printf("\n");
        for(int i=0;i<Nt;i++){
            for(int j=0;j<tech[i].total_course;j++){
                printf("%s: %d \n",tech[i].course[j],stud[x].marks[i][j]);
            }
        }
    }
    fclose(fptr);
    printf("\n");
    printf("Press Enter to continue...\n ");
    getchar();
    menu();
}
int compare(char a[],char b[])
{
    int flag=0,i=0;
    while(a[i]!=' '){
        if(a[i]!=b[i]){
            flag=1;
            break;
        }
        i++;
    }
    if (flag==0)
        return 1;
    else
        return 0;
}
// function for comparision two}
int main()
{
    FILE *fptr;
    char user_name[20];
    char pass[20];
    fptr=fopen("record.bin","r");
    if(fptr==NULL){
        jump:
        system("cls");
        printf("\n\t\tWelcome to Department Management System.\n");
        printf("\n\t#####################################################\n\n"
        );
        printf("Admin Panel\n");
        printf("Enter Name: ");
        fflush(stdin);
        gets(user_name);
        printf("Enter password: ");
        fflush(stdin);
        gets(pass);
        if(strcmp(user_name,auser_name)==0 && strcmp(pass,apassword)==0){
            teachers();
        }
        else{
            goto jump;
        }
    }
    else{
        printf("\n\t\tWelcome to Department Management System.\n");
        printf("\n\t#####################################################\n\n");
        menu();
    }
}
