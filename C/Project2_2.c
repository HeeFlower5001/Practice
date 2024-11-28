#include <stdio.h>
#include <string.h>

/* 변수 선언 부분: 수정하지 마세요 */
#define price_americano 3500
#define price_icetea 3000
#define price_smoothie 5000
#define price_carrot 7000
#define price_cheese 6000
#define price_choco 5500
/* ------------------------------ */

int main(){
    /* 변수 선언 부분: 수정하지 마세요 */
    int num_americano;
    int num_icetea;
    int num_smoothie;
    int num_carrot;
    int num_cheese;
    int num_choco;
    int num_set1;
    int num_set2;
    int total_price_set1;
    int total_price_set2;
    int total_price;
    /* ------------------------------ */

    // 반드시 다음 코드 사용해서 출력하세요. 
    // 주문 받을 때: printf("주문하고자 하는 음료(커피, 아이스티, 스무디)와 케잌(당근, 치즈, 초코)의 갯수를 각각 입력하세요:\n"); 이용하여 출력
    // 음료 갯수가 10개 넘었을 때: printf("음료 갯수가 10개를 넘었습니다. 다시 주문해주세요.\n\n"); 이용하여 출력
    // 케잌 갯수가 10개 넘었을 때: printf("케잌 갯수가 10개를 넘었습니다. 다시 주문해주세요.\n\n"); 이용하여 출력
    
    /*put your answer*/
    int num_drink_sum;
    int num_cake_sum;

    // 음료와 케잌의 갯수의 입력 받기
    do {
        printf("주문하고자 하는 음료(커피, 아이스티, 스무디)와 케잌(당근, 치즈, 초코)의 갯수를 각각 입력하세요:\n");
        scanf("%d %d %d %d %d %d", &num_americano, &num_icetea, &num_smoothie, &num_carrot, &num_cheese, &num_choco);

        num_drink_sum = num_americano + num_icetea + num_smoothie;
        num_cake_sum = num_carrot + num_cheese + num_choco;

        if (num_drink_sum > 10 ) {
            printf("음료 갯수가 10개를 넘었습니다. 다시 주문해주세요.\n\n");
        }

        else if (num_cake_sum > 10) {
            printf("케잌 갯수가 10개를 넘었습니다. 다시 주문해주세요.\n\n");
        }

    } while(num_drink_sum > 10 || num_cake_sum > 10);

    // 세트 1번 계산
    num_set1 = 0;
    total_price_set1 = 0;

    while (num_drink_sum >= 2 && num_cake_sum >= 2) {
        int num_drink = 0;
        int num_cake = 0;
        int sum_price = 0;

        while (num_drink < 2) {
            if (num_smoothie > 0) {
                num_smoothie--;
                num_drink++;
                
                sum_price += price_smoothie;
            }

            else if (num_americano > 0) {
                num_americano--;
                num_drink++;

                sum_price += price_americano;
            }

            else if (num_icetea > 0) {
                num_icetea--;
                num_drink++;

                sum_price += price_icetea;
            }
        }

        while (num_cake < 2) {
            if (num_carrot > 0) {
                num_carrot--;
                num_cake++;

                sum_price += price_carrot;
            }

            else if (num_cheese > 0) {
                num_cheese--;
                num_cake++;

                sum_price += price_cheese;
            }

            else if (num_choco > 0) {
                num_choco--;
                num_cake++;

                sum_price += price_choco;
            }
        }

        num_set1++;
        total_price_set1 += (sum_price * 8 / 10);

        num_drink_sum = num_americano + num_icetea + num_smoothie;
        num_cake_sum = num_carrot + num_cheese + num_choco;
    }

    // 세트 2번 계산
    num_set2 = 0;
    total_price_set2 = 0;

    while (num_drink_sum  >= 2 && num_cake_sum >= 1) {
        int num_drink = 0;
        int num_cake = 0;
        int sum_price = 0;

        while (num_drink < 2) {
            if (num_smoothie > 0) {
                num_smoothie--;
                num_drink++;

                sum_price += price_smoothie;
            }

            else if (num_americano > 0) {
                num_americano--;
                num_drink++;

                sum_price += price_americano;
            }

            else if (num_icetea > 0) {
                num_icetea--;
                num_drink++;

                sum_price += price_icetea;
            }
        }

        while (num_cake < 1) {
            if (num_carrot > 0) {
                num_carrot--;
                num_cake++;

                sum_price += price_carrot;
            }

            else if (num_cheese > 0) {
                num_cheese--;
                num_cake++;

                sum_price += price_cheese;
            }

            else if (num_choco > 0) {
                num_choco--;
                num_cake++;

                sum_price += price_choco;
            }
        }

        num_set2++;
        total_price_set2 += (sum_price * 9 / 10);

        num_drink_sum = num_americano + num_icetea + num_smoothie;
        num_cake_sum = num_carrot + num_cheese + num_choco;
    }

    // total_price 계산
    total_price = total_price_set1 + total_price_set2 + (num_smoothie * price_smoothie) + (num_americano * price_americano) + (num_icetea * price_icetea) + (num_carrot * price_carrot) + (num_cheese * price_cheese) + (num_choco * price_choco);

    /* 출력 부분: 수정하지 마세요 */ 
    printf("\n품목      갯수   금액\n");
    if (num_set1 > 0)
        printf("세트1    %4d %7d\n",num_set1, total_price_set1);
    if (num_set2 > 0)
        printf("세트2    %4d %7d\n", num_set2, total_price_set2);
    if (num_americano > 0)
        printf("커피     %4d %7d\n", num_americano, price_americano * num_americano);
    if (num_icetea > 0)
        printf("아이스티 %4d %7d\n", num_icetea, price_icetea * num_icetea);
    if (num_smoothie > 0)
        printf("스무디   %4d %7d\n", num_smoothie, price_smoothie * num_smoothie);
    if (num_carrot > 0)
        printf("당근케잌 %4d %7d\n", num_carrot, price_carrot * num_carrot);
    if (num_cheese > 0)
        printf("치즈케잌 %4d %7d\n", num_cheese, price_cheese * num_cheese);
    if (num_choco > 0)
        printf("초코케잌 %4d %7d\n", num_choco, price_choco * num_choco);
    printf("----------------------------\n");
    printf("총 지불 금액 %8d\n", total_price);
    /* ------------------------- */

    return 0;
}