#include<stdio.h>
#include<string.h>

int main(){
	struct Dish{
		int id;
		char name[40];
		double price;
	};
	struct Dish menu[100] = {
	    {1,"fish",100},
		{2,"cat",200},
		{3,"dog",300},
		{4,"shark",1000},
		{5,"coca",10},
	};
	int choice=0;
	int size=5;
	do {
		printf("MENU\n");
		printf("1.in ra gia tri cac phan tu co trong menu\n");
		printf("2.them mot phan tu vao vi tri cuoi\n");
		printf("3.sua mot phan tu o vi tri chi dinh\n");
		printf("4.xoa mot phan tu o vi tri cuoi\n");
		printf("5.sap xep cac phan tu\n");
		printf("6.tim kiem phan tu theo name nhap vao\n");
		printf("7.thoat\n");
		printf("lua chon cua ban: ");
		scanf("%d",&choice);
		fflush(stdin);
		switch (choice){
			case 1:
				for(int i=0;i<size;i++){
					printf("%d,%s,%.2f\n", menu[i].id, menu[i].name, menu[i].price);
				}
				break;
			case 2:
				printf("Nhap ten mon muon them: ");
	            fgets(menu[size].name,sizeof(menu[size].name),stdin);
	            menu[size].name[strlen(menu[size].name)-1] = '\0';
	            printf("Nhap gia tien: ");
	            scanf("%lf",&menu[size].price);
	            size++;
	            for (int i=0;i<size; i++){ 
                	printf("%d. %s: %lf\n",menu[i].id,menu[i].name,menu[i].price);
            	}        
            break;	
			case 3:{
				int stt;
				struct Dish DishSua;
				printf("nhap vi tri can sua: ");
				scanf("%d",&stt);
				printf("nhap id,name,price moi: ");
				scanf("%d %s %lf",&DishSua.id,DishSua.name,&DishSua.price);
				menu[stt]=DishSua;
				break;
			}
			case 4:
				size--;
            	for (int i=0;i<size; i++){ 
                	if(menu[i].id==0){
                    	break;
                	}
                printf("%d. %s: %lf\n",menu[i].id,menu[i].name,menu[i].price);
            }
            break;
			case 5:
				for(int i=0;i<size-1;i++){
					for(int j=i+1;j<size;j++){
						if(menu[i].price>menu[j].price) {
							struct Dish temp=menu[i];
							menu[i]=menu[j];
							menu[j]=temp;
						}
					}
				}
				break;
			case 6:{
				char search[40];
				printf("nhap ten mon an can tim: ");
				scanf("%s",search);
				int test=0;
				for(int i=0;i<size;i++){
					if(strcmp(menu[i].name,search)==0){
						printf("Tim thay: %d,%s,%.2f\n", menu[i].id, menu[i].name, menu[i].price);
						test=1;
						break;
					}
				}
				if(!test){
					printf("Khong tim thay mon an\n");
				}
				break;
			}
			default:
				printf("lua chon khong hop le\n");
		}
	}while(choice!=7);
	return 0;
}

