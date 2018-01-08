# 指定头文件路径
# makefile的变量CFLAGS makefile的默认规则会自动读取的变量
# CFLAGS加头文件途径	LDFLAGS 指定链接库名 LDFLAGS+=-lmath
CFLAGS+=-I.

# 定义变量
SRC=main.o

# 追加
SRC+=list.o

# 编译规则

# 目标:依赖
#规则 如何通过依赖生存目标
seqlist:$(SRC)
	gcc -o $@ $^
#@gcc -o seqlist $(SRC)
# $@ 目标变量  $^依赖文件

#main.o:main.c
#	gcc -c -o main.o main.c

#list.o:list.c
#	gcc -c -o list.o list.c

#没有依赖的目标称为伪目标
clean:
	rm *.o seqlist

test:
	ls -l

