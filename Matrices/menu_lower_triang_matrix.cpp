#include<iostream>
using namespace std;
// COLUMN WISE 
int main(){
  int *A,n,ch,x,i,j;
  printf("Enter dimension ");
  scanf("%d",&n);
  A= new int[n*(n+1)/2];
  do{
    printf("Menu Driver\n");
    printf("1.Create\n");
    printf("2.Get\n");
    printf("3.Set\n");
    printf("4.Display\n");

    printf("Enter choice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1: for(i=1;i<=n;i++){
              for(j=1;j<=n;j++){
                scanf("%d",&A[(i*(i-1))/2+j-1]);
                }
             }
        break;
      case 2: printf("Enter the row,col ");
              scanf("%d%d",&i,&j);
              if(i>=j){
                printf("%d",A[(i*i-1)/2+j-1]); 
               }
              else{
                printf("0");
        }
                break;
      case 3: printf("Enter the row,col,ele ");
             scanf("%d%d%d",&i,&j,&x);
            if(i>=j){
              A[(i*i-1)/2+j-1]=x;
        }
          break;
      case 4:for(i=1;i<=n;i++){
              for(j=1;j<=n;j++){
              if(i>=j){
                printf("%d ",A[(i*(i-1))/2+j-1]);
              }
              else{
            printf("0 ");
          } 
        }
        printf("\n");
      }
        break;
      default: exit(0);
    }
  }while(ch<5);
  return 0;
}
