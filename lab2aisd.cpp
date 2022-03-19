#include <iostream>
#include <windows.h>
#include <cstdio>
#include <conio.h>
#include <dos.h>
#include <ctime>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "tree.cpp"

int bin_search(const struct Tree *search_tree, int item, double *sec);
void treeoutput(struct Node* current_node);


int main()
{
    LARGE_INTEGER tstart, tend, tfreq;
    struct Tree *new_tree = new Tree;
    new_tree->root = NULL;
	new_tree->count = 0;
    insert(new_tree, 16);
    insert(new_tree, 8);
    insert(new_tree, 15);
    insert(new_tree, 4);
    insert(new_tree, 23);
    insert(new_tree, 42);

    printf("////////////////////////////\nTree elements: ");
    inorder(new_tree->root);
    treeoutput(new_tree->root);

    int key;
    double sec;
    printf("\nInput key for search: ");
    cin >> key;
    if (cin.fail())
    {
        cout << "Wrong input!";
        exit(1);
    }
    
    QueryPerformanceCounter(&tstart);

    int search = bin_search(new_tree, key, &sec);

    QueryPerformanceCounter(&tend);
    QueryPerformanceFrequency(&tfreq);
    sec = (double)(tend.QuadPart - tstart.QuadPart) / tfreq.QuadPart;

    if (search == 1)
        printf("\n\nElement %d has been found.", key);
    else
        printf("\n\nElement %d has NOT been found.", key);

    cout << "\nTime estimated on algorythm running: " << sec * 1000 << " ms" << endl;

    cout << "\n////////////////////////////\nTEXT SEARCH ALGORYTHMS\n#1 - Knutt-Morris-Prutt algorythm:" << endl;
    system("kmp.exe");

    cout << "\n#2 - Boyer-Moor algorythm:" << endl;
    system("bm.exe");

    cout << "\n#3 - Rabin algorythm:" << endl;
    system("rabincopy.exe");

    return 0;
}

int bin_search(const struct Tree *search_tree, int item, double *sec)
{
    const struct Node *search_node;
    search_node = search_tree->root;

    for (;;)
    {
        if (search_node == NULL)
            return 0;
        else if (item == search_node->data)
            return 1;
        else if (item > search_node->data)
            search_node = search_node->right;
        else
            search_node = search_node->left;
    }
}