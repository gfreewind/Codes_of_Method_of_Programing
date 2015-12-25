#include <algorithm>

void odd_even_sort_2(int *array, int size)
{
	if (!(array && size)) {
		return;
	}

	int *p1, *p2;
	int *tail = array+size;
	p1 = array;
	p2 = p1-1;
	
	while (p1 < tail) {
		while (*p1%2 == 0 && p1 < tail) {
			++p1;
		}

		if (p1 < tail) {
			++p2;
			std::swap(*p1, *p2);
			++p1;
		}
	}
}

void odd_even_sort_1(int *array, int size)
{
	if (!(array && size)) {
		return;
	}

	int *head = array;
	int *tail = array+size-1;

	while (head < tail) {
		while (*head%2 && head <= tail) {
			++head;
		}

		while (!(*tail%2) && tail > head) {
			--tail;
		}

		if (head >= tail) {
			break;
		}

		std::swap(*head, *tail);
		++head;
		--tail;
	}
}
