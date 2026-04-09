#include <stdio.h>
#include <windows.h>

typedef enum {
    RED, 
    YELLOW,
    GREEN,
    PEDESTRIAN_WALK,
}lightstate;

#define RED_DURATION 5
#define GREEN_DURATION 4 
#define YELLOW_DURATION 2
#define WALK_DURATION 3

int main(){
LightState current_state = RED;
int timer = 0;
int pedestrian_button = 0;

while (1){
switch (current_state) {

case RED:
    printf("RED - Stop");
    timer++;
    if (timer = RED_DURATION){
        current_state = GREEN;
        timer = 0;
    }
    break;

case GREEN:
printf("GREEN - Cross");
timer++;
if (timer == 2) {
pedestrian_button = 1;
}

if (pedestrian_button) {
current_state = YELLOW;
timer = 0;
pedestrian_button = 0;
}

else if (timer >= GREEN_DURATION) {
current_state = YELLOW;
timer = 0;
}
break;


case YELLOW:
printf("YELLOW - Calm down");
timer++;

if (timer >= YELLOW_DURATION) {
if (pedestrian_button) {
current_state = PEDESTRIAN_WALK;

} else {
current_state = RED;
    }
timer = 0;
}
break;

case PEDESTRIAN_WALK:
printf("RED - WALK for pedestrians");
timer++;

if (timer >= WALK_DURATION) {
current_state = RED;
timer = 0;
}
break;

}

sleep(1);  
    }

    return 0;
}
