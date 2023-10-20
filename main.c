#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Users{
    char username[20];
    char password[20];
    bool active;
};
void login(struct Users user);
void isExist(struct Users* users,char* username,char* password,int cntOfUsers);
bool _register(struct Users* users,char* username,int cntOfUsers);
int main() {
    char username[50], password[50];
    struct Users users[20];
    int cntOfUsers = 0;
    int operation_number = 0;
    while (1) {
        printf("Choose operation\n");
        printf("1: Login\n");
        printf("2: Register\n");
        printf("3: Exit\n");
        scanf("%d", &operation_number);

        if (operation_number == 1) {
            printf("Enter your Email: ");
            scanf("%s", username);
            printf("Enter your password: ");
            scanf("%s", password);
            isExist(users,username,password,cntOfUsers);
        }
        else if (operation_number == 2) {
            int active;
            printf("Enter your username: ");
            scanf("%s", users[cntOfUsers].username);
            printf("Enter your password: ");
            scanf("%s", users[cntOfUsers].password);
            printf("Enter Is this Active => 1 or not => 0: ");
            scanf("%d", &active);
            users[cntOfUsers].active = (active == 0) ? false : true;
            bool flag = _register(users,username,cntOfUsers);
            if(flag == 1){
                cntOfUsers++;
                printf("Register successful.\n");
            }
            else{
                printf("This email already exists\n");
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
void login(struct Users user){
    int operation;
    if(!user.active){
        printf("This account not active\n");
        return;
    }
    printf("Login successful\n");
    printf("Welcome %s \n",user.username);
    while (1){
        printf("What is action you went to do\n");
        printf("1: logout\n");
        scanf("%d", &operation);
        if(operation == 1){
            return;
        }
        else{
            printf("Invalid input. Please try again.\n");
        }
    }
}
void isExist(struct Users users[20],char username[50],char password[50],int cntOfUsers){
    int i = 0;
    int flag = 0;
    while(i < cntOfUsers){
        if(strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0){
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 1){
        login(users[i]);
    }
    else{
        printf("Incorrect Email or Password.\n");
    }
    return;
}
bool _register(struct Users* users,char* username,int cntOfUsers){
    int i=0;
    while(i < cntOfUsers){
        if(strcmp(users[cntOfUsers].username, users[i].username) == 0) {
            return false;
        }
        i++;
    }
    return true;
}