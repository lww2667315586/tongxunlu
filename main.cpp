#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define LEN sizeof(struct tong)
struct tong
{
    int xuhao;
    char name[20];
    char sex[20];
    int age;
    char phone[20];
    char jiguan[20];
    char workaddress[20];
    char familyaddress[20];
    char newselleraddress[20];
    char youbian[20];
    struct tong *next;
};//����ṹ�崢������
struct tong *creat()
{
    printf("��������ϵ�˵���š��������Ա����䡢�绰,���ᡢ�ֹ�����λ����ͥסַ��ͨ�ŵ�ַ���ʱ����Ϣ");
    printf("\n");
    struct tong *head,*tail,*pnew;
    head=(struct tong *)malloc(LEN);
    tail=head;
    while(1)
    {
        pnew=(struct tong *)malloc(LEN);
        scanf("%d",&pnew->xuhao);
        if(pnew->xuhao==0)
        {
            break;
        }
        scanf("%s%s%d%s%s%s%s%s%s",&pnew->name,&pnew->sex,&pnew->age,&pnew->phone,&pnew->jiguan,&pnew->workaddress,&pnew->familyaddress,&pnew->newselleraddress,&pnew->youbian);
        tail->next=pnew;
        tail=pnew;
    }
    tail->next=NULL;
    return head;
};
void xinjian(struct tong *head)
{

    printf("��ӭʹ���½�ͨѶ¼����");
    printf("\n");
    printf("�������½���ϵ�˵���š��������Ա����䡢�绰,���ᡢ�ֹ�����λ����ͥסַ��ͨ�ŵ�ַ���ʱ����Ϣ");
    printf("\n");
    struct tong *p,*q,*z;
    q=(struct tong *)malloc(LEN);
    scanf("%d%s%s%d%s%s%s%s%s%s",&q->xuhao,&q->name,&q->sex,&q->age,&q->phone,&q->jiguan,&q->workaddress,&q->familyaddress,&q->newselleraddress,&q->youbian);
    q->next=head->next;
    head->next=q;
    for(z=head->next;z!=NULL;z=z->next)
    {
        printf("%d %s %s %d %s %s %s %s %s %s ",z->xuhao,z->name,z->sex,z->age,z->phone,z->jiguan,z->workaddress,z->familyaddress,z->newselleraddress,z->youbian);
        printf("\n");
    }
}
void chaxun(struct tong *head)
{
    printf("��ӭʹ�ò���ͨѶ¼����");
    printf("\n");
    printf("��������������ϵ�˵�����");
    printf("\n");
    char mingzi[20];
    struct tong *p;
    int a=0;
    scanf("%s",&mingzi);
    for(p=head->next;p!=0;p=p->next)
    {
        if(strcmp(p->name,mingzi)==0)
        {
            printf("%d %s %s %d %s %s %s %s %s %s ",p->xuhao,p->name,p->sex,p->age,p->phone,p->jiguan,p->workaddress,p->familyaddress,p->newselleraddress,p->youbian);
            printf("\n");
            a=1;
        }
    }
    if(a==0)
    {
        printf("���޴���");
    }
}
void xiugai(struct tong *head)
{
    printf("��ӭʹ���޸���ϵ����Ϣ����");
    printf("\n");
    printf("���������޸���ϵ�˵����");
    printf("\n");
    int hao;
    struct tong *p,*x,*q,*z;
    scanf("%d",&hao);
    printf("��������ϵ���޸ĺ����š��������Ա����䡢�绰,���ᡢ�ֹ�����λ����ͥסַ��ͨ�ŵ�ַ���ʱ����Ϣ");
    printf("\n");
    x=(struct tong *)malloc(LEN);
    for(p=head,q=head->next;q!=NULL;p=p->next,q=q->next)
    {

        if(q->xuhao-hao==0)
        {
            scanf("%d%s%s%d%s%s%s%s%s%s",&x->xuhao,&x->name,&x->sex,&x->age,&x->phone,&x->jiguan,&x->workaddress,&x->familyaddress,&x->newselleraddress,&x->youbian);
            x->next=q->next;
            p->next=x;
            free(q);
        }
    }
    for(z=head->next;z!=NULL;z=z->next)
    {
        printf("%d %s %s %d %s %s %s %s %s %s ",z->xuhao,z->name,z->sex,z->age,z->phone,z->jiguan,z->workaddress,z->familyaddress,z->newselleraddress,z->youbian);
        printf("\n");
    }
}
void shanchu(struct tong *head)
{
    printf("��ӭʹ��ɾ����ϵ����Ϣ����");
    printf("\n");
    printf("��������ɾ����ϵ�˵�����");
    printf("\n");
    struct tong *p,*q,*z;
    int i;
    char ming[20];
    scanf("%s",&ming);
    for(p=head,q=head->next;q!=NULL;)
    {
        if(strcmp(q->name,ming)==0)
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
        p=p->next;
        q=q->next;
    }
    for(z=head->next;z!=NULL;z=z->next)
    {
        printf("%d %s %s %d %s %s %s %s %s %s ",z->xuhao,z->name,z->sex,z->age,z->phone,z->jiguan,z->workaddress,z->familyaddress,z->newselleraddress,z->youbian);
        printf("\n");
    }
}
int main()
{
    int v,j;
    struct tong *head,*i,*p,*z;
    FILE *fp;
    printf("��ӭʹ��ͨѶ¼����");
    printf("\n");
    printf("��������Ϊ0ʱ���������");
    printf("\n");
    head=creat();
    for(j=0;j<4;j++)
    {
        printf("������½���ϵ�ˣ�������1");
        printf("\n");
        printf("����������ϵ�ˣ�������2");
        printf("\n");
        printf("������޸���ϵ����Ϣ��������3");
        printf("\n");
        printf("�����ɾ����ϵ����Ϣ��������4");
        printf("\n");
        scanf("%d",&v);
        if(v==1)
        {
            xinjian(head);//�½����������ݣ�
        }
        if(v==2)
        {
            chaxun(head);//����ͨѶ¼��ϵ��
        }
        if(v==3)
        {
            xiugai(head);//�޸���ϵ�������Ϣ
        }
        if(v==4)
        {
            shanchu(head);
        }
    }
    if((fp=fopen("fp","w"))==NULL)
    {
        printf("���ܴ��ļ�");
            exit(0);
    }
    for(z=head->next;z!=NULL;z=z->next)
    {
         fprintf(fp,"%d %s %s %d %s %s %s %s %s %s ",z->xuhao,z->name,z->sex,z->age,z->phone,z->jiguan,z->workaddress,z->familyaddress,z->newselleraddress,z->youbian);
    }
    fclose(fp);
    //����ϵ�������Ϣ�����ݴ��浽�ļ���
    return 0;
}

/*1 jio oij 12 oij jio jio ioj oji ioj
2 opk kop 45 kop pok okp kop kop opk
3 knk kjn 20 njk njk kjn kjn njk njk*/
