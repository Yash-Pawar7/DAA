#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    // Constructor for Node
    Node(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
        left = right = NULL;
    }
};

// Comparator for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Smaller freq should come first
    }
};

// Print Huffman codes by traversing the tree
void printHuffmanCodes(Node* root, string code) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << endl;
    }
    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

// Build Huffman Tree and print codes
void huffman(vector<char>& chars, vector<int>& freqs) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and push into the queue
    for (int i = 0; i < chars.size(); i++) {
        pq.push(new Node(chars[i], freqs[i]));
    }

    // Build the Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* newNode = new Node('-', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    // Print the Huffman codes
    printHuffmanCodes(pq.top(), "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freqs(n);

    // Input characters and frequencies
    for (int i = 0; i < n; i++) {
        cout << "Enter character and its frequency: ";
        cin >> chars[i] >> freqs[i];
    }

    // Build Huffman Tree and display the codes
    huffman(chars, freqs);

    return 0;
}

/*OUTPUT

Enter number of characters: 5
Enter character and its frequency: a 5
Enter character and its frequency: b 8
Enter character and its frequency: c 10
Enter character and its frequency: d 15
Enter character and its frequency: e 22
c: 00
a: 010
b: 011
d: 10
e: 11

*/
