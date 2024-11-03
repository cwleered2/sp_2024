#include "kvs.h"
#define MAX_LINE_LENGTH 256

int main() {
    kvs_t* kvs = open();

    if (!kvs) {
        printf("Failed to open kvs\n");
        return -1;
    }

    FILE* query_file = fopen("query.dat", "r");
    if (!query_file) {
        printf("Failed to open query.dat\n");
        return -1;
    }

    FILE* answer_file = fopen("answer.dat", "w");
    if (!answer_file) {
        printf("Failed to open answer.dat\n");
        fclose(query_file);
        return -1;
    }

	char command[4], key[256], value[256];
	while (fscanf(query_file, "%3s, %99[^,],%99[^\n]\n",command, key, value)==3){
		if (strcmp(command, "set") == 0) {
			put(kvs, key, value);
		} 
		else if (strcmp(command, "get") == 0) {
			char* result = get(kvs, key);
			if (result) {
				//fprintf(answer_file, "result");
				fprintf(answer_file, "%s\n",result);  // 결과 저장
			} 
			else {
				fprintf(answer_file, "-1\n");  // 키가 없는 경우 -1 저장
			}
		}
	}
   

    fclose(query_file);
    fclose(answer_file);
    close(kvs);

    return 0;
}


//  char line[MAX_LINE_LENGTH];

//     while (fgets(line, sizeof(line), query_file)) {
//         char command[4];
//         char key[256];
//         char value[256];

//         if (sscanf(line, "%s %s %[^\n]", command, key, value) == 3) {
//             if (strcmp(command, "put") == 0) {
//                 put(kvs, key, value);
//             } 
// 			else if (strcmp(command, "get") == 0) {
//                 char* result = get(kvs, key);
//                 if (result) {
//                     fprintf(answer_file, "%s\n",result);  // 결과 저장
//                 } else {
//                     fprintf(answer_file, "-1\n");  // 키가 없는 경우 -1 저장
//                 }
//             }
//         }
//     }