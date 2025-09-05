#include "Tile.hpp"
#include<raylib.h>
#include "knight.hpp"





void Tile::set_directions(Tile* up, Tile* down, Tile* left, Tile* right, Tile* upLeft, Tile* upRight, Tile* downLeft, Tile* downRight) {
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
    this->upLeft = upLeft;
    this->upRight = upRight;
    this->downLeft = downLeft;
    this->downRight = downRight;
}
void Tile::set_position(Vector2 a){
    this->pos = a;
}

Vector2 Tile::get_pos(){
    return this->pos;
}
Color Tile::get_color(){
    return this->color;
}
float Tile::get_width(){
    return this->width;
}
float Tile::get_height(){
    return this->height;
}


Tile* Tile::search_up(){
    return this->up;
}
Tile* Tile::search_down(){
    return this->down;
}
Tile* Tile::search_left(){
    return this->left;
}
Tile* Tile::search_right(){
    return this->right;
}
Tile* Tile::search_upLeft(){
    return this->upLeft;
}
Tile* Tile::search_upRight(){
    return this->upRight;
}
Tile* Tile::search_downLeft(){
    return this->downLeft;
}
Tile* Tile::search_downRight(){
    return this->downRight;
}




