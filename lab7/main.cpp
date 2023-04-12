#include "Template.h"
#include <iostream>

using namespace std;

int main() 
{
    Tree<int>* t = new Tree<int>(2);
    t->add_node(t);
    t->add_node(t);
    t->add_node(t);
    t->add_node(t.children[0]);
    cout << t->get_node(t.children[0]) << endl;
    t->delete_node(t.children[0]);
    cout << t->get_node(t.children[0]) << endl;
    cout << t->count() << endl;
    t->insert(t.children[0], 2);
    cout << t->count();

}