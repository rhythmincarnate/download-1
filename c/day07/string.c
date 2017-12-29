#include <stdio.h>

static int mystrlen(const char *p);
static char *mystrcpy(char *dest, const char *src);
static char *mystrcat(char *dest, const char *src);
static int mystrcmp(const char *s1, const char *s2);
static char *mystrchr(const char *s, int ch);
static char *mystrstr(const char *s, const char *sub);
int main(void)
{
	char *p = "good morning";
	char str[100] = "uplooking";

	printf("%d\n", mystrlen(p));

	printf("%s\n", mystrcpy(str, p));

	printf("%s\n", mystrcat(str, p));

	printf("%d\n", mystrcmp("good morning", p));

	printf("%s\n", mystrchr(str, 'm'));

	mystrcpy(str, "how aaaaaare you are you");
	if ((p = mystrstr(str, "aaarea")) != NULL)
		printf("%s\n", p);
	else {
		printf("%s is not in %s\n", "aaaarea", str);
	}

	return 0;
}


static int mystrlen(const char *p)
{
#if 1
	int len = 0;

	while (*p++)
		len ++;
	
	return len;
#endif
#if 0
	int i;
	for (i = 0; p[i]; i++) 
		;	

	return i;
#endif
}

static char *mystrcpy(char *dest, const char *src)
{
#if 1 
	char *ret = dest;

	while (*src) {
		*dest++ = *src++;
	}
	*dest = '\0';

	return ret;
#endif
#if 0
	int i;

	for (i = 0; src[i]; i++) {
		dest[i] = src[i];	
	}
	dest[i] = '\0';

	return dest;
#endif
}


static char *mystrcat(char *dest, const char *src)
{
	char *ret = dest;
			
	//找到dest字符串的'\0的地址'
	while (*dest)
		dest ++;
	mystrcpy(dest, src);

	return ret;
}

static int mystrcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)	{
		if (*s1 != *s2)	
			return *s1 - *s2;
		s1++;
		s2++;	
	}

	return 0;
}

/*
		 
 */
static char *mystrchr(const char *s, int ch)
{
	while (*s) {
		if (*s == ch)	
			return (char *)s;
		s ++;
	}
	if (ch == '\0')
		return (char *)s;

	return NULL;
}

static char *mystrstr(const char *s, const char *sub)
{
	const char *tmp1, *tmp2;

	while (*s) {
		if (*s == *sub) {
			tmp1 = s+1;	
			tmp2 = sub+1;
			while (*tmp2) {
				if (*tmp1 != *tmp2)	
					break;
				tmp1++;
				tmp2++;
			}
			if (*tmp2 == '\0') {
				//find substring
				return (char *)s;	
			}
		}	
		s ++;		
	}

	return NULL;
}





