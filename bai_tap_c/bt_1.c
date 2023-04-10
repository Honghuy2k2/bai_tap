#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

//mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                             7 xuat hien 2 lan
//                                             8 xuat hien 3 lan


typedef struct{  // tao 1 ham kieu du lieu con tro
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

int randomA(int minN, int maxN);
void randomArray(typeArray *value, uint8_t length); //ham random so
void  sortArray(typeArray *arr); // sap xep thu tu tang dan
void liet_ke_c1(typeArray arr);   // dem so lan xuat hien trong mang da sap xep
void liet_ke_c2(typeArray arr);  // dem so lan xuat hien trong mang chua sap xep



int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));

    value->size = length; // tro den kich thuoc da nhap

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size); // cap phat dong
    int r;
    for(int i = 0; i < value->size; ++i){
        value->firstAdd[i] = randomA(0,10); // ramdom gia tri tu 0-10
    }    
}

void  sortArray(typeArray *arr) // sap xep thu tu tang dan
{
  for(int i=0;i<arr->size;i++)
  {
    int hoan_vi;
    for(int j=i+1;j<arr->size;j++)
    {
      if(arr->firstAdd[j]<arr->firstAdd[i]) // kiem tra xem phan tu nao nho hon de hoa vi
      {
         hoan_vi=arr->firstAdd[j];
         arr->firstAdd[j]=arr->firstAdd[i];
         arr->firstAdd[i]=hoan_vi;
      }
    }
  }
}
//mang bat ky vd arr[] = {0,1,1,2,2,2,3,4,5,6,6}
void liet_ke_c1(typeArray arr)
{
  printf("\nliet ke cac phan tu co so lan xuat hien\n");


   for(int i=0;i<arr.size;i++)
   {
    int dem=1;
    a:  // goi lai
    if(arr.firstAdd[i]==arr.firstAdd[i+1])  // tim so tiep theo co bang so o trc khong
    {
       dem++;  // dem gia tri giong nhau trong mang
       i++;
       goto a;   // quay lai cau dieu kien if de tim so lan lap
    } 
      printf("%d xuat hien %d lan\n",arr.firstAdd[i],dem);
   } 
   
}
//mang bat ky vd arr[] = {0,1,1,2,2,2,3,4,5,6,6}
void liet_ke_c2(typeArray arr)  // dem so lan xuat hien trong mang chua sap xep
{
  int i=0,j=0;
  for (int i = 0; i < arr.size; i++)
  {
     int dem=1;
    for (int j =i+1; j < arr.size; j++) // j la phan tu tiep theo cua i
    {
      if(arr.firstAdd[i]==arr.firstAdd[j]) // xem 2 phan tu co bang nhau khong
      {       
        dem++;
        arr.firstAdd[j]=11;  // gan 1 gia tri bat ki vao con tro de khi goi lai thi se bo qua gia tri do di roi

      }
    }
    if(arr.firstAdd[i]!=11) 
    {
      // printf("%d xuat hien %d lan\n",arr.firstAdd[i],dem);
    }
    
  }
   
}

int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 20); // random 20 so

    for (int i = 0; i < arr.size; i++) 
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]); // goi ham
    }

     sortArray(&arr);
       printf("sap xep thu tu tang dan \n");
     for (int i = 0; i < arr.size; i++)
     {
         printf(" %d  ", arr.firstAdd[i]);
     }

     liet_ke_c1(arr);
 
     //liet_ke_c2(arr);
    
    return 0;
}