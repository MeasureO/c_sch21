#include <stdio.h>

void encode();
void decode();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("n/a");
        return 0;
    }
    char cmd_mode = *argv[1];
    if (cmd_mode == '0' || cmd_mode == '1') {
        // if (scanf("%c\n", &cmd_mode) == 1 && (cmd_mode == '0' || cmd_mode == '1')) {
        if (cmd_mode == '0') {
            encode();
        } else {
            decode();
        }
    } else {
        printf("n/a\n");
    }
}

void encode() {
    // char c;
    // int flag = 0;
    while (1) {
        char a = getchar();
        char b = getchar();
        if ((b == ' ' || b == '\n') && (('A' < a && a < 'Z') || ('a' < a && a < 'z'))) {
            printf("%X", a);
            if (b != '\n')
                printf("%c", b);
            else
                break;
        } else {
            printf("n/a");
            break;
        }
    }
    /* while (scanf("%c", &c) == 1 && c != '\n') {
         if (c == ' ' && flag == 1) {
             printf("%c", c);
             flag -= 1;

         } else if (c != ' ' && flag == 0) {
             printf("%X", c);
             flag += 1;
         } else {
             printf("n/a\n");
         }
     }
     printf("\n");
     */
}
void decode() {
    int a;
    char b;
    while (1) {
        if (scanf("%X%c", &a, &b) == 2 && (b == ' ' || b == '\n')) {
            if (b == ' ') {
                printf("%c", a);
            } else {
                printf("n/a");
                break;
            }
            if (b != '\n')
                printf("%c", b);
            else
                printf("n/a");
        } else {
            printf("n/a");
            break;
        }
    }
    // char c;
    // int nt;
    // int t;
    // int flag = 0;
    /*
    while (scanf("%c", &c) == 1 && c != '\n') {
        if (c == ' ') {
            t = 0;
            flag = 0;
        } else if (c != ' ' && flag == 0) {
            t += (int) c * 16;
            flag += 1;
        } else if ((c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F')  && flag == 1) {
            t += (int ) c - 55;
            flag += 1;
            printf("%c ", (char) t);
        } else if (c != ' ' && flag == 1) {
           // printf("ts:(%d)", (int) c);
            t += (int ) c - 48;
            flag += 1;
            printf("%c ", (char) t);
        } else {
            printf("n/a\n");
        }
    }
    printf("\n");
    */
}
/*   while (scanf("%d", &c) == 1 ) {
      // printf("%d", c);
      nt = getchar();
      if (nt == '\n') {
          break;
      }
      if (nt == ' ') {
          t = c / 10 * 16 + c % 10;
      } else if (nt == 'A' || nt == 'B' || nt == 'C' || nt == 'D' || nt == 'E' || nt == 'F') {
          t = c * 16 + (int) nt - 55;
      }
      printf("%c ", (char) t);
   }
*/
