#include "binary_trees.h"

queue_t *pop(queue_t **);

/**
 * is_full_node - Checks if a node is full.
 * @node: Pointer to the node that is being checked.
 * Return: If the node is full 1, Otherwise 0.
 */
int is_full_node(binary_tree_t *node)
{
	if (!node->left && node->right)
		return (0);
	if (node->left && !node->right)
		return (0);
	if (!node->left && !node->right)
		return (0);
	return (1);
}

/**
 * pop - Removes the top number in the queue.
 * @head: Head node in the queue.
 * Return: The number that was poped.
 */
queue_t *pop(queue_t **head)
{
	queue_t *node;

	if (!head || *head == NULL)
		return (NULL);
	node = *head;
	*head = node->next;
	return (node);
}

/**
 * add_to_queue - Adds a node to the queue
 * @head: Pointer to a pointer to the first node in the queue.
 * @child: Node to add to the queue.
 */
void add_to_queue(queue_t **head, binary_tree_t *child)
{
	queue_t *node;
	queue_t *tmp;

	if (!head || !child)
		return;
	tmp = *head;
	node = malloc(sizeof(queue_t));
	node->child = child;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}


/**
 * is_complete - Checks if the binary tree is complete looking at each level
 * and checking that after a non full node is found the next nodes are a leaf
 *
 * @head: Pointer to a pointer to the first node in a queue.
 * @flag: 1 if the tree is complete or 0 if incomplete
 * @full: 1 when node is full or 0 when is not.
 *
 * Return: 1 if the tree is complete. Otherwise 0.
 */
int is_complete(queue_t **head, int flag, int full)
{
	queue_t *poped;
	binary_tree_t *node;


	if (head == NULL || *head == NULL)
		return (flag);
	poped = pop(head);
	if (poped == NULL)
		return (flag);
	node = poped->child;
	if (full == 0) /*The node is not full*/
	{
		/*Everything else needs to be a leaf*/
		if (!(node->left == NULL && node->right == NULL))
			flag = 0;
	}
	if (node->left == NULL && node->right != NULL)
		flag = 0;
	full = is_full_node(node);
	add_to_queue(head, poped->child->left);
	add_to_queue(head, poped->child->right);
	flag = is_complete(head, flag, full);
	free(poped);
	return (flag);
}

/**
 * binary_tree_is_complete - Checks if the binary tree is complete.
 * @tree: Pointer to a pointer to the first node in the tree.
 *
 * Return: 1 if the tree is complete. Otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flag;
	int full;
	queue_t *head;

	head = NULL;
	if (tree == NULL)
		return (0);
	add_to_queue(&head, (binary_tree_t *)tree);
	flag = 1;
	full = 1;
	flag = is_complete(&head, flag, full);
	return (flag);
}
