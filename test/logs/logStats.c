//Script for dumping the *.log error counts
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){

        system("ls *.log > /tmp/ls_dump.txt");
	system("echo `printf ''` > /tmp/add_line.txt");
	system("cat /tmp/ls_dump.txt /tmp/add_line.txt > /tmp/temp_dump.txt; mv /tmp/temp_dump.txt /tmp/ls_dump.txt");
        FILE* ls_dump;
        ls_dump = fopen("/tmp/ls_dump.txt", "r");
	char log_file[200];

        while(!feof(ls_dump) && log_file != ""){
		fgets(log_file, 200, ls_dump);
		log_file[strlen(log_file)-1] = '\0';

		//Sys_arg compilation:
		char sys_arg[200] = "grep 'error =' ";
		strcat(sys_arg, log_file);
		strcat(sys_arg, " | wc -l ");

		char sys_echo[200] = "echo ";
		strcat(sys_echo, log_file);
		system(sys_echo);
		system(sys_arg);
	}
	printf("yooyoyoyoyo\n");
	fclose(ls_dump);
	system("rm /tmp/ls_dump.txt; rm /tmp/add_line.txt");


        return 0;
}
