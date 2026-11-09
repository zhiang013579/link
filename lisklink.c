#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node,*link;

//初始化
link initlisk(int value){
    link head=(link)malloc(sizeof(node));
    head->data=value;
    head->next=NULL;
    return head;
}

//尾插
void addback(link head,int n){
    link h,b;
    h=head;
    while (h->next!=NULL){
        h=h->next;
    }
    b=(link)malloc(sizeof(node));
    h->next=b;
    h=b;
    h->data=n;
    h->next=NULL;
    return;
}

//头插
link addhead(link head,int n){
	link h;
    h=(link)malloc(sizeof(node));
    h->next=head;
    h->data=n;
    return h;
} 

//打印
void plink(link head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    return;
}

//按位置查找
void check_position(link head,int n){
    int i=1;
    while(i<n){
        head = head->next;
        i++;
    }
    printf("position %d: %d\n", n, head->data);
    return;
}

//按值查找
void check_data(link head,int n){
    int i=1;
    if(head->data==n){printf("data %d in position 1",n);return;}
    while(head->data!=n){
        head=head->next;
        i++;
    }
    printf("data %d in position %d",n,i);
    return;
}

//倒置
link contraty(link head){
    link before,now,after;
    now = head;before=NULL;after=NULL;
    while(now!=NULL){
        after=now->next;
        now->next = before;
        before=now;
        now=after;
    }
    return before;
}

//删除
void delete(link head,int n){
    link h,b;
    for(;n>2;n--){
        head=head->next;
    }
    h=head;
    b=head->next;
    head=head->next;
    b=b->next;
    h->next=b;
    free(head);
    return;
}

//求长
int lenlink(link head){
    int n=1;
    while(head->next!=NULL){
        n++;
        head=head->next;
    }
    return n;
}

//插入
void insert(link head,int p,int n){
    for(;p>2;p--){
        head=head->next;
    }
    link b=head->next;
    link h=(link)malloc(sizeof(node));
    head->next=h;
    h->next=b;
    h->data=n;
    return;
}

//释放内存
void freelink(link head){
    link h=head,b=head->next;
    while(b!=NULL){
        head=b;
        free(h);
        b=head->next;
        h=head;
    }
    free(h);
    return;
}

//修改
void change(link head,int p,int n){
    for(;p>1;p--){
        head=head->next;
    }
    head->data=n;
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    if(n==-1)return 0;
    link head = initlisk(n);
    while(1){
        scanf("%d",&n);
        if(n==-1)break;//输入-1结束
        head = addhead(head,n);
        //addback(head,n);
    }
    plink(head);
    printf("\n");
    int p;
    scanf("%d %d",&p,&n);
    change(head,p,n);
    // insert(head,p,n);
     plink(head);
    // scanf("%d",&n);
    // check_position(head,n);
    // scanf("%d",&n);
    // check_data(head,n);
    // head=contraty(head);
    // plink(head);
    // scanf("%d",&n);
    // delete(head,n);
    // plink(head);
    // n=lenlink(head);
    // printf("%d",n);
    freelink(head);
    return 0;
}
