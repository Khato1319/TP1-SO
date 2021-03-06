// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "masterADT.h"

#define READ 0700
#define WRITE 0007

#define RESULT_PATH "./results.txt"


int main(int argc, char *argv[])
{
    sleep(2);
    masterADT master = new_master(argv + 1, argc - 1, RESULT_PATH);
    init_slaves(master);
    assign_initial_tasks(master); // Asignamos 2 tareas iniciales por esclavo
    fetch_and_assign_new_tasks(master); // Si se libera alguno, le damos una tarea nueva
    free_master(master);
    return 0;
}


        
   