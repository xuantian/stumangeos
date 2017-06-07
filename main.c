#include <stdio.h>
#include <stdlib.h>
#define NUNM 30
#define NUMC 6
#define LENNM 20
typedef struct student
{
    long studentID;
    char  name[LENNM];
    float score[NUMC];
    float sum;
    float aver;
    int rank;

} STUDENT;
void menu();
void InputRecord(STUDENT stud[],int n, int c);
int AverCourse(STUDENT stud[],int n, int c);
int AverStudent(STUDENT stud[],int n, int c);
void ListRecord(STUDENT stud[],int n, int c);
void DescendSort(STUDENT stud[],int n, int c);
void AscendSort(STUDENT stud[],int n, int c);
void FileWrite(STUDENT stud[],int n, int c);
void SearchNum(STUDENT stud[],int n, int c);
void SearchName(STUDENT stud[],int n, int c);
void NumSort(STUDENT stud[],int n, int c);
void NameSort(STUDENT stud[],int n, int c);
void AnaStatistic(STUDENT stud[],int n, int c);
void ReadPut(STUDENT stud[],int n, int c);


int main()
{
    int c,n,x;
    STUDENT str[NUNM];
    printf("Enter the number of students(n<=%d):\n",NUNM);
    scanf("%d",&n);
    printf("Enter the number of courses(c<=%d):\n",NUMC);
    scanf("%d",&c);
    while(1)
    {
        printf("Please enter your choice:\n");
        menu();
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            InputRecord(str,n,c);
            break;
        case 2:
            AverCourse(str,n,c);
            break;
        case 3:
            AverStudent(str,n,c);
            break;
        case 4:
            DescendSort(str,n,c);
            break;
        case 5:
            AscendSort(str,n,c);
            break;
        case 6:
            NumSort(str,n,c);
            break;
        case 7:
            NameSort(str,n,c);
            break;
        case 8:
            AverStudent(str,n,c);
            SearchNum(str,n,c);
            break;
        case 9:
            AverStudent(str,n,c);
            SearchName(str,n,c);
            break;
        case 10:
            AnaStatistic(str,n,c);
            break;
        case 11:
            ListRecord(str,n,c);
            break;
        case 12:
            FileWrite(str,n,c);
            break;
        case 13:
            ReadPut(str,n,c);
            ListRecord(str,n,c);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("error");
        }
    }

}
void menu()
{
    printf("1. Input record\n");
    printf("2. Caculate total and average score of every course\n");
    printf("3. Caculate total and average score of every student\n");
    printf("4. Sort in descending order by total score of every student\n");
    printf("5. Sort in ascending order by total score of every student\n");
    printf("6. Sort in ascending order by number\n");
    printf("7. Sort in dictionary oeder by name\n");
    printf("8. Search by number\n");
    printf("9. Search by name\n");
    printf("10. Satistic analysis for every course\n");
    printf("11. List record\n");
    printf("12. Write to a file\n");
    printf("13. Read from a file\n");
    printf("0. Exit\n");
}
/*
1����ѧ��ѧ�������ɼ�
*/
void InputRecord(STUDENT stud[],int n, int c)
{
    int i,k;
    printf("Enter the name,ID and every course score of student");
    for(i=0; i<n; i++)
    {
        scanf("%s",&stud[i].name);
        scanf("%ld",&stud[i].studentID);
        for(k=0; k<c; k++)
        {
            scanf("%f",&stud[i].score[k]);
        }
    }
}
/*
2����ÿ�ſγ��ֺܷ�ƽ����
*/
int AverCourse(STUDENT stud[],int n, int c)
{
    int i,k;
    float sum[NUNM]= {0},aver[NUNM]= {0};
    for(i=0; i<c; i++)
    {
        for(k=0; k<n; k++)
        {
            sum[i]=sum[i]+stud[k].score[i];
        }
        if(n>0)
            aver[i]=sum[i]/n;
        else
            aver[i]=0;

        printf("course%d total course%.1f average course%.1f\n",i+1,sum[i],aver[i]);
    }
}

/*
3����ÿ��ѧ���γ��ֺܷ�ƽ����
*/
int AverStudent(STUDENT stud[],int n, int c)
{
    int i,k;
    for(i=0; i<n; i++)
    {
        stud[i].sum=0;
        for(k=0; k<c; k++)
        {
            stud[i].sum+=stud[i].score[k];
        }
        if(c>0)
            stud[i].aver=stud[i].sum/c;
        else
            stud[i].sum=0;
        printf("studen%stotal course%.1f average course%.1f\n",stud[i].name,stud[i].sum,stud[i].aver);
    }
}
/*
4�ߵ���������
*/
void DescendSort(STUDENT stud[],int n, int c)
{
    int i,j,k;
    STUDENT temp[NUNM],p;
    for(i=0; i<n; i++)
    {
        temp[i]=stud[i];
    }
    for(i=0; i<n-1; i++)
    {
        for(j=n+1; j<n; j++)
        {
            if(temp[j].sum<temp[i].sum)
            {
                p=temp[i];
                temp[i]=temp[j];
                temp[j]=p;
            }
        }

    }
    for(i=0; i<n; i++)
    {
        for(k=0; k<n; k++)
        {
            if(temp[i].studentID==stud[k].studentID)
            {
                stud[k].rank=i+1;
                break;
            }

        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d%s\t%ld\t%.1f\t%.1f",i+1,temp[i].name,temp[i].studentID,temp[i].sum,temp[i].aver);
        for(k=0; k<c; k++)
        {
            printf("%.1f",temp[i].score[k]);
        }
        printf("\n");
    }
}
/*
5�͵���������
*/
void AscendSort(STUDENT stud[],int n, int c)
{
    int i,k;
    STUDENT temp[NUNM],p;
    for(i=0; i<n; i++)
    {
        temp[i]=stud[i];
    }
    for(k=0; k<n-1; k++)
    {
        for(k=n+1; k<n; k++)
        {
            if(temp[k].studentID>temp[i].sum)
            {
                p=temp[i];
                temp[i]=temp[k];
                temp[k]=p;
            }
        }

    }
    for(i=0; i<n; i++)
    {
        printf("%d%s\t%ld\t%.1f\t%.1f",i+1,temp[i].name,temp[i].studentID,temp[i].sum,temp[i].aver);
        for(k=0; k<c; k++)
        {
            printf("%.1f",temp[i].score[k]);
        }
        printf("\n");
    }
}
/*
6ѧ���ű�
*/
void NumSort(STUDENT stud[],int n, int c)
{
    int i,j,k;
    STUDENT temp[NUNM],p;
    for(i=0; i<n; i++)
    {
        temp[i]=stud[i];
    }
    for(i=0; i<n-1; i++)
    {
        for(j=n+1; j<n; j++)
        {
            if(temp[j].studentID>temp[i].studentID)
            {
                p=temp[i];
                temp[i]=temp[j];
                temp[j]=p;
            }
        }

    }
    for(i=0; i<n; i++)
    {
        printf("%d%s\t%ld\t%.1f\t%.1f",i+1,temp[i].name,temp[i].studentID,temp[i].sum,temp[i].aver);
        for(k=0; k<c; k++)
        {
            printf("%.1f",temp[i].score[k]);
        }
        printf("\n");
    }
}
/*
7�����ֵ�����
*/
void NameSort(STUDENT stud[],int n, int c)
{
    int i,j,k;
    STUDENT temp[NUNM],p;
    for(i=0; i<n; i++)
    {
        temp[i]=stud[i];
    }
    for(j=0; j<n-1; j++)
    {
        for(j=i+1; j<n; j++)
            if(strcmp(temp[j].name,temp[i].name)<0)
            {
                p=temp[i];
                temp[i]=temp[j];
                temp[j]=p;
            }

    }
    for(i=0; i<n; i++)
    {
        printf("%d%s\t%ld\t%.1f\t%.1f",i+1,temp[i].name,temp[i].studentID,temp[i].sum,temp[i].aver);
        for(k=0; k<c; k++)
        {
            printf("%.1f",temp[i].score[k]);
        }
        printf("\n");
    }
}
/*
8ѧ�Ų�ѯ
*/
void SearchNum(STUDENT stud[],int n, int c)
{
    long number;
    int i,k;
    printf("Input id of student:");
    scanf("%ld",&number);
    for(i=0; i<n; i++)
    {
        if(stud[i].studentID==number)
        {
            printf("%ld\t%s\t",stud[i].studentID,stud[i].name);
            for(k=0; k<c; k++)
            {
                printf("%.1f",stud[i].score[k]);
            }
            printf("%.1f\t%.1f\n",stud[i].sum,stud[i].aver);
        }
    }
    printf("Can not find it\n");
}
/*
9������ѯ
*/
void SearchName(STUDENT stud[],int n, int c)
{
    char x[LENNM];
    int i,k;
    printf("Input name:");
    scanf("%s",x);
    for(i=0; i<n; i++)
    {
        if(strcmp(stud[i].name,x)==0)
        {
            printf("%ld\t%s\t",stud[i].studentID,stud[i].name);
            for(k=0; k<c; k++)
            {
                printf("%.1f\t",stud[i].score[k]);
            }
            printf("%.1f\t%.1f\n",stud[i].sum,stud[i].aver);
        }
    }
    printf("Can not find it\n");

}
/*
10ѧ��ͳ��
*/
void AnaStatistic(STUDENT stud[],int n, int c)
{
    int i,k;
    float pi[5][5]= {0};
    for(k=0; k<c; k++)
    {
        for(i=0; i<n; i++)
        {
            if(stud[i].score[k]<=100&&stud[i].score[k]>=90)
                pi[k][0]++;
            else if(stud[i].score[k]<=89&&stud[i].score[k]>=80)
                pi[k][1]++;
            else if(stud[i].score[k]<=79&&stud[i].score[k]>=70)
                pi[k][2]++;
            else if(stud[i].score[k]<=69&&stud[i].score[k]>=60)
                pi[k][3]++;
            else pi[k][4]++;
        }
    }
    for(k=0; k<c; k++)
    {
        printf("course %d %.1f%\t%.1f%\t%.1f%\t%.1f%\t%.1f%\n",k+1,pi[k][0]/n*100,pi[k][1]/n*100,pi[k][2]/n*100,pi[k][3]/n*100,pi[k][4]/n*100);
    }
}
/*
11�����Ϣ
*/
void ListRecord(STUDENT stud[],int n, int c)
{
    int i,k;
    for(i=0; i<n; i++)
    {
        printf("%ld %s\t",stud[i].studentID,stud[i].name);
        for(k=0; k<c; k++)
        {
            printf("%.1f\t",stud[i].score[k]);
        }
        printf("%.1f %.1f \n",stud[i].sum,stud[i].aver);
    }
}

/*
12�洢��Ϣ
*/
void FileWrite(STUDENT stud[],int n, int c)
{
    FILE *fp;
    int i,k;
    if((fp=fopen("studentinfo.txt","w"))==NULL)
    {
        printf("Fail to open studentinfo.txt.\n");
        exit(0);
    }
    fprintf(fp,"number%d\tcourse%d\n",n,c);
    for(i=0; i<n; i++)
    {
        fprintf(fp,"%ld\t%s\t",stud[i].studentID,stud[i].name);
        for(k=0; k<c; k++)
        {
            fprintf(fp,"%.1f\t",stud[i].score[k]);
        }
        fprintf(fp,"%.1f\t%.1f\n",stud[i].sum,stud[i].aver);
    }
    fclose(fp);
}
/*
13��ȡ��Ϣ����ʾ
*/
void ReadPut(STUDENT stud[],int n, int c)
{
    FILE *fp;
    int i,k;
    if((fp = fopen("studentinfo.txt","r"))==NULL)
    {
        printf("Can not open the file.\n");
        exit(0);
    }
    fscanf(fp,"number%d\tcourse%d\n",&n,&c);
    for(i=0; i<n; i++)
    {
        fscanf(fp,"%ld\t%s\t",&stud[i].studentID,&stud[i].name);
        for(k=0; k<c; k++)
        {
            fscanf(fp,"%.1f\t",&stud[i].score[k]);
        }
        fscanf(fp,"%.1f\t%.1f\n",&stud[i].sum,&stud[i].aver);
    }
    fclose(fp);
}