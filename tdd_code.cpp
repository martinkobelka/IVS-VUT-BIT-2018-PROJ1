//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find a GetHead
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "double-linked list", ktera bude splnovat dodane testy 
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{
    // Root is pointer to head
    root = nullptr;
}

PriorityQueue::~PriorityQueue()
{
    // Free just non-empty Queue
    if(root != nullptr) {
        
        Element_t * help_pointer_cycle = root;
        Element_t * help_pointer_cycle_next;

        // Free all pointers
        while(help_pointer_cycle != nullptr) {
            
            help_pointer_cycle_next = help_pointer_cycle->pNext;
            free(help_pointer_cycle);
            
            help_pointer_cycle = help_pointer_cycle_next;
            
        }

        // Change root to null
        root = nullptr;
    }
}

void PriorityQueue::Insert(int value)
{
    
    // Malloc new element
    Element_t * added_value = (Element_t *) malloc(sizeof(Element_t));
    added_value->value = value;
    
    // If it is first value
    if(root == nullptr) {
        
        added_value->pPrev = added_value->pNext = nullptr;
        root = added_value;
    }
    
    // If it is not first value
    else {
        
        Element_t * find_root = root;
        
        // Add item as first value
        if (find_root->value > value) {
            
            added_value->pNext = root;
            root->pPrev = added_value;
            added_value->pPrev = nullptr;
            root = added_value;
            
        }
        
        else {
            
            while(find_root->pNext != nullptr) {
                
                // Add in the middle of two elements
                if(find_root->pNext->value > value) {
                    
                    find_root->pNext->pPrev = added_value;
                    added_value->pNext = find_root->pNext;
                    added_value->pPrev = find_root;
                    find_root->pNext = added_value;
                    
                    return;
                }
                
                find_root = find_root->pNext;
                
            }
            
            // Add in the end of list
            added_value->pNext = nullptr;
            added_value->pPrev = find_root;
            find_root->pNext = added_value;
        }
    }    
}

bool PriorityQueue::Remove(int value)
{
    
    Element_t * help_pointer_cycle = root;
    
    // Find removed element
    while(help_pointer_cycle != nullptr) {
        
        // If it is removed element
        if(help_pointer_cycle->value == value) {
            
            // If it is first element
            if(help_pointer_cycle->pPrev == nullptr) {
                
                Element_t * help_pointer = help_pointer_cycle;
                root = help_pointer->pNext;
                free(help_pointer);
                if(root != nullptr) {
                    root->pPrev = nullptr;
                }
                help_pointer = nullptr;
            }
            
            
            // If it is last element
            else if(help_pointer_cycle->pNext == nullptr) {
                
                Element_t * help_pointer = help_pointer_cycle;
                help_pointer->pPrev->pNext = nullptr;
                free(help_pointer);
                help_pointer = nullptr;
            }
            
            // If it is element in the middle of two elements
            else {
                
                Element_t * help_pointer = help_pointer_cycle;
                help_pointer->pPrev->pNext = help_pointer->pNext;
                help_pointer->pNext->pPrev = help_pointer->pPrev;
                free(help_pointer);
                help_pointer = nullptr;
            }
            
            // If the element was found, return true
            return true;
        }
        
        help_pointer_cycle = help_pointer_cycle->pNext;
        
    }
    
    // If the element was not found, return false
    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{
    // Help_pointer_cycle
    Element_t * help_pointer_cycle = root;
    
    // Loop while there is another element
    while(help_pointer_cycle != nullptr) {
        
        // If the value and value of element is correct, return item
        if(help_pointer_cycle->value == value) {
            return help_pointer_cycle;
        }
        
        // Go to next item
        help_pointer_cycle = help_pointer_cycle->pNext;
    }
    
    // If there is no item with value, return NULL
    return nullptr;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    // Root is pointer to head
    return root;
}

/*** Konec souboru tdd_code.cpp ***/
