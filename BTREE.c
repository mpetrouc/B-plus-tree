#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
#define N 1000

struct Node {
    long int data[1000];
    int length;
    struct Node *link[1001];
};

void init(){
int *ptr =(int *) malloc(sizeof(struct Node));
}

struct Node *riza;
struct Node *pateras;
struct Node *createNode(long int data, struct Node *left, struct Node *right);
void insert(long int data);
void split(struct Node *ptr);
void sort(struct Node *ptr);
struct Node *search(long int data, struct Node *ptr, int flag);


int main(int argc, char *argv[]){
	init();
   FILE *fptr = NULL; 
  fptr = fopen(argv[2], "r+");
FILE *fptr2 = NULL;
fptr2 = fopen(argv[3], "w");
    char line[N][M];
    int i = 0;
    int plithos = 0;
	int epilogi;

    while(fgets(line[i], M, fptr)) 
	{
        line[i][15] = '\0';
        i++;
    }
    plithos = i;
    for(i = 0; i < plithos; ++i)
    {
        printf(" %s\n", line[i]);
    }

long *result = (long *)malloc(plithos * sizeof(long));

char *eptr;
for(int i = 0; i< plithos;i++){
result[i] = strtol(line[i],&eptr,10);
printf("%ld \n",result[i]);
}
int j = 0;
long data = strtol(argv[3],&eptr,10);
long sn;
sn = strtol(argv[3],&eptr,10);
int thesi;

long find(long key){
int thesi = -1;
for(int i=0;i< plithos;i++){
	if (result[i] == key){		
		thesi = i;
}
}
return thesi;
}

if(strcmp(argv[1],"-create")==0){
        epilogi = 1;
}
else if(strcmp(argv[1],"-find")==0){
	epilogi = 2;
}
else if(strcmp(argv[1],"-insert")==0){
	epilogi =3;
}
    while (epilogi != 0){
        switch (epilogi) {
            case 1:
               for(int i=0;i < 22 ;i++){
              insert(result[i]);

}
for(int i=0;i < 22 ;i++){
fprintf(fptr2,"%li \n",result[i]);
}
epilogi = 0;
break;
            case 2:
               if (find(sn) == -1){
                    printf("Number %lu is absent!\n",sn);
}
else{
printf("Eggrafi %d , periexomena: %lu",thesi,sn);}
                
		epilogi = 0;
break;

case 3:
                insert(data);
	        fprintf(fptr,"%li \n",data);
		epilogi = 0;
                break;
 case 0:
                printf("Exit\n");
                break;
            default:
                printf("Enter a valid command\n");
                break;
        }
        printf("\n");
    }
}

struct Node *createNode(long int data, struct Node *left, struct Node *right){
        struct Node *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data[0] = data;
        newNode->length = 1;
        newNode->link[0] = left;
        newNode->link[1] = right;
        return newNode;
}

void insert(long int data){
    if (riza == NULL){
        riza = createNode(data, NULL, NULL);
        return;
    }
    struct Node *ptr = search(data, riza, 0);

    if (ptr == NULL){
        return;
    }
    else {
        ptr->data[ptr->length] = data;
        (ptr->length)++;
        ptr->link[ptr->length] = ptr->link[(ptr->length)-1];
        sort(ptr);
        int i;
        for (i=0; i<ptr->length; i++){
            if (ptr->link[i] != NULL){
                ptr->link[ptr->length] = ptr->link[i];
                ptr->link[i] = NULL;
                break;
            }
        }

        if ((ptr->length) > 4){
            split(ptr);
        }
    }
}

void split(struct Node *ptr){

    search(ptr->data[(ptr->length)-1], riza, 1);

    struct Node *newNode = createNode(ptr->data[2], ptr->link[2], ptr->link[3]);
    newNode->data[1] = ptr->data[3];
    newNode->link[2] = ptr->link[4];
    newNode->data[2] = ptr->data[4];
    newNode->link[3] = ptr->link[5];
    newNode->length = 3;
    ptr->length = 2;
    ptr->link[2] = newNode;

    if (ptr == riza){
        pateras = createNode(ptr->data[2], ptr, newNode);
        riza = pateras;
    }
    else {
        pateras->data[pateras->length] = ptr->data[2];
        (pateras->length)++;
        pateras->link[pateras->length] = newNode;
        sort(pateras);

        if ((pateras->length) > 2){
            split(pateras);
        }
    }
}

void sort(struct Node *ptr){
    int i,j;
    long temp;
    struct Node *temp_ptr;
    for (i = 0; i < (ptr->length)-1; i++){
        for (j = 0; j < ((ptr->length)-i-1); j++){
            if (ptr->data[j] > ptr->data[j+1]){
                temp = ptr->data[j];        
                temp_ptr = ptr->link[j+1];   
                ptr->data[j] = ptr->data[j+1];
                ptr->link[j+1] = ptr->link[j+2];
                ptr->data[j+1] = temp;            
                ptr->link[j+2] = temp_ptr;     
            }
        }
    }
}

struct Node *search(long int data, struct Node *ptr, int flag){
    int i;
    if (ptr != NULL){
        for (i=0; i<(ptr->length); i++){ 
            if (data == ptr->data[i]){
                if (flag == 0)
                    printf("O arithmos %lu yparxei hdh\n", data);
                return NULL;


            }
            else if (data < ptr->data[i]){
                pateras = ptr;
                return search(data, ptr->link[i], flag);
            }
        }

        pateras = ptr;
        return search(data, ptr->link[ptr->length], flag);
    }
    return pateras;
}



