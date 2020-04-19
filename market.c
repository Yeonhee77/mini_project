#include "product.h"
#include <stdio.h>

int main(void) {
    	Product p[100];
    	int menu;
    	int count=0;
    	int del;
	int no;
	int index=0;

	count = loadProduct(p, index);
	index = count;

    	while(1) {
        	readMenu(p[count]);
        	scanf("%d", &menu);

        	if(menu==0) {
            		break;
 		}else if(menu==1){
            		if(count!=0) {
                		listProduct(p, index);
            		}else{
                		printf("등록된 제품이 없습니다.\n");
           		}
        	}else if(menu==2){
            		addProduct(&p[index++]);
            		count++;
        	}else if(menu==3){
			listProduct(p, index);
			printf("어느 제품을 수정하시겠습니까? (0: 취소): ");
			scanf("%d", &no);

			if(no==0) {
				printf("취소되었습니다.\n");
			}else{
            			updateProduct(&p[no-1]);
			}
        	}else if(menu==4){
			listProduct(p, index);
			printf("어느 제품을 삭제하시겠습니까? (0: 취소): ");
			scanf("%d", &no);
			
			if(no==0) {
				printf("취소되었습니다.\n");
			}else{
            			printf("정말 삭제하시겠습니까? (예: 1, 아니오: 0)");
            			scanf("%d", &del);

				if(del==0) {
					printf("취소되었습니다.\n");
				}else{
					deleteProduct(&p[no-1]);
					count--;
				}
    			}
		}else if(menu==5){
			if(count==0){
				printf("데이터가 없습니다.\n");
			}else{
				saveProduct(p, index);
			}
		}
	}
    	printf("프로그램이 종료 되었습니다.\n");
	#ifdef DEBUG
		printf("debug[main.c] : call listProduct()\n");
 
	#endif
		listProduct(p, index);

    	return 0;
}
