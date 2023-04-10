#include<istream>
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include <vector>
using namespace std;

typedef struct {

    uint8_t id;
    uint8_t stt;
    char temon[20];
    float gia;
}thongtinmon;


typedef struct 
{
    thongtinmon Mon;
    uint8_t SoLuong;
}slmon;

typedef struct 
{
    uint8_t soBan;
    bool trangthai;
    slmon somon[20];
    vector<slmon>soluongMon;
}thongtinBan;

class Quanly
{
    private:
   static uint8_t soluongBan;
    vector<thongtinmon> DataMon;
    public:
  
    void setsoluongBan(const uint8_t soluongBan);
    void them_mon(thongtinmon mon);
    void sua_mon(uint8_t id);
    void xoa_mon(uint8_t id);
    void hienthimon();

    uint8_t getsoluongBan();
    uint8_t getID();
    uint8_t getSTT();
    string gettenmon(uint8_t id);
    float getgia();
    vector<thongtinmon> getDataMon();
};


vector<thongtinmon> Quanly::getDataMon()
{
    return DataMon;
}



void Quanly::them_mon(thongtinmon mon)
{
    mon.id=DataMon.size()+100;
    DataMon.push_back(mon);
   
}

void Quanly::sua_mon(uint8_t id)
{
   uint8_t ID;
    int i=0,gia;
    printf("nhap ID mon :");
    scanf("%d",&ID);
    // for (Quanly &ql : dataquanly)  
    // {
    //     if(ql.getID()==ID) //kiểm tra xem id nhập vào có trong dữ liệu đã nhập chưa
    //     {
    //         printf("gia Ban can sua:");
    //         scanf("%d",&gia);

    //         dataquanly.erase(dataquanly.begin()+i);
    //         printf("Ban da thay doi thanh conng !!!\n");
    //         return;
    //     }
    //     i++;
    // }
    //  printf("ID khong ton tai !!\n");
}

void Quanly::xoa_mon(uint8_t id)
{
    uint8_t ID;
    int i=0;
    printf("nhap ID mon can xoa :");
    scanf("%d",&ID);
    // for (Quanly &ql : dataquanly)  
    // {
    //     if(ql.getID()==ID) //kiểm tra xem id nhập vào có trong dữ liệu đã nhập chưa
    //     {
    //         dataquanly.erase(dataquanly.begin()+i);
    //         printf("Ban da thay doi thanh conng !!!\n");
    //         return;
    //     }
    //     i++;
    // }
     printf("ID khong ton tai !!\n");
}

void Quanly::hienthimon()
{
    Quanly ql;
    printf("Danh sach mon\n");
    printf("STT\t ID\t Ten_mon\t Gia\n");

    
     printf("%d\t %d\t %s\t %.2f\t\n",ql.getSTT(),ql.getID(),ql.gettenmon().c_str(),ql.getgia());
    
}


class Nhanvien 
{
    private:
    //Quanly ql;
    vector<thongtinmon>DataMon;
    vector<thongtinBan>DataBan;
    
    public:
    void hienthiBan(uint8_t Ban);
    Nhanvien(Quanly ql);
    void goimon(thongtinBan soBan);
    void hienthidanhsachmon();
    void tinhtien();
};

Nhanvien::Nhanvien(Quanly ql)
{
   for (int i = 0; i < ql.getDataMon().size(); i++)
   {
        DataMon.push_back(ql.getDataMon()[i]);
   }
   thongtinBan Ban;

   for (int i = 0; i < ql.getsoluongBan(); i++)
   {
    Ban.soBan=i+1;
    Ban.trangthai=false;
    DataBan.push_back(Ban);
   }

}

void Nhanvien::hienthiBan(uint8_t Ban)
{
    thongtinBan table;
    DataBan[table.soBan -1]=Ban;
}

void Nhanvien::goimon(thongtinBan soBan)
{
    // ql.hienthimon();
    // int id,soluong;
    // printf("nhap id mon:");
    // scanf("%d",&id);
    // printf("So luong :");
    // scanf("%d",&soluong);
     DataBan[soBan.soBan -1]=soBan;
}

void Nhanvien::hienthidanhsachmon()
{
  
    printf("Danh sach mon da goi \n");
    printf("STT\t ID\t Ten_mon\t soluong\t Gia\n");   

}

class Menu
{
    private:
    Quanly ql;
    Nhanvien nv(Quanly ql);
    public:
    void hienthiBan(uint8_t Ban);
    void hamQuanly();
    void hamNhanvien();

};

void Menu::hienthiBan(uint8_t soBan)
{
    thongtinBan Ban;
    Ban.soBan=soBan;
    int menu= 0;
    int id;
    printf("Ban :%d",soBan);
    switch (menu)
    {
    case 1:
      printf("goi mon");
      ql.hienthimon();
      do{
        slmon soluongmon;
      printf("nhap ID :");
      scanf("%d",&id);
      soluongmon.Mon=ql.gettenmon(id);
      printf(" nhap so luong mon :");
      scanf("%d",&soluongmon.SoLuong);
      Ban.soBan.push_back(soluongmon);
      }while();
      Ban.trangthai=true;
      nv(ql).goimon(Ban);
        break;
    
    default:
        break;
    }
}

enum{DAT_Ban=1,TMON,XMON,DSMON};

void Menu::hamQuanly()
{
    int key,sl_Ban;
    do
    {
        printf("1.Dat so luong Ban\n");
        printf("2.Them mon\n");
        printf("3.Xoa mon\n");
        printf("4.Danh sach mon\n");
        printf("nhap so can chon :");
        scanf("%d",&key);

    } while (key);
    switch (key)
    {
    case DAT_Ban:
         printf("Nhap so luong Ban :");
         scanf("%d",&sl_Ban);
         ql.setsoluongBan(sl_Ban);
        break;
    case TMON:
         thongtinmon mon;
         printf(" nhap mon Ban muon them :");
         scanf("%s",&mon.temon);
         printf("nhap gia tien :");
         scanf("%d",&mon.gia);
         ql.them_mon(mon);
    case XMON:
    printf("nhap ID can xoa:");
    break;      
    default:
        break;
    } 
}


void Menu::hamNhanvien()
{
    int Ban;
    printf("Nhan vien Ban\n");
    printf("Ban");
    for (int i = 0; i < ql.getsoluongBan(); i++)
    {
       printf("| %d\t",i);
    }
    printf("\nChon Ban tu 1 - %d\n",ql.getsoluongBan());  // hien thi danh sach ban da co
    printf("nhap .");
    // check Ban co ton tai khong
   // printf("nhap so mon ban can them vao trong danh sach:");
    scanf("%d",&Ban);
    hienthiBan(Ban);


    
}


int main(int argc, char const *argv[])
{
    

    
    return 0;
}
