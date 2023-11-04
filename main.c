#include<stdio.h>
#include<stdlib.h>
#include"BigInteger.h"


int main() {
    long long int num1,num2,revNum1=0,revNum2=0,temp;
    struct node* head1,* head2,* sum,* sub,* div,* mult,* mod;
    head1=head2=sum=NULL;
    printf("Enter Two Number: ");
    scanf("%lld %lld",&num1,&num2);
    temp = num1;
    while(temp != 0) {
        revNum1 = revNum1*10 + temp%10;
        temp = temp/10;
    }
    temp = num2;
    while (temp != 0)
    {
        revNum2 = revNum2 * 10 + temp % 10;
        temp = temp / 10;
    }
    temp = revNum1;
    while(temp != 0) {
        addNode(&head1,temp%10);
        temp = temp/10;
    }
    temp = revNum2;
    while (temp != 0)
    {
        addNode(&head2, temp % 10);
        temp = temp / 10;
    }
    int choice;
    do{
        printf(" Enter choice: \n -1 Exit\n 0 add\n 1 subtract\n 2 multiply\n 3 divide\n 4 modulus\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            sum = add(head1,head2);
            printf("%llu + %llu = ",num1,num2);
            display(sum);
            break;
        case 1:
            if(num1 > num2) {
                sub = subtract(head1, head2);
                printf("%llu - %llu = ",num1,num2);
                display(sub);
            }
            else{
                sub = subtract(head2, head1);
                printf("%llu - %llu = -",num1,num2);
                display(sub);
            }
            break;
        case 3: 
            div = divide(num1,num2);
            printf("%llu / %llu = ",num1,num2);
            display(div);
            break;
        case 2:
            mult = multiply(num1,num2);
            printf("%llu * %llu = ",num1,num2);
            display(mult);
            break;
        case 4:
            mod = modulus(num1,num2);
            printf("%llu mod %llu = ",num1,num2);
            display(mod);        default:
            break;
        }
    }while(choice != -1);
}