#include <stddef.h>

#include "unity.h"
#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void test_ft_atoi()
{

}

void test_ft_bzero()
{
	// simple test case for a few elements
	char buffer1[10];
	char buffer2[10];

	memset(buffer1, 'A', sizeof(buffer1));
	memset(buffer2, 'A', sizeof(buffer2));

	bzero(buffer1, 5);
	ft_bzero(buffer2, 5);

	TEST_ASSERT_EQUAL_MEMORY(buffer1, buffer1, sizeof(buffer1));

	// test case for each elements
	char buff1[6] = "hello";
	char buff2[6] = "hello";

	bzero(buff1, 6);
	ft_bzero(buff2, 6);
	TEST_ASSERT_EQUAL_MEMORY(buff1, buff2, 6);

	// zero lenght test
	char buffer11[5] = "abcd";
	char buffer21[5] = "abcd";

	bzero(buffer11, (0));
	ft_bzero(buffer21, 0);

	TEST_ASSERT_EQUAL_MEMORY(buffer1, buffer2, 5);
	
	// test null test case
	ft_bzero(NULL, 0);
	TEST_PASS();
}

void test_ft_isalnum()
{
	char isalphacapital = 'A';
	char isalpha = 'a';
	char num = '1';
	int i;

	while (isalphacapital <= 'Z')
	{
		i = isalnum(isalphacapital);
		//printf("isalnum(%c) = %d\n", isalphacapital, i);
		TEST_ASSERT_EQUAL_INT(!!i, !!ft_isalnum(isalphacapital));
		isalphacapital++;
	}
	while (isalpha <= 'z')
	{
		TEST_ASSERT_EQUAL_INT(!!isalnum(isalpha), !!ft_isalnum(isalpha));
		isalpha++;
	}
	while (num <= '9')
	{
		TEST_ASSERT_EQUAL_INT(!!isalnum(num), !!ft_isalnum(num));
		num++;
	}
}

void test_ft_isalpha()
{
	for (int c = 0; c <= 255; c++)
	{
		int expected = !!isalpha(c);
		int actual = ft_isalpha(c);
		TEST_ASSERT_EQUAL_INT(expected, actual);
	}
}

void test_ft_isascii()
{
	for (int i = 0; i <= 127; i++)
	{
		int expected = !!isascii(i);
		int actual = ft_isascii(i);
		TEST_ASSERT_EQUAL_INT(expected, actual);
	}
}

void	test_ft_isdigit()
{
}

void test_ft_isprint()
{
	for (int i = 40; i <= 176; i++)
	{
		int excpected = isprint(i);
		int actual = ft_isprint(i);
		//printf("i = %d char = %c,  isprint = %d ft_isprint = %d\n", i, i, excpected, actual); 

		TEST_ASSERT_EQUAL_INT(!!excpected, actual);
	}
}

void test_ft_memchr()
{
	char buf[] = "bonjour";
	//cherche z, missing char
	TEST_ASSERT_EQUAL_PTR(memchr(buf, 'z', 7), ft_memchr(buf, 'z', 7));
	//find r at the end
	TEST_ASSERT_EQUAL_PTR(memchr(buf, 'r', 7), ft_memchr(buf, 'r', 7));
	//char in the outside of the limits
	TEST_ASSERT_EQUAL_PTR(memchr(buf, 'n', 2), ft_memchr(buf, 'n', 2));
	//n =0, shouldn't return null directly
	TEST_ASSERT_EQUAL_PTR(memchr(buf, 'b', 0), ft_memchr(buf, 'b', 0));
	//caractere trouve au milieu
	TEST_ASSERT_EQUAL_PTR(memchr(buf, 'j', 7), ft_memchr(buf, 'j', 7));
	// Recherche du caractère nul
	char with_null[] = {'a', 'b', '\0', 'c', 'd'};
	TEST_ASSERT_EQUAL_PTR(memchr(with_null, '\0', 5), ft_memchr(with_null, '\0', 5));
	// Recherche après le caractère nul (non défini dans chaîne C, mais mémoire existante)
	TEST_ASSERT_EQUAL_PTR(memchr(with_null, 'd', 5), ft_memchr(with_null, 'd', 5));
}

void test_ft_memcmp()
{
	// 1. Strings égales
	char s1[] = "Bonjour";
	char s2[] = "Bonjour";
	TEST_ASSERT_EQUAL_INT(memcmp(s1, s2, 7), ft_memcmp(s1, s2, 7));

	// 2. s1 < s2
	char s3[] = "Bonjour";
	char s4[] = "Bonjouz";
	TEST_ASSERT_EQUAL_INT(memcmp(s3, s4, 7), ft_memcmp(s3, s4, 7));

	// 3. s1 > s2
	char s5[] = "Bonjouz";
	char s6[] = "Bonjour";
	TEST_ASSERT_EQUAL_INT(memcmp(s5, s6, 7), ft_memcmp(s5, s6, 7));

	// 4. Comparaison partielle
	char s7[] = "ABCDEF";
	char s8[] = "ABCXYZ";
	TEST_ASSERT_EQUAL_INT(memcmp(s7, s8, 3), ft_memcmp(s7, s8, 3)); // égaux sur 3
	TEST_ASSERT_EQUAL_INT(memcmp(s7, s8, 4), ft_memcmp(s7, s8, 4)); // diff à partir de 4

	// 5. Avec des caractères nuls
	char s9[] = {'A', 'B', '\0', 'C'};
	char s10[] = {'A', 'B', '\0', 'D'};
	TEST_ASSERT_EQUAL_INT(memcmp(s9, s10, 4), ft_memcmp(s9, s10, 4));

	// 6. Avec n = 0 (doit retourner 0 même si les buffers sont différents)
	char s11[] = "abc";
	char s12[] = "xyz";
	TEST_ASSERT_EQUAL_INT(memcmp(s11, s12, 0), ft_memcmp(s11, s12, 0));

	// 7. Comparaison de buffers binaires
	unsigned char bin1[] = {0x01, 0x02, 0x03, 0xFF};
	unsigned char bin2[] = {0x01, 0x02, 0x03, 0xFE};
	TEST_ASSERT_EQUAL_INT(memcmp(bin1, bin2, 4), ft_memcmp(bin1, bin2, 4));
}

void test_ft_memcpy()
{
	char src[42] = "bonjour les amis !";
	char dst_exp[42] = {0};
	char dst_act[42] = {0};

	// Test 1 : copier les 2 premiers caractères
	memcpy(dst_exp, src, 2);
	ft_memcpy(dst_act, src, 2);
	TEST_ASSERT_EQUAL_MEMORY(dst_exp, dst_act, 2);

	// Test 2 : copier toute la chaîne
	memset(dst_exp, 0, sizeof(dst_exp));
	memset(dst_act, 0, sizeof(dst_act));
	memcpy(dst_exp, src, strlen(src));
	ft_memcpy(dst_act, src, strlen(src));
	TEST_ASSERT_EQUAL_MEMORY(dst_exp, dst_act, strlen(src));

	// Test 3 : copier 0 octet (ne doit rien faire, mais ne crasher pas)
	TEST_ASSERT_EQUAL_PTR(NULL, ft_memcpy(NULL, NULL, 0));

	// Test 4 : buffer de destination rempli avant copie partielle
	memset(dst_exp, 'X', sizeof(dst_exp));
	memset(dst_act, 'X', sizeof(dst_act));
	memcpy(dst_exp + 5, src, 5);
	ft_memcpy(dst_act + 5, src, 5);
	TEST_ASSERT_EQUAL_MEMORY(dst_exp, dst_act, sizeof(dst_exp));

	// Test 5 : copier dans le même buffer (comportement défini uniquement si buffers ne se recouvrent pas)
	char a[] = "0123456789";
	char b[] = "0123456789";
	memcpy(a + 1, "XYZ", 3);
	ft_memcpy(b + 1, "XYZ", 3);
	TEST_ASSERT_EQUAL_MEMORY(a, b, 10);
	
}

void test_ft_memmove()
{
	// Cas null-safe
	TEST_ASSERT_NULL(ft_memmove(NULL, NULL, 0));

	// Cas où src == dst
	char buf1[] = "hello";
	char buf2[] = "hello";
	ft_memmove(buf1, buf1, 5);
	memmove(buf2, buf2, 5);
	TEST_ASSERT_EQUAL_MEMORY(buf1, buf2, 5);

	// Copie sans chevauchement
	char d1[20] = "oldstring";
	char d2[20] = "oldstring";
	ft_memmove(d1, "newstring", 9);
	memmove(d2, "newstring", 9);
	TEST_ASSERT_EQUAL_MEMORY(d1, d2, 20);

	// Chevauchement vers l’avant (src < dst)
	char overlap1[] = "123456789";
	char overlap2[] = "123456789";
	ft_memmove(overlap1 + 2, overlap1, 5);   // "121234589"
	memmove(overlap2 + 2, overlap2, 5);
	TEST_ASSERT_EQUAL_MEMORY(overlap1, overlap2, 9);

	// Chevauchement vers l’arrière (dst < src)
	char back1[] = "abcdef";
	char back2[] = "abcdef";
	ft_memmove(back1, back1 + 2, 4);  // "cdefef"
	memmove(back2, back2 + 2, 4);
	TEST_ASSERT_EQUAL_MEMORY(back1, back2, 6);
}

void test_ft_memset()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	TEST_ASSERT_EQUAL_STRING(memset(str + 13, '.', 8*sizeof(char)), ft_memset(str + 13, '.', 8*sizeof(char)));
}

void test_ft_strchr()
{
	char str[] = "bonjour";
	TEST_ASSERT_EQUAL_STRING(
		strchr(str, 'b'),
		ft_strchr(str, 'b')
	);

	TEST_ASSERT_EQUAL_STRING(
		strchr(str, 'o'),
		ft_strchr(str, 'o')
	);

	TEST_ASSERT_EQUAL_STRING(
		strchr(str, '\0'),
		ft_strchr(str, '\0')
	);
}

void	test_ft_strlcat()
{

	char dest_ex[11] = "a";
	char dest_ac[11] = "a";
	size_t ex = strlcat(dest_ex, "lorem", sizeof(dest_ex));
	size_t ac = ft_strlcat(dest_ac, "lorem", sizeof(dest_ac));
	TEST_ASSERT_EQUAL_INT(ex, ac);
	TEST_ASSERT_EQUAL_STRING(dest_ex, dest_ac);

	// char dest_ex1[11] = "a";
	// char dest_ac2[11] = "a";
	// ex = strlcat(dest_ex1, "lorem", 15);
	// ac = ft_strlcat(dest_ac2, "lorem", 15);
	// TEST_ASSERT_EQUAL_INT(ex, ac);
	// TEST_ASSERT_EQUAL_STRING(dest_ex1, dest_ac2);

	char buff[14];
	char buff_a[14];
	ft_memset(buff, 'r', 14);
	ft_memset(buff_a, 'r', 14);
	ex = strlcat(buff, "lorem", sizeof(dest_ex));
	ac = ft_strlcat(buff_a, "lorem", sizeof(dest_ac));
	TEST_ASSERT_EQUAL_INT(ex, ac);
	TEST_ASSERT_EQUAL_STRING(dest_ex, dest_ac);

}
void	test_ft_strlcpy()
{
	// usage case with enought space on dest
	char src[56] = "bonjour;";
	char destexp[68];
	char destact[68];

	size_t excpected = strlcpy(destexp, src, sizeof(destexp));
	size_t actual = ft_strlcpy(destact, src, sizeof(destact));
	TEST_ASSERT_EQUAL_INT(excpected, actual);
	//printf("exp = %s , act = %s\n", destexp, destact);
	TEST_ASSERT_EQUAL_STRING(destexp, destact);
	TEST_ASSERT_EQUAL_STRING(destexp, src);

	// more room in the src than dest
	char bufexp[3];
	char bufact[3];
	char s[56] = "bonjour;";
	
	excpected = strlcpy(bufexp, s, sizeof(bufexp));
	actual = ft_strlcpy(bufact, s, sizeof(bufact));
	TEST_ASSERT_EQUAL_INT(excpected, actual);
	TEST_ASSERT_EQUAL_STRING(bufexp, bufact);

	//source vide
	char bufexp1[3];
	char bufact1[3];
	char s1[56] = "";
	
	excpected = strlcpy(bufexp1, s1, sizeof(bufexp1));
	actual = ft_strlcpy(bufact1, s1, sizeof(bufact1));
	TEST_ASSERT_EQUAL_INT(excpected, actual);
	TEST_ASSERT_EQUAL_STRING(bufexp, bufact);
}

void	test_ft_strlen()
{
	unsigned long long size = 5;
	TEST_ASSERT_EQUAL_UINT64(size, ft_strlen("abcdf"));
	TEST_ASSERT_EQUAL_UINT64(0, ft_strlen(""));
	//TEST_ASSERT_EQUAL_UINT64(0, ft_strlen(NULL)); // return segfault and make test fail
}

void	test_ft_strncmp()
{
	//compare same string, equal
	char s1[50] = "ab";
	char s2[50] = "ab";

	int excpected = strncmp(s1, s2, 6);
	int actual = ft_strncmp(s1, s2, 6);
	TEST_ASSERT_EQUAL_INT(excpected, actual);


	// P is lower than Z
	excpected = strncmp("AZP", "AZZ", 3);
	actual = ft_strncmp("AZP", "AZZ", 3);
	//printf("excpected strn= %d, actual ft= %d\n", excpected, actual);
	TEST_ASSERT_LESS_OR_EQUAL(0, excpected);
	TEST_ASSERT_LESS_OR_EQUAL(0, actual);

	// equal a
	TEST_ASSERT_EQUAL_INT(strncmp("abc", "abc", 0), ft_strncmp("abc", "abc", 0));

	// greater 
	TEST_ASSERT_GREATER_OR_EQUAL(strncmp("abc", "", 3), ft_strncmp("abc", "", 3));
	TEST_ASSERT_GREATER_OR_EQUAL(strncmp("abc", "abd", 3), ft_strncmp("abc", "abd", 3));

}

/*
void	test_ft_strnstr()
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr_expt;
	char *ptr_act;

	// len = 0 should return 0
	ptr_expt = strnstr(largestring, smallstring, 0);
	ptr_act = ft_strnstr(largestring, smallstring, 0);
	TEST_ASSERT_EQUAL_STRING(ptr_expt, ptr_act);

	// normal case
	ptr_expt = strnstr(largestring, smallstring, sizeof(largestring));
	ptr_act = ft_strnstr(largestring, smallstring, sizeof(largestring));
	TEST_ASSERT_EQUAL_STRING(ptr_expt, ptr_act);

	// find empty char or string and then return first argument
	ptr_expt = strnstr(largestring, "", sizeof(largestring));
	ptr_act = ft_strnstr(largestring, "", sizeof(largestring));
	TEST_ASSERT_EQUAL_STRING(ptr_expt, ptr_act);

	// if the size of needle is greater than size of haystack
	char *big = "abcdef";
	char *little = "abcdefghijklmnop";
	size_t max = strlen(big);
	char *s1 = strnstr(big, little, max);
	char *s2 = ft_strnstr(big, little, max);
	TEST_ASSERT_EQUAL_STRING(s1, s2);

	s1 = "FF";
	s2 = "see FF your FF return FF now FF";
	char *i1 = strnstr(s1, s2, 4);
	char *i2 = ft_strnstr(s1, s2, 4);
	TEST_ASSERT_EQUAL_STRING(i1, i2);

	s1 = "oh no not the empty string !";
	s2 = "";
	max = 0;
	i1 = strnstr(s1, s2, max);
	i2 = ft_strnstr(s1, s2, max);
	TEST_ASSERT_EQUAL_STRING(i1, i2);

	s1 = "AAAAAAAAAAAAA";
	max = strlen(s1);
	i1 = strnstr(s1, s1, max);
	i2 = ft_strnstr(s1, s1, max);
	TEST_ASSERT_EQUAL_STRING(i1, i2);

	s1 = "MZIRIBMZIRIBMZE123";
	s2 = "MZIRIBMZE";
	max = strlen(s2);
	i1 = strnstr(s1, s2, max);
	i2 = ft_strnstr(s1, s2, max);
	TEST_ASSERT_EQUAL_STRING(i1, i2);

	big = "123456789";
	little = "9";
	max = 8;
	s1 = strnstr(big, little, max);
	s2 = ft_strnstr(big, little, max);
	TEST_ASSERT_EQUAL_STRING(s1, s2);

}*/

void test_ft_strrchr()
{
	char str[] = "bonjour";
	TEST_ASSERT_EQUAL_STRING(
		strrchr(str, 'b'),
		ft_strrchr(str, 'b')
	);

	TEST_ASSERT_EQUAL_STRING(
		strrchr(str, 's'),
		ft_strrchr(str, 's')
	);

	TEST_ASSERT_EQUAL_STRING(
		strrchr(str + 2, 'b'),
		ft_strrchr(str + 2, 'b')
	);
}

void test_ft_tolower()
{
	char i = 'A';
	while (i <= 'Z')
	{
		TEST_ASSERT_EQUAL(tolower(i), ft_tolower(i));
		i++;
	}
	TEST_ASSERT_EQUAL(tolower('A'), ft_tolower('A'));
	TEST_ASSERT_EQUAL(tolower('Z'), ft_tolower('Z'));
	TEST_ASSERT_EQUAL(tolower(' '), ft_tolower(' '));
	TEST_ASSERT_EQUAL(tolower('a'), ft_tolower('a'));
	TEST_ASSERT_EQUAL(tolower('0'), ft_tolower('0'));
}

void test_ft_toupper()
{
	char i = 'a';
	while (i <= 'z')
	{
		TEST_ASSERT_EQUAL(toupper(i), ft_toupper(i));
		i++;
	}
	TEST_ASSERT_EQUAL(toupper('A'), ft_toupper('A'));
	TEST_ASSERT_EQUAL(toupper('Z'), ft_toupper('Z'));
	TEST_ASSERT_EQUAL(toupper(' '), ft_toupper(' '));
	TEST_ASSERT_EQUAL(toupper('a'), ft_toupper('a'));
	TEST_ASSERT_EQUAL(toupper('0'), ft_toupper('0'));
}

void setUp()
{

}

void tearDown()
{

}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_ft_atoi);
	RUN_TEST(test_ft_bzero);
	RUN_TEST(test_ft_isalnum);
	RUN_TEST(test_ft_isalpha);
	RUN_TEST(test_ft_isascii);
	RUN_TEST(test_ft_isdigit);
	RUN_TEST(test_ft_strchr);
	RUN_TEST(test_ft_strlcat);
	RUN_TEST(test_ft_strlcpy);
	RUN_TEST(test_ft_strlen);
	RUN_TEST(test_ft_strncmp);
	//RUN_TEST(test_ft_strnstr);
	RUN_TEST(test_ft_strrchr);
	RUN_TEST(test_ft_tolower);
	RUN_TEST(test_ft_toupper);
	RUN_TEST(test_ft_isprint);
	RUN_TEST(test_ft_memcpy);
	RUN_TEST(test_ft_memcmp);
	RUN_TEST(test_ft_memchr);
	RUN_TEST(test_ft_memmove);
	UNITY_END();

	return 0;
}
