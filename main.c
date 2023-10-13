#include <stdio.h>
#include <string.h>

int main() {
    char username[20], password[20];
    char usernamesInDatabase[20][20], passwordsInDatabase[20][20];
    int UsersInDatabase = 0;
    int operation_number = 0;
    while (1) {
        printf("Choose operation\n");
        printf("1: Login\n");
        printf("2: Register\n");
        printf("3: Exit\n");
        scanf("%d", &operation_number);

        if (operation_number == 1) {
            printf("Enter a Email: ");
            scanf("%s", username);
            printf("Enter a password: ");
            scanf("%s", password);
            int i = 0;
            int flag = 0;
            while(i < UsersInDatabase){
                if(strcmp(username,usernamesInDatabase[i])==0&&strcmp(password,passwordsInDatabase[i])==0){
                    flag = 1;
                    break;
                }
                i++;
            }
            if(flag == 1){
                printf("Login successful!\n");
            }
            else{
                printf("Incorrect Email or Password.\n");
            }
        }
        else if (operation_number == 2) {
            printf("Enter your username: ");
            scanf("%s", usernamesInDatabase[UsersInDatabase]);
            printf("Enter your password: ");
            scanf("%s", passwordsInDatabase[UsersInDatabase]);
            int flag = 1,i=0;
            while(i<UsersInDatabase){
                if(strcmp(usernamesInDatabase[UsersInDatabase],usernamesInDatabase[i])==0) {
                    flag = 0;
                }
                i++;
            }
            if(flag == 1){
                UsersInDatabase++;
                printf("Register successful.\n");
            }
            else{
                printf("This email already exists!\n");
            }
        }
        else if (operation_number == 3) {
            printf("Good Bye\n");
            break;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}
