#include <stdio.h>
#include <string.h>

#define BUF_SIZE 64
#define MAX_PRESENTATION_LIST 3
#define MAX_SEMESTER 8

typedef struct STUDENT {
    /*put your answer*/
    char name[BUF_SIZE];
    char ID[BUF_SIZE];
    int semester;
    char class_name[BUF_SIZE];
} STUDENT;

STUDENT s_list_align[]={0};

/* 출력 부분: 수정하지 마세요 */
void print_student(const STUDENT *s){
    printf("%-9s %-5s %5d %10s\n", s->name, s->ID, s->semester, s->class_name);
}
/* -------------------------- */


/* print_student_list 함수 구현 */
// 반드시 다음 코드 사용해서 출력하세요. 
// 가장 윗줄: printf("\n%8s  %-11s %-5s %10s %14s\n", "번호", "이름", "학번", "학기", "수강과목"); 이용하여 출력
// 학생 번호: printf("%3d번: ",변수); 이용하여 출력
// 학생 정보: print_student 함수 이용하여 출력 
/* -------------------------- */
void print_student_list(const STUDENT *s, STUDENT *s_sort, int size) {
    int number = 0;

    printf("\n%8s  %-11s %-5s %10s %14s\n", "번호", "이름", "학번", "학기", "수강과목");

    for (int semester_number = 1; semester_number <= MAX_SEMESTER; semester_number++) {
        for (int i = 0; i < size; i++) {
            if ( (s + i) -> semester == semester_number) {
                *(s_sort + number) = *(s + i);
                printf("%3d번: ", number + 1);
                print_student(s + i);

                number++;
            }
        }
    }
}


/* find_student 함수 구현 */
// 반드시 다음 코드 사용해서 출력하세요.
// 학생 번호: printf("%3d번: ",변수); 이용하여 출력
// 학생 정보: print_student 함수 이용하여 출력
/* -------------------------- */
void find_student(const STUDENT *s, int size, char *name) {
    int isNotHere = 1;

    if (strcmp(name, "exit") != 0) {
        for (int i = 0; i < size; i++) {
            if (strcmp((s + i)->name, name) == 0 || strcmp((s + i)->class_name, name) == 0) {
                printf("%3d번: ", i + 1);
                print_student(s + i);

                isNotHere = 0;
            }
        }

        if (isNotHere == 1)
            printf("해당 학생 정보를 찾을 수 없습니다.");
    }
}

/* print_presentation_list 함수 구현 */
// 반드시 다음 코드 사용해서 출력하세요.
// 가장 윗줄: printf("<< 발표리스트 >>\n"); 이용하여 출력
// 학생 번호: printf("%3d번: ",변수); 이용하여 출력
// 학생 정보: print_student 함수 이용하여 출력
/* -------------------------- */
void print_presentation_list (const STUDENT *s) {
    printf("<< 발표리스트 >>\n");
    printf("%3d번: ", 1);
}

int main(void)
{
    /* 입력 부분: 수정하지 마세요 */
	STUDENT s_list[] = {
		{"Jihyeon", "2018001", 8, "class1" }, 
		{"Sujung", "2022015", 2, "class2"}, 
		{"Minjung", "2021016", 3, "class2"},
		{"Minji", "2021013", 4, "class4"},
		{"Sujung", "2020033", 5, "class3"},
		{"Heejoon", "2020010", 6, "class4"},
		{"Ayoon", "2019022", 5, "class1"},
        {"Jihyeon", "2019001", 7, "class5"},	
	};
    /* -------------------------- */

    // #1-2 구현 시 반드시 다음 코드 사용해서 출력하세요.
    // printf("\n찾으려는 학생의 이름 또는 수강과목을 입력하세요(종료는 exit): ");
    
    // #1-3 구현 시 반드시 다음 코드 사용해서 출력하세요.
    // printf("\n발표리스트에 추가하려면 1번, 삭제하려면 2번, 종료하려면 3번을 누르세요: ");
    // printf("발표리스트에 추가할 학생 번호를 입력하세요: ");
    // printf("이미 발표리스트에 있는 학생입니다.\n");
    // printf("잘못된 번호입니다.\n");   
    // printf("발표리스트에서 삭제할 학생 번호를 입력하세요: ");
    // printf("삭제할 학생이 없습니다.\n");
    
    /* Put your answer */
    STUDENT student_sort[sizeof(s_list) / sizeof(STUDENT)];
    STUDENT student_presentation[sizeof(s_list) / sizeof(STUDENT)];

    char name[BUF_SIZE];
    int number = 0;

    // #1 - 1
    print_student_list(s_list, student_sort, sizeof(s_list) / sizeof(STUDENT));

    // #1 - 2
    do {
        printf("\n찾으려는 학생의 이름 또는 수강과목을 입력하세요(종료는 exit): ");
        scanf("%s", name);
        find_student(student_sort, sizeof(student_sort) / sizeof(STUDENT), name);
    } while (strcmp(name, "exit") != 0);


    // #1 - 3
    print_student_list(s_list, student_sort, sizeof(s_list) / sizeof(STUDENT));

    do {
        int student_number = 0;

        printf("\n발표리스트에 추가하려면 1번, 삭제하려면 2번, 종료하려면 3번을 누르세요: ");
        scanf("%d", &number);

        if (number == 1) {
            printf("발표리스트에 추가할 학생 번호를 입력하세요: ");
            scanf("%d", &student_number);

            if ()

            print_presentation_list(student_presentation);
        }

        else if (number == 2) {
            printf("발표리스트에서 삭제할 학생 번호를 입력하세요: ");
            scanf("%d", &student_number);

            print_presentation_list(student_presentation);
        }



    } while(number != 3 || sizeof());


    return 0;
}