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

STUDENT s_list_align[MAX_SEMESTER]={0};

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

                s_list_align[number - 1] = *(s + i);
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
    int isHere = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp((s + i)-> name, name) == 0 || strcmp((s + i) -> class_name, name) == 0) {
            printf("%3d번: ", i + 1);
            print_student(s + i);

            isHere = 1;
        }
    }

    if (!isHere)
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

    printf("총 발표명 수: %d명\n", size);
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
        
        if (strcmp(name, "exit") != 0)
            find_student(s_list_align, sizeof(s_list_align) / sizeof(STUDENT), name);
    } while (strcmp(name, "exit") != 0);

    // #1 - 3
    int n; // do - while 반복문 안에서, 발표리스트의 추가, 삭제, 종료를 위해 사용하는 변수

    STUDENT s_list_presentation[MAX_PRESENTATION_LIST]; // 발표리스트를 저장하기 위한 구조체 배열
    int s_list_presentation_size = 0; // 발표리스트의 사이즈를 저장하기 위한 변수
    
    print_student_list(s_list, sizeof(s_list) / sizeof(STUDENT)); // 학생들의 인적사항을 쭉 보기 위해 사용한다.

    do {
        // 발표리스트에 학생을 추가할지, 삭제할지, 종료할지 입력을 받는다.
        printf("\n발표리스트에 추가하려면 1번, 삭제하려면 2번, 종료하려면 3번을 누르세요: ");
        scanf("%d", &n);

        // 발표리스트에 학생을 추가하는 logic
        if (n == 1) {
            int student_number;

            // 발표리스트에 추가할 학생 번호를 입력받는다.
            printf("발표리스트에 추가할 학생 번호를 입력하세요: ");
            scanf("%d", &student_number);

            int isEmpty = 1; // 발표리스트에 이미 중복된 학생이 있는지 없는지 구분하기 위해 선언했다.

            // student_number가 범위를 벗어나면, "잘못된 번호입니다." 를 출력한다.
            if (student_number <= 0 || student_number > sizeof(s_list_align) / sizeof(STUDENT)) {
                printf("잘못된 번호입니다.\n");
            }

            // 그렇지 않다면, s_list_presentation을 탐색하고, 학생이 중복되어 있는지 탐색한다.
            else {
                // 학생이 중복되어 있는지 탐색하는 logic이다.
                // 학생들은 각자를 구별할 수 있는 학번을 가지고 있기 때문에,
                // 학번이 같은지 확인하고, 같은 학번을 가지고 있다면 "이미 발표리스트에 있는 학생입니다." 를 출력한다.
                
                for (int i = 0; i < s_list_presentation_size; i++) {
                    if (strcmp(s_list_align[student_number - 1].ID, s_list_presentation[i].ID) == 0 ) {
                        printf("이미 발표리스트에 있는 학생입니다.\n");

                        // 출력이 끝나면, isEmpty을 0으로 바꿔 뒤의 logic을 건너뛸 수 있도록 하고, break를 통해 반복문을 벗어난다.
                        isEmpty = 0;
                        break;
                    }
                }

                // 발표리스트에 추가가 되어 잇지 않다면, s_list_presentation 배열에 추가한다.
                // 학생을 추가했으므로, s_list_presentation_size를 증가시킨다.
                // print_presentation_list()를 call해서 발표리스트를 출력한다.
                if (isEmpty) {
                    s_list_presentation[s_list_presentation_size] = s_list_align[student_number - 1];
                    s_list_presentation_size++;

                    print_presentation_list(s_list_presentation, s_list_presentation_size);
                }
            }
        }

        // 발표리스트에 학생을 삭제하는 logic
        else if (n == 2) {
            int student_number;
            
            // 발표리스트에서 삭제할 학생 번호를 입력받는다.
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

            // 그렇지 않다면, 해당하는 index의 학생을 삭제한다.
            // for문을 통해서, 배열을 해당 index부터 정렬한다.
            // 정렬하지 않으면, 출력에 문제가 생기기 때문이다.
            else {
                for (int i = student_number - 1; i < s_list_presentation_size; i++) {
                    s_list_presentation[i] = s_list_presentation[i + 1];
                }

                // 정렬이 끝나면, 학생을 한 명 삭제했으므로, s_list_presentation_size의 크기를 감소시킨다.
                // print_presentation_list()를 call해서 발표리트를 출력한다.
                s_list_presentation_size--;
                print_presentation_list(s_list_presentation, s_list_presentation_size);
            }
        }

        // 리스트의 학생 수가 MAX_PRESENTATION_LIST와 같아지면, do-while 반복문을 종료한다.
        if (s_list_presentation_size == MAX_PRESENTATION_LIST) {
            break;
        }
        
    } while(n != 3); // n이 3이라면 do - while 반복문을 종료한다.

    return 0;
}