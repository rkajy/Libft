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

}

void test_ft_isascii()
{

}

void	test_ft_isdigit()
{

}

void test_ft_isprint()
{

}

void test_ft_memchr()
{

}

void test_ft_memcmp()
{

}

void test_ft_memcpy()
{

}

void test_ft_memmove()
{

}

void test_ft_memset()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	TEST_ASSERT_EQUAL_STRING(memset(str + 13, '.', 8*sizeof(char)), ft_memset(str + 13, '.', 8*sizeof(char)));
}

void test_ft_strchr()
{

}

void	test_ft_strlcat()
{

}

void	test_ft_strlcpy()
{

}

void	test_ft_strlen()
{
	unsigned long long size = 5;
	TEST_ASSERT_EQUAL_UINT64(size, ft_strlen("abcdf"));
	TEST_ASSERT_EQUAL_UINT64(0, ft_strlen(""));
	TEST_ASSERT_EQUAL_UINT64(0, ft_strlen(NULL));
}

void	test_ft_strncmp()
{

}

void	test_ft_strnstr()
{

}

void test_ft_strrchr()
{

}

void test_ft_tolower()
{

}

void test_ft_toupper()
{
	char i = 'A';
	while (i <= 'Z')
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
	RUN_TEST(test_ft_strnstr);
	RUN_TEST(test_ft_strrchr);
	RUN_TEST(test_ft_tolower);
	RUN_TEST(test_ft_toupper);

	UNITY_END();

	return 0;
}
