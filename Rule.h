//
// Created by 54pla on 10/16/2022.
//

#ifndef PROJECT1_STARTER_CODE_RULE_H
#define PROJECT1_STARTER_CODE_RULE_H
#include "Predicate.h"
#include <vector>
#include <string>


class Rule {
public:
    Rule() {};
    Rule(Predicate headPredicate, std::vector<Predicate> listOfPredicates){
        this->headPredicate = headPredicate;
        this->listOfPredicates = listOfPredicates;
    };
    ~Rule() {};
    std::string toString();

    void addPredicate(Predicate predicate){
        listOfPredicates.push_back(predicate);
    }

    void addHeadPredicate(Predicate givenHeadPredicate){
        headPredicate = givenHeadPredicate;
    }

    Predicate getPredicate(int index){
        return listOfPredicates.at(index);
    }
private:
    Predicate headPredicate;
    std::vector<Predicate> listOfPredicates;
};


#endif //PROJECT1_STARTER_CODE_RULE_H
