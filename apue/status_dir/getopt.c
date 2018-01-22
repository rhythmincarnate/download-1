#include <stdio.h>
#include <getopt.h>
#include <unistd.h>

/*
 	-m "message comming"
	-h "hello world"
	--help
	--list
	-l 参数
	非选项参数
 */

int main(int argc, char **argv)
{
	int ch;
	int index;
	struct option ops[] = {
		{"help", no_argument, NULL, 'e'},
		{"list", optional_argument, NULL, 'i'},
		{0, 0, 0, 0}
	};

	while (1) {
		//ch = getopt(argc, argv, "-mhl:");
		ch = getopt_long(argc, argv, "-mhl:", ops, &index);
		if (ch < 0) {
			break;
		}
		switch (ch) {
			case 'm':
				printf("messages comming\n");	
				break;
			case 'h':
				printf("hello world\n");
				break;	
			case 'l':
				printf("have the argument\n");
				printf("arg: %s\n", optarg);
				break;
			case 1:
				printf("non-option argment\n");	
				printf("%s\n", argv[optind-1]);
				break;
			case '?':
				printf("have no this option\n");
				break;
			case 'e':
				printf("help! help! help!, index:%d\n", index);
				break;
			case 'i':
				printf("list menu\n");
				if (optarg != NULL) {
					printf("the argument is %s\n", optarg);
				}
				break;
			default:
				break;
		}
	}

	return 0;
}


