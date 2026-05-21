#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
    char name[100];
    int age;
    char gender[100];
} Person;

void nhap(Person* nguoi, int n){
    for (int i = 0; i < n; i++){
        printf("\n- Nhap nguoi thu nhat:\n");
        inp(&nguoi[i]);
    }
}

void inp(Person* nguoi){
    getchar();printf("+ Ten: "); scanf("%[^\n]s", nguoi->name);
    printf("+ Tuoi: "); scanf("%d", &nguoi->age);
    getchar();printf("+ Gioi tinh: ");scanf("%[^\n]s", nguoi->gender);
}

int main(){
    int n;
    printf("* Nhap so nguoi: ");scanf("%d", &n);
    Person* nguoi = (Person*) malloc(n * sizeof(Person));
    nhap(nguoi, n);
    //xuat(nguoi);
}