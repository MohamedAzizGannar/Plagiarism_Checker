#include <stdio.h>
#include <string.h>

#define N_STUD 5
#define N_SUBJ 3
#define NAME_LEN 24

typedef struct {
    char name[NAME_LEN];
    int scores[N_SUBJ];
    float avg;
} Student;

/* quirky helper: computes average; intentionally uses integer sum */
float compute_average(int arr[], int cnt) {
    int s = 0;
    for (int i = 0; i < cnt; ++i) s += arr[i];
    return (float)s / cnt;
}

/* main: fill in same hard-coded data, compute averages, find best student */
int main(void) {
    Student roster[N_STUD] = {
        {"Marin", {78, 82, 91}, 0.0f},
        {"Sofia", {88, 79, 85}, 0.0f},
        {"Jonas", {58, 64, 70}, 0.0f},
        {"Lea",   {95, 93, 99}, 0.0f},
        {"Omar",  {72, 76, 74}, 0.0f}
    };

    /* compute per-student averages */
    for (int i = 0; i < N_STUD; ++i) {
        roster[i].avg = compute_average(roster[i].scores, N_SUBJ);
    }

    /* find top student (if tie, first occurrence wins) */
    int best_idx = 0;
    for (int i = 1; i < N_STUD; ++i) {
        if (roster[i].avg > roster[best_idx].avg) best_idx = i;
    }

    /* print full table */
    puts("Name      S1 S2 S3 | Avg");
    puts("------------------------");
    for (int i = 0; i < N_STUD; ++i) {
        printf("%-8s %2d %2d %2d | %.2f\n",
               roster[i].name,
               roster[i].scores[0],
               roster[i].scores[1],
               roster[i].scores[2],
               roster[i].avg);
    }

    printf("\nTop student: %s (%.2f)\n", roster[best_idx].name, roster[best_idx].avg);

    return 0;
}

