#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int opt;
    char *num_param = NULL;
    char *head_param = NULL;
    char *remote_param = NULL;

    // コマンドの引数処理
    while ((opt = getopt(argc, argv, "n:h:r::")) != -1) {
        switch (opt) {
            case 'n':
                num_param = optarg;
                break;
            case 'h':
                head_param = optarg;
                break;
            case 'r':
                remote_param = optarg;
                break;
            default:
                printf("Usage: %s [-n pull-req number] [-h head] [-r repo]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (num_param == NULL || head_param == NULL) {
        exit(EXIT_FAILURE);
    }


    // 実行コマンドの整形
    char exec_cmd[256];
    if (remote_param == NULL) {
        sprintf(exec_cmd, "git fetch origin pull/%s/head:%s", num_param, head_param);
    } else {
        sprintf(exec_cmd, "git fetch %s pull/%s/head:%s", remote_param, num_param, head_param);
    }


    // コマンド実行
    if (system(exec_cmd) == -1) {
        perror("Failed to execute command!");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
