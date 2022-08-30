/*
 * 1213 펠린드롬 만들기
 * 실버III
 */
#include <iostream>
int main() {
  char str[51];
  scanf("%s", str);
  int arr[26]{0}, len = 0;
  for (int i = 0; str[i]; i++) {
    arr[str[i] - 'A']++;
    len++;
  }
  char res[51]{0}, index = 0, check = false;
  for (int i = 0; i < 26;) {
    if (arr[i] > 1) {
      res[len - index - 1] = res[index] = i + 'A';
      arr[i] -= 2;
      index++;
    } else if (arr[i] == 1) {
      if (check) {
        printf("I'm Sorry Hansoo");
        return 0;
      }
      res[len / 2] = i + 'A';
      i++;
      check = true;
    } else {
      i++;
    }
  }
  printf("%s", res);
}