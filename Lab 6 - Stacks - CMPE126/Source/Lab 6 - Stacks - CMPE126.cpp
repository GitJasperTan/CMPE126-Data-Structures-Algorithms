#include <iostream>
//#include "Stack.h"
#include <stack>
using namespace std;

int find_precedence(char ch) {

	switch (ch) {
	case '+':
	case'-':
		return 1;
	case'*':
	case'/':
		return 2;
	}
}


int main() {

	stack<int> s2;
	//Stack s1;
	char ch;
	int i = 0;
	int j = 0;
	char infix[100], postfix[100];

	cout << "Enter infix expression" << endl;
	cin >> infix;


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

	//while (infix[i] != '\0') {

	//	if (infix[i] == '(') {

	//		s1.push(infix[i]);
	//	}
	//	else if (infix[i] >= 'a' && infix[i] <= 'z') {

	//		postfix[j++] = infix[i];

	//	}
	//	else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {

	//		while (s1.peep() == '+' || s1.peep() == '-' || s1.peep() == '*' || s1.peep() == '/') {

	//			if (find_precedence(s1.peep()) >= find_precedence(infix[i])) {

	//				postfix[j++] = s1.pop();
	//			}
	//			else {
	//				break;
	//			}
	//		}
	//		s1.push(infix[i]);
	//	}
	//	else if (infix[i] == ')') {

	//		while ((ch = s1.pop()) != '(') {
	//			postfix[j++] = ch;
	//		}
	//	}

	//	i++;
	//}

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


	postfix[j] = '\0';
	cout << postfix << endl;

}
