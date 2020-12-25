#include <stdio.h>
#include <stdlib.h>
struct sinhvien{
    int   msv;
    char  HoTen[32];
    char  GioiTinh[4];
    char  NgaySinh[12];
    char  DiaChi[128];
    float DiemTB;
};
typedef struct sinhvien sinhvien;
struct NODE{
    struct sinhvien  data;
    struct NODE      *next;
    struct NODE      *previous;
};
typedef struct NODE node;
struct LIST{
    node *pFirst;
    node *pLast;
};
typedef struct LIST list;
void     KhoiTaoList(list *l);
node*    KhoiTaoNode(sinhvien sv);
sinhvien KhoiTaoSV();
void     ThongTinSV(sinhvien sv);

void  Them_LanDau(list *l);
void  Them(list *l, sinhvien sv, int index);
void  ThemDau(list *l, sinhvien sv);
void  ThemCuoi(list *l, sinhvien sv);
node* TimKiem_MSV(list *l, int msv);
void  SuaDoi_MSV(list *l, int msv);
void  Xoa_MSV(list *l,int msv);
void  DanhSach(list *l);
void  DanhSach_Gioi(list *l);
void  DanhSach_HocLai(list *l);

void  XoaManHinh();
void  Menu_Selections(list *l);
// ____main____
void  main(){
    list l;
    KhoiTaoList(&l);
    Menu_Selections(&l);
};
// ____end____
void KhoiTaoList(list *l){
    l->pFirst = NULL;
    l->pLast = NULL;
};
node* KhoiTaoNode(sinhvien sv){
    node *p;
    p = malloc(sizeof(node));
    if (p==NULL){
        printf("khong du bo nho de cap phat\n");
        return NULL;
    }
    p->data = sv;
    p->next = NULL;
    p->previous = NULL;
    return p;
};
sinhvien KhoiTaoSV(){
    sinhvien sv;
    printf("[  nhap thong tin sinh vien  ]\n");
    printf("msv\t:"); scanf("%d",&sv.msv);
    fflush(stdin);
    printf("HoTen\t:");gets(sv.HoTen);
    printf("GioiTinh:");scanf("%s",&sv.GioiTinh);
    printf("NgaySinh:");scanf("%s",&sv.NgaySinh);
    fflush(stdin);
    printf("DiaChi\t:");gets(sv.DiaChi);
    printf("DiemTb\t:");scanf("%f",&sv.DiemTB);
    return sv;
};
void ThongTinSV(sinhvien sv){
    printf("* %-6d | %-20s| %-4s| %-10s | %20s| %-5.2f*\n",sv.msv,sv.HoTen,sv.GioiTinh,sv.NgaySinh,sv.DiaChi,sv.DiemTB);
};
void Them_LanDau(list *l){
    unsigned int n;
    printf("nhap so sv ban dau:");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        sinhvien sv = KhoiTaoSV();
        ThemDau(l,sv);
    }
};
void Them(list *l, sinhvien sv, int index){
    if(l->pFirst == NULL){
        ThemDau(l,sv);
    }else{
        node* p = l->pFirst;
        int i=1;
        while(i<=index && p->next != NULL){
            p = p->next;
            i++;
        };
        node* newnode       = KhoiTaoNode(sv);
        node* p_next        = p->next;
        p_next->previous    = newnode;
        newnode->previous   = p;
        newnode->next       = p->next;
        p->next             = newnode;
    }
};
void ThemDau(list *l, sinhvien sv){
    node* p = KhoiTaoNode(sv);
    if(l->pFirst == NULL){
        l->pFirst = p;
        l->pLast = p;
    }else{
        node* node_1 = l->pFirst;
        node_1->previous = p;
        p->next = node_1;
        l->pFirst = p;
    }
};
void ThemCuoi(list *l, sinhvien sv){
    node *p;
    p = malloc(sizeof(node));
    if(l->pFirst == NULL){
        l->pFirst = p;
        l->pLast = p;
    }else{
        node* node_last = l->pLast;
        node_last->next = p;
        p->previous = node_last;
        l->pLast = p;
    }
};
node* TimKiem_MSV(list *l, int msv){
    node* p = l->pFirst;
    while( p != NULL){
        if(p->data.msv == msv)
            return p;
        p = p->next;
    }
    return p;
};
void SuaDoi_MSV(list *l, int msv){
    if(l->pFirst == NULL){
        printf("DANH SACH TRONG\n");
    }else{
        node* node_sv = TimKiem_MSV(l,msv);
        if(node_sv ==NULL){
            printf("khong ton tai\n");
        }else{
            ThongTinSV(node_sv->data);
            sinhvien sv_rep = KhoiTaoSV();
            node_sv->data   = sv_rep;
            printf("%s\n", "---sau sua doi---");
            ThongTinSV(node_sv->data);
        }
    }
};

void Xoa_MSV(list *l,int msv){
    node* p          = TimKiem_MSV(l,msv);
    if( p == NULL)
        printf("khong ton tai msv: %d\n",msv);
    else{
        node* p_prev     = p->previous;
        node* p_next     = p->next;
        if(p_prev != NULL)
            p_prev->next     = p_next;
        if(p_next != NULL)
            p_next->previous = p_prev;
        free(p);
    }
};
void DanhSach(list *l){
    if(l->pFirst == NULL){
        printf("DANH SACH TRONG\n");
    }else{
        node* p = l->pFirst;
        printf("********************************************************************************\n");
        printf("*                           DANH SACH SINH VIEN                                *\n");
        printf("********************************************************************************\n");
        printf("*  msv   |       Ho & Ten      | GT  | Ngay Sinh  |       Dia Chi       | DTB  *\n");
        while( p != NULL){
            ThongTinSV(p->data);
            p = p->next;
        };
        printf("********************************************************************************\n");
    }
};
void DanhSach_Gioi(list *l){
    if(l->pFirst == NULL){
        printf("DANH SACH TRONG\n");
    }else{
        node* p = l->pFirst;
        printf("********************************************************************************\n");
        printf("*                           DANH SACH SINH VIEN GIOI                           *\n");
        printf("********************************************************************************\n");
        printf("*  msv   |       Ho & Ten      | GT  | Ngay Sinh  |       Dia Chi       | DTB  *\n");
        while( p != NULL){
            if( p->data.DiemTB >= 8.0)
                ThongTinSV(p->data);
            p = p->next;
        };
        printf("********************************************************************************\n");
    }
};
void DanhSach_HocLai(list *l){
    if(l->pFirst == NULL){
        printf("DANH SACH TRONG\n");
    }else{
        node* p = l->pFirst;
        printf("********************************************************************************\n");
        printf("*                           DANH SACH SINH VIEN HOC LAI                        *\n");
        printf("********************************************************************************\n");
        printf("*  msv   |       Ho & Ten      | GT  | Ngay Sinh  |       Dia Chi       | DTB  *\n");
        while( p != NULL){
            if(p->data.DiemTB < 5.0)
                ThongTinSV(p->data);
            p = p->next;
        };
        printf("********************************************************************************\n");
    }
};
void XoaManHinh(){
    system("cls");
};
void Menu_Selections(list *l){
    printf("********************************************************************************\n");
    printf("*                              BANG DIEU KHIEN                                 *\n");
    printf("********************************************************************************\n");
    printf("*  1. Khoi tao lai danh sach sinh vien.                                        *\n");
    printf("*                                                                              *\n");
    printf("*  2. Tim kiem sinh vien theo ma sinh vien.                                    *\n");
    printf("*                                                                              *\n");
    printf("*  3. Hien thi danh sach sinh vien.                                            *\n");
    printf("*  4. Hien thi danh sach sinh vien dat GIOI.                                   *\n");
    printf("*  5. Hien thi danh sach sinh vien HOC LAI.                                    *\n");
    printf("*                                                                              *\n");
    printf("*  6. Them sinh vien moi vao dau danh sach.                                    *\n");
    printf("*  7. Them sinh vien moi vao cuoi danh sach.                                   *\n");
    printf("*  8. Them sinh vien moi vao vi tri.                                           *\n");
    printf("*                                                                              *\n");
    printf("*  9. Sua doi thong tin sinh vien theo ma sinh vien.                           *\n");
    printf("* 10. Xoa sinh vien theo msv.                                                  *\n");
    printf("*                                                                              *\n");
    printf("* 11. Xoa man hinh (clean screen).                                             *\n");
    printf("* 99. Thoat chuong trinh.                                                      *\n");
    printf("********************************************************************************\n");

    sinhvien sv;
    node*    node_sv;
    int      vitri;
    int      msv;
    int      luachon = 0;
    printf("nhap lua chon:");
    scanf("%d",&luachon);
    switch(luachon){
        case 1:
            KhoiTaoList(l);
            Them_LanDau(l);
            Menu_Selections(l);
            break;
        case 2:
            printf("nhap ma sinh vien:");
            scanf("%d",&msv);
            node_sv = TimKiem_MSV(l,msv);
            ThongTinSV(node_sv->data);
            Menu_Selections(l);
            break;
        case 3:
            DanhSach(l);
            Menu_Selections(l);
            break;
        case 4:
            DanhSach_Gioi(l);
            Menu_Selections(l);
            break;
        case 5:
            DanhSach_HocLai(l);
            Menu_Selections(l);
            break;
        case 6:
            sv = KhoiTaoSV();
            ThemDau(l,sv);
            Menu_Selections(l);
            break;
        case 7:
            sv = KhoiTaoSV();
            ThemCuoi(l,sv);
            Menu_Selections(l);
            break;
        case 8:
            sv = KhoiTaoSV();
            printf("vi tri them:");
            scanf("%d",&vitri);
            Them(l,sv,vitri);
            Menu_Selections(l);
            break;
        case 9:
            printf("nhap ma sinh vien:");
            scanf("%d",&msv);
            SuaDoi_MSV(l,msv);
            Menu_Selections(l);
            break;
        case 10:
            printf("nhap ma sinh vien:");
            scanf("%d",&msv);
            Xoa_MSV(l,msv);
            Menu_Selections(l);
            break;
        case 11:
            XoaManHinh();
            Menu_Selections(l);
            break;
        case 99:
            break;
        default:
            XoaManHinh();
            Menu_Selections(l);
    }
};

