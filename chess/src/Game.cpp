#include "Game.hpp"
#include "Piece.hpp"
#include <iostream>

void Game::setPiece(int index, int piece)
{
    board[index] &= empty;
    board[index] |= piece;
}

void Game::movePiece(int from, int to)
{
    board[to] &= empty;
    board[to] |= board[from];
    board[from] &= empty;
}

bool Game::isValidMove(int from, int to)
{
    int fp = getPiece(from);
    int tp = getPiece(to);
    if ((fp >> 3) == (tp >> 3))
        return false;
    if ((fp & king) == king)
    {
        // top corners
        if ((from % 8 < 7 && int(from / 8) > 0 && to == from - 7) || (from % 8 > 0 && int(from / 8) > 0 && to == from - 9))
            return true;
        // bottom corners
        if ((from % 8 < 7 && int(from / 8) < 7 && to == from + 9) || (from % 8 > 0 && int(from / 8) < 7 && to == from + 7))
            return true;
        // horizontal
        if ((from % 8 < 7 && to == from + 1) || (from % 8 > 0 && to == from - 1))
            return true;
        // vertical
        if ((int(from / 8) < 7 && to == from + 8) || (int(from / 8) > 0 && to == from - 8))
            return true;
        // need to check for castling
        return false;
    }
    else if ((fp & queen) == queen)
    {
    }
    else if ((fp & bishop) == bishop)
    {
    }
    else if ((fp & knight) == knight)
    {
    }
    else if ((fp & rook) == rook)
    {
    }
    else if ((fp & pawn) == pawn)
    {
    }
    // std::cout << "shouldnt be here: isValidMove()";
    return true;
}

void Game::clearBoard()
{
    for (int i = 0; i < 64; i++)
    {
        board[i] = empty;
    }
}

void Game::newBoard()
{
    clearBoard();
    setPiece(0, black | rook);
    setPiece(1, black | knight);
    setPiece(2, black | bishop);
    setPiece(3, black | queen);
    setPiece(4, black | king);
    setPiece(5, black | bishop);
    setPiece(6, black | knight);
    setPiece(7, black | rook);
    setPiece(8, black | pawn);
    setPiece(9, black | pawn);
    setPiece(10, black | pawn);
    setPiece(11, black | pawn);
    setPiece(12, black | pawn);
    setPiece(13, black | pawn);
    setPiece(14, black | pawn);
    setPiece(15, black | pawn);
    setPiece(48, white | pawn);
    setPiece(49, white | pawn);
    setPiece(50, white | pawn);
    setPiece(51, white | pawn);
    setPiece(52, white | pawn);
    setPiece(53, white | pawn);
    setPiece(54, white | pawn);
    setPiece(55, white | pawn);
    setPiece(56, white | rook);
    setPiece(57, white | knight);
    setPiece(58, white | bishop);
    setPiece(59, white | queen);
    setPiece(60, white | king);
    setPiece(61, white | bishop);
    setPiece(62, white | knight);
    setPiece(63, white | rook);
}