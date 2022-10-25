#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;
    int maxAutomaton = 0;

    void CreateAutomata();
    int lineNumber = 0;
    int maxRead = 0;
    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);

    std::vector<std::string> Print();
    std::vector<Token*> reLex();
    // TODO: add other public methods here

};

#endif // LEXER_H

