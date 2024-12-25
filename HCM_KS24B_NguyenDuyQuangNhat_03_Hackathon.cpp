#include <stdio.h>
#include <math.h>
int main(){
    while(1){
        printf("\n================MENU==============\n");
        printf("1.nhap si phan tu va gtri cho mang\n");
        printf("2.In cac phna tu trong mang theo hang ngang\n");
        printf("3.dem so luong cac so nguyen to trong mang\n");
        printf("4.tim gia tri nho thu 2 trong amgn\n");
        printf("5.them phna tu vao mang\n");
        printf("6.xoa phan tu\n");
        printf("7.Sap xep mang giam dan\n");
        printf("8.kiem tra phan tu co ton tai trong mang khong\n");
        printf("9.xoa toan bo phan tu trung lap trong mang va hien thi phan tu con lai\n");
        printf("10.dao nguoc thu tu phan tu trong mang\n");
        printf("11.thoat\n");
        printf("lua chon cua ban: ");
        int command;
        scanf("%d", &command);
        int n,arr[100],count,min,min2,position,value,t,temp,left,right,mid,flag,array[100],index,key;
        switch(command) {
            case 1:
                printf("\nnhap so phan tu co tring mang: ");
                scanf("%d", &n);
                printf("nhap vao mang:\n");
                for(int i=0;i<n;i++){
                    printf("arr[%d]= ", i);
                    scanf("%d", &arr[i]);
                }break;
            case 2:
                for(int i=0;i<n;i++){
                    printf("arr[%d]= %d, ",i, arr[i]);
                } break;
            case 3:
                count=0;
                for(int i=0;i<n;i++){
                    if(arr[i]>=2){
                        flag=1;
                        for(int j=2;j<sqrt(arr[i]);j++){
                            if(arr[i]%j==0){
                                flag=0;
                                break;
                            }
                        }if(flag){
                            count=count+1;
                        }
                    }
                } printf("\ntrong mang co %d so prime", count);
                break;
            case 4:
                min=arr[0];
                for(int i=0;i<n;i++){
                    if(min>arr[i]){
                        min=arr[i];
                    }
                }min2=arr[0];
                for(int i=0;i<n;i++){
                    if(min2>arr[i] && min2>min){
                        min2=arr[i];
                    }
                } printf("\nphan tu nho thu 2 trong mang: %d",min2);
                break;
            case 5:
                printf("nhap vij tri can them vao mang: ");
                scanf("%d", &position);
                printf("nhap gia tri nuom them: ");
                scanf("%d", &value);
                for(int i=n;i>position;i--){
                    arr[i]=arr[i-1];
                }arr[position]=value;
                n++;
                break;
            case 6:
                printf("nhap vi tri can xoa: ");
                scanf("%d", &position);
                for(int i=position;i<n;i++){
                    arr[i]=arr[i+1];
                }n--;
                break;
            case 7:
                printf("\nmang sau insertion sort giam dan: ");
                for(int i=1;i<n;i++){
                    key=arr[i];
                    t=i-1;
                    while(t>=0 && arr[t]<key){
                       arr[t+1]=arr[t];
                       t--;
                    }arr[t+1]=key;
                }for(int i=0;i<n;i++){
                    printf("%d ",arr[i]);
                } break;
            case 8:
                printf("nap pnha tu can tim: ");
                scanf("%d", &value);
                for(int i=0;i<n-1;i++){
                    for(int j=0;j<n-i-1;j++){
                        if(arr[j]>arr[j+1]){
                            temp=arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        }
                    }
                }left=0,right=n-1,mid=left+(right-left)/2;
                flag=1;
                while(left>=right){
                    if(arr[mid]==value){
                        printf("\nphan tu %d nam ow arr[%d]", value,mid);
                        flag=0;
                    }else if(arr[mid]<value){
                        left=mid+1;
                    }else {
                        right=mid-1;
                    }
                }if(flag){
                    printf("\nkhong tim thay %d trong mang", value);
                }break;
            case 9:
                for(int i=0;i<n-1;i++){      //neu ke cuoi khong trung voi cuoi thi cuoi cung khong trung?con duyet ca cuoi thi se trung khi vong j duyet den cuoi??
                    for(int j=1;j<n;j++){
                        if(arr[i]==arr[j]){
                            for(int k=j;k>n;k++){
                                arr[j]=arr[j+1];
                            }n--;
                        }
                    }
                }printf("\nmang chi gom cac phan tu doc nhat: ");
                for(int i=0;i<n;i++){
                    printf("%d ", arr[i]);
                } break;
            case 10:
                index=0;
                for(int i=n-1;i>=0;i--){
                    array[index]=arr[i];
                    index++;
                }index=0;
                for(int i=0;i<n;i++){
                    arr[i]=array[index];
                    index++;
                }printf("\nmang sau dao nguoc: ");
                for(int i=0;i<n;i++){
                    printf("%d ");
                }break;
            case 11:
                printf("\nban da thoat chuong trinh");
                return 0;
            default:
                printf("nhap sai vui long hanp lai");
                break;
        }
    }return 0;
}
