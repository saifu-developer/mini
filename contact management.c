


#include <stdio.h>

struct Contact {
    char name[100], phone[20], email[100];
};

int main() {
    struct Contact c[10];
    int n = 0;

    while (1) {
        printf("1.Add 2.Display 3.Exit\n");
        int ch; scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter name, phone, email: ");
            scanf("%s %s %s", c[n].name, c[n].phone, c[n].email);
            n++;
        } else if (ch == 2) {
            for (int i = 0; i < n; i++)
                printf("Name: %s, Phone: %s, Email: %s\n", c[i].name, c[i].phone, c[i].email);
        } else return 0;
    }
}
