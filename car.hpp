#include <iostream>
#include <fstream>
#include <list>
struct State{
    int VELOCITY[2];
    int POSITION_COORDINATES[2];
};


class Car{
    /*
    Index 0: Distance, 
    Index 1: Speed
    */
    private:
    // ORIGIN VECTOR
        State state;
        int dt = 1;
        int DIRRECTION_VECTOR[2];
        int WORLD[4][4];
        std::list <State> path;
    public:
        Car(int POSITION[2], int velocity[2], int WORLD_IN[4][4]);
        void start();
        void updateWorld();
        void predictState(int dt);
        void move();
        void turnLeft();
        void turnRight();
        void displayWorld();
};
Car::Car(int POSITION[2], int VELOCITY[2], int WORLD_IN[4][4]){
    std::ofstream writer;
    writer.open("world.txt");
    //Intitializing world
    for(int i1= 0; i1<4; i1++ ){
        for(int i2= 0; i2<4;i2++){
            WORLD[i2][i1] = WORLD_IN[i2][i1];
            writer <<WORLD[i2][i1];
            if(i2 ==3){
                writer << std::endl;  
            }
            else{
                writer <<" - ";
            }
        }
    }
    writer.close();
    //Initialize States
    for(int i = 0; i<2; i++){
        state.VELOCITY[i] = VELOCITY[i];
        state.POSITION_COORDINATES[i] = POSITION[i];
    }   
    //Add to path 
    path.push_back(state);
}
void Car::updateWorld(){
    std::ofstream writer;
    writer.open("world.txt");
    WORLD[state.POSITION_COORDINATES[0]][state.POSITION_COORDINATES[1]] = 1;
    for(int i1= 0; i1<4; i1++ ){
        for(int i2= 0; i2<4;i2++){
            WORLD[i2][i1] = 0;

            if((i2 == state.POSITION_COORDINATES[0]) && (i1 ==state.POSITION_COORDINATES[1])){

            }
            writer <<WORLD[i2][i1];        
            if(i2 ==3){
                writer << std::endl;  
            }
            else{
                writer <<" - ";
            }
        }
    }
}
void Car::move(){
    /*Move Car in the Dirrection of the Velocity 
    */
   state.POSITION_COORDINATES[0] = (state.POSITION_COORDINATES[0] + (state.VELOCITY[0] * dt))%4;
   state.POSITION_COORDINATES[1] = (state.POSITION_COORDINATES[1] + (state.VELOCITY[1] * dt))%4;
   path.push_back(state);
   updateWorld();
}
void Car::turnRight(){
    state.VELOCITY[1] = -state.VELOCITY[0] ;
    state.VELOCITY[0] =  state.VELOCITY[1];
}
void Car::turnRight(){
    state.VELOCITY[1] = -state.VELOCITY[0] ;
    state.VELOCITY[0] =  state.VELOCITY[1];
}X