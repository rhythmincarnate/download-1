#ifndef __STDIO_H
#define __STDIO_H

#define IO_ERR(fname)	\
		{\
			fprintf(stderr, "%s() error\n", #fname);\
			return 1;\
		}
#endif

