#include <algorithm>

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
