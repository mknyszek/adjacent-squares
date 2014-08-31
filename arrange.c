#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * LINKED LIST IMPLEMENTATION
 */

typedef struct node {
    struct node *next;
    int d;
} node;

node *node_new(int d) {
    node *head = malloc(sizeof(node));
    head->next = NULL;
    head->d = d;
    return head;
}

node *node_add(node *head, int d) {
    node *new_head = malloc(sizeof(node));
    if(head != NULL) {
        new_head->next = head;
        new_head->d = d;
    }
    return new_head;
}

void node_free(node *head) {
    node *tmp = head;
    while(head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    head = NULL;
}

node *sq_list(int n) {
    node *head = node_new(4);
    int i = 3;
    int i_sq = i*i;
    while(i_sq < n << 1) {
        head = node_add(head, i_sq);
        ++i;
        i_sq = i*i;
    }
    return head;
}

/*
 * PRIMARY ALGORITHM
 */

int arrange_sub(int *a, int *used, node *sq, int p, int n) {
    node *tmp_sq = sq;
    int res, diff;
    while(tmp_sq != NULL) {
        if(tmp_sq->d <= a[p-1]) {
            tmp_sq = tmp_sq->next;
            continue;
        }
        diff = abs(tmp_sq->d-a[p-1]);
        if(diff <= n && diff > 0 && !used[diff-1]) {
            used[diff-1] = 1;
            a[p] = diff;
            p += 1;
            if(p != n) {
                res = arrange_sub(a, used, sq, p, n);
                if(res) return res;
            }else{
                return 1;
            }
            p -= 1;
            used[diff-1] = 0;
        }
        tmp_sq = tmp_sq->next;
    }
    return 0;
}

int arrange(int *a, int *used, node *sq, int n) {
    int i, res;
    for(i = 1; i <= n; ++i) {
        a[0] = i;
        used[i-1] = 1;
        res = arrange_sub(a, used, sq, 1, n);
        if(res) return res;
        used[i-1] = 0;
    }
    return 0;
}

/*
 * PRINT FUNCTIONS FOR DATA STRUCTS
 */

void printf_list(node *head) {
    node *tmp = head;
    printf("( ");
    while(tmp != NULL) {
        printf("%d ", tmp->d);
        tmp = tmp->next;
    }
    printf(")\n");
}

void printf_array(int *arr, int arrc) {
    int i;
    printf("[ ");
    for(i = 0; i < arrc; ++i) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

/*
 * RUN
 */

void run(int N) {
    int *a, *used, result;
    node *sq;
    a = malloc(N*sizeof(int));
    used = malloc(N*sizeof(int));
    sq = sq_list(N);
    memset(used, 0, N*sizeof(int));
    
    /*printf_array(used, N);
    printf_list(sq);*/
    
    result = arrange(a, used, sq, N);
    
    /*printf("%d\n", result);
    printf_array(a, N);*/
    
    printf("N = %d -> ", N);
    
    if(result) {
        printf_array(a, N);
    }else{
        printf("None\n");
    }
    
    node_free(sq);
    free(a);
    free(used);
    return;
}

/*
 * MAIN
 */

int main(int argc, char *argv[]) {
    int i;
    for(i = 1; i <= 100; ++i) {
        run(i);
    }
    return 0;
}
