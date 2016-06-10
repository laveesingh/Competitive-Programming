#include <iostream>
#include <cstdlib>

using namespace std;

struct TrieNode{
	struct TrieNode *children[2];
	bool isleaf;
}*pNode;

struct TrieNode *getNode(void){
	pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
	if(pNode){
		pNode -> isleaf = false;
		pNode->children[1] = NULL;
		pNode->children[0] = NULL;
	}
	return pNode;
}

void insert(struct TrieNode *root, string key){
	struct TrieNode *pCrawl = root;
	for (int level = 0; level < key.length(); level += 1){
		if (!pCrawl->children[key[level]-'0']){
			pCrawl->children[key[level]-'0'] = getNode();
		}
		pCrawl = pCrawl -> children[key[level]-'0'];
	}
	pCrawl->isleaf = true;
}

bool search(struct TrieNode *root, string key){
	struct TrieNode *pCrawl = root;
	for(int level = 0; level < key.length(); level += 1){
		if(!pCrawl->children[key[level]-'0']) return false;
		pCrawl = pCrawl -> children[key[level]-'0'];
	}
	return (pCrawl != NULL && pCrawl -> isleaf);
}

int main(void){
	string key;
	struct TrieNode *root;
	root = getNode();
	int q;
	do{
		cout << "Enter 1 to insert and 2 to search any key and 0 to quit: " << endl;
		cin >> q;
		if (q == 1){
			cout << "Enter key to insert" << endl;
			cin >> key;
			insert(root, key);
		}else if(q == 2){
			cout << "Enter key to search" << endl;
			cin>>key;
			if(search(root, key)){
				cout << "Key is present in the trie" << endl;
			}else{
				cout << "Key is not present in the trie" << endl;
			}
		}else{
			cout << "Quitting..." << endl;
			break;
		}
	}while(1);
}