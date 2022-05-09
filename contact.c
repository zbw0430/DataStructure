//
//  contact.c
//  2022.2.28
//
//  Created by 暖暖 on 2022/3/6.
//

#include "contact.h"

#include "string.h"
#include "stdlib.h"

//初始化通讯录
//静态版本
//void InitContact(Contact* pc)
//{
//    pc->sz = 0;
//    memset(pc->data,0,sizeof(pc->data));
//}
//动态版本
void InitContact(Contact* pc)
{
    pc->data = (PeoInfo*)malloc(DEFAULT_SZ*(sizeof(PeoInfo)));
    if(pc->data == NULL)
    {
        perror("InitContact");
        return;
    }
    pc->sz = 0;
    pc->capacity = DEFAULT_SZ;
    //加载通讯录
    LoadContact(pc);
}

void LoadContact(Contact* pc)
{
    FILE* pf = fopen("//Users//nuannuan//Desktop//code//2022.2.28//contact.dat", "r");
    if(pf == NULL)
    {
        perror("LoadContact");
        return;
    }
    //读文件
    PeoInfo tmp = {0};
    while(fread(&tmp, sizeof(PeoInfo), 1, pf))
    {
        //是否需要增容
        CheckCapacity(pc);
        pc->data[pc->sz] = tmp;
        pc->sz++;
    }
    //关闭文件
    fclose(pf);
    pf = NULL;
}

void CheckCapacity(Contact* pc)
{
    if(pc->sz == pc->capacity)
    {
        PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity+INC_SZ)*sizeof(PeoInfo));
        if(ptr != NULL)
        {
            pc->data = ptr;
            pc->capacity += INC_SZ;
            printf("增容成功\n");
        }
        else
        {
            perror("AddContact");
            printf("增加联系人失败\n");
            return;
        }
    }
}

//静态版增加联系人
//void AddContact(Contact* pc)
//{
//    if(pc->sz == MAX)
//    {
//        printf("通讯录已满，无法添加");
//        return;
//    }
//    printf("请输入名字：");
//    scanf("%s",pc->data[pc->sz].name);
//    printf("请输入性别：");
//    scanf("%s",pc->data[pc->sz].sex);
//    printf("请输入年龄：");
//    scanf("%d",&pc->data[pc->sz].age);
//    printf("请输入电话号码：");
//    scanf("%s",pc->data[pc->sz].tele);
//    printf("请输入地址：");
//    scanf("%s",pc->data[pc->sz].addr);
//    pc->sz++;
//    printf("增加成功\n");
//}
//动态版增加联系人
void AddContact(Contact* pc)
{
    CheckCapacity(pc);
    printf("请输入名字：");
    scanf("%s",pc->data[pc->sz].name);
    printf("请输入性别：");
    scanf("%s",pc->data[pc->sz].sex);
    printf("请输入年龄：");
    scanf("%d",&pc->data[pc->sz].age);
    printf("请输入电话号码：");
    scanf("%s",pc->data[pc->sz].tele);
    printf("请输入地址：");
    scanf("%s",pc->data[pc->sz].addr);
    pc->sz++;
    printf("增加成功\n");
}


void PrintContact(const Contact* pc)
{
    printf("%-10s\t%-10s\t%-10s\t%-12s\t%-20s\n","姓名","性别","年龄","电话号","地址");
    for(int i = 0; i < pc->sz; i++)
    {
        printf("%-10s\t%-10s\t%-10d\t%-12s\t%-20s\n",pc->data[i].name,
               pc->data[i].sex,
               pc->data[i].age,
               pc->data[i].tele,
               pc->data[i].addr);
    }
}

static int FindByName(Contact* pc,char name[])
{
    for(int i = 0; i < pc->sz; i++)
    {
        if(strcmp(pc->data[i].name, name) == 0)
            return i;
    }
    return -1;
}

void DelContact(Contact* pc)
{
    char name[MAX_NAME] = {0};
    if(pc->sz == 0)
    {
        printf("通讯录为空，无需删除\n");
        return;
    }
    //查找要删除的人是否在通讯录中
    printf("请输入要删除人的姓名:");
    scanf("%s",name);
    int pos = FindByName(pc,name);
    //有或没有
    if(pos == -1)
    {
        printf("通讯录中查无此人\n");
        return;
    }
    //删除
    for(int i = pos; i < pc->sz-1; i++)
    {
        pc->data[i] = pc->data[i+1];
    }
    pc->sz--;
    printf("删除成功\n");
}

void SearchContact(Contact* pc)
{
    char name[MAX_NAME] = {0};
    printf("请输入要查找人的姓名:");
    scanf("%s",name);
    int pos = FindByName(pc,name);
    if(pos == -1)
    {
        printf("通讯录中查无此人\n");
        return;
    }
    else
    {
        printf("%-10s\t%-10s\t%-10s\t%-12s\t%-20s\n","姓名","性别","年龄","电话号","地址");
        printf("%-10s\t%-10s\t%-10d\t%-12s\t%-20s\n",pc->data[pos].name,
                   pc->data[pos].sex,
                   pc->data[pos].age,
                   pc->data[pos].tele,
                   pc->data[pos].addr);
        
    }
}

void ModifyContact(Contact* pc)
{
    char name[MAX_NAME] = {0};
    printf("请输入要修改人的姓名:");
    scanf("%s",name);
    int pos = FindByName(pc,name);
    if(pos == -1)
    {
        printf("通讯录中查无此人\n");
        return;
    }
    else
    {
        printf("请输入名字：");
        scanf("%s",pc->data[pos].name);
        printf("请输入性别：");
        scanf("%s",pc->data[pos].sex);
        printf("请输入年龄：");
        scanf("%d",&pc->data[pos].age);
        printf("请输入电话号码：");
        scanf("%s",pc->data[pos].tele);
        printf("请输入地址：");
        scanf("%s",pc->data[pos].addr);
        printf("修改成功\n");
    }
}

void SaveContact(Contact* pc)
{
    FILE* pf = fopen("//Users//nuannuan//Desktop//code//2022.2.28//contact.dat", "w");
    if(pf == NULL)
    {
        perror("SaveContact");
        return;
    }
    //写文件
    for (int i = 0; i < pc->sz; i++)
    {
        fwrite(pc->data+i, sizeof(PeoInfo), 1, pf);
    }
    
    //关闭文件
    fclose(pf);
    pf = NULL;
}

void DestroyContact(Contact* pc)
{
    free(pc->data);
    pc->data = NULL;
    pc->sz = 0;
    pc->capacity = 0;
}
