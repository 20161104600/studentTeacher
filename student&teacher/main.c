//
//  main.c
//  student&teacher
//
//  Created by 20161104600 on 18/6/25.
//  Copyright © 2018年 20161104600. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <string.h>
#define MAXSIZE 30
struct Student
{
    char name[10];
    char sex[3];
    char proname[10];
    char protype[10];
    int num;
    char class[10];
    int Score;
};
typedef struct Student ElemTypeS;

typedef struct
{
    ElemTypeS elem[MAXSIZE];
    int lastS;
}SeqListS;

struct Teacher
{
    char name[10];
    char sex[3];
    int num;
    int Score;
};
typedef struct Teacher ElemTypeT;

typedef struct
{
    ElemTypeT elem[MAXSIZE];
    int lastT;
}SeqListT;

int load(SeqListT *L)//写入读取
{
    FILE * fp;
    fp=fopen("Users/a20161104600/Desktop/Student/student\&teacher/student\&teacher/student.csv ","r+");
    if(fp==NULL)
    {
        printf("没有这个文件！\n");
        return 0;
    }
    else if(fp!=NULL)
    {
        int i,j;
        char name[10];
        int num,MScore,CScore,EScore,Score;
        //fscanf(fp,"|  –Ú∫≈  |  –’√˚  |   —ß∫≈   |   ˝—ß  |  ”ÔŒƒ  |  ”¢”Ô  | ◊‹≥…º® |\n");
        //fscanf(fp,"|--------|--------|----------|--------|--------|--------|--------|\n");
        //ElemType X;
        while(fscanf(fp,"%d,%s,%d,%d,%d,%d,%d\n",&j,name,&num,&MScore,&CScore,&EScore,&Score)!=EOF)
        {
            i=j-1;
            strcpy(L->elem[i].name,name);
            L->elem[i].num=num;
            L->elem[i].MathScore=MScore;
            L->elem[i].ChinaseScore=CScore;
            L->elem[i].EnglishScore=EScore;
            L->elem[i].Score=Score;
            //printf("|%-8d|%-8s|%-10d|%-8d|%-8d|%-8d|%-8d|\n",i+1,L->elem[i].name,L->elem[i].num,L->elem[i].MathScore,L->elem[i].ChinaseScore,L->elem[i].EnglishScore,L->elem[i].Score);
            L->last++;
        } 
        printf("        Œƒº˛∂¡»°≥…π¶\n\n");
        fclose(fp);	
    }
    return 0;
}

char menu()
{
    int input;
    printf("\n");
    printf("         |************评分系统*************|        \n");
    printf("         |--------------------------------|        \n");
    printf("         |            菜单选项             |        \n");
    printf("         |--------------------------------|        \n");
    printf("         |    1---输入                    |        \n");
    printf("         |    2---增加                    |        \n");
    printf("         |    3---删除                    |        \n");
    printf("         |    4---修改                    |        \n");
    printf("         |    5---查找                    |        \n");
    printf("         |    6---评分                    |        \n");
    printf("         |    7---在文件中读取              |        \n");
    printf("         |    8---保存到文件中              |        \n");
    printf("         |    9---退出                    |        \n");
    
    do
    {
        printf("\n选择你要进行的操作(1-9):");
        scanf("%d",&input);
    }
    while(input<1 || input>9);
    return input;
}

bool Insert(SeqListT* L) //增加老师
{
    int Int;
    printf("请输入要插入老师的相关信息：");
    ElemTypeT X;
    printf("请输入老师姓名：\n");
    scanf("%s",X.name);
    printf("请输入老师性别：\n");
    scanf("%s",X.sex);
    printf("输入老师的联系方式：\n");
    scanf("%d",&X.num);
    printf("请输入要插入的位置:\n");
    scanf("%d",&Int);
    int j;
    if(L->lastT==MAXSIZE-1){
        printf("线性表满！\n");
        return false;
    }
    if(Int<1 || Int>L->lastT+2){
        printf("位置不合法！\n");
        return false;
    }
    for(j=L->lastT; j>=Int-1; j--)
    {
        L->elem[j+1]=L->elem[j];
    }
    L->elem[Int-1]=X;
    L->lastT++;
    return true;
}
bool delet(SeqListT* L) //删除老师信息
{
    int i,j;
    printf("请选择要删除老师信息的位置:\n");
    scanf("%d/n",&i);
    if(L->lastT==-1){
        printf("没有可以删除的老师信息！\n");
        return false;
    }
    if(i<1 || i>L->lastT+2){
        printf("位置不合法！\n");
        return false;
    }
    for(j=i-1; j<L->lastT; j++)
    {
        L->elem[j]=L->elem[j+1];
    }
    L->lastT--;
    printf("删除成功！\n");
    return true;
}

void sortMax(SeqListT *L)
{
    int i,j;
    ElemTypeT X;
    for(j=0;j<L->lastT-1;j++)
    {
        for(i=0;i<=L->lastT-1-j;i++)
        {
            if(L->elem[i].Score<L->elem[i+1].Score)
            {
                X=L->elem[i];
                L->elem[i]=L->elem[i+1];
                L->elem[i+1]=X;
            }
        }
    }
}

int count(SeqListT L)
{
    int i,j=0,c=0;
    int average;
    for(i=1;i<=L.lastT-1;i++)
    {
        j=j+L.elem[i].Score;
        c++;
    }
    average=j/c;
    return average;
}
void readin(SeqListT *L)// 输入老师相关信息
{
    int r;
    int i;
    printf("输入想要录入教师的数量:");
    scanf("%d",&r);
    //char name1[10];
    for(i=0; i<=r-1; i++)
    {
        //ElemType X;
        //scanf("%d",&X.num);
        //scanf("%d",&X.score);
        //L->elem[i]=X;
        /*
         char name[10];
         int num;
         int MathScore;
         int ChinaseScore;
         int EnglishScore;
         */
        L->lastT++;
        printf("----------------------------\n");
        printf("请输入第%d名老师的信息：\n",i+1);
        printf("请输入老师的姓名\n");
        scanf("%s",L->elem[i].name);
        //strcpy(L->elem[i].name,name1);
        printf("请输入老师的性别：\n");
        scanf("%s",L->elem[i].sex);
        printf("请输入老师的联系方式：\n");
        scanf("%d",&L->elem[i].num);
    }
}


bool   findNameT(SeqListT L) //按姓名查找老师int
{
    char name2[10];//
    printf("要查找的老师姓名为:\n");
    scanf("%s",name2);
    int i=0;
    while ((i<=L.lastT)&&(strcmp(L.elem[i].name,name2)))//查找该老师
        i++;
    if  (i<=L.lastT)
    {
        printf("|  序号   |   姓名   |   性别  |   联系方式  |\n");
        printf("|--------|----------|--------|----———----|\n");
        printf("|%-8d|%-8s|%-8s|%-10d|\n",i+1,L.elem[i].name,L.elem[i].sex,L.elem[i].num);
        return true;
    }
    else
        printf("没有找到这名教师！");  //没找到返回空序号
    return false;
}

bool  findNameS(SeqListS L) //查找学生int
{
    char name2[10];
    printf("要查找的学生姓名为:\n");
    scanf("%s",name2);
    int i=0;        //  顺序扫描表直到找到，或找不到 到表尾
    while ((i<=L.lastS)&&(strcmp(L.elem[i].name,name2)))//找到后印相关信息
        i++;
    if  (i<=L.lastS)
    {
        printf("|   序号  |    姓名   |  性别  |   节目名称  |  节目类型  |   联系方式  |  班级   |\n");
        printf("|--------|----------|--------|----———----|----———----|----———----|--------|\n");
        printf("|%-8d|%-8s|%-8s|%-10s|%-10s|%-10d|%-8s|\n",i+1,L.elem[i].name,L.elem[i].sex,L.elem[i].proname,L.elem[i].protype,L.elem[i].num,L.elem[i].class);
        return true;
    }
    else
        printf("没有找到这名学生！\n");  //没找到返回空序号
    return false;
}

void find(SeqListT L1,SeqListS L2)
{
    int a;
    if(L1.lastT==-1)
        printf("没有可以查询的老师信息!\n");
    else
    {
        printf("查找学生还是教师（1.教师 2.学生）\n");
        scanf("%d",&a);
        if(a==1)
        {
            findNameT(L1);
        }
        else if(a==2)
        {
            findNameS(L2);
        }
        else if(a!=1&&a!=2)
        {
            printf("输入信息有问题！\n");
        }
    }
}

void grade(SeqListT *L1,SeqListS *L2)//评分
{
    int s=0,t=0,i,j=1,a;
    a=L1->lastT;
    printf("开始评分\n");
    for(s=0;s<=L2->lastS;s++)
    {
        printf("----------------------------\n");
        printf("对第%d名同学评分：\n",s+1);
        for(t=0;t<=L1->lastT;t++)
        {
            printf("请输入%s老师给予的分数：",L1->elem[t].name);
            scanf("%d",&L1->elem[t].Score);
            printf("\n");
        }
        printf("已经对第%d名同学完成评分，是否保存（保存后不可更改）！（1.保存   2.修改信息）：\n",s+1);
        scanf("%d",&j);
        while(j==2)
        {
            //readin(&L1);
            printf("请输入要修改第几名教师所给的分数：\n");
            scanf("%d",&i);
            printf("请输入分数：\n");
            scanf("%d",&L1->elem[i-1].Score);
            printf("是否继续修改其他老师给的分数：\n");
            scanf("%d",&j);
        }
        count(*L1);
        printf("去除一个最高分：%d\n",L1->elem[0].Score);
        printf("去除一个最低分：%d\n",L1->elem[a].Score);
        printf("最后%s同学得分为：%d\n",L2->elem[s].name,count(*L1));
    }
}

int  main()
{
    SeqListS l1;
    SeqListT l2;
    l1.lastS=-1;
    l2.lastT=-1;
    while(1)
    {
        switch(menu())
        {
            case 1:
                readin(&l2);//输入
                //display(l2);
                break;
            case 2:
                find(l2,l1);//增加
                break;
            case 3:
                Insert(&l2);//删除
                //display(l);
                break;
            case 4:
                delet(&l2);//修改
                //display(l);
                break;
            case 5:
                find(l2,l1);//查找
                break;
            case 6:
                grade(&l2, &l1);//评分
                //display(l);
                break;
            /*case 7:
                save(&l);//读取
                break;
            case 8:
                load(&l);//保存
                break;*/
            case 9:
                printf("-----–谢谢使用-----\n");
                exit(1);
        }
    }
}

