cmake_minimum_required(VERSION 3.23)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1_Starter_Code
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h CommaAutomaton.cpp CommaAutomaton.h PeriodAutomaton.cpp PeriodAutomaton.h QuestionMarkAutomaton.cpp QuestionMarkAutomaton.h LeftParenAutomaton.cpp LeftParenAutomaton.h RightParenAutomaton.cpp RightParenAutomaton.h MultiplyAutomaton.cpp MultiplyAutomaton.h AddAutomaton.cpp AddAutomaton.h FactsAutomaton.cpp FactsAutomaton.h RulesAutomaton.cpp RulesAutomaton.h QueriesAutomaton.cpp QueriesAutomaton.h CommentAutomaton.cpp CommentAutomaton.h SchemesAutomaton.cpp SchemesAutomaton.h IdAutomata.cpp IdAutomata.h MultiLineCommentAutomaton.cpp MultiLineCommentAutomaton.h StringAutomaton.cpp StringAutomaton.h DatalogProgram.cpp DatalogProgram.h Rule.cpp Rule.h Parameter.cpp Parameter.h Predicate.cpp Predicate.h Parser.cpp Parser.h)
