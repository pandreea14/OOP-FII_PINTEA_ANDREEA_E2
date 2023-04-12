#pragma once
#include <iostream>

template <class T>
class Tree
{
    T value;
    Tree<T>* parent;
    Tree<T>* children;
    int num_children = 0;

public:
    Tree(T value) : Tree(nullptr, T) { }
    Tree(Tree<T>* parent, T value)
    {
        this->value = value;
        this->children = new int[0];
        this->parent = parent;
        this->num_children = 0;
    }
    ~Tree()
    {
        this->parent = nullptr;
        this->num_children = 0;
        delete[] this->children;
    }

    void add_node(Tree<T>* parent) 
    {
        Tree<T>* new_node = new Tree<T>(T(this->value));
        new_node->parent = parent;      //se actualizeaza parintele
        if (parent != nullptr)
        {
            parent->children[parent->num_children] = new_node;
            parent->num_children++;
        }
        else
        {
            parent = new_node;  //in caz ca e root
        }
    }

    Tree<T>* get_node(Tree<T>* parent)//cauta fii unui nod parinte dat
    {
        if (parent == nullptr) //if the reference is nullptr, than the root node will be returned
        {
            return this;
        }
        for (int i = 0; i < num_children; i++) 
        {
            if (children[i]->parent == parent) 
            {
                return children[i];
            }
        }
        return nullptr;
    }

    void delete_node(Tree<T>* node) 
    {
        if (node == nullptr) 
        {
            return;
        }
        for (int i = 0; i < node->num_children; i++) 
        {
            delete_node(node->children[i]);//apel recursiv pentru a sterge toti copii copiilor
            node->children[i] = nullptr;
        }
        if (node->parent != nullptr) 
        {
            for (int i = 0; i < node->parent->num_children; i++) 
            {
                if (node->parent->children[i] == node) 
                {
                    for (int j = i + 1; j < node->parent->num_children; j++) //stergerea din vectorul de fii al parintelui
                    {
                        node->parent->children[j - 1] = node->parent->children[j];
                    }
                    node->parent->num_children--;
                }
            }
        }
        delete node;
    }

    Tree<T>* find(bool (*compare)(T)) 
    {
        if (compare(this->value))   
        {
            return this;
        }
        for (int i = 0; i < num_children; i++)
        {
            Tree<T>* found = children[i]->find(compare);
            if (found != nullptr) 
            {
                return found;
            }
        }
        return nullptr;
    }

    void insert(Tree<T>* parent, int index) 
    {
        if (index < 0 || index > num_children) 
        {
            std::cout << "Indexul este invalid" << std::endl;
            return;
        }
        Tree<T>* new_node = new Tree<T>(T());
        new_node->parent = parent;
        for (int i = num_children - 1; i >= index; i--) 
        {
            children[i + 1] = children[i];
        }
        children[index] = new_node;
        num_children++;
    }

    void sort(bool (*compare)(const T&, const T&) = nullptr) 
    {
        for (int i = 0; i < num_children - 1; i++) 
        {
            for (int j = i + 1; j < num_children; j++) 
            {
                if (compare(children[j]->value, children[i]->value)) 
                {
                    std::swap(children[i], children[j]);
                }
            }
        }
        for (int i = 0; i < num_children; i++) 
        {
            children[i]->sort(compare);
        }
    }

    int count()
    {
        int count = num_children;
        for (int i = 0; i < num_children; i++)
        {
            count += children[i]->count();
        }
        return count;
    }
};