#include <stdio.h>
#include <shadow.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char name[32] = {};
	size_t size = 0;
	char *pwd;
	struct spwd *p;

	while (1) {
		printf("用户名:");
		fgets(name, 32, stdin);
		//'\n'
		name[strlen(name)-1] = 0;
		pwd = getpass("密码:");		

		//校验
		//获取user的加密之后的密码
		p = getspnam(name);
		if (NULL == p) {
			fprintf(stderr, "getspnam() failed\n");
			return 1;
		}
		pwd = crypt(pwd, p->sp_pwdp);
		if (NULL == pwd) {
			fprintf(stderr, "crypt() failed\n");
			return 1;
		}
		//pwd存储的就是加密之后的序列串	
		if (!strcmp(pwd, p->sp_pwdp)) {
			printf("登录成功\n");
			break;
		}
		printf("用户名或密码错误\n");	
	}


	return 0;
}
