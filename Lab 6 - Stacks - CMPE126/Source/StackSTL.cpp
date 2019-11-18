#include "StackSTL.h"

StackSTL::StackSTL() {
	i = 0;
	j = 0;
	ch = '\0';
}

StackSTL::StackSTL(char sample[]) {

	strncpy_s(infix, sample, sizeof(sample));
}

void StackSTL::conversion() {

	while (infix[i++] != '\0');
	infix[i + 1] = '\0';
	infix[i--] = ')';
	while (i > 0) {
		infix[i] = infix[i - 1];
		i--;
	}
	infix[i] = '(';
	cout << infix << endl;

	i = 0;

	while (infix[i] != '\0') {

		if (infix[i] == '(') {

			s2.push(infix[i]);
		}
		else if (infix[i] >= 'a' && infix[i] <= 'z') {

			postfix[j++] = infix[i];

		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {

			while (s2.top() == '+' || s2.top() == '-' || s2.top() == '*' || s2.top() == '/') {

				if (find_precedence(s2.top()) >= find_precedence(infix[i])) {

					postfix[j++] = s2.top();
					s2.pop();
				}
				else {
					break;
				}
			}
			s2.push(infix[i]);
		}
		else if (infix[i] == ')') {

			while ((ch = s2.top()) != '(') {
				postfix[j++] = ch;
				s2.pop();
			}
			s2.pop();
		}

		i++;
	}
}

int StackSTL::find_precedence(char ch) {
	switch (ch) {
	case '+':
	case'-':
		return 1;
	case'*':
	case'/':
		return 2;
	}
}

void StackSTL::printout() {

	int temp = 0;
	while (postfix[temp] != '/0') {
		cout << postfix[temp++];
	}
}
