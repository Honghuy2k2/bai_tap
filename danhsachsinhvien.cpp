#include<istream>
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class SinhVien
{
    private:

     uint8_t id;
    char name_student[20];
    char gioitinh[4];
    uint8_t age_student;
    float diemtoan;
    float diemly;
    float diemhoa;
    float Average;
    char Academic_ability[11];
    public:

    SinhVien(const char name[],const char gioitinh[],const uint8_t age,const float toan,const float ly,const float hoa);
    void setID(const uint8_t id);
    void setname_student(const char name[]);
    void setgioitinh(const char gioitinh[]);
    void setage_student(uint8_t age);
    void setdiemtoan(float toan);
    void setdiemly(float ly);
    void setdiemhoa(float hoa);

    uint8_t getID();
    char *getname_student();
    char *getgioitinh();
    uint8_t getage_student();
    float getdiemtoan();
    float getdiemly();
    float getdiemhoa();
    float getAverage();
    char * getAcademic_ability();
};



SinhVien::SinhVien(const char name[],const char gioitinh[],const uint8_t age,const float toan,const float ly,const float hoa)
{
    strcpy(SinhVien::name_student,name);
    strcpy(SinhVien::gioitinh,gioitinh);
    SinhVien::age_student=age;
    SinhVien::diemtoan=toan;
    SinhVien::diemly=ly;
    SinhVien::diemhoa=hoa;
     static uint8_t id=0;
    SinhVien::id=id;
    id++;
}

void SinhVien::setID(const uint8_t id)
{
    SinhVien::id=id;
}
   

uint8_t SinhVien::getID()
{

    return SinhVien::id;
}

void SinhVien::setname_student(const char name[])
{
    strcpy(SinhVien::name_student,name);  // dùng để copy giá trị của chuỗi
}

char *SinhVien::getname_student()
{
    return SinhVien::name_student;
}
void SinhVien::setage_student(uint8_t age)
{
    SinhVien::age_student=age;

}

uint8_t SinhVien::getage_student()
{
    return age_student;
}

void SinhVien::setgioitinh(const char gioitinh[])
{
    if(strcmp((char*)"nam",gioitinh)!=0  && strcmp((char *)"nu",gioitinh)!=0)  // so sanh 2 cai name xem no co giong nhau khong
    {                                                                          //neu giong 1 trong 2 name thi xuong else
        printf("ERROR !! Gioi tinh khong hop le \n");

    }
    else
    {
        strcpy(SinhVien::gioitinh,gioitinh);
    }
}

char *SinhVien::getgioitinh()
{
    return gioitinh;
}

void SinhVien::setdiemtoan(float toan)
{
   
    SinhVien::diemtoan=toan;
}

float SinhVien::getdiemtoan()
{
    return diemtoan;
}
void SinhVien::setdiemhoa(float hoa)
{
    SinhVien::diemhoa=hoa;
}

float SinhVien::getdiemhoa()
{
    return diemhoa;
}void SinhVien::setdiemly(float ly)
{
    SinhVien::diemly=ly;
}

float SinhVien::getdiemly()
{
    return diemly;
}


float SinhVien::getAverage()
{
     Average=(diemtoan+diemly+diemhoa)/3;
    return SinhVien::Average;
}



char* SinhVien::getAcademic_ability()
{ 
    if(getAverage()>=8)  // kiểm tra xem điểm trung bình lớn hơn 8 hay không
    {
        strcpy(SinhVien::Academic_ability,"Gioi");  // dùng để copy giá trị của chuỗi
    }else if(getAverage()>=6.5) // kiểm tra xem điểm trung bình lớn hơn 6.5 hay không
    {
        strcpy(SinhVien::Academic_ability,"Kha");// dùng để copy giá trị của chuỗi

    }else if(getAverage()>=5) // kiểm tra xem điểm trung bình lớn hơn 5 hay không
    {
        strcpy(SinhVien::Academic_ability,"Trung binh");// dùng để copy giá trị của chuỗi
    }
    else{
        strcpy(SinhVien::Academic_ability,"Yeu");// dùng để copy giá trị của chuỗi
    }

    return SinhVien::Academic_ability;
}



class Menu 
{
    private:
    vector<SinhVien> danhsachSinhVien;
    public:
    void themSinhVien();
    void capnhatthongioitinhinSV_bangID();
    void xoasinhvienboiID();
    void timkiemSinhVien();
    void sapxepAverageSinhVien();
    void sapxepSinhVienTheoname();
    void Hienthidanhsach();
};

#define NHAP_THONG_TIN(noidung,dinhdang,bien,dieukien)\
   do                                                 \
     {                                               \
        printf(noidung); scanf(dinhdang,bien);       \
     } while (dieukien);                             \

void Menu::themSinhVien()     // nhập sinh viên vào danh sách
{
    char name[20],gioitinh[5];
    int age;
    int key;
    float Dtoan,Dly,Dhoa;
    do{
    // printf("khai bao thong tin sinh vien :\n");
     printf("Nhap ten :");
     scanf("%s",&name);
     //fflush(stdin);
     printf("nhap gioi tinh :");scanf("%s",&gioitinh);
    // fflush(stdin);
    NHAP_THONG_TIN("nhap tuoi :","%d",&age,age >100 || age <18);
    NHAP_THONG_TIN("nhap diem toan :","%f",&Dtoan,Dtoan >10 || Dtoan <0);
    NHAP_THONG_TIN("nhap diem ly :","%f",&Dly,Dly >10 || Dly <0);
    NHAP_THONG_TIN("nhap diem hoa :","%f",&Dhoa,Dhoa >10 || Dhoa <0);
    SinhVien sv(name,gioitinh,age,Dtoan,Dly,Dhoa);  // gọi đến contructor
    danhsachSinhVien.push_back(sv);  // đẩy 1 phần tử vào sau cung của vector
    printf("nhan 1 de them tiep sinh vien !!\nNhan phim bat ki de qua lai Menu!!!!\n");
    scanf("%d",&key);
    }while (key==1);  // nếu key =1 thì quay lại do để tiếp tục

}

void Menu::capnhatthongioitinhinSV_bangID()   // Thay đổi dữ liệu của sinh viên bằng ID
{
    uint8_t id;
    int i=0;
    printf("nhap ID cua sinh vien :");
    scanf("%d",&id);
     for(SinhVien &sv :danhsachSinhVien)  //duyệt các phần tử trong vector
    {
       if(sv.getID()==id)  //kiểm tra xem id nhập vào có trong dữ liệu đã nhập chưa
       {
        danhsachSinhVien.erase(danhsachSinhVien.begin()+i);  // xóa phần tử thứ i
        themSinhVien();
        printf("Ban da thay doi thanh conng !!!\n");
        return;
       }
       i++;
    }
    printf("Sinh vien khong ton tai !!\n");
}

void Menu::xoasinhvienboiID()
{
   // SinhVien sv;
    uint8_t id;
    int i=0;
    printf("nhap ID can xoa :");
    scanf("%d",&id);
    for(SinhVien sv :danhsachSinhVien)  //duyệt các phần tử trong vector
    {
        if(sv.getID()==id)
        {
            danhsachSinhVien.erase(danhsachSinhVien.begin()+i);  // xóa phần tử thứ i
            printf("Ban da xoa thanh cong !!!\n");
            return ;
        }
        i++;
    }
   // danhsachSinhVien.pop_back();

}

void Menu::timkiemSinhVien()
{
    char name[20];
    //SinhVien sv;
    printf("nhap name sinh vien can tim :");
    scanf("%s",&name);
    for(SinhVien sv :danhsachSinhVien)  //duyệt các phần tử trong vector
    {
         if(strcmp(sv.getname_student(),name)==0)  // so sánh 2 chuỗi với nhau ,trả về 0 thì chuỗi bằng nhau
         {
             printf("ID\t Ten\t Gioitinh\t tuoi\t Toan\t  Ly\t  Hoa\t DiemTB\t Hocluc\t \n");
              printf("%d\t %s\t  %s\t\t %d\t %.2f\t %.2f\t %.2f\t %.2f\t %s\t \n",sv.getID(),sv.getname_student(),sv.getgioitinh(),
        sv.getage_student(),sv.getdiemtoan(),sv.getdiemly(),sv.getdiemhoa(),sv.getAverage(),sv.getAcademic_ability());
                  return ;
         }
    }
        printf("Khong tim thay sinh vien trong danh sach.\n");
}


void Menu::sapxepAverageSinhVien()  //sắp xếp danh sách sinh viên theo tên theo thứ tự giảm dần từ giỏi -> yếu
{
   int n=danhsachSinhVien.size();  // lấy số lượng của sinh viên trong danh sách
   for(int i=0;i<n;i++)
   {
    for (int j = 1+i; j<n; j++)
    {
       if(danhsachSinhVien[i].getAverage()<danhsachSinhVien[j].getAverage())  //so sánh điểm trung bình
       {
        /* hóa vị các giá trị */
        SinhVien tmp=danhsachSinhVien[i];   
        danhsachSinhVien[i]=danhsachSinhVien[j];
        danhsachSinhVien[j]=tmp;
       }
    }
   }
   printf("Sap xep diem trung binh thanh cong!!!\n");
}

void Menu::sapxepSinhVienTheoname()  //sắp xếp danh sách sinh viên theo tên theo thứ tự tăng dần bảng chữ cái 
{

   int n=danhsachSinhVien.size(); // lấy số lượng của sinh viên trong danh sách
   for(int i=0;i<n;i++)
   {
    for (int j = 1+i; j<n; j++)
    {
        if (strcmp(danhsachSinhVien[i].getname_student(),danhsachSinhVien[j].getname_student() ) > 0)  // chuỗi lớn hơn 0 thì chuỗi str1 lớn hơn chuỗi str2
       {
        /* hóa vị các giá trị */
        SinhVien tmp=danhsachSinhVien[i];
        danhsachSinhVien[i]=danhsachSinhVien[j];
        danhsachSinhVien[j]=tmp;
       }
    }
   }
   printf("Sap xep ten thanh cong!!!\n");
}



void Menu::Hienthidanhsach()  // hiện thị danh sách các sinh viên
{
    printf("ID\t Ten\t Gioitinh\t tuoi\t Toan\t  Ly\t  Hoa\t DiemTB\t Hocluc\t \n");
    for(SinhVien sv : danhsachSinhVien)  //duyệt từng phần tử của vector
    {
        printf("%d\t %s\t  %s\t\t %d\t %.2f\t %.2f\t %.2f\t %.2f\t %s\t \n",sv.getID(),sv.getname_student(),sv.getgioitinh(),
        sv.getage_student(),sv.getdiemtoan(),sv.getdiemly(),sv.getdiemhoa(),sv.getAverage(),sv.getAcademic_ability());
    }
}



int main(int argc, char const *argv[])
{
    Menu sv;
    int value;
 while(true) {
        printf ("            CHUONG TRINH QUAN LY SINH VIEN              \n");
        printf ( "*************************MENU**************************\n");
        printf ( "**  1. Them sinh vien.                               **\n");
        printf ( "**  2. Cap nhat thong tin sinh vien boi ID.          **\n");
        printf ( "**  3. Xoa sinh vien boi ID.                         **\n");
        printf ( "**  4. Tim kiem sinh vien theo name.                 **\n");
        printf ( "**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n");
        printf ( "**  6. Sap xep sinh vien theo name.                  **\n");
        printf ( "**  7. Hien thi danh sach sinh vien.                 **\n");
        printf ( "**  0. Thoat                                         **\n");
        printf ( "*******************************************************\n");
        printf ( "Nhap tuy chon: ");
        scanf("%d",&value);
        switch(value){
            case 1:
            printf("Them Sinh vien :\n");
            sv.themSinhVien();
            break;
             case 2:
            printf("Cap nhat thong tin sinh vien boi ID\n");
            sv.capnhatthongioitinhinSV_bangID();
            break;
            case 3:
            printf("Xoa sinh vien boi ID\n");
            sv.xoasinhvienboiID();
            break;
            case 4 :
            printf("Tim kiem sinh vien theo name\n");
            sv.timkiemSinhVien();
            break;
            case 5:
            printf("Sap xep sinh vien theo diem trung binh (GPA)\n");
            sv.sapxepAverageSinhVien();
            break;
            case 6:
            printf("Sap xep sinh vien theo name\n");
            sv.sapxepSinhVienTheoname();
            break;
            case 7:
             printf ("Hien thi danh sach sinh vien\n");
             sv.Hienthidanhsach();
             break;
             case 0:
             printf("Thoat chuong trinh!!");
             return 0;
             default:
             printf("\nKhong co chuc nang nay!");
             printf( "\nHay chon chuc nang trong hop menu.");
             break;
        }
  
     }
        return 0;
}
