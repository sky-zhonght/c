#include <iostream>
using namespace std;
typedef struct node
{  int data;
   struct node *next;
} NODE;

class LinkList
{  private:
   NODE *head;
   public:
   LinkList()  {head=NULL;}
   ~LinkList();
   void clearSqlist() {head=NULL;}
   bool IsEmpty() {return head==NULL;}
   int Length();
   bool GetElem(int position,int e);
   int LocateElem(int e);
   bool PriorElem(int cur_e,int pre_e);
   bool nextElem(int cur_e,int next_e);
   bool Insert(int position,int e);
   bool Delete(int position);
   bool Traverse(); 
};
int LinkList::Length()
{  NODE *p=head;
   int i;
   for(i=0;p!=NULL;i++)
     p=p->next;
   return i;
}
bool LinkList::GetElem(int position,int e)
{  NODE *p=head;
   int j;
   while(p&&j<position)
   {  p=p->next;
   	  j++;
   }
   if(p==NULL)
   	 return false;
   else
   {  e=p->data;
   	  return true;
   }
}
int LinkList::LocateElem(int e)
{  NODE *p=head;
   int i=1;
   while(p!=NULL)
   {  if(e==p->data)
       {  return i;
       	  break;
       }
       else 
       {  i++;
       	  p=p->next;
       }
   }
   if(p==NULL)
     return -1;
}
bool LinkList::PriorElem(int cur_e,int pre_e)
{  NODE *p=head;
   if(IsEmpty()==true)
  {  cout<<"该链表为空链表，因此无法输出前驱元素"<<endl;
     return false;
  }
  else
  {  if(head->data==cur_e)//head==NULL怎么办。
   {  cout<<"该数据位于链表表头，没有先驱元素。"<<endl;
      return false;
   }
   else
   {  while(p->next!=NULL)
   	  {  if(cur_e==p->next->data)
   	  	   {  pre_e=p->data;
   	  	   	  return true;
   	  	   }
   	  	 else  p=p->next;
   	  } 
   	  if(p->next==NULL)
   	  {  cout<<"该链表中找不到该元素，因此无法输出前驱元素。"<<endl;
   	  	 return false;
   	  }
   }
  }
}
bool LinkList::nextElem(int cur_e,int next_e)
{  NODE *p=head;
   if(IsEmpty()==true)
   {	cout<<"该链表为空链表，因此无法输出前驱元素"<<endl;
     return false;
   }
   else
   {  while(p!=NULL)
   {  if(cur_e==p->data)
   	  {  if(p->next==NULL)
   	  	  {  cout<<"该数据位于链表表尾，没有后继元素。"<<endl;
   	  	     return false;
   	  	  }
   	  	  else
   	  	  {  next_e=p->next->data;
   	  	  	 return true;
   	  	  }
   	  }
   	  else  p=p->next;
   }
   if(p==NULL)
   {  cout<<"该链表中找不到该元素，因此无法输出后继元素。"<<endl;
   	  	 return false;
   	  }
   }
}
bool LinkList::Insert(int position,int e)
{  NODE *p=head,*s;
   int j=0;
   if(position==0)
   {  s=(NODE*)new NODE[1];
   	  s->data=e;
   	  s->next=head;
   	  head=s;
   	  return true;
   }
   else
   {  while(p&&j<position-1)
   	  {  p=p->next;
   	  	 j++;
   	  }
   	  if(!p) return false;
   	  else 
   	  {  s=(NODE*)new NODE[1];
   	  	 s->data=e;
   	  	 s->next=p->next;
   	  	 p->next=s;
   	  	 return true;
   	  }
   }
}
bool LinkList::Delete(int position)
{  NODE *p=head,*q;
   int i=0;
   if(p==NULL)
   return false;
   else
   {    if(position==0)
       {  head=head->next;
       	  delete p;
       	  p=NULL;
       	  return true;
       }
        else
        {  while(p->next&&i<position-1)
        	{  p=p->next;
        	   i++;
        	}
        	if(!(p->next)||i>position-1)
        	  return false;
            q=p->next;
            p->next=q->next;
            delete q;
            q=NULL;
            return true;
        }
   }
}
int main()
{  return 0;
}
