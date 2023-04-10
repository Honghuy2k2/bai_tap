#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>

void readUnita(uint8_t num);  // ham in ra so ban chu
void readDec(uint8_t num);  // ham in ra cach doc trong chu cai
void readNummer(uint32_t *ptr,uint32_t num); //in ra chu so

void readUnita(uint8_t num)
{
    switch(num)  
    {
        case  0 :
        printf("KHONG");
        break;
        case  1 :
        printf("MOT ");
        break;
        case  2 :
        printf("HAI ");
        break;
        case  3 :
        printf("BA ");
        break;
        case  4 :
        printf("BON ");
        break;
        case  5 :
        printf("NAM ");
        break;
        case  6 :
        printf("SAU ");
        break;
        case  7 :
        printf("BAY ");
        break;
        case  8 :
        printf("TAM ");
        break;
        case  9 :
        printf("CHIN ");
        break;
        default:
        printf("ERROR!! khong hop le !!\n");
        break;
    }
}

void readDec(uint8_t num)  // ham in ra cach doc trong chu cai
{
    switch(num)
    {
        case 1:
        case 4:
        printf("MUOI");
        break;
        case 2:
        case 5:
        printf("TRAM");
        break;
        case 3:
        printf("NGHIN ");
        break;
        case 6:
        printf("TRIEU");
        default:
        break;
    }
}


void readNummer(uint32_t *ptr,uint32_t num)
{
    uint32_t count=0,a=0;
    uint32_t value=0;
    for (int i = 0; 0 < num;i++,num/=10)  // dao nguoc chu so
    {
       count=num%10; 
       ptr[i]=count;  //luu vao trong con tro
       a++;   // dem kich thuoc cua so 
    } 

   for (int i = a - 1; 0 <= i; i--)
    {
        value = ptr[i];  // gan ptr[i] bang voi value
        if (ptr[i] == 0)   // xem phan tu cua mang
        {
            if (i == 4 && ptr[i+1] != 0)  // ptr[i+1] xem phan tu trong co gia tri khac 0
            {
                readDec(3); // in ra phan nghin
            }
            else if (i == 1 && ptr[i-1] != 0)   // ptr[i-1] xem phan tu trong co gia tri khac 0
            {
                printf(" LINH "); // in ra chu
            }
             else if (i == 3 && ptr[i-3] != 0)
            {
                readUnita(0);
                readDec(i-1);  // in ra phan cham
            }
        }
        else {    
            readUnita(value);  // in chu so    
            readDec(i);        // in ra cach doc trong chu cai
            printf(" ");
        }
    }    
}

int main(int argc, char const *argv[])
{
    uint32_t *ptr;
    int value;
    ptr=(uint32_t*)malloc(sizeof(uint32_t)); // cap phat dong
   printf("Enter the nummer :");
   scanf("%d",&value);
  readNummer(ptr,value);  
    return 0;
}
