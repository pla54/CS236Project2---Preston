#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "AddAutomaton.h"
#include "CommaAutomaton.h"
#include "CommentAutomaton.h"
#include "FactsAutomaton.h"
#include "IdAutomata.h"
#include "LeftParenAutomaton.h"
#include "MultiLineCommentAutomaton.h"
#include "MultiplyAutomaton.h"
#include "PeriodAutomaton.h"
#include "QueriesAutomaton.h"
#include "QuestionMarkAutomaton.h"
#include "RightParenAutomaton.h"
#include "RulesAutomaton.h"
#include "SchemesAutomaton.h"
#include "StringAutomaton.h"


Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for(unsigned int i = 0; i < tokens.size(); i++){
        delete tokens[i];
    }
    // TODO: need to clean up the memory in `automata` and `tokens`
}

/*
void Lexer::EraseTokens(){
    for(unsigned int i = 0; i < tokens.size(); i++){
        delete tokens[i];
    }
}
*/
void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new MultiLineCommentAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new QuestionMarkAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new IdAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    lineNumber = 1;

    while (input.size() > 0) {
        //std::cout << "dalooper" << input.size() << input[0] << "should have a space first" << std::endl;
        maxRead = 0;
        maxAutomaton = 0;
        while(input[0] == ' ' || input[0] == '\t' || input[0] == '\n') {
            if(input[0] == '\n') {
                lineNumber++;
                input.erase(0,1);
            }
            else {
                input.erase(0,1);
            }
        }

        for (unsigned int i = 0; i < automata.size(); i++) {
            int inputRead = 0;
            //std::cout<<input.size() << std::endl;
            inputRead = automata[i]->Start(input);

            if(inputRead == -1){
                maxRead = -1;
                break;
            }
            else if(inputRead == -2){
                maxRead = -2;
                break;
            }
            else if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = i;
            }

        }
        if(maxRead == -1){
            tokens.push_back(new Token(TokenType::UNDEFINED, input, lineNumber));
            lineNumber += automata[7]->NewLinesRead();
            maxRead = 0;
            input = "";
            break;
        }
        else if (maxRead == -2){
            tokens.push_back(new Token(TokenType::UNDEFINED, input, lineNumber));
            lineNumber += automata[15]->NewLinesRead();
            maxRead = 0;
            input = "";
            break;
        }
        else if (maxRead > 0) {
            tokens.push_back(new Token(automata[maxAutomaton]->getType(), input.substr(0, maxRead),lineNumber));
            lineNumber += automata[maxAutomaton]->NewLinesRead();
            input.erase(0,maxRead);
            maxRead = 0;
        }
        else if(input == "" || input == " " || input == "\n"){
            break;
        }
        else {
            if(input.substr(0,1) != " " || input[0] == '\t' ){
                tokens.push_back(new Token(TokenType::UNDEFINED, input.substr(0,1),lineNumber));
                input.erase(0,1);
            }
        }
    }
    tokens.push_back(new Token(TokenType::Eof,"", lineNumber));
}

std::vector<std::string> Lexer::Print(){
    std::string outPut = "";
    std::vector<std::string> final;
    for(unsigned int i = 0; i < tokens.size(); i++){
        if(tokens[i]->getType() == TokenType::UNDEFINED){
            outPut = ("(UNDEFINED,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }
        else if(tokens[i]->getType() == TokenType::Eof){
            outPut = ("(EOF,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")");
            final.push_back(outPut);
            break;
        }
        else if(tokens[i]->getType() == TokenType::ADD){
            outPut = ("(ADD,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }
        else if(tokens[i]->getType() == TokenType::SCHEMES){
            outPut = ("(SCHEMES,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }
        else if(tokens[i]->getType() == TokenType::COLON){
            outPut = ("(COLON,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::COLON_DASH){
            outPut += ("(COLON_DASH,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::COMMA){
            outPut = ("(COMMA,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::COMMENT){
          //  outPut = ("(COMMENT,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
          //  final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::FACTS){
            outPut = ("(FACTS,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::ID){
            outPut = ("(ID,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::LEFT_PAREN){
            outPut = ("(LEFT_PAREN,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::MULTIPLY){
            outPut = ("(MULTIPLY,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::PERIOD){
            outPut = ("(PERIOD,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::QUERIES){
            outPut = ("(QUERIES,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::Q_MARK){
            outPut = ("(Q_MARK,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }
        else if(tokens[i]->getType() == TokenType::RIGHT_PAREN){
            outPut = ("(RIGHT_PAREN,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::RULES){
            outPut = ("(RULES,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }

        else if(tokens[i]->getType() == TokenType::STRING){
            outPut = ("(STRING,\"" + tokens[i]->getDescription() + "\"," + std::to_string(tokens[i]->getLine()) + ")\n");
            final.push_back(outPut);
            break;
        }
    }
 //   outPut = ("\nTotal Tokens = " + std::to_string(tokens.size()));
//    final.push_back(outPut);

    return final;
}

std::vector<Token*> Lexer::reLex(){

    return tokens;
}
