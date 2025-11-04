#include <stdio.h>
#include <string.h>

#define STUDENTS 5
#define SUBJECTS 3
#define MAXNAME 24

typedef struct {
    char fullname[MAXNAME];
    int marks[SUBJECTS];
    float average;
} Pupil;

/* helper to average integer marks (same integer-sum style) */
float avg_marks(int m[], int mcount) {
    int total = 0;
    for (int k = 0; k < mcount; ++k) {
        total += m[k];
    }
    return (float)total / mcount;
}

/* main: identical dataset and flow but with renamed identifiers and reordered prints */
int main() {
    Pupil class[STUDENTS] = {
        {"Marin", {78, 82, 91}, 0.0f},
        {"Sofia", {88, 79, 85}, 0.0f},
        {"Jonas", {58, 64, 70}, 0.0f},
        {"Lea",   {95, 93, 99}, 0.0f},
        {"Omar",  {72, 76, 74}, 0.0f}
    };

    /* calculate averages */
    for (int idx = 0; idx < STUDENTS; ++idx) {
        class[idx].average = avg_marks(class[idx].marks, SUBJECTS);
    }

    /* pick best (same tie-handling behavior) */
    int top = 0;
    for (int j = 1; j < STUDENTS; ++j) {
        if (class[j].average > class[top].average) {
            top = j;
        }
    }

    /* print header then rows (header formatting slightly different spacing) */
    printf("Name     M1 M2 M3 | Average\n");
    printf("-------------------------\n");
    for (int r = 0; r < STUDENTS; ++r) {
        printf("%-8s %2d %2d %2d | %.2f\n",
               class[r].fullname,
               class[r].marks[0],
               class[r].marks[1],
               class[r].marks[2],
               class[r].average);
    }

    printf("\nTop pupil is %s with %.2f points\n", class[top].fullname, class[top].average);

    return 0;
}

