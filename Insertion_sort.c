#include<stdio.h>
#include<string.h>
#include<time.h>

int scan_size(void);
int* make_num(int num);
int* Sort(int*, int);
void Swap(int*, int*);
void print_num(int*, int);

int main() {
	int size;
	int* before_num;
	int* after_num;
	srand(time(NULL));
	size = scan_size();
	before_num = make_num(size);
	after_num = Sort(before_num, size);
	print_num(after_num, size);
}

int scan_size(void) {
	int num;
	printf("How many number : ");
	scanf("%d", &num);
	return num;
}

int* make_num(int num) {
	static int before_num[110];
	int check_board[110] = { 0, };
	int idx = 0;
	while (idx < num) {
		int tmp = rand() % num + 1;
		if (check_board[tmp] == 0) {
			check_board[tmp]++;
			before_num[idx] = tmp;
			idx++;
		}
	}

	int i;
	printf("Before Sorting : ");
	for (i = 0; i < num; i++) {
		printf("%d ", before_num[i]);
	}
	printf("\n");
	return before_num;
}

void print_num(int* after_num, int size) {
	int i;
	printf("After Sorting : ");
	for (i = 0; i < size; i++) {
		printf("%d ", after_num[i]);
	}
}

int* Sort(int* sort_num, int size) {
	int now = 0;
	int now_val;
	int i, j;
	for (now = 1; now < size ; now++) {
		now_val = sort_num[now];
		for (i = now - 1; i >= 0; i--) {
			if (sort_num[i] > now_val)
				Swap(&sort_num[i], &sort_num[i + 1]);
		}
	}

	return sort_num;
}

void Swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}