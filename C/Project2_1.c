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
void print_student_list(const STUDENT *s, int size) {
    int number = 1;

    printf("\n%8s  %-11s %-5s %10s %14s\n", "번호", "이름", "학번", "학기", "수강과목");

    for (int semester_number = 1; semester_number <= MAX_SEMESTER; semester_number++) {
        for (int i = 0; i < size; i++) {
            if ( (s + i) -> semester == semester_number) {
                printf("%3d번: ", number);
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
    int number = 1;
    int isHere = 0;

    for (int semester_number = 1; semester_number <= MAX_SEMESTER; semester_number++) {
        for (int i = 0; i < size; i++) {
            if ( (s + i) -> semester == semester_number) {
                if (strcmp((s + i)-> name, name) == 0 || strcmp((s + i) -> class_name, name) == 0) {
                    printf("%3d번: ", number);
                    print_student(s + i);

                    isHere = 1;
                }
            
                number++;
            }
        }
    }

    if (isHere != 1)
        printf("해당 학생 정보를 찾을 수 없습니다.");
}

/* print_presentation_list 함수 구현 */
// 반드시 다음 코드 사용해서 출력하세요.
// 가장 윗줄: printf("<< 발표리스트 >>\n"); 이용하여 출력
// 학생 번호: printf("%3d번: ",변수); 이용하여 출력
// 학생 정보: print_student 함수 이용하여 출력
/* -------------------------- */
void print_presentation_list (const STUDENT *s, int size) {
    printf("<< 발표리스트 >>\n");
    
    for (int i = 0; i < size; i++) {
        printf("%3d번: ", i + 1);
        print_student(s + i);
    }

    printf("총 발표명 수 : %d명\n", size);
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

    // #1 - 1
    print_student_list(s_list, sizeof(s_list) / sizeof(STUDENT));

    // #1 - 2
    char name[BUF_SIZE];

    do {
        printf("\n찾으려는 학생의 이름 또는 수강과목을 입력하세요(종료는 exit): ");
        scanf("%s", name);
        find_student(s_list, sizeof(s_list) / sizeof(STUDENT), name);
    } while (strcmp(name, "exit") != 0);

    // #1 - 3
    int n = 0;

    STUDENT s_list_presentation[MAX_PRESENTATION_LIST];
    int s_list_presentation_size = 0;
    
    print_student_list(s_list, sizeof(s_list) / sizeof(STUDENT));

    do {
        int student_number;

        printf("\n발표리스트에 추가하려면 1번, 삭제하려면 2번, 종료하려면 3번을 누르세요: ");
        scanf("%d", &n);

        if (n == 1) {
            printf("발표리스트에 추가할 학생 번호를 입력하세요: ");
            scanf("%d", &student_number);

            int number = 1;
            int isEmpty = 1;

            STUDENT student_presentation;

            if (student_number <= 0 || student_number > sizeof(s_list) / sizeof(STUDENT)) {
                printf("잘못된 번호입니다.\n");
                continue;
            }

            for (int semester_number = 1; semester_number <= MAX_SEMESTER; semester_number++) {
                for (int i = 0; i < sizeof(s_list) / sizeof(STUDENT); i++) {
                    if ( (s_list + i) -> semester == semester_number) {
                        if (number == student_number) {
                            student_presentation = s_list[i];
                        }

                        number++;
                    }
                }
            }

            for (int i = 0; i < s_list_presentation_size; i++) {
                if (strcmp(student_presentation.ID, s_list_presentation[i].ID) == 0 ) {
                    printf("이미 발표리스트에 있는 학생입니다.\n");
                    isEmpty = 0;

                    break;
                }
            }

            if (isEmpty) {
                s_list_presentation[s_list_presentation_size] = student_presentation;
                s_list_presentation_size++;

                print_presentation_list(s_list_presentation, s_list_presentation_size);
            }
        }

        else if (n == 2) {
            printf("발표리스트에서 삭제할 학생 번호를 입력하세요: ");
            scanf("%d", &student_number);

            int number = 1;
            int isEmpty = 1;

            STUDENT student_presentation = s_list_presentation[student_number - 1];

            for (int i = 0; i < s_list_presentation_size; i++) {
                if (strcmp(student_presentation.ID, s_list_presentation[i].ID) == 0) {
                    for (int j = i; j < s_list_presentation_size; j++) {
                        s_list_presentation[j] = s_list_presentation[j + 1];
                    }

                    
                    s_list_presentation_size--;
                    isEmpty = 0;

                    break;
                }
            }

            if (isEmpty) {
                printf("삭제할 학생이 없습니다.\n");
            }

            else {
                print_presentation_list(s_list_presentation, s_list_presentation_size);
            }
        }

        if (s_list_presentation_size == MAX_PRESENTATION_LIST) {
            break;
        }
        
    } while(n != 3);

    return 0;
}