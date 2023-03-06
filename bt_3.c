#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char arr[] = "The Grammy award winning singer. who has been less active on digital platforms in recent weeks. explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";

//Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
//cau 2: In Hoa chu cai dau tien sau dau cham
//Cau 3: Chuyen doi tat ca doan van thanh chu thuong
//Cau 4: Chuyen doi tat ca doan van thanh chu hoa

typedef struct  // tao 1 ham kieu du lieu con tro
{
   char size;
   char *text; 
} type_text;


int string_length(char arr[]);  // tim kich thuoc cua mang
void string_reverse(char arr[]); //ham dao nguoc chuoi
void after_cham (char arr[]); //In Hoa chu cai dau tien sau dau cham
void chu_thuong (char arr[]);  // in ra toan bo chu viet thuong
void chu_hoa (char arr[]);  // in ra toan bo chu viet hoa

int string_length(char arr[])  // tim kich thuoc cua mang
 {
    int i = 0;

    while (arr[i] != '\0')  //  \0 khi het gia tri trong ham 
   {
        i++;
   }
    return i;  // xuat ra kich thuoc cua mang
}


/**
 * ham dao nguoc chuoi
 */
void string_reverse(char arr[])
 {
    int i, j;
    char temp; // dung de hoa vi ky tu

    j = string_length(arr) - 1; // kich thuoc cua mang
    i = 0;

    while (i < j) {  // dao nguoc chu
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
}

void after_cham (char arr[])
{
  int length=string_length(arr); // kich thuoc cua mang
  printf("\n\n In hoa sau dau cham\n");
  for (int i = 0; i < length; i++)
  {
    if(arr[i-2]=='.' && arr[i]>='a') // arr[i-2] phan tu sau dau cham
    {
        printf("%c",arr[i]-32);  // in ky tu viet hoa
       
    }else
    {
    printf("%c",arr[i]); // in ky tu viet thuong
    }
  }
  
}


void chu_thuong (char arr[])  // in ra toan bo chu viet thuong
{
  int length=string_length(arr);  // kich thuoc cua mang
  printf(" \n\nIn ra chu in thuong \n");
   for (int i = 0; i < length; i++)
   {
    if(arr[i]>='a' || arr[i]==' ' || arr[i]=='.' ) // a==97 va phim cach 32
    {
        printf("%c",arr[i]);
    }
    else{
        printf("%c",arr[i]+32);  // 32 la khoang cach tu in hoa den in thuong
    }
   } 
}

void chu_hoa (char arr[])  // in ra toan bo chu viet hoa
{
  int length=string_length(arr);
  printf(" \n\n In ra chu in hoa \n");
   for (int i = 0; i < length; i++)
   {
    if(arr[i]<='Z' || arr[i]==' ' ) // a==97 va phim cach 32
    {
        printf("%c",arr[i]);
    }
    else{
        printf("%c",arr[i]-32);  // 32 la khoang cach tu in hoa den in hoa
    }
   } 
}


int main(int argc, char const *argv[])
{
   printf("Chuoi ban dau:\n %s", arr);  // in chuoi ban dau
    type_text temp; // goi ham con tro
    temp.text=(char*)malloc(sizeof(char)*temp.size);
    int i, j, n;
    n = string_length(arr); // kich thuoc cua mang

    printf("\n\nChuoi sau khi da duoc dao nguoc:\n");

    for (i = n - 1; i >= 0; --i) {

        for (j = 0; i >= 0 && arr[i] != ' '; --i, ++j) // tim chu cuoi cung trong mang toi dau Backspace dung lai
        {
            temp.text[j] = arr[i]; //luu gia tri vao con tro
        }
        temp.text[j] = '\0';
        string_reverse(temp.text);  // goi ham dao nguoc 
        printf("%s ", temp.text);    // in chuoi ra man hinh
    }

    after_cham(arr);

    chu_thuong(arr);

    chu_hoa(arr);
    
    return 0;
}