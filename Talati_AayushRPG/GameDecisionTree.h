#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    std::unordered_map<int, Node<T>*> nodes;  // Map for quick access by event number

    // Helper to find or create a node based on event number
    Node<T>* findOrCreateNode(int eventNumber, const std::string& description = "", int leftEvent = -1, int rightEvent = -1) {
    	if (nodes.find(eventNumber) == nodes.end()) {
      		nodes[eventNumber] = new Node<T>(T(description, eventNumber, leftEvent, rightEvent));
    	} else {
        // If the node already exists, we reuse it
            nodes[eventNumber]->data.description = description;
        	nodes[eventNumber]->data.leftEventNumber = leftEvent;
        	nodes[eventNumber]->data.rightEventNumber = rightEvent;
    	}
	    return nodes[eventNumber];
}

public:
    GameDecisionTree() : root(nullptr) {}

    // Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        std::ifstream file(filename);
    	if (!file.is_open()) {
        	std::cerr << "Failed to open file: " << filename << std::endl;
        	return;
  	    }

    	std::string line;
    	while (std::getline(file, line)) {
        	std::istringstream ss(line);
        	int eventNumber, leftEvent, rightEvent;
        	std::string description;

        	// Parse line: eventNumber | description | leftEventNumber | rightEventNumber
        	ss >> eventNumber >> delimiter;
        	std::getline(ss, description, delimiter);
        	ss >> leftEvent >> delimiter >> rightEvent;
        	// Create or find the current node
        	Node<T>* currentNode = findOrCreateNode(eventNumber, description, leftEvent, rightEvent);
        // Set root if it’s the first node
        	if (root == nullptr) {
            	root = currentNode;
        	}

        // Link child nodes if specified
        	if (leftEvent != -1) {  // -1 indicates no left child (leaf node)
            	currentNode->left = findOrCreateNode(leftEvent);
        	}
        	if (rightEvent != -1) {  // -1 indicates no right child (leaf node)
            	currentNode->right = findOrCreateNode(rightEvent);
        	}
    	}

    file.close();
    }

    // Function to start the game and traverse the tree based on user input
    void playGame() {
        if (!root) {
            std::cerr << "The game has not been loaded." << std::endl;
            return;
        }

        Node<T>* currentNode = root;
        while (currentNode) {
            std::cout << "Event #" << currentNode->data.eventNumber << ": " << currentNode->data.description << std::endl;

            // Check if it’s a leaf node
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                std::cout << "The game has ended. Thank you for playing!" << std::endl;
                break;
            }

            std::cout << "Choose an option (L for left, R for right): ";
            std:string choice;
            std::cin >> choice;
            for (auto& c : choice) c = std::tolower(c);

            if (choice == "left" || choice == "l") {
                if (currentNode->left) {
                    currentNode = currentNode->left;
                } else {
                    std::cout << "Invalid choice. No path available to the left." << std::endl;
                }
            } else if (choice == "right" || choice =="r") {
                if (currentNode->right) {
                    currentNode = currentNode->right;
                } else {
                    std::cout << "Invalid choice. No path available to the right." << std::endl;
                }
            } else {
                std::cout << "Invalid input. Please enter L or R." << std::endl;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H
