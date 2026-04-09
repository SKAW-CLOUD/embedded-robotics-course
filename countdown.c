#include <stdio.h>
#include <unistd.h>  

int main() {
    int minutes, seconds;
    
    printf("Enter countdown time (MM SS): ");
    
   
    scanf("%d %d", &minutes, &seconds);

    
    int total_seconds = minutes * 60 + seconds;

    
    if (total_seconds <= 0) {
        printf("Error: Invalid time\n");
        return 1;
    }

   
    while (total_seconds > 0) {
        int display_min = total_seconds / 60;
        int display_sec = total_seconds % 60;

        
        printf("%02d:%02d\r", display_min, display_sec);
        fflush(stdout);  

        sleep(1);        
        total_seconds--; 
    }

    
    printf("\nTIME IS UP!\n");
    printf("\a");  

    return 0;
}