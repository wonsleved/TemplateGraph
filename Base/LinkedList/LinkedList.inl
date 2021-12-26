template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin() {
    return iterator(m_head);
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end() {
    if (m_tail)
        return iterator(m_tail->next);
    else
        return iterator(0);
}


template <typename T>
LinkedList<T>::LinkedList() : m_size(0), m_tail(nullptr), m_head(nullptr) {
}

//template <typename T>
//LinkedList<T>::LinkedList(int size) : LinkedList() {
//    if (size < 0) throw (Exceptions(ExceptionConsts::INVALID_SIZE));
//    for (int i = 0; i < size; i++)
//        append(NULL);
//}

template <typename T>
LinkedList<T>::LinkedList(T* items, int size) : LinkedList() {
    if (size < 0) throw (Exceptions(ExceptionConsts::INVALID_SIZE));
    for (int i = 0; i < size; i++)
        append(items[i]);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& another) : LinkedList() {
    for (int i = 0; i < another.m_size; i++) {
        append(another.getItem(i));
    }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& another) {
    clear();
    for (m_Element* element = another.m_head; element != nullptr; element = element->next) {
        append(element->data);
    }

    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator= (LinkedList<T>* another) {
    clear();
    for (m_Element* element = another->m_head; element != nullptr; element = element->next) {
        append(element->data);
    }

    return *this;
}


template <typename T>
LinkedList<T>::~LinkedList() {

    m_Element* tail = m_head;
    while(m_head) {
        tail = tail->next;
        delete m_head;
        m_head = tail;
    }
}

template <typename T>
T LinkedList<T>::getItem(int index) const {
    if (m_size == 0) throw(Exceptions(ExceptionConsts::EMPTY_LIST));
    if (index < 0 || index >= m_size) throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));

    m_Element* tmp;
    if (m_size / 2 >= index) {
        tmp = m_head;
        for (int i = 0; i < index; i++)
            tmp = tmp->next;
    } else {
        tmp = m_tail;
        for (int i = m_size - 1; i > index; i--)
            tmp = tmp->prev;
    }

    return tmp->data;
}

template <typename T>
int LinkedList<T>::getSize() const {
    return m_size;
}

template <typename T>
T LinkedList<T>::getFirst() const {
    if (m_size == 0) throw(Exceptions(ExceptionConsts::EMPTY_LIST));
    return m_head->data;
}

template <typename T>
T LinkedList<T>::getLast() const {
    if (m_size == 0) throw(Exceptions(ExceptionConsts::EMPTY_LIST));
    return m_tail->data;
}

template <typename T>
LinkedList<T>& LinkedList<T>::append(const T& item) { // tail->prev = nullptr

    m_Element* newOne = new m_Element;

    newOne->data = item;
    newOne->prev = m_tail; // if getSize is 0 m_tail is equal nullptr!
    if (m_tail) {
        newOne->next = m_tail->next;
        m_tail->next->prev = newOne;
    }
    else {
        newOne->next = new m_Element;
        newOne->next->prev = newOne;
        newOne->next->next = nullptr;
        newOne->next->data = item;
    }

    if (m_size > 0)
        m_tail->next = newOne;
    else
        m_head = newOne;


    m_size++;
    m_tail = newOne;

    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::prepend(const T &item) {
    if (m_size == 0) {
        append(item);
    } else {
        m_Element* newOne = new m_Element;

        newOne->data = item;
        newOne->prev = nullptr;
        newOne->next = m_head;

        m_head->prev = newOne;

        m_size++;
        m_head = newOne;
    }
    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::insert(int index, const T& item) {
    if (m_size == 0) throw(Exceptions(ExceptionConsts::EMPTY_LIST));
    if (index < 0 || index >= m_size) throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));

    m_Element* newOne = new m_Element;

    newOne->data = item;

    if (index == 0) {
        m_head->prev = newOne;
        newOne->next = m_head;
        newOne->prev = nullptr;
        m_head = newOne;
    } else {
        if (m_size / 2 >= index) {
            newOne->next = m_head;
            for (int i = 0; i < index; i++) {
                newOne->next = newOne->next->next;
            }
            newOne->prev = newOne->next->prev;
            newOne->prev->next = newOne;
            newOne->next->prev = newOne;
        } else {
            newOne->prev = m_tail->prev;
            for (int i = m_size - 1; i > index; i--) {
                newOne->prev = newOne->prev->prev;
            }
            newOne->next = newOne->prev->next;
            newOne->next->prev = newOne;
            newOne->prev->next = newOne;
        }
    }



    m_size++;
    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::remove(int index) {
    if (m_size == 0) throw (Exceptions(ExceptionConsts::EMPTY_LIST));
    if (index < 0 || index >= m_size) throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));


    if (m_size == 1) {
        delete m_head;
        delete m_tail->next;
        m_head = m_tail = nullptr;
    } else {
        m_Element* item = m_head;
        for (int i = 0; i < index; i++) {
            item = item->next;
        }

        if (item->next != nullptr) item->next->prev = item->prev;
        if (item->prev != nullptr) item->prev->next = item->next;

        if (m_tail == item) m_tail = item->prev;
        if (m_head == item) m_head = item->next;

        delete item;
    }


    m_size--;
    return *this;
}
template <typename T>
LinkedList<T>&
LinkedList<T>::
removeItem(T& item) {
    int index = -1;
    iterator it = begin();
    for (int i = 0; i < m_size; ++i)
        if (*(it + i) == item)
            index = i;

    remove(index);
    return *this;
}

template <typename T>
LinkedList<T>* LinkedList<T>::concat(const LinkedList<T>& list) const {
    LinkedList<T>* result = new LinkedList(*this);
    for (int i = 0; i < list.getSize(); i++)
        result->append(list.getItem(i));

    return result;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getSubList(int startIndex, int endIndex) const {
    if(m_size == 0) throw(Exceptions(ExceptionConsts::EMPTY_LIST));
    if ( (startIndex < 0 || startIndex >= m_size) && (endIndex < startIndex || endIndex >= m_size) )
        throw(BaseException(0, m_size == 0 ? 0 : m_size - 1, ExceptionConsts::INVALID_INDEX));

    LinkedList<T>* result = new LinkedList<T>();
    for (int i = startIndex; i <= endIndex; i++)
        (*result).append(getItem(i));

    return result;
}

template <typename T>
LinkedList<T>* LinkedList<T>::map(T (*function)(const T& item)) const {
    LinkedList<T>* result = new LinkedList<T>();

    for (int i = 0; i < m_size; i++)
        result->append(function( getItem(i) ));

    return result;
}

template <typename T>
LinkedList<T>& LinkedList<T>::clear() {
    m_Element* tail = m_head;
    while(m_head) {
        tail = tail->next;
        delete m_head;
        m_head = tail;
    }
    m_size = 0;
    m_tail = m_head = nullptr;
    return *this;
}

template <typename T>
T LinkedList<T>::reduce (T (*function)(const T& previousValue, const T& currentValue)) const {
    if (m_size < 2) throw(Exceptions(ExceptionConsts::EMPTY_LIST));
    T result = getItem(0);
    for (int i = 1; i < m_size; i++)
        result = function(result, getItem(i));

    return result;
}

template <typename T>
bool LinkedList<T>::find(const T& item) const {
    for (auto i : *this)
        if (i == item)
            return true;

    return false;
}

template <typename T>
LinkedList<T>* LinkedList<T>::filter(bool (*function)(const T& item)) const {
    LinkedList<T>* result = new LinkedList<T>();
    T tmp;
    for (int i = 0; i < m_size; i++) {
        tmp = getItem(i);
        if (function(tmp))
            result->append(tmp);
    }

    return result;
}

// Operators

template <typename T>
std::ostream& operator<< (std::ostream &out, const LinkedList<T>& list) {
    out << "{";
    for (int i = 0; i < list.getSize() - 1; i++) {
        out << list.getItem(i) << ", ";
    }
    if (list.getSize() > 0)
        out << list.getItem(list.getSize() - 1);
    out << "}";
    return out;
}