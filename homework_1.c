#include <stdio.h>
#include <string.h>

int main(void) {
    int i, j;
    int count, len, score, scores[10];
    char name[15], names[10][15];
    int total = 0, top_score = -1, passing_students = 0;
    double average_score;

    printf("Enter student count: ");
    scanf("%d", &count);

    if (count > 9 || count < 0) {
        printf("Error!\n");
        return -1;
    }

    printf("--------------------------------\n");

    for (i = 0; i < count; i++) {
        scanf("%s %d", name, &score);

        len = strlen(name);
        name[len] = '\0';

        if (len > 10 || score < 0 || score > 100) {
            printf("Error!\n");
            return -1;
        }

        total += score;
        if (top_score < score) top_score = score;
        if (score >= 60) passing_students++;

        scores[i] = score;
        strcpy(names[i], name);
    }

    printf("--------------------------------\n\n");
    printf("Calculating...");
    printf("\n\n-----------[result]-------------\n");

    average_score = (double)total / count;

    int temp;
    char temp2[15];

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (scores[i] < scores[j]) {
                temp = scores[i];
                strcpy(temp2, names[i]);

                scores[i] = scores[j];
                scores[j] = temp;

                strcpy(names[i], names[j]);
                strcpy(names[j], temp2);
            }
        }
    }

    printf("Average score: %.1f\n", average_score);
    printf("Top score: %d\n", top_score);
    printf("Passing students: %d\n", passing_students);

    printf("\n");

    for (i = 0; i < count; i++) {
        printf("%d. %s - %d\n", i+1, names[i], scores[i]);
    }

    printf("--------------------------------\n");
    return 0;
}
