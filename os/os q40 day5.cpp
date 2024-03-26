#include <stdio.h>

int main() {
    // File permissions: owner, group, others
    char permissions[3][3] = {
        {'r', 'w', 'x'}, // Owner permissions
        {'r', '-', 'x'}, // Group permissions
        {'r', '-', '-'}  // Others permissions
    };

    // Print file access permissions
    printf("File Access Permissions:\n");
    for (int i = 0; i < 3; i++) {
        printf("User Type %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c", permissions[i][j]);
        }
        printf("\n");
    }

    // Different types of users: owner, group, others
    printf("\nTypes of Users:\n");
    printf("1. Owner\n");
    printf("2. Group\n");
    printf("3. Others\n");

    return 0;
}

