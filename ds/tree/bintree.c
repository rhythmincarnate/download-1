#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE	32

struct stu_st {
	int id;
	char name[NAMESIZE];
};

//树结点数据类型
struct node_st {
	struct stu_st stu;
	struct node_st *left;//左子树根的地址
	struct node_st *right;//右子树根的地址
};

static struct node_st *tree = NULL;

/*
	插入一个新的结点 
	root:存储用于存放树的根结点的指针变量的地址 
	data:存储在当前结点的数据的地址
 */
int tree_insert(struct node_st **root, const struct stu_st *data)
{
	struct node_st *new;

	if (*root == NULL) {
		new = malloc(sizeof(*new));
		if (NULL == new)
			return -1;
		memset(new, '\0', sizeof(*new));
		memcpy(&new->stu, data, sizeof(*data));
		new->left = new->right = NULL;
		//空树
		*root = new;	
		return 0;
	}
	if (data->id <= (*root)->stu.id) {
		return tree_insert(&(*root)->left, data);	
	} else {
		return tree_insert(&(*root)->right, data); 	
	}
}

/*
 树的遍历
 中序
	root:根结点的地址
 
 */
void tree_traval(const struct node_st *root)
{
	if (root == NULL)
		return;
	tree_traval(root->left);
	printf("%d %s\n", root->stu.id, root->stu.name);
	tree_traval(root->right);
}

static void __draw(const struct node_st *root, int level)
{
	if (root == NULL)
		return;
	__draw(root->right, level+1);
	for (int i = 0; i < level; i++)
		printf("    ");
	printf("%d %s\n", root->stu.id, root->stu.name);
	__draw(root->left, level+1);
}

/*
 打印树
 */
void tree_draw(const struct node_st *root)
{
	__draw(root, 1);
}

//平衡二叉树
//计算出树的结点个数
int tree_nodenum(const struct node_st *root)
{
	if (root == NULL)
		return 0;
	return (tree_nodenum(root->left) + tree_nodenum(root->right) + 1);
}

static struct node_st *find_max_node(const struct node_st *root)
{
	if (root->right == NULL)
		return (void *)root;
	return find_max_node(root->right);
}

//左子树结点多 向右旋转
void tree_turnright(struct node_st **root)
{
	struct node_st *cur, *l, *r;
	cur = (*root);
	l = cur->left;
	r = cur->right;

	if (l != NULL)	{
		*root = l;	
		cur->left = NULL;
		find_max_node(l)->right = cur;
	}
	getchar();
	tree_draw(tree);
}

static struct node_st *find_min_node(struct node_st *root)
{
	if (root->left == NULL)
		return root;
	return find_min_node(root->left);
}

//右子树的结点多　向左旋转
void tree_turnleft(struct node_st **root)
{
	struct node_st *cur, *r, *l;

	cur = (*root);
	r = cur->right;
	l = cur->left;

	if (r != NULL) {
		(*root) = r;
		cur->right = NULL;
		find_min_node(r)->left = cur;
	}

	getchar();
	tree_draw(tree);
}

void tree_balance(struct node_st **root)
{
	int num;

	if ((*root) == NULL)
		return;

	while (1) {
		num = tree_nodenum((*root)->left) - tree_nodenum((*root)->right);
		if (num < -1) {
			tree_turnleft(root);	
		} else if (num > 1) {
			tree_turnright(root);
		} else
			break;
	}

	tree_balance(&(*root)->left);
	tree_balance(&(*root)->right);
}

int main(void)
{
	int id[] = {1,2,3,4,5,6,7,8,9,10};
	char *name[] = {"malongxiang", "hekaifang", "wangsicheng", "sunlei", "sunweiyuan",\
	"huhuixiang", "zhanwenge", "yangming", "zhangbin", "lixuexi"};
	struct stu_st stu;

	for (int i = 0; i < sizeof(id)/sizeof(*id); i++) {
		stu.id = id[i];	
		strcpy(stu.name, name[i]);
		tree_insert(&tree, &stu);
	}

//	tree_traval(root);
	tree_draw(tree);

	printf("**************after balance**************\n");
	tree_balance(&tree);
	tree_draw(tree);


	return 0;
}

