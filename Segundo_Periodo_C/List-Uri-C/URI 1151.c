#include <stdio.h>

int main() {

    int i, n, primeiro, segundo, terceiro;
    primeiro = 0;
    segundo = 1;
    scanf("%d", &n);
    terceiro = primeiro + segundo;
    for (i = 0; i < n; i++){
        if (i == n -1){
            printf("%d\n", primeiro);
            break;
        }
        printf("%d ", primeiro);
        primeiro = segundo;
        segundo = terceiro;
        terceiro = primeiro + segundo;
    }

    return 0;
}
