#include<stdio.h>
#define _0901

#ifdef _0901
int main(void) {
	char str[] = "ABC\0DEF";

	printf("文字列strは\"%s\"です。", str);
	//'\0'ので終端のためそれより後の文字は認識されない
	return 0;
}
#endif

#ifdef _0902
int main(void) {
	char s[] = "ABC";
	printf("[%s]\n", s);

	s[0] = '\0';
	printf("[%s]", s);



	return 0;
}
#endif

#ifdef _0903

#define NUM 12

int main(void) {
	int i;
	int n = 0;
	char s[NUM][128] = { 0 };

	for (i = 0; i < NUM; i++) {
		printf("s[%d] : ", i);
		scanf_s("%s", s[i],sizeof(s[i]));
		if (s[i][0] == '$'&& s[i][1] == '$'&& s[i][2] == '$'&&
			s[i][3] == '$'&& s[i][4] == '$')break;
		else n++;
	}

	for (i = 0; i < n; i++) {
		printf("s[%d] = \"%s\"\n", i, s[i]);
	}
	
	return 0;
}
#endif

#ifdef _0904

void null_string(char s[]) {
	s[0] = '\0';
}

int main(void) {
	char str[128];

	printf("文字列を入力してください : ");
	scanf_s("%s", str,sizeof(str));
	
	null_string(str);

	putchar('\n');
	printf("空文字列に置き換えました : \"%s\"",str);

	return 0;
}
#endif

#ifdef _0905

#define SIZE 128

int str_char(const char s[], int c) {
	c = -1;
	for (int i = 0; i < SIZE; i++) {
		if (s[i] == 'c') {
			c = i;
			break;
		}
	}
	return c;
}

int main(void) {
	int c = 0;
	char str[SIZE];

	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));

	printf("走査結果 : %d", str_char(str,c));

	return 0;
}
#endif

#ifdef _0906

#define SIZE 128

int str_chnum(const char s[], int c) {
	for (int i = 0; i < SIZE; i++) {
		if (s[i] == 'c') {
			c++;
		}
	}
	return c;
}

int main(void) {
	int c = 0;
	char str[SIZE];

	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));

	putchar('\n');
	printf("文字列には\'c\'が%d個含まれています。", str_chnum(str, c));

	return 0;
}
#endif

#ifdef _0907

#define SIZE 32

void put_stringn(const char s[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%s", s);
	}
	putchar('\n');
}
int main(void) {
	int n;
	char str[SIZE];

	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));
	printf("何回繰り返しますか : ");
	scanf_s("%d", &n);

	put_stringn(str, n);


	return 0;
}
#endif

#ifdef _0908

#define SIZE 32

void put_stringr(const char s[]) {
	int cnt = 0;
	for (int i = 0; s[i + 1] != '\0'; i++) {
		cnt++;
	}
	for (int i = cnt; i >= 0; i--) {
		printf("%c", s[i]);
	}

}

int main(void) {
	char str[SIZE];

	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));
	putchar('\n');

	printf("反転して表示 : ");
	put_stringr(str);

	return 0;
}
#endif

#ifdef _0909

#define SIZE 64

void rev_string(char s[]) {
	char S[SIZE];
	int i = 0;
	int cnt = 0;

	while (s[i] != '\0') {
		S[i] = s[i];
		cnt++;
		i++;
	}

	for (i = 0; i < cnt; i++) {
		s[i] = S[cnt - 1 - i];
	}
}

int main(void) {
	char str[SIZE];

	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));

	rev_string(str);

	printf("反転して表示 : ");

	printf("%s",str);

	return 0;
}
#endif

#ifdef _0910

#define SIZE 32

void del_digit(char s[]) {
	int i = 0, j = 0;

	while (s[i]) {
		if (s[i] >= '0' && s[i] <= '9') {
			j++;
		}
		else {
			s[i - j] = s[i];
		}
		i++;
	}
	s[i - j] = '\0';
}

int main(void) {
	char str[SIZE];

	printf("文字列を入力してください : ");
	scanf_s("%s", str, sizeof(str));

	del_digit(str);
	printf("数字文字を削除 : %s", str);


	return 0;
}
#endif

#ifdef _0911

#define NUM 12
#define SIZE 128

void put_strary(const char s[NUM][SIZE], int n) {
	for (int i = 0; i < n; i++) {
		printf("s[%d] = \"%s\"\n", i, s[i]);
	}
}
int main(void) {
	char cs[NUM][SIZE] = { 0 };
	int cnt = 0;

	printf("文字列を入力してください : \n");
	for (int i = 0; i < NUM; i++) {
		printf("cs[%d] : ", i);
		scanf_s("%s", cs[i], sizeof(cs[i]));
		if (cs[i][0] == '$' && cs[i][1] == '$' && cs[i][2] == '$' &&
			cs[i][3] == '$' && cs[i][4] == '$') break;
		else cnt++;
	}

	put_strary(cs, cnt);

	return 0;
}
#endif

#ifdef _0912

#define NUM 4
#define SIZE 128

void rev_strins(char s[][SIZE], int n) {
	char S[NUM][SIZE];
	int cnt = 0;
	int i = 0;
	for(int j = 0; j < n; j++){
		while (s[j][i] != '\0') {
			S[j][i] = s[j][i];
			cnt++;
			i++;
		}
		for (i = 0; i < cnt; i++) {
			s[j][i] = S[j][cnt - 1 - i];
		}
		cnt = 0;
		i = 0;
	}

}

int main(void) {
	char str[NUM][SIZE];

	printf("文字列を入力してください : \n");
	for (int i = 0; i < NUM; i++) {
		printf("str[%d] : ", i);
		scanf_s("%s", str[i], sizeof(str[i]));
	}
	putchar('\n');

	rev_strins(str, NUM);

	printf("各文字列を反転\n");
	for (int i = 0; i < NUM; i++) {
		printf("str[%d] = \"%s\"\n", i, str[i]);
	}

	return 0;
}
#endif

