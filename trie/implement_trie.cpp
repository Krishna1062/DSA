// https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d){
            data = d;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public: 
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root -> isTerminal = true;
            return ;
        }

        // Assuming the word is in caps
        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if(root -> children[index] != NULL){
            child = root->children[index];
        }
        else{ // absent
            child = new TrieNode(word[0]);
            root->children[index] = child; // update the children array with the new value at is index for ex x at index 23
        }

        // recursive call for reamining string 
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root -> isTerminal;
        }

        // Assumin word is in caps
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else {
            return false;
        }

        // recursive call for remaining word
        return searchUtil(child, word.substr(1));
    }
    

    bool searchWord(string word){
        return searchUtil(root, word);
    }

    void deleteUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        // Assuming word is in caps
        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            cout<<"word not found";
            return;
        }

        deleteUtil(child, word.substr(1));
    }

    void deleteWord (string word){
        deleteUtil(root, word);
    }
};

int main(){
    Trie t;
    t.insertWord("KRISHNA");
    t.insertWord("ADITI");
    t.insertWord("PARTH");
    t.insertWord("PRANAV");

    t.searchWord("ADITI") ? cout<<"Found"<<endl: cout<<"Not Found"<<endl;
    t.searchWord("AKASH") ? cout<<"Found"<<endl: cout<<"Not Found"<<endl;
    
    t.deleteWord("ADITI");
    t.searchWord("ADITI") ? cout<<"Found"<<endl: cout<<"Not Found"<<endl;
    t.deleteWord("dkfjkd");

    return 0;

}