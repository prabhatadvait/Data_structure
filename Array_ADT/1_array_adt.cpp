#include<iostream>
using namespace std;

class Array{
  // int A[10];
private:
  int *A; //for menu driver
  int size;
  int length;

void swap(int *x,int *y);
public:
  Array(int sz){
    size =sz;
    length=0;
    A=new int[size];
  }
  ~Array(){
    delete []A;
  }
void Display();
void Append (int n);
void Insert(int index,int x);
int Delete(int index);
int LinearSearch(int key);
int ImpLinearSearch(int key);
int BinarySearch(int key);
int RBinarySearch(int a[],int l,int h,int key);
int Get(int index);
void Set(int index,int x);
int Max();
int Min();
int Sum();
float Avg();
void Reverse();
void Reverse2();
void InsertSort(int x);
int isSorted();
void RearrangeNeg();
Array * Merge(Array arr2);
Array * Union(Array arr2);
Array * Intersection(Array arr2);
Array * Difference(Array arr2);

};
void Array:: Display(){
  for(int i=0;i<length;i++){
    printf("%d\n",A[i]);
  }
}
void Array :: Append(int n){
 if(length<size){
    A[length]=n;
  length++;
  }
}
void Array:: Insert(int index,int x){
  if(index>=0 && index<=length){
    for(int i=length;i>index;i--){
      A[i]=A[i-1];
    }
    A[index]=x;
    length++;
  }
}
int Array :: Delete(int index){
  int x = 0;
  if(index>=0 && index<length){
    x = A[index];
    for(int i=index;i<length-1;i++){
      A[i]=A[i+1];
    }
    length--;
    return x;
  }
  return 0;
}
int Array ::  LinearSearch(int key){
  for(int i=0;i<length;i++){
    if(key==A[i]){
      return i;
    }
  }
    return -1;
}
void Array :: swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y=temp;
}
int Array :: ImpLinearSearch(int key){
  for(int i=0;i<length;i++){
    if(key==A[i]){
      // swap(arr->A[i],arr->A[i-1]);  //Transposition
      swap(&A[i],&A[0]);
      return A[0];
    }
  }
  return -1;
}
int Array :: BinarySearch(int key){
  int l,mid,h;
  l=0;
  h=length-1;
  int k=0;
  while(l<=h){
    mid = (l+h)/2;
    if(key==A[mid]){
  printf("In how many times %d\n",k);
      return mid;
    }
    else if(key<A[mid]){
      h=mid-1;
    }
    else{
      l=mid+1;
    }
   k++; 
  }
  return -1;
}
int Array :: RBinarySearch(int a[],int l,int h,int key){
  int mid;
  if(l<=h){
    mid = (l+h)/2;
    if(key=a[mid]){
      return mid; 
    }
    else if(key<a[mid]){
      return RBinarySearch(a,l,mid-1,key);
    }
    else{
      return RBinarySearch(a,mid+1,h,key);
    }
    return -1;
  }

}
int Array :: Get(int index){
  if(index>=0 && index<length){
    return A[index];
  }
  return -1;
}
void Array :: Set(int index,int x){
  if(index>=0 && index<length){
    A[index]=x;
  }
}
int Array ::Max(){
  int max = A[0];
  for(int i=0;i<length;i++){
    if(A[i]>max){
      max = A[i];
    }
  }
  return max;
}
int Array :: Min(){
  int min = A[0];
  for(int i=0;i<length;i++){
    if(A[i]<min){
      min = A[i];
    }
  }
  return min;
}
int Array :: Sum(){
  int total=0;
  for(int i=0;i<length;i++){
    total=total+A[i];
  }
  return total;
}
float Array :: Avg(){
  return (float)Sum()/length;
}
void Array :: Reverse(){
  int *B;
  int i,j;
  B=(int *)malloc(length*sizeof(int));
  for(i=length-1,j=0;i>=0;i--,j++){
    B[j]=A[i];
  }
  for(int i=0;i<length;i++){
    A[i]=B[i];
  }
}
void Array :: Reverse2(){
  int i,j;
  for(i=0,j=length-1;i<j;i++,j--){
    int temp = A[i];
    A[i]=A[j];
    A[j]=temp;
    //we can use swap(&arr->A[i],&arr->A[j]);
  }
}
void Array :: InsertSort(int x){
  int i=length-1;
  if(length==size){
    return;
  }
  while(i>=0 && A[i]>x){
    A[i+1]=A[i];
    i--;
  }
  A[i+1]=x;
  length++;
}
int Array :: isSorted(){
  for(int i=0;i<length-1;i++){
    if(A[i]>A[i+1]){
      return 0;
    }
  }
  return 1;
}
void Array :: RearrangeNeg(){
  int i=0,j=length-1;
  while(i<j){
    while(A[i]<0){i++;}
    while(A[j]>=0){j--;} 
    if(i<j){
      swap(&A[i],&A[j]);
    }
    
  }
}
Array * Array:: Merge(Array arr2){
  int i,j,k;
  i=j=k=0;
  Array *arr3 = new Array(length+arr2.length);
  while(i<length && j<arr2.length){
    if(A[i]<arr2.A[j]){
      arr3->A[k++]=A[i++];
    }
    else{
      arr3->A[k++]=arr2.A[j++];
    }
  }
  for(;i<length;i++){
    arr3->A[k++]=A[i];
  }
  for(;j<arr2.length;j++){
    arr3->A[k++]=arr2.A[j];
  }
   arr3->length = length + arr2.length;
  return arr3;
}
Array * Array::Union(Array arr2){
  int i,j,k;
  i=j=k=0;
  Array *arr3 = new Array(length+arr2.length); 
  while(i<length && j<arr2.length){
    if(A[i]<arr2.A[j]){
      arr3->A[k++]=A[i++];
    }
    else if(arr2.A[j]<A[i]){
      arr3->A[k++]=arr2.A[j++];
    }
    else{
      arr3->A[k++]=A[i++];
      j++;
    }
  }
  for(;i<length;i++){
    arr3->A[k++]=A[i++];
  }
  for(;j<arr2.length;j++){
    arr3->A[k++]=arr2.A[j++];
  }
  length = k;
  return  arr3;
}
Array * Array::Intersection(Array arr2){
  int i,j,k;
  i=j=k=0;
  Array *arr3 = new Array(arr2.length +length);
  while(i<length && j<arr2.length){
    if(A[i]<arr2.A[j]){
      i++;
    }
    else if(arr2.A[j]<A[i]){
      j++;
    }
    else{
      arr3->A[k++]=A[i++];
      j++;
    }
    
  }
  length = k;
  return arr3;
}
Array * Array::Difference(Array arr2){
  int i,j,k;
  i=j=k=0;
  Array *arr3 =new Array(arr2.length +length);
  while(i<length && j<arr2.length){
    if(A[i]<arr2.A[j]){
      arr3->A[k++]=A[i++];
    }
    else if(arr2.A[j]<A[i]){
      j++;
    } 
    else{
      i++;
      j++;
    }
  }
  for(;i<length;i++){
    arr3->A[k++]=A[i];
    printf("check %d\n",i);
  }
  length = k;
  return arr3;
}
int main(){
 /* struct Array arr={{2,4,5,6,7},10,5};
 Append(&arr,9);
  Insert(&arr,1,1);
  Delete(&arr,0);
  printf("%d\n",LinearSearch(arr,4));
  printf("%d\n",ImpLinearSearch(&arr,5))
  printf("%d\n",BinarySearch(arr,6));
  printf("%d\n",RBinarySearch(arr.A,0,arr.length,6));
  printf("%d\n",Get(arr,2));
  Set(&arr,2,9);
  printf("%d\n",Max(arr));
  printf("%d\n",Min(arr));
  printf("%d\n",Sum(arr));
  printf("%f\n",Avg(arr));
  Reverse(&arr);
  Reverse2(&arr);
  InsertSort(&arr,9);
  printf("%d\n",isSorted(arr));
  RearrangeNeg(&arr);
  Display(arr);
 */ 
  /*
  struct Array arr1 = {{3,4,5,6,10},10,5};
  struct Array arr2 = {{2,4,5,7,12},10,5};
  struct Array *arr3;
  // arr3=Merge(&arr1,&arr2);
  // arr3 = Union(&arr1,&arr2);
  // arr3 =Intersection(&arr1,&arr2);
  arr3 = Difference(&arr1,&arr2);
  Display(*arr3);
  */
 Array *arr1;
  int ch,index,x,sz;
  printf("enter the size of array1: ");
  scanf("%d",&sz);
  arr1 = new Array(sz);
do{
  printf("Menu\n");
  printf("1.Insert\n");
  printf("2.Append\n");
  printf("3.Delete\n");
  printf("4.LinearSearch\n");
  printf("5.BinarySearch\n");
  printf("6.Get\n");
  printf("7.Set\n");
  printf("8.Max\n");
  printf("9.Min\n");
  printf("10.Sum\n");
  printf("11.Avg\n");
  printf("12.isSorted\n");
  printf("13.Display\n");

  printf("Please Enter your choice (welcome by prabhat)\n");
  scanf("%d",&ch);
 switch(ch){
  case 1: printf("Enter an element and index: ");
      scanf("%d%d",&x,&index);
      arr1->Insert(index,x);
      break;
  case 2: printf("Enter the element: ");
    scanf("%d",&x);
    arr1->Append(x);
    break;
  case 3: printf("Enter the index: ");
    scanf("%d",&index);
    arr1->Delete(index);
    break;
  case 4: printf("Enter the element: ");
    scanf("%d",&x);
    printf("%d\n",arr1->LinearSearch(x));
    break;
  case 5: printf("Enter the element: ");
    scanf("%d",&x);
    printf("%d\n",arr1->BinarySearch(x));
    break;
  case 6: printf("Enter the index: ");
    scanf("%d",&index);
    printf("%d\n",arr1->Get(index));
    break;
  case 7: printf("Enter the index and element: ");
    scanf("%d%d",&index,x);
    arr1->Set(index,x);
    break;
  case 8: printf("Get the Maximum value: ");
    printf("%d\n",arr1->Max());
    break;
  case 9: printf("Get the minimum value: ");
    printf("%d\n",arr1->Min());
    break;
  case 10: printf("Get the sum of array: ");
    printf("%d\n",arr1->Sum());
    break;
  case 11: printf("Get the average of array: ");
    printf("%d\n",arr1->Avg());
    break;
  case 12: printf("Check is array sorted or not: ");
    printf("%d\n",arr1->isSorted());
    break;
  case 13: printf("To display the output");
    arr1->Display();
  }
 }while(ch<13);
  return 0;
}
