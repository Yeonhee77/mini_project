#include "product.h"
#include <string.h>

void readMenu(Product p) {
	printf("*****제품 관리 프로그램*****\n");
	printf("1. 제품 조회\n");
	printf("2. 제품 등록\n");
	printf("3. 제품 수정\n");
   	printf("4. 제품 삭제\n");
   	printf("5. 파일 저장\n");
   	printf("6. 제품 검색\n");
   	printf("0. 프로그램 종료\n");
   	printf("원하는 메뉴는? ");
}

void listProduct(Product *p, int count) {
   	printf("제품 이름   중량   가격\n");
	
	for(int i=0;i<count;i++) {
		if(p[i].price!=-1) {
  			printf("%s\t      %d\t %d\n", p[i].name, p[i].weight, p[i].price);
		}
	}
}

int addProduct(Product *p) {

    	while(getchar()!='\n');
   	printf("제품 이름은? ");
    	fgets(p->name, sizeof(p->name), stdin);
    	p->name[strlen(p->name)-1] = '\0';

    	printf("제품의 중량은?(g) ");
    	scanf("%d", &p->weight);
    	printf("제품의 가격은? ");
    	scanf("%d", &p->price);

    	return 1;
}

int updateProduct(Product *p) {

    	while(getchar()!='\n');
    	printf("제품 이름은? ");
    	fgets(p->name, sizeof(p->name), stdin);
    	p->name[strlen(p->name)-1] = '\0';

    	printf("제품의 중량은?(g) ");
    	scanf("%d", &p->weight);
    	printf("제품의 가격은? ");
    	scanf("%d", &p->price);

    	printf("수정이 완료되었습니다.\n");

   	 return 1;
}

int deleteProduct(Product *p) {
    	p->price = -1;

	printf("삭제 완료되었습니다.\n");

	return 1;
}

void saveProduct(Product *p, int count) {
	FILE *fp = fopen("product.txt", "wt");

	for(int i=0;i<=count;i++) {
		if(p[i].price == -1) continue;
		fprintf(fp, "%s %d %d\n", p[i].name, p[i].weight, p[i].price);
	}
	
	fclose(fp);

	printf("저장되었습니다\n");
}

int loadProduct(Product *p, int count) {
	FILE *fp = fopen("product.txt", "rt");

	if(fp==NULL) return 0;

	for(count=0;;count++) {
		fscanf(fp, "%s %d %d\n", p[count].name, &p[count].weight, &p[count].price);
	if(feof(fp)) break;
	}

	fclose(fp);

	return count;
}
