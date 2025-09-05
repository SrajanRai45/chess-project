#include <raylib.h>
#include "tile.hpp"
#include <iostream>
#include "knight.hpp"

float pos[64][2] = {{0, 0}, {0, 75}, {0, 150}, {0, 225}, {0, 300}, {0, 375}, {0, 450}, {0, 525}, {100, 0}, {100, 75}, {100, 150}, {100, 225}, {100, 300}, {100, 375}, {100, 450}, {100, 525}, {200, 0}, {200, 75}, {200, 150}, {200, 225}, {200, 300}, {200, 375}, {200, 450}, {200, 525}, {300, 0}, {300, 75}, {300, 150}, {300, 225}, {300, 300}, {300, 375}, {300, 450}, {300, 525}, {400, 0}, {400, 75}, {400, 150}, {400, 225}, {400, 300}, {400, 375}, {400, 450}, {400, 525}, {500, 0}, {500, 75}, {500, 150}, {500, 225}, {500, 300}, {500, 375}, {500, 450}, {500, 525}, {600, 0}, {600, 75}, {600, 150}, {600, 225}, {600, 300}, {600, 375}, {600, 450}, {600, 525}, {700, 0}, {700, 75}, {700, 150}, {700, 225}, {700, 300}, {700, 375}, {700, 450}, {700, 525}};

// Declare all the tiles
Tile a1(WHITE, "a1"), a2(BLACK, "a2"), a3(WHITE, "a3"), a4(BLACK, "a4"), a5(WHITE, "a5"), a6(BLACK, "a6"), a7(WHITE, "a7"), a8(BLACK, "a8");
Tile b1(BLACK, "b1"), b2(WHITE, "b2"), b3(BLACK, "b3"), b4(WHITE, "b4"), b5(BLACK, "b5"), b6(WHITE, "b6"), b7(BLACK, "b7"), b8(WHITE, "b8");
Tile c1(WHITE, "c1"), c2(BLACK, "c2"), c3(WHITE, "c3"), c4(BLACK, "c4"), c5(WHITE, "c5"), c6(BLACK, "c6"), c7(WHITE, "c7"), c8(BLACK, "c8");
Tile d1(BLACK, "d1"), d2(WHITE, "d2"), d3(BLACK, "d3"), d4(WHITE, "d4"), d5(BLACK, "d5"), d6(WHITE, "d6"), d7(BLACK, "d7"), d8(WHITE, "d8");
Tile e1(WHITE, "e1"), e2(BLACK, "e2"), e3(WHITE, "e3"), e4(BLACK, "e4"), e5(WHITE, "e5"), e6(BLACK, "e6"), e7(WHITE, "e7"), e8(BLACK, "e8");
Tile f1(BLACK, "f1"), f2(WHITE, "f2"), f3(BLACK, "f3"), f4(WHITE, "f4"), f5(BLACK, "f5"), f6(WHITE, "f6"), f7(BLACK, "f7"), f8(WHITE, "f8");
Tile g1(WHITE, "g1"), g2(BLACK, "g2"), g3(WHITE, "g3"), g4(BLACK, "g4"), g5(WHITE, "g5"), g6(BLACK, "g6"), g7(WHITE, "g7"), g8(BLACK, "g8");
Tile h1(BLACK, "h1"), h2(WHITE, "h2"), h3(BLACK, "h3"), h4(WHITE, "h4"), h5(BLACK, "h5"), h6(WHITE, "h6"), h7(BLACK, "h7"), h8(WHITE, "h8");

// Create a 2D array for easy reference
Tile *board[8][8] = {
    {&a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8},
    {&b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8},
    {&c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8},
    {&d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8},
    {&e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8},
    {&f1, &f2, &f3, &f4, &f5, &f6, &f7, &f8},
    {&g1, &g2, &g3, &g4, &g5, &g6, &g7, &g8},
    {&h1, &h2, &h3, &h4, &h5, &h6, &h7, &h8}};

void draw_board()
{
    // draw board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            DrawRectangle(pos[i * 8 + j][0], pos[i * 8 + j][1], 100, 75, board[i][j]->get_color());
        }
    }
}

void Set_pos_and_direction()
{
    // up , down, left , right, upleft, upright, downleft ,downright are arguments
    a1.set_directions(&a2, nullptr, nullptr, &b1, nullptr, &b2, nullptr, nullptr);
    a2.set_directions(&a3, &a1, nullptr, &b2, nullptr, &b3, nullptr, &b1);
    a3.set_directions(&a4, &a2, nullptr, &b3, nullptr, &b4, nullptr, &b2);
    a4.set_directions(&a5, &a3, nullptr, &b4, nullptr, &b5, nullptr, &b3);
    a5.set_directions(&a6, &a4, nullptr, &b5, nullptr, &b6, nullptr, &b4);
    a6.set_directions(&a7, &a5, nullptr, &b6, nullptr, &b7, nullptr, &b5);
    a7.set_directions(&a8, &a6, nullptr, &b7, nullptr, &b8, nullptr, &b6);
    a8.set_directions(nullptr, &a7, nullptr, &b8, nullptr, nullptr, nullptr, &b7);
    b1.set_directions(&b2, nullptr, &a1, &c1, &a2, &c2, nullptr, nullptr);
    b2.set_directions(&b3, &b1, &a2, &c2, &a3, &c3, &a1, &c1);
    b3.set_directions(&b4, &b2, &a3, &c3, &a4, &c4, &a2, &c2);
    b4.set_directions(&b5, &b3, &a4, &c4, &a5, &c5, &a3, &c3);
    b5.set_directions(&b6, &b4, &a5, &c5, &a6, &c6, &a4, &c4);
    b6.set_directions(&b7, &b5, &a6, &c6, &a7, &c7, &a5, &c5);
    b7.set_directions(&b8, &b6, &a7, &c7, &a8, &c8, &a6, &c6);
    b8.set_directions(nullptr, &b7, &a8, &c8, nullptr, nullptr, &a7, &c7);
    c1.set_directions(&c2, nullptr, &b1, &d1, &b2, &d2, nullptr, nullptr);
    c2.set_directions(&c3, &c1, &b2, &d2, &b3, &d3, &b1, &d1);
    c3.set_directions(&c4, &c2, &b3, &d3, &b4, &d4, &b2, &d2);
    c4.set_directions(&c5, &c3, &b4, &d4, &b5, &d5, &b3, &d3);
    c5.set_directions(&c6, &c4, &b5, &d5, &b6, &d6, &b4, &d4);
    c6.set_directions(&c7, &c5, &b6, &d6, &b7, &d7, &b5, &d5);
    c7.set_directions(&c8, &c6, &b7, &d7, &b8, &d8, &b6, &d6);
    c8.set_directions(nullptr, &c7, &b8, &d8, nullptr, nullptr, &b7, &d7);
    d1.set_directions(&d2, nullptr, &c1, &e1, &c2, &e2, nullptr, nullptr);
    d2.set_directions(&d3, &d1, &c2, &e2, &c3, &e3, &c1, &e1);
    d3.set_directions(&d4, &d2, &c3, &e3, &c4, &e4, &c2, &e2);
    d4.set_directions(&d5, &d3, &c4, &e4, &c5, &e5, &c3, &e3);
    d5.set_directions(&d6, &d4, &c5, &e5, &c6, &e6, &c4, &e4);
    d6.set_directions(&d7, &d5, &c6, &e6, &c7, &e7, &c5, &e5);
    d7.set_directions(&d8, &d6, &c7, &e7, &c8, &e8, &c6, &e6);
    d8.set_directions(nullptr, &d7, &c8, &e8, nullptr, nullptr, &c7, &e7);
    e1.set_directions(&e2, nullptr, &d1, &f1, &d2, &f2, nullptr, nullptr);
    e2.set_directions(&e3, &e1, &d2, &f2, &d3, &f3, &d1, &f1);
    e3.set_directions(&e4, &e2, &d3, &f3, &d4, &f4, &d2, &f2);
    e4.set_directions(&e5, &e3, &d4, &f4, &d5, &f5, &d3, &f3);
    e5.set_directions(&e6, &e4, &d5, &f5, &d6, &f6, &d4, &f4);
    e6.set_directions(&e7, &e5, &d6, &f6, &d7, &f7, &d5, &f5);
    e7.set_directions(&e8, &e6, &d7, &f7, &d8, &f8, &d6, &f6);
    e8.set_directions(nullptr, &e7, &d8, &f8, nullptr, nullptr, &d7, &f7);
    f1.set_directions(&f2, nullptr, &e1, &g1, &e2, &g2, nullptr, nullptr);
    f2.set_directions(&f3, &f1, &e2, &g2, &e3, &g3, &e1, &g1);
    f3.set_directions(&f4, &f2, &e3, &g3, &e4, &g4, &e2, &g2);
    f4.set_directions(&f5, &f3, &e4, &g4, &e5, &g5, &e3, &g3);
    f5.set_directions(&f6, &f4, &e5, &g5, &e6, &g6, &e4, &g4);
    f6.set_directions(&f7, &f5, &e6, &g6, &e7, &g7, &e5, &g5);
    f7.set_directions(&f8, &f6, &e7, &g7, &e8, &g8, &e6, &g6);
    f8.set_directions(nullptr, &f7, &e8, &g8, nullptr, nullptr, &e7, &g7);
    g1.set_directions(&g2, nullptr, &f1, &h1, &f2, &h2, nullptr, nullptr);
    g2.set_directions(&g3, &g1, &f2, &h2, &f3, &h3, &f1, &h1);
    g3.set_directions(&g4, &g2, &f3, &h3, &f4, &h4, &f2, &h2);
    g4.set_directions(&g5, &g3, &f4, &h4, &f5, &h5, &f3, &h3);
    g5.set_directions(&g6, &g4, &f5, &h5, &f6, &h6, &f4, &h4);
    g6.set_directions(&g7, &g5, &f6, &h6, &f7, &h7, &f5, &h5);
    g7.set_directions(&g8, &g6, &f7, &h7, &f8, &h8, &f6, &h6);
    g8.set_directions(nullptr, &g7, &f8, &h8, nullptr, nullptr, &f7, &h7);
    h1.set_directions(&h2, nullptr, &g1, nullptr, &g2, nullptr, nullptr, nullptr);
    h2.set_directions(&h3, &h1, &g2, nullptr, &g3, nullptr, &g1, nullptr);
    h3.set_directions(&h4, &h2, &g3, nullptr, &g4, nullptr, &g2, nullptr);
    h4.set_directions(&h5, &h3, &g4, nullptr, &g5, nullptr, &g3, nullptr);
    h5.set_directions(&h6, &h4, &g5, nullptr, &g6, nullptr, &g4, nullptr);
    h6.set_directions(&h7, &h5, &g6, nullptr, &g7, nullptr, &g5, nullptr);
    h7.set_directions(&h8, &h6, &g7, nullptr, &g8, nullptr, &g6, nullptr);
    h8.set_directions(nullptr, &h7, &g8, nullptr, nullptr, nullptr, &g7, nullptr);

    // total number of pointers = 64 * 8 = 512 , memory allocation = 512 * 8 = 4096 bytes -> 4KB

    // positions
    a1.set_position({0, 525});
    a2.set_position({0, 450});
    a3.set_position({0, 375});
    a4.set_position({0, 300});
    a5.set_position({0, 225});
    a6.set_position({0, 150});
    a7.set_position({0, 75});
    a8.set_position({0, 0});
    b1.set_position({100, 525});
    b2.set_position({100, 450});
    b3.set_position({100, 375});
    b4.set_position({100, 300});
    b5.set_position({100, 225});
    b6.set_position({100, 150});
    b7.set_position({100, 75});
    b8.set_position({100, 0});
    c1.set_position({200, 525});
    c2.set_position({200, 450});
    c3.set_position({200, 375});
    c4.set_position({200, 300});
    c5.set_position({200, 225});
    c6.set_position({200, 150});
    c7.set_position({200, 75});
    c8.set_position({200, 0});
    d1.set_position({300, 525});
    d2.set_position({300, 450});
    d3.set_position({300, 375});
    d4.set_position({300, 300});
    d5.set_position({300, 225});
    d6.set_position({300, 150});
    d7.set_position({300, 75});
    d8.set_position({300, 0});
    e1.set_position({400, 525});
    e2.set_position({400, 450});
    e3.set_position({400, 375});
    e4.set_position({400, 300});
    e5.set_position({400, 225});
    e6.set_position({400, 150});
    e7.set_position({400, 75});
    e8.set_position({400, 0});
    f1.set_position({500, 525});
    f2.set_position({500, 450});
    f3.set_position({500, 375});
    f4.set_position({500, 300});
    f5.set_position({500, 225});
    f6.set_position({500, 150});
    f7.set_position({500, 75});
    f8.set_position({500, 0});
    g1.set_position({600, 525});
    g2.set_position({600, 450});
    g3.set_position({600, 375});
    g4.set_position({600, 300});
    g5.set_position({600, 225});
    g6.set_position({600, 150});
    g7.set_position({600, 75});
    g8.set_position({600, 0});
    h1.set_position({700, 525});
    h2.set_position({700, 450});
    h3.set_position({700, 375});
    h4.set_position({700, 300});
    h5.set_position({700, 225});
    h6.set_position({700, 150});
    h7.set_position({700, 75});
    h8.set_position({700, 0});
    // total memory allocation = 4KB + 4KB = 8KB
}

// main function

int main()
{

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    Set_pos_and_direction();

    InitWindow(screenWidth, screenHeight, "chess");
    SetTargetFPS(60);

    
    knight bKnightright;
    bKnightright.current_tile = &g8;
    bKnightright.lod_knight_texture();
    knight bRookright;
    bRookright.current_tile = &h8;
    bRookright.lod_knight_texture();
    knight bBishopright;
    bBishopright.current_tile = &f8;
    bBishopright.lod_knight_texture();
    knight bQueenright;
    bQueenright.current_tile = &d8;
    bQueenright.lod_knight_texture();
    knight bKingright;
    bKingright.current_tile = &e8;
    bKingright.lod_knight_texture();
    knight bBishopleft;
    bBishopleft.current_tile = &c8;
    bBishopleft.lod_knight_texture();
    knight bRookleft;
    bRookleft.current_tile = &a8;
    bRookleft.lod_knight_texture();
    knight bKnightleft;
    bKnightleft.current_tile = &b8;
    bKnightleft.lod_knight_texture();


    //black pawns
    knight bPawn;
    bPawn.current_tile = &b7;
    bPawn.lod_knight_texture();
    knight bPawn2;
    bPawn2.current_tile = &a7;
    bPawn2.lod_knight_texture();
    knight bPawn3;
    bPawn3.current_tile = &c7;
    bPawn3.lod_knight_texture();
    knight bPawn4;
    bPawn4.current_tile = &d7;
    bPawn4.lod_knight_texture();
    knight bPawn5;
    bPawn5.current_tile = &e7;
    bPawn5.lod_knight_texture();
    knight bPawn6;
    bPawn6.current_tile = &f7;
    bPawn6.lod_knight_texture();
    knight bPawn7;
    bPawn7.current_tile = &g7;
    bPawn7.lod_knight_texture();
    knight bPawn8;
    bPawn8.current_tile = &h7;
    bPawn8.lod_knight_texture();


    // white pieces
    knight wRookright;
    wRookright.current_tile = &h1;
    wRookright.lod_knight_texture();
    knight wKnightright;
    wKnightright.current_tile = &g1;
    wKnightright.lod_knight_texture();
    knight wBishopright;
    wBishopright.current_tile = &f1;
    wBishopright.lod_knight_texture();
    knight wQueenright;
    wQueenright.current_tile = &e1;
    wQueenright.lod_knight_texture();
    knight wKingright;
    wKingright.current_tile = &d1;
    wKingright.lod_knight_texture();
    knight wBishopleft;
    wBishopleft.current_tile = &c1;
    wBishopleft.lod_knight_texture();
    knight wRookleft;
    wRookleft.current_tile = &a1;
    wRookleft.lod_knight_texture();
    knight wKnightleft;
    wKnightleft.current_tile = &b1;
    wKnightleft.lod_knight_texture();

    //white pawns
    knight wpawn;
    wpawn.current_tile = &a2;
    wpawn.lod_knight_texture();
    knight wpawn2;
    wpawn2.current_tile = &b2;
    wpawn2.lod_knight_texture();
    knight wpawn3;
    wpawn3.current_tile = &c2;
    wpawn3.lod_knight_texture();
    knight wpawn4;
    wpawn4.current_tile = &d2;
    wpawn4.lod_knight_texture();
    knight wpawn5;
    wpawn5.current_tile = &e2;
    wpawn5.lod_knight_texture();
    knight wpawn6;
    wpawn6.current_tile = &f2;
    wpawn6.lod_knight_texture();
    knight wpawn7;
    wpawn7.current_tile = &g2;
    wpawn7.lod_knight_texture();
    knight wpawn8;
    wpawn8.current_tile = &h2;
    wpawn8.lod_knight_texture();




    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(PURPLE);

        draw_board();
        //black draw
        bKnightright.draw_knight_black();
        bRookright.draw_rook_black();
        bBishopright.draw_bishop_black();
        bQueenright.draw_queen_black();
        bKingright.draw_king_black();
        bBishopleft.draw_bishop_black();
        bRookleft.draw_rook_black();
        bKnightleft.draw_knight_black();
        bPawn.draw_pawn_black();
        bPawn2.draw_pawn_black();
        bPawn3.draw_pawn_black();
        bPawn4.draw_pawn_black();
        bPawn5.draw_pawn_black();
        bPawn6.draw_pawn_black();
        bPawn7.draw_pawn_black();
        bPawn8.draw_pawn_black();

        
        //white draw
        wRookright.draw_rook_white();
        wKnightright.draw_knight_white();
        wBishopright.draw_bishop_white();
        wQueenright.draw_queen_white();
        wKingright.draw_king_white();
        wBishopleft.draw_bishop_white();
        wRookleft.draw_rook_white();
        wKnightleft.draw_knight_white();
        wpawn.draw_pawn_white();
        wpawn2.draw_pawn_white();
        wpawn3.draw_pawn_white();
        wpawn4.draw_pawn_white();
        wpawn5.draw_pawn_white();
        wpawn6.draw_pawn_white();
        wpawn7.draw_pawn_white();
        wpawn8.draw_pawn_white();


        //experiments
        

        

        EndDrawing();
    }

    CloseWindow();
    return 0;
}