#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <raylib.h>
#include "knight.hpp"
#include "tile.hpp"

class knight
{
private:
    Texture2D knight_texture;
    Texture2D white_texture;
    Vector2 pos;
    knight *me = this;

public:
    Tile *current_tile;
    void draw_knight_black();
    void draw_rook_black();
    void draw_bishop_black();
    void draw_queen_black();
    void draw_king_black();
    void draw_pawn_black();
    void draw_knight_white();
    void draw_rook_white();
    void draw_bishop_white();
    void draw_queen_white();
    void draw_king_white();
    void draw_pawn_white();
    
    void lod_knight_texture();


    //search algos
    
};

#endif