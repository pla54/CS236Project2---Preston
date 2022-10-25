//
// Created by 54pla on 10/16/2022.
//

#include "Parser.h"
#include "Token.h"

Parser::Parser() = default;

Parser::~Parser() = default;

void Parser::Parse(std::vector<std::string> listOfTokens) {
   // std::string test = "";
    //test = listOfTokens[1];

    //std::cout << test << std::endl;

    currentLine = 0;

    if(listOfTokens[currentLine].substr(0,18) == "(SCHEMES,\"Schemes\""){
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
    if(listOfTokens[currentLine].substr(0,10) == "(COLON,\":\""){
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
    Scheme(listOfTokens);
    SchemeList(listOfTokens);
    if(listOfTokens[currentLine].substr(0,14) == "(FACTS,\"Facts\"") {
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
    if(listOfTokens[currentLine].substr(0,10) == "(COLON,\":\""){
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
    FactList(listOfTokens);
    if(listOfTokens[currentLine].substr(0,14) == "(RULES,\"Rules\""){
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
    if(listOfTokens[currentLine].substr(0,10) == "(COLON,\":\""){
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
    RuleList(listOfTokens);
    if(listOfTokens[currentLine].substr(0,18) == "(QUERIES,\"Queries\""){
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
    if(listOfTokens[currentLine].substr(0,10) == "(COLON,\":\""){
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
    Query(listOfTokens);
    QueryList(listOfTokens);
    if(listOfTokens[currentLine].substr(0,7) == "(EOF,\"\""){
        currentLine++;
    } else{
        throw (Failure(listOfTokens[currentLine]));
    }

}

void Parser::SchemeList(const std::vector<std::string>& listOfTokens) {
    if(listOfTokens[currentLine].substr(0,3) == "(ID"){
        Scheme(listOfTokens);
        SchemeList(listOfTokens);
    }else {
        return;
    }
}

void Parser::FactList(const std::vector<std::string>& listOfTokens) {
    if(listOfTokens[currentLine].substr(0,3) == "(ID"){
        Fact(listOfTokens);
        FactList(listOfTokens);
    }
    else{
        return;
    }
}

void Parser::RuleList(const std::vector<std::string>& listOfTokens){
    if(listOfTokens[currentLine].substr(0,3) == "(ID"){
        ParseRule(listOfTokens);
        RuleList(listOfTokens);
    }else{
        return;
    }
}

void Parser::StringList(const std::vector<std::string>& listOfTokens, Predicate* fact) {
    if(listOfTokens[currentLine].substr(0,10) == "(COMMA,\",\"") {
        currentLine++;

        if(listOfTokens[currentLine].substr(0,7) == "(STRING"){
            fact->addParameter(switchChar(listOfTokens[currentLine], '\"'));

            domainList.insert(switchChar(listOfTokens[currentLine],'\"'));

            currentLine++;

            StringList(listOfTokens, fact);
        } else {
            throw (Failure(listOfTokens[currentLine]));
        }
    } else {
        return;
    }
}

void Parser::QueryList(const std::vector<std::string>& listOfTokens){
    if(listOfTokens[currentLine].substr(0,3) == "(ID"){
        Query(listOfTokens);
        QueryList(listOfTokens);
    }else{
        return;
    }
}

void Parser::IDList(const std::vector<std::string> &listOfTokens, Predicate* givenPredicate) {

    if(listOfTokens[currentLine].substr(0,10) == "(COMMA,\",\"") {
        currentLine++;
    } else {
        return;
    }

    if(listOfTokens[currentLine].substr(0,3) == "(ID") {
        givenPredicate->addParameter(switchChar(listOfTokens[currentLine],'\"'));

        currentLine++;
        IDList(listOfTokens, givenPredicate);
    } else {
        throw (Failure(listOfTokens[currentLine]));
    }
}

void Parser::Scheme(const std::vector<std::string>& listOfTokens){
    Predicate newScheme;
    if(listOfTokens[currentLine].substr(0,3) == "(ID") {
        currentLine++;
        newScheme.addID(switchChar(listOfTokens[currentLine - 1],'\"'));
    }else{
        throw (Failure(listOfTokens[currentLine]));
    }
    if(listOfTokens[currentLine].substr(0,15) == "(LEFT_PAREN,\"(\""){
        currentLine++;
    }else{
        throw (Failure(listOfTokens[currentLine]));
    }
    if(listOfTokens[currentLine].substr(0,3) == "(ID"){
        newScheme.addParameter(switchChar(listOfTokens[currentLine],'\"'));
        //TODO Make new scheme
        currentLine++;
        IDList(listOfTokens, &newScheme);
        //TODO ID LIST
    }else{
        throw (Failure(listOfTokens[currentLine]));
    }
    if(listOfTokens[currentLine].substr(0,16) == "(RIGHT_PAREN,\")\""){
        currentLine++;
        //TODO add new scheme to vector
        schemesList.push_back(newScheme);
        return;
    }else{
        throw (Failure(listOfTokens[currentLine]));
    }
}

void Parser::Fact(const std::vector<std::string>& listOfTokens){
    //TODO PREDICATE NEW FACT
    Predicate newFact;
    if (listOfTokens[currentLine].substr(0,3) == "(ID") {
        newFact.addID(switchChar(listOfTokens[currentLine],'\"'));
        //TODO Make new ID
        currentLine++;
    }else{
        throw (Failure(listOfTokens[currentLine]));
    }

    if(listOfTokens[currentLine].substr(0,15) == "(LEFT_PAREN,\"(\""){
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }

    if(listOfTokens[currentLine].substr(0,7) == "(STRING"){
        newFact.addParameter(switchChar(listOfTokens[currentLine],'\"'));
        domainList.insert(switchChar(listOfTokens[currentLine],'\"'));
        currentLine++;
        StringList(listOfTokens, &newFact);
    }else{
        throw (Failure(listOfTokens[currentLine]));
    }
    if(listOfTokens[currentLine].substr(0,16) == "(RIGHT_PAREN,\")\""){
        currentLine++;
    }else{
        throw (Failure(listOfTokens[currentLine]));
    }

    if(listOfTokens[currentLine].substr(0,11) == "(PERIOD,\".\""){
        currentLine++;
        //TODO PUSHBACK FACT
        factsList.push_back(newFact);
        return;
    }
    else {
        throw (Failure(listOfTokens[currentLine]));
    }
}

void Parser::ParseRule(const std::vector<std::string>& listOfTokens){
    //TODO NEW RULE
    Rule newRule;
    //TODO HEAD PREDICATE
    HeadPredicate(listOfTokens, &newRule);
    if(listOfTokens[currentLine].substr(0,11) == "(COLON_DASH"){
        currentLine++;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
    //TODO PREDICATE
    ParsePredicate(listOfTokens, &newRule);
    PredicateList(listOfTokens, &newRule);
    if(listOfTokens[currentLine].substr(0,11) == "(PERIOD,\".\""){
        currentLine++;
        rulesList.push_back(newRule);
        //TODO PUSHBACK RULE
        return;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
}

void Parser::Query(const std::vector<std::string>& listOfTokens){
    //TODO rule
    //TODO Predicate
    Rule testRule;
    ParsePredicate(listOfTokens, &testRule);
    if(listOfTokens[currentLine].substr(0,11) == "(Q_MARK,\"?\""){
        //TODO PUSH BACK QUERY
        queriesList.push_back(testRule.getPredicate(0));
        currentLine++;
        return;
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }
}

void Parser::Parameter(const std::vector<std::string>& listOfTokens, Predicate* givenPredicate){

    if(listOfTokens[currentLine].substr(0,3) == "(ID") {
        givenPredicate->addParameter(switchChar(listOfTokens[currentLine],'\"'));
        currentLine++;
        return;
    }
    else if(listOfTokens[currentLine].substr(0,7) == "(STRING") {
        givenPredicate->addParameter(switchChar(listOfTokens[currentLine],'\"'));
        currentLine++;
        return;
    }
    else {
        throw (Failure(listOfTokens[currentLine]));
    }
}

void Parser::HeadPredicate(const std::vector<std::string> &listOfTokens, Rule *givenRule) {
    Predicate newHeadPredicate;
    if(listOfTokens[currentLine].substr(0,3) == "(ID") {
        newHeadPredicate.addID(switchChar(listOfTokens[currentLine],'\"'));
        currentLine++;
    } else {
        throw (Failure(listOfTokens[currentLine]));
    }

    if(listOfTokens[currentLine].substr(0,15) == "(LEFT_PAREN,\"(\"") {
        currentLine++;
    } else {
        throw (Failure(listOfTokens[currentLine]));
    }

    if(listOfTokens[currentLine].substr(0,3) == "(ID") {
        currentLine++;
        newHeadPredicate.addParameter(switchChar(listOfTokens[currentLine-1],'\"'));
        IDList(listOfTokens, &newHeadPredicate);
    }
    else{
        throw (Failure(listOfTokens[currentLine]));
    }

    if(listOfTokens[currentLine].substr(0,16) == "(RIGHT_PAREN,\")\"") {
        currentLine++;
        givenRule->addHeadPredicate(newHeadPredicate);
        return;
    }
    else {
        throw (Failure(listOfTokens[currentLine]));
    }
}

void Parser::PredicateList(const std::vector<std::string> &listOfTokens, Rule* givenRule) {
    if(listOfTokens[currentLine].substr(0,10) == "(COMMA,\",\"") {
        currentLine++;
        ParsePredicate(listOfTokens, givenRule);
        PredicateList(listOfTokens, givenRule);
    }
    else {
        return;
    }

}

void Parser::ParsePredicate(const std::vector<std::string>& listOfTokens, Rule* givenRule){
    Predicate newPredicate;
    if(listOfTokens[currentLine].substr(0,3) == "(ID") {
        newPredicate.addID(switchChar(listOfTokens[currentLine], '\"'));
        currentLine++;
    } else {
        throw (Failure(listOfTokens[currentLine]));
    }

    if(listOfTokens[currentLine].substr(0,15) == "(LEFT_PAREN,\"(\"") {
        currentLine++;
    } else {
        throw (Failure(listOfTokens[currentLine]));
    }

    Parameter(listOfTokens, &newPredicate);
    ParameterList(listOfTokens, &newPredicate);

    if(listOfTokens[currentLine].substr(0,16) == "(RIGHT_PAREN,\")\"") {
        currentLine++;
        givenRule->addPredicate(newPredicate);
        return;
    }
    else {
        throw (Failure(listOfTokens[currentLine]));
    }
}

void Parser::ParameterList(const std::vector<std::string>& listOfTokens, Predicate* givenPredicate){
    if(listOfTokens[currentLine].substr(0,10) == "(COMMA,\",\"") {
        currentLine++;
        Parameter(listOfTokens, givenPredicate);
        ParameterList(listOfTokens, givenPredicate);
    }
    else {
        return;
    }
}

std::string Parser::toString()
{
    std::string final;
    final = "Success!\n";

    final += "Schemes(" + std::to_string(schemesList.size()) + "):\n";

    for (unsigned int i = 0; i < schemesList.size(); i++)
    {
        final += "  " + schemesList[i].toString() + "\n";
    }

    final += "Facts(" + std::to_string(factsList.size()) + "):\n";

    for (unsigned int i = 0; i < factsList.size(); i++)
    {
        final += "  " + factsList[i].toString() + ".\n";
    }

    final += "Rules(" + std::to_string(rulesList.size()) + "):\n";

    for (unsigned int i = 0; i < rulesList.size(); i++)
    {
        final += "  " + rulesList[i].toString() + ".\n";
    }

    final += "Queries(" + std::to_string(queriesList.size()) + "):\n";

    for (unsigned int i = 0; i < queriesList.size(); i++)
    {
        final += "  " + queriesList[i].toString() + "?\n";
    }

    if(domainList.size() > 0)
    {
        final += "Domain(" + std::to_string(domainList.size()) + "):\n";

        for (auto it = domainList.begin(); it != --domainList.end(); ++it) {
            final += "  " + *it + "\n";
        }

        final += "  " + *--domainList.end();

    }
    else{
        final += "Domain(" + std::to_string(domainList.size()) + "):";
    }
    return final;
}

std::string Parser::switchChar(std::string givenString, char split)
{
    std::string final;
    bool switchTest = false;
    for (unsigned int i = 0; i< givenString.length(); i++)
    {
        if (givenString[i] == split && !switchTest)
        {
            switchTest = true;
        }

        else if (givenString[i] == split && switchTest)
        {
            switchTest = false;
        }

        else if (switchTest)
        {
            final += givenString[i];
        }
    }
    return final;
}

/*
bool Parser::Match(Token* p1, TokenType type){
    if(p1->getType() == type){
        return true;
    }
   // else{
        //throw p1->getType();
  //  }
  return false;
}
*/

