#include "hash_list.h"
#include <iostream>
hash_list::hash_list() 
{
    head = NULL;
    size = 0;
}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) 
{
    node * curr;
    if (!head)
    {
        head = build_node(key, value);
        size += 1;
        return;
    }

    curr = head;
    while(curr -> next)
    {
        if(curr -> key == key)
        {
            curr -> value = value;
            return;
        }
        curr = curr -> next;
        size += 1;
    }

    curr -> next = build_node(key, value);
}

std::optional<float> hash_list::get_value(int key) const 
{
    if(!head)
    {
        return std::nullopt;
    }

    node * curr = head;
    while(curr -> next)
    {
        if(curr -> key == key)
        {
            return curr -> value;
        }
        curr = curr -> next;
    }
    return std::nullopt; 
}

bool hash_list::remove(int key) 
{ 
    node * temp;
    node * curr;
    if(!head)
    {
        return false;
    }

    if(head -> key == key)
    {
        temp = head -> next;
        delete head;
        head = temp;
        return true;
    }

    curr = head;
    while(curr -> next)
    {
        if((curr -> next) -> key == key)
        {
            temp = (curr -> next) -> next;
            delete curr -> next;
            curr -> next = temp;
            return true;
        }
        curr = curr -> next;
    }
    return false; 
}

size_t hash_list::get_size() const { return size; }

hash_list::~hash_list() 
{
    node * temp;
    while (head -> next)
    {
        temp = head -> next;
        delete head;
        head = temp;
    }

    delete head;
}

//personal helper functions below:

node * hash_list::build_node(int key, float value)
{
    node * temp = new node;
    temp -> next = NULL;
    temp -> key = key;
    temp -> value = value;

    return temp;
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) {}

hash_list &hash_list::operator=(const hash_list &other) { return *this; }

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
