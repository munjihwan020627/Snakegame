#include<ncurses.h>
#include<time.h>
#include <thread>
#include"items.h"



void draw_maps() {
    int rows{22}; 
    int cols{22};
    

    // 중앙을 기준으로 x, y축 그리기
    mvaddch(0,0, 'X');
    mvaddch(22,22, 'X');
    mvaddch(22,0, 'X');
    mvaddch(0,22, 'X');


    for (int c = 1; c < cols; ++c) {
        mvaddch(0, c, '0');
        mvaddch(22, c, '0');

    }

    // y축 그리기
    for (int r = 1; r < rows; ++r) {
        mvaddch(r,0, '0');
        mvaddch(r,22, '0');

    }



}





int main() {
    int score = 0;
    time_t start_time = time(nullptr);
    initscr();            // ncurses 모드 시작
    cbreak();             // 입력을 즉시 읽기
    noecho();             // 입력 문자를 화면에 출력하지 않음
    keypad(stdscr, TRUE); // 특수 키 입력 활성화
    draw_maps();
    refresh();
    time_t last_time_create = start_time; // timetocreate 마지막 실행 시간 저장
    while (true) {

        time_t current_time = time(nullptr);
        item i;
        i.timetocreate(); // 5초마다 호출

        if (current_time - last_time_create >= 5) {
            item i;
            i.timetocreate(); // 5초마다 호출
            last_time_create = current_time; // 마지막 실행 시간을 현재 시간으로 업데이트
        }

        refresh(); // 화면 갱신
    }
    
    refresh();
        
    
    refresh();            // 화면 갱신
    getch();              // 키 입력 대기
    endwin();             // ncurses 모드 종료

    return 0;
}
