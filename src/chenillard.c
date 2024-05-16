#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    
    FILE * fp = NULL;
    const char* mode = "w+";        
    const char* filename[] = {
        "/sys/class/leds/fpga_led0/brightness",
        "/sys/class/leds/fpga_led1/brightness",
        "/sys/class/leds/fpga_led2/brightness",
        "/sys/class/leds/fpga_led3/brightness",
        "/sys/class/leds/fpga_led4/brightness",
        "/sys/class/leds/fpga_led5/brightness",
        "/sys/class/leds/fpga_led6/brightness",
        "/sys/class/leds/fpga_led7/brightness",
        "/sys/class/leds/fpga_led8/brightness",
        "/sys/class/leds/fpga_led9/brightness"
    };   

    
    while(1) {
        for (int i=0; i<10; i++) {
            fp = fopen(filename[i], mode);        

            if (fp == NULL) {
                printf("Impossible d'ouvrir le fichier de la LED %d\n", i);
            } else {
                fputc('1', fp ); // Écriture du caractère A
                fclose(fp);
                usleep(100000);            
            }
        }

        for (int i=9; i>=0; i--) {
            fp = fopen(filename[i], mode);        

            if (fp == NULL) {
                printf("Impossible d'ouvrir le fichier de la LED %d\n", i);
            } else {
                fputc('0', fp ); // Écriture du caractère A
                fclose(fp);
                usleep(100000);            
            }
        }
    }      
   
    return 0;
}