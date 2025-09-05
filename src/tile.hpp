#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include<raylib.h>



class Tile 
{

private:
    Vector2 pos;
    const float width = 100;
    const float height = 75;
    Color color;
    std::string name;
    

public:
    
    // Directional pointers to adjacent tiles
    
    Tile *up = nullptr;
    Tile *down = nullptr;
    Tile *left = nullptr;
    Tile *right = nullptr;
    Tile *upLeft = nullptr;
    Tile *upRight = nullptr;
    Tile *downLeft = nullptr;
    Tile *downRight = nullptr;
    Tile *me = nullptr;
    //methods

    Tile(Color color ,std::string name ){
        this->color = color;
        this->name = name;
        
    }
    void declare_positions();
    void set_directions(Tile* up, Tile* down, Tile* left, Tile* right, Tile* upLeft, Tile* upRight, Tile* downLeft, Tile* downRight);
    void set_position(Vector2);
    Vector2 get_pos();
    float get_width();
    float get_height();
    Color get_color();
    


    //search algos
    Tile* search_up(); 
    Tile* search_down();
    Tile* search_left();
    Tile* search_right();
    Tile* search_upLeft();
    Tile* search_upRight();
    Tile* search_downLeft();
    Tile* search_downRight();
    

};



#endif
