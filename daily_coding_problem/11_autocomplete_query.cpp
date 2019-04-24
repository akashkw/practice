#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include "gtest/gtest.h"

using namespace std;

/*
 * Problem Statement
 * 
 * This problem was asked by Twitter.
 * 
 * Implement an autocomplete system. 
 * That is, given a query string s and a set of all possible query strings, 
 * return all strings in the set that have s as a prefix.
 * 
 * For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].
 * 
 * Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
 */

struct trie_node {
    unordered_map<char, trie_node*> _chars;
    trie_node() : _chars() {}
    void add_string(const string &str) {
        char front = str[0];
        if(_chars.find(front) == _chars.end())
            _chars[front] = new trie_node;
        if(str.size() > 1)
            _chars[front]->add_string(str.substr(1, str.size()-1));
    }
    vector<string> return_all_strings_below() {
        if(_chars.empty())
            return {""};
        vector<string> strings;
        for(pair<char, trie_node*> p : _chars) {
            vector<string> sub_strings = p.second->return_all_strings_below();
            for(const string &str : sub_strings) {
                strings.push_back(p.first + str);
            }
        }
        return strings;
    }
    ~trie_node() {
        for_each(begin(_chars), end(_chars), [](pair<char, trie_node*> p) {delete p.second;});
    }
};

// Solution Function
vector<string> autocomplete(const string &query, const vector<string> &dict) {
    trie_node* root = new trie_node;
    for(const string &str : dict) {
        root->add_string(str);
    }
    trie_node* current = root;
    for(const char &c : query) {
        current = current->_chars[c];
    }
    vector<string> remainders = current->return_all_strings_below();
    delete root;
    for_each(begin(remainders), end(remainders), [&query] (string &str) {str = query + str;});
    sort(begin(remainders), end(remainders));
    return remainders;
}

TEST(SolutionFixture, test_1) {
    vector<string> dict = {"dog", "deer", "deal"};
    vector<string> sol = autocomplete("de", dict);
    ASSERT_EQ(sol, vector<string>({"deal", "deer"}));
}

TEST(SolutionFixture, test_2) {
    vector<string> dict = {"the", "quick", "brown", "fox"};
    vector<string> sol = autocomplete("b", dict);
    ASSERT_EQ(sol, vector<string>({"brown"}));
}

TEST(SolutionFixture, test_3) {
    vector<string> dict = {"akash", "andrew", "avery", "aaron", "jaxon", "sue anne"};
    vector<string> sol = autocomplete("a", dict);
    ASSERT_EQ(sol, vector<string>({"aaron", "akash", "andrew", "avery"}));
}

TEST(SolutionFixture, test_4) {
    vector<string> dict = {"akash", "andrew", "avery", "aaron", "jaxon", "sue anne"};
    vector<string> sol = autocomplete("s", dict);
    ASSERT_EQ(sol, vector<string>({"sue anne"}));
}

TEST(SolutionFixture, test_5) {
    vector<string> dict = {"maroon 5", "macklemore", "metallica"};
    vector<string> sol = autocomplete("ma", dict);
    ASSERT_EQ(sol, vector<string>({"macklemore", "maroon 5"}));
}
