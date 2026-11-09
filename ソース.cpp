#include<iostream>
using namespace std;


const char* str_match(const char* s1, const char* s2) {
	int save = -1;
	for (int j = 0;s1[j] != '\0';++j) {
		if (s1[j] == s2[0]) {
			save = j;
			break;
		}
	}
	if (save == -1) {
		return nullptr;
	}
	int k = 0;
	for (int i = save;s1[i] != s2[k];++i) {
		if (s1[i] != s2[k]) {
			return &s1[i];
			k++;
		}
	}

}

int main() {

	char s1[] = "abcabcdef";
	char s2[] = "abcd";

	cout << "帰ってきたアドレスは " <<str_match(s1, s2);
}

