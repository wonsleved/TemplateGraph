#ifndef LAB3_LINKEDLIST_H
#define LAB3_LINKEDLIST_H

#include <cinttypes>
#include <iostream>
#include <cassert>
#include "../../Exceptions/Exceptions.h"

template <typename T>
class LinkedList
{
protected:
    using m_Element = struct m_Element {
        T data;
        struct m_Element* next;
        struct m_Element* prev;
    };

    m_Element* m_tail;
    m_Element* m_head;
    int m_size;
public:
    class iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;
        using reference         = T&;

        explicit iterator(m_Element* ptr) : m_ptr(ptr) {};

        reference   operator * () const { return m_ptr->data; };
        pointer     operator -> () { return &(m_ptr->data); };
        iterator&   operator ++ () { m_ptr = m_ptr->next; return *this; };
        iterator    operator ++ (int) { iterator tmp = *this; m_ptr = m_ptr->next; return tmp; };
        iterator&   operator -- () { m_ptr = m_ptr->prev; return *this; };
        iterator    operator -- (int) { iterator tmp = *this; m_ptr = m_ptr->prev; return tmp; };

        iterator operator + (size_t offset)
        { iterator tmp(m_ptr); while(offset--) ++tmp; return tmp; };
        iterator operator - (size_t offset)
        { iterator tmp(m_ptr); while(offset--) --tmp; return tmp; };

        difference_type operator - (const iterator& iterator) const
        {
            difference_type diff = 0;
            m_Element* tmp = m_ptr;
            while(tmp != nullptr && tmp != iterator.m_ptr) {
                tmp = tmp->prev;
                ++diff;
            }
            if (tmp == nullptr) {
                diff = 0;
                tmp = m_ptr;
                while(tmp != nullptr && tmp != iterator.m_ptr) {
                    tmp = tmp->next;
                    --diff;
                }
            }
            return diff;
        };


        bool operator == (const iterator& iterator) const
        { return m_ptr == iterator.m_ptr; };

        bool operator != (const iterator& iterator) const
        { return m_ptr != iterator.m_ptr; };

        bool operator < (const iterator& iterator) const
        { return m_ptr < iterator.m_ptr; }

        bool operator <= (const iterator& iterator) const
        { return m_ptr <= iterator.m_ptr; }

        bool operator > (const iterator& iterator) const
        { return m_ptr > iterator.m_ptr; }

        bool operator >= (const iterator& iterator) const
        { return m_ptr >= iterator.m_ptr; }

        iterator& operator=(const iterator&) = default;
    private:
        m_Element* m_ptr;
    };

    iterator begin();
    iterator end();

    explicit LinkedList();
    explicit LinkedList(int size);
    explicit LinkedList(T* items, int size);
    LinkedList(const LinkedList<T>& another);

    LinkedList<T>& operator= (const LinkedList<T>& another);
    LinkedList<T>& operator= (LinkedList<T>* another);

    ~LinkedList();

    int getSize() const;

    T getItem(int index) const;
    T getFirst() const;
    T getLast() const;
    T reduce(T (*function)(const T& previousValue, const T& currentValue)) const;
    bool find(const T& item) const;

    LinkedList<T>& clear();
    LinkedList<T>& append(const T& item);
    LinkedList<T>& prepend(const T& item);
    LinkedList<T>& remove(int index);
    LinkedList<T>& removeItem(T& item);
    LinkedList<T>& insert(int index, const T& item);
    LinkedList<T>* concat(const LinkedList<T>& list) const;
    LinkedList<T>* getSubList(int startIndex, int endIndex) const;
    LinkedList<T>* map(T (*function)(const T& item)) const;
    LinkedList<T>* filter(bool (*function)(const T& item)) const;

};


#include "./LinkedList.inl"

#endif
