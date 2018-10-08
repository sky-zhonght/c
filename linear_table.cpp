#include <iostream>
using namespace std;
#define LIST_MAX_SIZE 100
typedef struct 
{  int elem[LIST_MAX_SIZE];
   int length;
} SqList;

void InitList(SqList *L)//初始化顺序表。
{  L->length=0;
}

void ClearList(SqList *L)//清空顺序表。
{  L->length=0;
}

bool IsEmpty(SqList *L)//判断顺序表是否为空。
{  return L->length==0;
}

int ListLength(SqList *L)//获得顺序表长度。
{  return L->length;
}

void GetElem(SqList *L,int position,int e)//获得某个位置的元素。
{  if(position>=L->length)
     cout<<"输入位置超过表长，请重新输入。"<<endl;
   else
     e=L->elem[position];
}

int LocateElem(SqList *L,int e)//找元素所在的位置，如果找不到，则返回-1，表示错误。
{  int i=0;
   while(e!=L->elem[i])
    	i++;
   if(i==L->length)
      return -1;
   else 
      return i;
}

void PriorElem(SqList *L,int position,int pre_e)//找指定元素的前一个元素。
{   if(position>=L->length)
      cout<<"输入位置超过表长，请重新输入。"<<endl;
    else
    {  int index; 
       index=LocateElem(L,position);
       if(index==0)
          cout<<"该元素位于表头，没有前一位元素。"<<endl;
       else if(index>0)
          pre_e=L->elem[index-1];
    }
}

void NextElem(SqList *L,int position,int next_e)//找指定元素的后一个元素。
{   if(position>=L->length)
       cout<<"输入位置超过表长，请重新输入。"<<endl;
    else
    {  int index;
       index=LocateElem(L,position);
       if(index==L->length-1)
         cout<<"该元素位于表尾，没有后一位元素。"<<endl;
       else if(index>0)
         next_e=L->elem[index+1];
    } 
}

void ListInsert(SqList *L,int position,int insert_e)//在指定位置中插入一个元素。
{  if(L->length==LIST_MAX_SIZE)
  {  
  }
  else
  {  int j;
     if(position>=L->length+1)
      cout<<"输入位置超过当前表长加一，请重新输入。"<<endl;
     else
     {  for(j=L->length;j>position;j--)
          L->elem[j]=L->elem[j-1];
        L->elem[j]=insert_e;
        L->length=L->length+1;
     }
  }
}

void ListDelete(SqList *L,int position)//在指定位置中删除一个元素。
{  if(L->length==0)
    cout<<"目前顺序表长度为零，无法继续删除。"<<endl;
   else
   {  if(position>=L->length)
       cout<<"输入位置超过当前表长，请重新输入。"<<endl;
      else
      { for(int j=position;j<L->length-1;j++)
          L->elem[j]=L->elem[j+1];
        L->length=L->length-1;
      }
   }
}

void ListTraverse(SqList *L)//遍历顺序表，获得所有元素。
{  int i;
   if(L->length==0)
    cout<<"当前顺序表没有元素，不能遍历。"<<endl;
   else
  {   for(i=0;i<L->length;i++)
      cout<<L->elem[i]<<" ";
      cout<<endl;
  }
}
int main()
{  return 0;
}
