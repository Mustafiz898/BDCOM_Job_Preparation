#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library{
    const char *Book_name;
    int customer_id;
    int rent_no;
    char author[200];

};

int main(){
    struct library c1 = {"book1", 101, 1};
    struct library c2 = {"book2", 102, 2};
    struct library c3 = {"book3", 103, 3};
    struct library c4 ={.Book_name = "book4",.rent_no = 4, .customer_id = 104};
    
    // author name input 
    strcpy(c1.author, "Author01");
    strcpy(c2.author, "Author02");
    strcpy(c3.author, "Author03");
    strcpy(c4.author, "Author04");


    printf("Book Name: %s Customer Id: %d Rent no.: %d Author: %s\n", c1.Book_name, c1.customer_id, c1.rent_no, c1.author);
    printf("Book Name: %s Customer Id: %d Rent no.: %d Author: %s\n", c2.Book_name, c2.customer_id, c2.rent_no, c2.author);
    printf("Book Name: %s Customer Id: %d Rent no.: %d Author: %s\n", c3.Book_name, c3.customer_id, c3.rent_no, c3.author);
    printf("Book Name: %s Customer Id: %d Rent no.: %d Author: %s\n", c4.Book_name, c4.customer_id, c4.rent_no, c4.author);
    
    return 0;
}