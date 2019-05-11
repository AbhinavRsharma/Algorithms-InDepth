#include<stdio.h>
#include<stdlib.h>

struct event {
	float y;
	int hh1, hh2, mm1, mm2;
	struct event* next;
};

struct event* create_event() {
	struct event* eve = (struct event*)malloc(sizeof(struct event));
	scanf("%d:%d-%d:%d", &(eve->hh1), &(eve->mm1), &(eve->hh2), &(eve->mm2));
	scanf("%f", &(eve->y));
	return eve;
}

struct event* merge_lists(struct event* h1, struct event* h2) {

	struct event* merge, *temp;
	if (h1->y > h2->y) {
		temp = h2;
		h2 = h1;
		h1 = temp;
	}// first element of h1 is smaller

	merge = h1;
	temp = h1;
	h1 = h1->next;

	while (h1 && h2) {
		if (h1->y > h2->y) {
			temp->next = h2;
			h2 = h2->next;
		}
		else {
			temp->next = h1;
			h1 = h1->next;
		}
		temp = temp->next;
	}

	if (h1 == NULL)
		temp->next = h2;
	else
		temp->next = h1;

	return merge;
}

struct event* merge_sort(struct event* head, int n) {
	if (n == 1)
		return head;
	if (n == 0)return NULL;

	struct event* head2 = head;
	for (int i = 0; i < n / 2 - 1; i++)
		head2 = head2->next;

	struct event* temp = head2;
	head2 = head2->next;
	temp->next = NULL;

	head = merge_sort(head, n / 2);
	head2 = merge_sort(head2, n - n / 2);

	return merge_lists(head, head2);
}
void print_list(struct event* head, int comp) {
	printf("%d", comp);
	while (head != NULL) {
		printf(" %f", head->y);
		head = head->next;
	}
	printf("\n");
}
int main() {
	int N, K, x;//    N : no. of comp.      K : total no. of events
	scanf("%d", &N);
	int n_event[N];
	struct event* head[N];
	struct event* temp;

	for (int i = 0; i < N; i++) {
		head[i] = NULL;
		n_event[i] = 0;
	}

	int c = 0;
	while (c < K) {
		scanf("%d ", &x);
		n_event[x - 1]++;
		temp = head[x - 1];
		head[x - 1] = create_event();
		head[x - 1]->next = temp;
		c++;
	}

	for (int i = 0; i < N; i++) {
		head[i] = merge_sort(head[i], n_event[i]);
		print_list(head[i], i + 1);
	}

	return 0;
}