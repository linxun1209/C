#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	char id[10];
	char name[10];
	int score;
	struct student *next;//next��ָ�������ָ��ṹ�����
}; 
typedef struct student Stu;//��typedef������������
	Stu *s=0;
	int n=0;
void add(){	
	Stu *p;
	if(s==0){
		s=(Stu *)malloc(sizeof(Stu));     //  sizeof ����һ���������������һ�������������ʶ����Ҫ��
		p=s;         //malloc ����һ��������ԭ����void *malloc(size_t size)  ���Ƿ���size���ֽڵ��ڴ棬Ȼ�󷵻�ָ������ڴ����ֽڵ�ָ��
	}else{
		p=s;
	while(p->next!=0) p=p->next;  
 //->�����ṹ��ָ���������Ҳ���������ʽṹ���ڲ���Ա�ġ�����˵�������������C�����ж�����һ���ṹ�壬
 //Ȼ������һ��ָ��ָ������ṹ�壬��ô����Ҫ��ָ��ȡ���ṹ���е����ݣ���Ҫ�õ���->��.
	p->next=(Stu *)malloc(sizeof(Stu));
	p=p->next;
	}
	printf("**********Enter the new ID: ************\n");
	scanf("%s",p->id);
	printf("******Enter the new name: *********\n");
	scanf("%s",p->name);
	printf("********Enter the new score: **********\n");
	scanf("%d",&(p->score));
	printf("\n**********The following record has been added to the list:***********\n");
	printf("ID Name Score\n");
	printf("%s %s %d\n",p->id,p->name,p->score);
	p->next=0;//ʹpָ����һ��� 
	n++;
}
void edit(){	
	if(s==0){
	printf("No record available.\n");
	return;
	}
	Stu *p;
	char id[10];
	printf("************Enter the ID of the student you want to edit: *******************\n");
	scanf("%s",id);
	p=s;
	while(p!=0){
	if(strcmp(p->id,id)==0) break;   //strcmp �ַ����Ƚϣ������£� 
	p=p->next;
	}
	if(p==0) printf("No such record exists.\n");
	else{
	int c;
	printf("**********The following record has been found***********\n");
	printf("ID Name Score\n");
	printf("%s %s %d\n",p->id,p->name,p->score);
	printf("***********1.ID 2.Name 3.Score 4.Exit************\n");
	printf("************Choose your operation: ************\n");
	scanf("%d",&c);
	if(c==1){
		printf("********Enter the new ID: \n");
		scanf("%s",p->id);
	}else if(c==2){
		printf("*********Enter the new name: \n");
	scanf("%s",p->name);
	}else if(c==3){
		printf("***********Enter the new score: \n");
		scanf("%d",&(p->score));
	}else return;
	printf("********The edited record:********\n");
	printf("********ID Name Score***********\n");
	printf("%s %s %d\n",p->id,p->name,p->score);
	}
}
void search(){
	if(s==0){
		printf("No record available.\n");
		return;
	}	
	Stu *p;
	p=s;
	int c;
	printf("1.By ID 2.By name");
	printf("Enter the way you want to search: ");
	scanf("%d",&c);
	if(c==1){
	char id[10];
	printf("Enter the ID of the student: ");
	scanf("%s",id);
	while(p!=0){
	if(strcmp(p->id,id)==0) break;
		p=p->next;
	}
	if(p==0) printf("No such record exits.\n");
	else{
		printf("The following record has been found\n");
		printf("ID Name Score\n");
		printf("%s %s %d\n",p->id,p->name,p->score);
	}
	}else if(c==2){
		char name[10];
		printf("Enter the name of the student: ");
		scanf("%s",name);
	while(p!=0){
	if(strcmp(p->name,name)==0) break;
		p=p->next;
	}
	if(p==0) printf("No such record exits.\n");
	else{
	printf("The following record has been found\n");
	printf("ID Name Score\n");
	printf("%s %s %d\n",p->id,p->name,p->score);
	}
	}else printf("Invalid option.\n");
}
void display(){
	if(s==0){
	printf("No record available.\n");
	return;
	}
	Stu *p;
	p=s;
	printf("ID Name Score\n");
	while(p!=0){
	printf("%s %s %d\n",p->id,p->name,p->score);
	p=p->next;
	}
}
void save(){
	if(s==0){
	printf("No record available.\n");
	return;
	}
	char filename[100];
	printf("Enter the name of the file you want to save to(text file only): ");
	scanf("%s",filename);
	FILE *p;
	if((p=fopen(filename,"w"))==0){   //fopen ��һ������ �����Ǵ�һ���ļ�,֮�����Խ��ж���д�Ĳ��� (���б����õ���FILE)
	perror("Cannot open file.\n");    // w�����ı�����ʽ����д�� 
	return;
	}
	Stu *q;
	q=s;
	while(q!=0){
	fprintf(p,"%s %s %d\n",q->id,q->name,q->score);
	q=q->next;
	}
	fclose(p);
}

int main(){ 
	int i;
	do{ printf("      *****************************\n");
		printf("                  1.Add    \n   ");
		printf("               2.Edit \n       ");
		printf("           3.Save \n        ");
		printf("          4.Search \n     ");
		printf("             5.Display \n     ");
		printf("             6.Quit\n \n      ");
		printf("*****************************\n");
		printf("Choose your operation: "); 
		scanf("%d",&i);
	if(i==1) add();
	else if(i==2) edit();
	else if(i==3) save();
	else if(i==4) search();
	else if(i==5) display();
	else{
		Stu* p;
	while(s!=0){
		p=s->next;
		free(s);       //free����������ʾ�ڴ��ʹ������� 
		s=p;
	}
		break;
	}	
	}while(1);
	return 0;
}
