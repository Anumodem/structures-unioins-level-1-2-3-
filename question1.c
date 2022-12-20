#include <stdio.h>
union book{
    char name_of_book[20];
    char author_of_book[20];
    char genre_of_book[20];
}b2,b3;
int main()
{
    union book b1;
    scanf("%s",b1.name_of_book);
    scanf("%s",b2.author_of_book);
    scanf("%s",b3.genre_of_book);
    printf("Title:%s\n",b1.name_of_book);
    printf("Writer:%s\n",b2.author_of_book);
    printf("Genre:%s\n",b3.genre_of_book);

	return 0;
}
