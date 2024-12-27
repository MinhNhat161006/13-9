#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void nhapMaTran(int mat[MAX][MAX], int hang, int cot) {
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Phần tử [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void inMaTran(int mat[MAX][MAX], int hang, int cot) {
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void inGoc(int mat[MAX][MAX], int hang, int cot) {
    printf("%d %d\n", mat[0][0], mat[0][cot - 1]);
    printf("%d %d\n", mat[hang - 1][0], mat[hang - 1][cot - 1]);
}

void inBien(int mat[MAX][MAX], int hang, int cot) {
    for (int i = 0; i < cot; i++) printf("%d ", mat[0][i]);
    for (int i = 1; i < hang - 1; i++) printf("%d ", mat[i][cot - 1]);
    for (int i = cot - 1; i >= 0; i--) printf("%d ", mat[hang - 1][i]);
    for (int i = hang - 2; i > 0; i--) printf("%d ", mat[i][0]);
    printf("\n");
}

void inDuongCheo(int mat[MAX][MAX], int hang, int cot) {
    printf("Chéo chính: ");
    for (int i = 0; i < hang && i < cot; i++) printf("%d ", mat[i][i]);
    printf("\nChéo phụ: ");
    for (int i = 0; i < hang && i < cot; i++) printf("%d ", mat[i][cot - i - 1]);
    printf("\n");
}

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void inNguyenTo(int mat[MAX][MAX], int hang, int cot) {
    printf("Số nguyên tố: ");
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            if (laSoNguyenTo(mat[i][j])) {
                printf("%d ", mat[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int mat[MAX][MAX] = {0}, hang, cot, luaChon;
    printf("Nhập số hàng và số cột: ");
    scanf("%d %d", &hang, &cot);

    do {
        printf("\nMENU\n");
        printf("1. Nhập giá trị các phần tử của mảng\n");
        printf("2. In giá trị các phần tử của mảng theo ma trận\n");
        printf("3. In ra các phần tử ở góc theo ma trận\n");
        printf("4. In ra các phần tử nằm trên đường biên theo ma trận\n");
        printf("5. In ra các phần tử nằm trên đường chéo chính và chéo phụ theo ma trận\n");
        printf("6. In ra các phần tử là số nguyên tố theo ma trận\n");
        printf("7. Thoát\n");
        printf("Lựa chọn: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMaTran(mat, hang, cot);
                break;
            case 2:
                inMaTran(mat, hang, cot);
                break;
            case 3:
                inGoc(mat, hang, cot);
                break;
            case 4:
                inBien(mat, hang, cot);
                break;
            case 5:
                inDuongCheo(mat, hang, cot);
                break;
            case 6:
                inNguyenTo(mat, hang, cot);
                break;
            case 7:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ!\n");
        }
    } while (luaChon != 7);

    return 0;
}
