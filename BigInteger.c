#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node* next;
};

void addNode(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    if ((*head) == NULL)
    {
        temp->next = NULL;
        (*head) = temp;
        return;
    }
    temp->next = (*head);
    (*head) = temp;
}
void display(struct node *it)
{
    while (it != NULL)
    {
        printf("%d", it->data);
        it = it->next;
    }
    printf("\n");
}
struct node *add(struct node *head1, struct node *head2) {
	struct node* res = NULL,*temp;
    int carry;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = (head1->data + head2->data)%10;
    carry = (head1->data + head2->data) / 10;
    temp->next = NULL;
    head1=head1->next;
    head2=head2->next;
    res = temp;
    while (head1 != NULL && head2 != NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = (head1->data + head2->data + carry) % 10;
        carry = (head1->data + head2->data + carry) / 10;
        temp->next = res;
        head1 = head1->next;
        head2 = head2->next;
        res = temp;
    }
    while (head1 != NULL )
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = (head1->data + carry) % 10;
        carry = (head1->data + carry) / 10;
        temp->next = res;
        head1 = head1->next;
        res = temp;
    }
    while (head2 != NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = (head1->data + carry) % 10;
        carry = (head2->data + carry) / 10;
        temp->next = res;
        head2 = head2->next;
        res = temp;
    }
    if(carry != 0) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = carry;
        temp->next = res;
        res = temp;
    }
    return res;
}
struct node *subtract(struct node * head1, struct node *head2) {
    struct node* res = NULL,*temp,* it;
    if(head1->data < head2->data) {
        temp = (struct node* )malloc(sizeof(struct node));
        head1->data += 10;
        it = head1;
        it = it->next;
        it->data--;
        temp->data = (head1->data - head2->data);
        temp->next = NULL;
        head1 = head1->next;
        head2 = head2->next;
        res = temp;
    } else {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = (head1->data - head2->data);
        temp->next = NULL;
        head1 = head1->next;
        head2 = head2->next;
        res = temp;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            head1->data += 10;
            it = head1;
            it = it->next;
            it->data--;
            temp->data = (head1->data - head2->data);
            temp->next = res;
            head1 = head1->next;
            head2 = head2->next;
            res = temp;
        }
        else
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = (head1->data - head2->data);
            temp->next = res;
            head1 = head1->next;
            head2 = head2->next;
            res = temp;
        }
    }
    while (head1 != NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = head1->data;
        temp->next = res;
        head1 = head1->next;
        res = temp;
    }
    return res;
}
struct node *multiply(long long int num1, long long int num2) {
    long long int res = num1*num2;
    struct node* ans = NULL;
    while (res != 0)
    {
        addNode(&ans,res%10);
        res = res/10;
    }
    return ans;
}
struct node* divide(long long int num1, long long int num2) {
    long long int res = num1/num2;
    struct node *ans = NULL;
    while (res != 0)
    {
        addNode(&ans, res % 10);
        res = res / 10;
    }
    return ans;
}
struct node* modulus(long long int num1, long long int num2) {
    long long int res = num1%num2;
    struct node *ans = NULL;
    while (res != 0)
    {
        addNode(&ans, res % 10);
        res = res / 10;
    }
    return ans;
}