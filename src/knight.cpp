#include "knight.hpp"
#include "tile.hpp"

void knight::draw_knight_black(){
    // pos , pos , width , height
    Rectangle source{17,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(knight_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_rook_black(){
    // pos , pos , width , height
    Rectangle source{33,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(knight_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_bishop_black(){
    // pos , pos , width , height
    Rectangle source{81,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(knight_texture, source ,dest , Vector2{0,0} ,0, WHITE);
} 

void knight::draw_queen_black(){
    // pos , pos , width , height
    Rectangle source{65,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(knight_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_king_black(){
    // pos , pos , width , height
    Rectangle source{49,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(knight_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_pawn_black(){
    // pos , pos , width , height
    Rectangle source{1,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(knight_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_knight_white(){
    // pos , pos , width , height
    Rectangle source{17,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(white_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_rook_white(){
    // pos , pos , width , height
    Rectangle source{33,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(white_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_bishop_white(){
    // pos , pos , width , height
    Rectangle source{81,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(white_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_queen_white(){
    // pos , pos , width , height
    Rectangle source{65,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(white_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_king_white(){
    // pos , pos , width , height
    Rectangle source{49,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(white_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}

void knight::draw_pawn_white(){
    // pos , pos , width , height
    Rectangle source{1,0,16,16};
    //1 pawn , 17 knight , 33 rook , 49 king , 65 queen , 81 bishop
    Rectangle dest{current_tile->get_pos().x,current_tile->get_pos().y,100,75};
    
    DrawTexturePro(white_texture, source ,dest , Vector2{0,0} ,0, WHITE);
}




void knight::lod_knight_texture(){
    Texture2D tex , tex2;
    tex = LoadTexture("src/BlackPieces_Simplified.png");
    tex2 = LoadTexture("src/WhitePieces_Wood.png");
    this->knight_texture = tex;
    this->white_texture = tex2;
}

