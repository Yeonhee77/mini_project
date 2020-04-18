#include <stdio.h>

typedef struct {
    char name[20]; //제품명
    int weight; //중량
    int price; //가격
    int stdp; //표준가격
    int star; //별점수
} Product;

void readMenu(Product p); //전체 메뉴를 보여주는 함수
void listProduct(Product *p, int count); //전체 제품 리스트를 보여주는 함수
int addProduct(Product *p); //제품을 추가하는 함수
int updateProduct(Product *p); //기존 등록된 제품을 수정하는 함수
int deleteProduct(Product *p); //등록된 제품을 제거하는 함수

void saveProduct(Product *p, int count); //File에 저장하는 함수

int loadProduct(Product *p, int count); //저장된 파일을 불러오는 함수

void searchProduct(Product *p, int count); //제품을 검색하는 함수
