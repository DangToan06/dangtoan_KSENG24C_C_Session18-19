#include<stdio.h>
#include<string.h>

struct dish {
    int id;
    char name[100];
    double price;
};

typedef struct dish Dish;

Dish menu[100] = {
    {1,"Com rang thap cam", 40.000},
    {2,"Mi xao",35.000},
    {3,"Com rang dua bo", 39.000},
    {4,"Pho bo", 30.000},
    {5,"Bun bo hue", 50.000},
};

void export(Dish menu, int i){
    printf("%d. %s. %.3lf\n", menu.id, menu.name, menu.price);
}

void exportDs(Dish *menu, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d. %s. %.3lf\n", i + 1, menu[i].name, menu[i].price);
    }
}

void addMenu(Dish *menu, int *n, int position, char *addDish, int price){
    *n =*n + 1;
    for(int i = *n; i >= position; i--){
        menu[i] = menu[i - 1];
    }
    strcpy(menu[position - 1].name,addDish);
    menu[position - 1].price = price;
    for(int i = 0; i < *n ; i++){
        printf("%d. %s. %.3lf\n", i + 1, menu[i].name, menu[i].price);
    }
}

void swapMenu(Dish *menu, int n, int position, char *swapDish, int price){
    strcpy(menu[position - 1].name,swapDish);
    menu[position - 1].price = price;
    for(int i = 0; i < n ; i++){
        printf("%d. %s. %.3lf\n", i + 1, menu[i].name, menu[i].price);
    }
}

void deleMenu(Dish *menu, int *n, int position){
    *n =*n - 1;
    for(int i = position - 1; i <= *n; i++){
        menu[i] = menu[i + 1];
    }
    for(int i = 0; i < *n ; i++){
        printf("%d. %s. %.3lf\n", i + 1, menu[i].name, menu[i].price);
    }
}

void upSort(Dish *menu, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(menu[j].price > menu[j+1].price){
                Dish tmp = menu[j];
                menu[j] = menu[j + 1];
                menu[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d. %s. %.3lf\n", i + 1, menu[i].name, menu[i].price);
    }
}

void downSort(Dish *menu, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(menu[j].price < menu[j+1].price){
                Dish tmp = menu[j];
                menu[j] = menu[j + 1];
                menu[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d. %s. %.3lf\n", i + 1, menu[i].name, menu[i].price);
    }
}

void linearSearch(Dish *menu, int n, char *name){
    for(int i = 0; i < n; i++){
        if(strcmp(menu[i].name, name) == 0){
            printf("%d. %s. %.3lf\n", i + 1, menu[i].name, menu[i].price);
            return;
        }
    }
    
}

void binarySearch(Dish *menu, int n, double price){
    int max = n - 1;
    int min = 0;
    int mid;
    while(min <= max){
        mid = (max + min)/2;
        if(menu[mid].price == price){
            printf("%d. %s. %.3lf\n", mid + 1, menu[mid].name, menu[mid].price);
            return;
        }else if(menu[mid].price < price){
            min = mid + 1;
        }else if(menu[mid].price > price){
            max = mid - 1;
        }
    }
}

void printMenu(){
    printf("\n\tMENU\n");
    printf("1.In ra gia tri cac phan tu co trong menu mon an\n");
    printf("2.Them mot pha tu vao vi tri chi dinh\n");
    printf("3.Sua mot phan tu o vi tri chi dinh\n");
    printf("4.Xoa mot phan tu o vi tri chi dinh\n");
    printf("5.Sap xep cac phan tu \n");
    printf("6.Tim kiem phan tu theo name nhap vao\n");
    printf("7.Thoat\n");
    printf("\nNhap lua chon cua ban: ");
}

int main(){
    int number, n = 5, position, addPrice, length, swapPrice;
    char addDish[100], swapDish[100], chose, searchName[100];
    double searchPrice;
    do{
        printMenu();
        scanf("%d", &number);
        switch (number){
        case 1:
            exportDs(menu, n);
            break;
        case 2:
            getchar();
            printf("Nhap mon an ban muon them: ");
            fgets(addDish,100,stdin);
            length = strlen(addDish);
            if(length > 0 && addDish[length - 1] == '\n'){
                addDish[length - 1] = '\0';
            } 
            printf("Nhap gia tri mon an ban vua them: ");
            scanf("%d", &addPrice);
            fflush(stdin);
            printf("Nhap vi tri ban muon them do an: ");
            scanf("%d", &position);
            while(position <= 0 || position > n){
                printf("Vi tri ban nhap khong ton tai vui long nhap lai: ");
                scanf("%d", &position);
            }
            addMenu(menu, &n, position, addDish, addPrice);
            break;
        case 3:
            getchar();
            printf("Nhap mon an ban muon thay the: ");
            fgets(swapDish, 100, stdin);
            length = strlen(swapDish);
            if(length > 0 && swapDish[length - 1] == '\n'){
                swapDish[length - 1] = '\0';
            }
            printf("Nhap gia tri mon an ban vua thay the: ");
            scanf("%d", &swapPrice);
            fflush(stdin);
            printf("Nhap vi tri ban muon thay the do an: ");
            scanf("%d", &position);
            while(position <= 0 || position > n){
                printf("Vi tri ban nhap khong ton tai vui long nhap lai: ");
                scanf("%d", &position);
            }
            swapMenu(menu, n, position, swapDish, swapPrice);
            break;
        case 4:
            getchar();
            printf("Nhap vi tri mon an ban muon xoa: ");
            scanf("%d", &position);
            deleMenu(menu, &n, position);
            break;
        case 5:
            printf("a.Tang dan theo price\n");
            printf("b.Giam dan theo price\n");
            printf("Moi ban lua chon: ");
            getchar();
            scanf("%s", &chose);
            switch(chose){
                case 'a':
                case 'A':
                    printf("Phan tu sau khi duoc xap xep la:\n");
                    upSort(menu, n);
                    break;
                case 'b':
                case 'B':
                    printf("Phan tu sau khi duoc xap xep la:\n");
                    downSort(menu, n);
                    break;
                default:
                    break;
            }
            break;
        case 6:
            printf("a.Tim kiem tuyen tinh\n");
            printf("b.Tim kiem nhi phan\n");
            printf("Moi ban lua chon: ");
            getchar();
            scanf("%c", &chose);
            switch(chose){
                case 'a':
                case 'A':
                    getchar();
                    printf("Moi ban nhap ten mon an muon tim: ");
                    fgets(searchName, 100, stdin);
                    length = strlen(searchName);
                    if(length > 0 && searchName[length - 1] == '\n'){
                        searchName[length - 1] = '\0';
                    } 
                    linearSearch(menu, n, searchName);
                    break;
                case 'b':
                case 'B':
                    getchar();
                    printf("Moi ban nhap name mon an muon tim: ");
                    scanf("%lf", &searchPrice);
                    binarySearch(menu, n, searchPrice);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
        }
    }while(number != 7);
    return 0;
}