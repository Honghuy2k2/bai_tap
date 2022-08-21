#include "stdio.h"

   int arr[20]={};
   int arr1[]={1,5,7,8,55,33,2,44,56,87};
   int arr2[]={67,78,45,3,87,66,89,71,35,97};
 

   int length1=sizeof arr1 /sizeof(int);
   int length2=sizeof arr2 /sizeof(int);


static void hoan_vi(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void coppy_2arr(int arr1[],int arr2[])
{
   for(int i=0;i<length1;i++)
   {
      arr[i]=arr1[i];
      
   }
     for(int i=0;i<length2;i++)
   {
      
      arr[length1+i]=arr2[i];
   }
   
}


void be_lon(int arr[],int n)
{
  int temp;
    printf("sap xep tu be den lon :\n");
   for (int i = 0; i < n; i++)
   {
    for(int j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j])
      {
         hoan_vi(arr[i],arr[j]);
      }
    }
    printf("%d \t",arr[i]);
   }
}


void lon_be (int arr[],int n)
{
   int temp;
   printf("\nsap xep tu lon den be :\n");
   for (int i = 0; i < n ; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
			}
		}
      printf("%d \t ",arr[i]);
      
   }
}
   
   
int tim_giatri (int arr[],int k,int n)
   {
      int vitri;
      for (int i = 0; i < n; i++)
      {
         if(k==arr[i])
         {
            printf("\ntrue");
           return 1;

         }
      }
      printf("\nfail");   
   }


int main(int argc, char const *argv[])
{
    int tong=length1+length2;
     coppy_2arr(arr1,arr2);
      be_lon(arr,tong);
      lon_be(arr,tong);
      printf("",tim_giatri(arr,89,20));

    return 0;
}
