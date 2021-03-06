// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utilities.h"
#include "sh_mem_ADT.h"

#define MAX_ID_LENGTH 20
#define MAX_OUTPUT_LENGTH 256

int main(int argc, char *argv[])
{
    int key;
    if (argc == 1)
    {   // Llamo por el master
        // Recibo de STDIN el id de shared memory
        char buff[MAX_ID_LENGTH + 1];
        int count = read(STDIN_FILENO, buff, MAX_ID_LENGTH);
        if (count == -1)
        {
            error_exit("Error reading from STDIN", WRITE_ERROR);
        }

        buff[count] = 0;
        key =  atoi(buff);
    }
    else
    {
        // Recibo por argumento el id de shared memory
        key = atoi(argv[1]);
    }

    sh_mem_ADT sh_mem = new_sh_mem(&key, READ);

    // Imprimir por salida estandar

    char output[MAX_OUTPUT_LENGTH];

    read_sh_mem(sh_mem, output); // Lo primero que leo es la cantidad de lineas total

    int lines = atoi(output);
    int counter = 0;

    while(counter < lines) {  
        read_sh_mem(sh_mem, output);
        
        if (printf("%s\n", output) < 0)
            error_exit("Error printing line to stdout", WRITE_ERROR);

        counter++;
    }

    free_sh_mem(sh_mem);

    return 0;
}
