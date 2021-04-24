/* 

结构体

C 数组允许定义可存储相同类型数据项的变量，结构是 C 编程中另一种用户自定义的可用的数据类型，它允许您存储不同类型的数据项。

为了定义结构，您必须使用 struct 语句。struct 语句定义了一个包含多个成员的新的数据类型，struct 语句的格式如下：


声明结构体的几中形式

//声明结构
struct tag { 
    member-list
};
//定义这种结构的变量
struct tag variable-list


struct tag{
    member-list
} variable-list; 


struct{
    member-list
} variable-list;



 */
#include <stdio.h>
#include <string.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};
void printBook(struct Books book)
{
    book.book_id = 99;
    printf("Book title : %s\n", book.title);
    printf("Book author : %s\n", book.author);
    printf("Book subject : %s\n", book.subject);
    printf("Book book_id : %d\n", book.book_id);
}
void printBook1(struct Books *book)
{
    book->book_id = 99; //为了使用指向该结构的指针访问结构的成员，您必须使用 -> 运算符
    printf("Book title : %s\n", book->title);
    printf("Book author : %s\n", book->author);
    printf("Book subject : %s\n", book->subject);
    printf("Book book_id : %d\n", book->book_id);
}
struct Books book = {"C language", "azrael", "language", 10086};
struct Books Book1 = {"C Programming", "Nuha Ali", "C Programming Tutorial", 6495407};
struct Books Book2 = {"Telecom Billing", "Zara Ali", "Telecom Billing Tutorial", 6495700};
int main()
{

    // printf("%s\n%d\n%s\n%d\nd", book.title, book.book_id, book.subject, book.book_id);

    printBook(Book1);
    /* 输出 Book1 信息 */
    printf("---------------------------------\n");
    printf("Book 1 title : %s\n", Book1.title);
    printf("Book 1 author : %s\n", Book1.author);
    printf("Book 1 subject : %s\n", Book1.subject);
    printf("Book 1 book_id : %d\n", Book1.book_id);
    printf("---------------------------------\n");

    printBook1(&Book1);
    printf("---------------------------------\n");
    printf("Book 1 title : %s\n", Book1.title);
    printf("Book 1 author : %s\n", Book1.author);
    printf("Book 1 subject : %s\n", Book1.subject);
    printf("Book 1 book_id : %d\n", Book1.book_id);

    // /* 输出 Book2 信息 */
    // printf("Book 2 title : %s\n", Book2.title);
    // printf("Book 2 author : %s\n", Book2.author);
    // printf("Book 2 subject : %s\n", Book2.subject);
    // printf("Book 2 book_id : %d\n", Book2.book_id);
    return 0;
}