//
// Created by 54pla on 10/16/2022.
//

#ifndef PROJECT1_STARTER_CODE_PARSER_H
#define PROJECT1_STARTER_CODE_PARSER_H

#include<iostream>
#include<string>
#include<vector>
#include<set>
#include "Token.h"
#include "Predicate.h"
#include "Rule.h"

class Parser {
public:
    void Parse(std::vector<std::string> listOfTokens);
    Parser();
    ~Parser();
    std::string toString();

private:
    void SchemeList(const std::vector<std::string>& listOfTokens);
    void Scheme(const std::vector<std::string>& listOfTokens);
    void FactList(const std::vector<std::string>& listOfTokens);
    void Fact(const std::vector<std::string>& listOfTokens);
    void IDList(const std::vector<std::string>& listOfTokens, Predicate* givenPredicate);
    void StringList(const std::vector<std::string>& listOfTokens, Predicate* fact);
    void RuleList(const std::vector<std::string>& listOfTokens);
    void ParseRule(const std::vector<std::string>& listOfTokens);
    std::string Failure(const std::string failed){return "Failure!\n  " + failed.substr(0,failed.length()-1);};
    void HeadPredicate(const std::vector<std::string>& listOfTokens, Rule* givenRule);
    void ParsePredicate(const std::vector<std::string>& listOfTokens, Rule* givenRule);
    void PredicateList(const std::vector<std::string>& listOfTokens, Rule* givenRule);
    void ParameterList(const std::vector<std::string>& listOfTokens, Predicate* givenPredicate);
    void Parameter(const std::vector<std::string>& listOfTokens, Predicate* givenPredicate);
    void QueryList(const std::vector<std::string>& listOfTokens);
    void Query(const std::vector<std::string>& listOfTokens);
    void DatalogProgram();
    bool Match(Token* p1, TokenType type);
    std::string switchChar(std::string givenString, char split);
    int currentLine = 0;
    std::vector<Predicate> schemesList;
    std::vector<Predicate> factsList;
    std::vector<Predicate> queriesList;
    std::vector<Rule> rulesList;
    std::set<std::string> domainList;
};


#endif //PROJECT1_STARTER_CODE_PARSER_H
