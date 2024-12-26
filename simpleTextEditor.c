#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_OPERATIONS 100

typedef struct {
    char *state; 
} Operation;
void append(char **S, const char *W, Operation *history, int *undo_index);
void delete (char **S, int k, Operation *history, int *undo_index);
void print(const char *S, int k);
void undo(char **S, Operation *history, int *undo_index);
int main() {
    char *S = (char *)malloc(MAX_LEN * sizeof(char));
    S[0] = '\0'; 
    Operation history[MAX_OPERATIONS]; 
    int undo_index = -1; 
    int Q;
    printf("Enter the number of operations: ");
    scanf("%d", &Q);
    while (Q--) {
        int type;
        printf("Enter operation type (1=append, 2=delete, 3=print, 4=undo): ");
        scanf("%d", &type);
        if (type == 1) {
            char W[MAX_LEN];
            printf("Enter string to append: ");
            scanf("%s", W);
            append(&S, W, history, &undo_index);
        } else if (type == 2) {
            int k;
            printf("Enter number of characters to delete: ");
            scanf("%d", &k);
            delete (&S, k, history, &undo_index);
        } else if (type == 3) {
            int k;
            printf("Enter character position to print: ");
            scanf("%d", &k);
            print(S, k);
        } else if (type == 4) {
            undo(&S, history, &undo_index);
        }
    }
    free(S);
    for (int i = 0; i <= undo_index; i++) {
        free(history[i].state);
    }
    return 0;
}
void append(char **S, const char *W, Operation *history, int *undo_index) {
    history[++(*undo_index)].state = strdup(*S);
     strcat(*S, W);}
void delete (char **S, int k, Operation *history, int *undo_index) {
    history[++(*undo_index)].state = strdup(*S);
    int len = strlen(*S);
    if (k <= len) {
        (*S)[len - k] = '\0';
    }
}
void print(const char *S, int k) {
    int len = strlen(S);
    if (k > 0 && k <= len) {
        printf("Character at position %d: %c\n", k, S[k - 1]);
    } else {
        printf("Invalid position.\n");
    }
}
void undo(char **S, Operation *history, int *undo_index) {
    if (*undo_index >= 0) {
        
        strcpy(*S, history[(*undo_index)--].state);
    } else {
        printf("No operations to undo.\n");
    }
}
