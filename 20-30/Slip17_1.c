#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200
typedef struct dir
{
	char fname[20];
	int start,length;
	struct dir *next;
}NODE;
NODE *first,*last;
int bit[MAX],n;
void init()
{
	int i;
	printf("Enter total no of disk blocks");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		int k=rand()%n;
		bit[k]=1;
	}
}  
void show_bitvector()
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",bit[i]);
	}
	printf("\n");
}
void show_dir()
{
	NODE *p;
	printf("file \t start\t length\n");
	p=first;
	while(p!=NULL)
	{
		printf("%s\t%d\t%d\n",p->fname,p->start,p->length);
		p=p->next;
	}
}

void create() {
	NODE *p;
	char fname[20];
	int nob, i = 0, j = 0, start;

	printf("Enter the file name\n");
	scanf("%s", fname);
	printf("Enter no of blocks\n");
	scanf("%d", &nob);

	while (1) {
		while (i < n) {
			if (bit[i] == 0)
				break;
			i++;
		}

		if (i < n) {
			start = i;
			j = 1;
			while (j < nob && i < n && bit[i] == 0) {
				i++;
				j++;
			}

			if (j == nob) {
				p = (NODE *)malloc(sizeof(NODE));
				strcpy(p->fname, fname);
				p->start = start;
				p->length = nob;
				p->next = NULL;

				if (first == NULL) { 
					first = p;
				} else {
					last->next = p;
				}
				last = p;

				for (j = 0; j < nob; j++) {
					bit[j + start] = 1;
				}

				printf("File %s created successfully\n", fname);
				return;
			}
		} else {
			printf("Failed to create file %s\n", fname);
			return;
		}
	}
}


void delete()
{
	NODE *p,*q;
	char fname[20];
	int i;
	printf("Enter file to be deleted\n");
	scanf("%s",fname);
	p=q=first;
	while(p!=NULL)
	{
		if(strcmp(p->fname,fname)==0)
		{
			break;
		}
		q=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("file %s not found\n",fname);
		return;
	}
	for(i=0;i<p->length;i++)
	{
		bit[p->start+i]=0;
	}
	if(p==first)
	{
		first=first->next;
	}
	else if(p==last)
	{
		last=q;
		last->next=NULL;
	}
	else
	{
		q->next=p->next;
	}
	free(p);
	printf("File %s deleted successfully\n",fname);
}
int main()
{
	int ch;
	init();
	while(1)
	{
		printf("1.Show bit vector\n");
		printf("2.create new file\n");
		printf("3.Show directory\n");
		printf("4.Delete file\n");
		printf("5.Exit\n");
		printf("Enter your choice(1-5):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				show_bitvector();
				break;
			case 2:
				create();
				break;
			case 3:
				show_dir();
				break;
			case 4:
				delete();
				break;
			case 5:
				exit(0);
		}
	}
	return 0;
}

/*
Enter total no of disk blocks15
1.Show bit vector
2.create new file
3.Show directory
4.Delete file
5.Exit
Enter your choice(1-5):2
Enter the file name
shital
Enter no of blocks
3
File shital created successfully
*/
